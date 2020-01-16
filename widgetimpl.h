#ifndef WIDGETIMPL_H
#define WIDGETIMPL_H

#include <QObject>
#include <QWidget>
#include <memory>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
class IArea;
class QNetworkReply;
using std::shared_ptr;
QT_END_NAMESPACE

class WidgetImpl :public QWidget
{
    Q_OBJECT
public:
    WidgetImpl(QWidget *parent = nullptr);
    ~WidgetImpl();
    void ConnectUIControl();
    void SettingAPIString();
    void TransferWeatherAPI(const QString& strAPI);
    void JSONParser(QNetworkReply* pReply);
    Ui::Widget* m_pUI;
    shared_ptr<IArea> m_spIArea;
    QString m_strLocation;
    QString m_strElementName;
    QString m_strDateTime;
    QString m_strDateTimeHour;
    QString m_strStartTime;
    QString m_strAuthorization;
    QString m_strReplyText;
public slots:
    void HandlecbxAreaChanged(QString strText);
    void HandlecbxLocationChanged(QString strText);
    void HandlebtnEnterClicked();
    void HandleReplyFinished();
    void HandleDescriptionTextChanged(QString strText);
signals:
    void DescriptionTextChanged(QString strText);
};

#endif // WIDGETIMPL_H
