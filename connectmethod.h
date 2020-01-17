#ifndef CONNECTMETHOD_H
#define CONNECTMETHOD_H

#include <QObject>

class QNetworkRequest;
class QNetworkReply;
class QString;
class ConnectMethod :public QObject
{
    Q_OBJECT
public:
    ConnectMethod(QObject* parent = nullptr);
    virtual ~ConnectMethod();
    virtual void RunMethod(const QString& strAPI);
public slots:
    void HandleReplyFinished(QNetworkReply* pReply);
signals:
    void SendReply(QNetworkReply* pReply);
protected:
    virtual QNetworkRequest DoEncrypt(const QNetworkRequest& request);
};

class NoEncryptMethod :public ConnectMethod
{
    Q_OBJECT
public:
    NoEncryptMethod(QObject* parent = nullptr);
};

class EncryptMethod :public ConnectMethod
{
    Q_OBJECT
public:
    EncryptMethod(QObject* parent = nullptr);
protected:
    QNetworkRequest DoEncrypt(const QNetworkRequest &request) override;
};

#endif // CONNECTMETHOD_H
