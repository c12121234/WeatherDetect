#include "connectmethod.h"
#include <QObject>
#include <QtNetwork>
#include <QString>
#include <memory>
ConnectMethod::ConnectMethod(QObject *parent):
    QObject(parent)
{

}

ConnectMethod::~ConnectMethod()
{

}

void ConnectMethod::RunMethod(const QString &strAPI)
{
    QNetworkAccessManager* pManager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(QUrl(strAPI));
    request = DoEncrypt(request);
    QNetworkReply* pReply = pManager->get(request);
    connect(pReply,QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
            [=](QNetworkReply::NetworkError code){
        qDebug()<<code;
    });
    connect(pManager,&QNetworkAccessManager::finished,this,&ConnectMethod::HandleReplyFinished);
    connect(pManager,&QNetworkAccessManager::finished,pManager,&QObject::deleteLater);

}

void ConnectMethod::HandleReplyFinished(QNetworkReply *pReply)
{
    //QNetworkReply *pReply = qobject_cast<QNetworkReply*>(sender());
    emit SendReply(pReply);
}

QNetworkRequest ConnectMethod::DoEncrypt(const QNetworkRequest &request)
{
    return request;
}

NoEncryptMethod::NoEncryptMethod(QObject *parent):
    ConnectMethod(parent)
{

}

EncryptMethod::EncryptMethod(QObject *parent):
    ConnectMethod(parent)
{

}

QNetworkRequest EncryptMethod::DoEncrypt(const QNetworkRequest &request)
{
    QNetworkRequest cpyRequest = request;
    QSslConfiguration config = request.sslConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    config.setProtocol(QSsl::TlsV1SslV3);
    cpyRequest.setSslConfiguration(config);
    return cpyRequest;
}
