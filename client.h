#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QSslSocket>
#include <QHash>

#include "messagehandler.h"
#include "message.h"
#include "hostmask.h"

class Client : public QObject
{
    Q_OBJECT

public:
    Client(QObject *parent = 0);
    ~Client();

    void connectToServer();

    void setNickname(const QString& nickname);
    void setRealname(const QString& realname);
    void setUsername(const QString& username);

    QString getNickname() const;
    QString getUsername() const;
    QString getRealname() const;

    void setServerHostname(const QString& hostname);
    void setServerPort(quint16 port);

    QString getServerHostname() const;
    quint16 getServerPort() const;

    void registerMessageHandler(const QString& command, MessageHandler* handler);

    void sendNick(const QString& nickname);
    void sendUser(const QString& username, const QString& realname, const QString& hostname);
    void sendJoin(const QString& channel);
    void sendQuit(const QString& message);
    void sendPong(const QString& message);
    void sendRaw(const QString& message);

signals:
    void ReceivedMessage(const Message& message);
    void Connected();

private slots:
    void readData();
    void connectionEstablished();
    void dispatchMessage(const Message& message);

private:
    void writeLine(const QString& line);

    QString _nickname;
    QString _username;
    QString _realname;

    QString _server_hostname;
    int _server_port;

    QSslSocket *_socket;

    QHash<QString, QList<MessageHandler*> > _message_handlers;
};

#endif // CLIENT_H
