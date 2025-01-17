#ifndef IPMSGFILERECV_H
#define IPMSGFILERECV_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include "common.h"
#include "fileclient.h"

class IpMsgFileRecv : public QObject
{
    Q_OBJECT
public:
    explicit IpMsgFileRecv(IpMsgUser *user, fileEntryT *file, QObject *parent = nullptr);
    IpMsgFileClient *client = nullptr;
signals:
    void fileRecvCancel();

public slots:
    void ipMsgFileClientCancel(fileEntryT *file);
};

#endif // IPMSGFILERECV_H
