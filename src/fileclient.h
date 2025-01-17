#ifndef IPMSGFILECLIENT_H
#define IPMSGFILECLIENT_H

#include <QFileInfo>
#include <QHostAddress>
#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include "common.h"
#include "user.h"

#define FILE_TRANS_STATUS_IDLE 0
#define FILE_TRANS_STATUS_QUEUE 1
#define FILE_TRANS_STATUS_PRERUN 2
#define FILE_TRANS_STATUS_RUN 3
#define FILE_TRANS_STATUS_FINISHED 4

typedef struct userInfoT
{
    QByteArray userVer;
    QByteArray userId;
    QByteArray userNickName;
    QByteArray userGroupName;
    QByteArray userHostName;
    QByteArray userEmail;
    QByteArray userIcon;
    QHostAddress userHostAddr;
    uint32_t userPktSeq;
    uint32_t userCfmSeq;
} userInfoT;

class IpMsgFileClient : public QObject
{
    Q_OBJECT
public:
    explicit IpMsgFileClient(IpMsgUser *user, QObject *parent = nullptr);
    fileEntryT recvFileInfo;
    QTcpSocket *sock;
    int mProgress;
    userInfoT me;
signals:
    void ipMsgFileClientErrorSig(quint32 fileid, int progress);
    void ipMsgFileClientProgressSig(quint32 fileid, int progress);
    void ipMsgFileClientFinishSig(quint32 fileid);

public slots:

private slots:
    void ipMsgFileClientStart();
    void ipMsgFileClientConnected();
    void ipMsgFileClientError(QAbstractSocket::SocketError error);
    void ipMsgFileClientDisconnected();
    void ipMsgFileClientRecv();
    void ipMsgFileClientClose();

private:
    QFile mFile;
    qint64 mSize;
};

#endif // IPMSGFILECLIENT_H
