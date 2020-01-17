#include "widgetimpl.h"
#include "ui_widget.h"
#include "areafactory.h"
#include "IArea.h"
#include "judgepic.h"
#include <QMessageBox>
#include <vector>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>


WidgetImpl::WidgetImpl(QWidget *parent):
    QWidget(parent)
  , m_pUI(new Ui::Widget)
  , m_spIArea(nullptr)
  , m_spImg(std::make_shared<QImage>())
{
    m_pUI->setupUi(this);
    ConnectUIControl();
    SettingAPIString();
    m_spImg->load(":/img/weathericon.png");
    //m_pUI->labelPic->setPixmap(QPixmap::fromImage(*m_spImg).copy(73,113,187,187));
    emit m_pUI->cbxArea->currentTextChanged("宜蘭縣");
}

WidgetImpl::~WidgetImpl()
{
    delete m_pUI;
}

void WidgetImpl::ConnectUIControl()
{
    connect(m_pUI->cbxArea,&QComboBox::currentTextChanged,this,&WidgetImpl::HandlecbxAreaChanged);
    connect(m_pUI->cbxLocation,&QComboBox::currentTextChanged,this,&WidgetImpl::HandlecbxLocationChanged);
    connect(m_pUI->btnEnter,&QPushButton::clicked,this,&WidgetImpl::HandlebtnEnterClicked);
    connect(this,&WidgetImpl::DescriptionTextChanged,this,&WidgetImpl::HandleDescriptionTextChanged);
    connect(this,&WidgetImpl::DescriptionTextChanged,this,&WidgetImpl::ChangePicView);
}

void WidgetImpl::SettingAPIString()
{
    m_strLocation = "頭城鎮";
    QDateTime time = QDateTime::currentDateTime();
    m_strDateTime = time.toString("yyyy-MM-dd");
    m_strDateTimeHour = time.toString("hh");
    m_strStartTime = "00:00:00";
    m_strAuthorization = "CWB-A8736F28-385A-4742-AFC6-AEF35AE278C8";
}

void WidgetImpl::TransferWeatherAPI(const QString &strAPI)
{
    QNetworkAccessManager* pManager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(QUrl(strAPI));
    QNetworkReply* pReply = pManager->get(request);
    connect(pReply,QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
            [=](QNetworkReply::NetworkError code){
        qDebug()<<code;
    });
    connect(pReply,&QNetworkReply::finished,this,&WidgetImpl::HandleReplyFinished);
    connect(pManager,&QNetworkAccessManager::finished,pManager,&QObject::deleteLater);
}

void WidgetImpl::JSONParser(QNetworkReply *pReply)
{
    QByteArray data = pReply->readAll();    

    QJsonParseError ErrorReport;
    QJsonDocument myDocument = QJsonDocument::fromJson(data,&ErrorReport);
    if(ErrorReport.error != QJsonParseError::NoError)
    {
        qDebug()<<"json syntax error.";
        return;
    }
    else
    {
        QJsonObject RootObj = myDocument.object();
        QJsonObject RecordObj = RootObj.value("records").toObject();
        QJsonObject Locations = RecordObj.value("locations").toArray().at(0).toObject();
        QJsonObject Location = Locations.value("location").toArray().at(0).toObject();
        QJsonObject weatherElement = Location.value("weatherElement").toArray().at(0).toObject();
        QJsonObject time = weatherElement.value("time").toArray().at(0).toObject();
        QJsonObject elementValue = time.value("elementValue").toArray().at(0).toObject();
        QString strCall = elementValue.value("value").toString();
        emit DescriptionTextChanged(strCall);
        qDebug()<<strCall;
        qDebug()<<"end";
    }
}

QString WidgetImpl::ProcessWeatherText(const QString &strText)
{
    QStringList strList = strText.split("。");
    return strList[0];
}

void WidgetImpl::HandlecbxAreaChanged(QString strText)
{
    m_spIArea = AreaFactory::CreateArea(strText);
    if(m_spIArea)
    {
        std::vector<QString> vTemp = m_spIArea->GetLocation();
        m_pUI->cbxLocation->clear();
        for(auto strLocation : vTemp)
            m_pUI->cbxLocation->addItem(strLocation);
    }

}

void WidgetImpl::HandlecbxLocationChanged(QString strText)
{
    m_strLocation = strText;
}

void WidgetImpl::HandlebtnEnterClicked()
{
    int nselectTime = m_pUI->spxTime->value();
    if(nselectTime <= m_strDateTimeHour.toInt())
    {
        QMessageBox::about(this,"passed time","don't select pass time.");
        return;
    }
    QString strAreaAPI = m_spIArea->GetAreaAPItext();
    QString strHour = QString("%1").arg(m_pUI->spxTime->value(),2,10,QLatin1Char('0'));
    m_strStartTime[0] = strHour[0];
    m_strStartTime[1] = strHour[1];
    QString strTextURL = QString("https://opendata.cwb.gov.tw/api/v1/rest/datastore/%1?Authorization=%2&locationName=%3"
            "&elementName=WeatherDescription&startTime=%4T%5").arg(strAreaAPI).arg(m_strAuthorization)
            .arg(m_strLocation).arg(m_strDateTime).arg(m_strStartTime);
    //QMessageBox::about(this,"url",strTextURL);

    TransferWeatherAPI(strTextURL);

}

void WidgetImpl::HandleReplyFinished()
{
    QNetworkReply *pReply = qobject_cast<QNetworkReply*>(sender());
    JSONParser(pReply);

}

void WidgetImpl::HandleDescriptionTextChanged(QString strText)
{
    m_strReplyText = strText;
    m_pUI->labelWeather->setText(m_strReplyText);
}

void WidgetImpl::ChangePicView(QString strText)
{
    QString strWeather = ProcessWeatherText(strText);
    std::pair<int,int> pTemp = JudgePic::JudgePicPos(strWeather);
    m_pUI->labelPic->setPixmap(QPixmap::fromImage(*m_spImg).copy(pTemp.first,pTemp.second,187,187));
}
