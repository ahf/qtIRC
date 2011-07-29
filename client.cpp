#include "client.h"

#include <QtDebug>

Client::Client(QObject *parent) :
    QObject(parent)
{
    _socket = new QSslSocket(this);

    // We ignore SSL errors since most IRC servers uses invalid certificates.
    connect(_socket, SIGNAL(sslErrors(QList<QSslError>)), _socket, SLOT(ignoreSslErrors()));

    connect(_socket, SIGNAL(connected()), SLOT(connectionEstablished()));
    connect(_socket, SIGNAL(readyRead()), SLOT(readData()));

    // Send messages to dispatching.
    connect(this, SIGNAL(ReceivedMessage(Message)), SLOT(dispatchMessage(Message)));
}

Client::~Client()
{
}

void Client::sendNick(const QString &nickname)
{
    writeLine(QString("NICK %1").arg(nickname));

    // We set it here to keep track of it.
    _nickname = nickname;
}

void Client::sendUser(const QString &username, const QString &realname, const QString &hostname)
{
    writeLine(QString("USER %1 %1 %2 :%3").arg(username).arg(hostname).arg(realname));
}

void Client::sendJoin(const QString &channel)
{
    writeLine(QString("JOIN %1").arg(channel));
}

void Client::sendQuit(const QString &message)
{
    writeLine(QString("QUIT :%1").arg(message));
}

void Client::sendPong(const QString &message)
{
    writeLine(QString("PONG :%1").arg(message));
}

void Client::sendRaw(const QString &message)
{
    writeLine(message);
}

void Client::sendPrivmsg(const QString &target, const QString &text)
{
    writeLine(QString("PRIVMSG %1 :%2").arg(target).arg(text));
}

void Client::didReceivePrivmsg(const Hostmask &hostmask, const QString &target, const QString &text)
{
    emit PrivmsgReceived(hostmask, target, text);
}

void Client::connectToServer()
{
    _socket->connectToHost(_server_hostname, _server_port);
}

void Client::writeLine(const QString &line)
{
    qDebug() << "Send:" << line;
    _socket->write(QString("%1\r\n").arg(line).toUtf8());
}

void Client::connectionEstablished()
{
    qDebug() << "Connection Established";

    sendNick(_nickname);
    sendUser(_username, _realname, _socket->peerName());

    emit Connected();
}

void Client::readData()
{
    while (_socket->canReadLine())
    {
        QString line = _socket->readLine();
        line.remove("\r\n");

        qDebug() << "Recv:" << line;

        emit ReceivedMessage(Message::parse(line));
    }
}

void Client::registerMessageHandler(const QString& command, MessageHandler* handler)
{
    _message_handlers[command.toLower()].append(handler);
    handler->setParent(this);
}

void Client::dispatchMessage(const Message& message)
{
    foreach (MessageHandler* handler, _message_handlers[message.getCommand().toLower()])
    {
        handler->handle(this, message);
    }
}

void Client::setServerHostname(const QString &hostname)
{
    _server_hostname = hostname;
}

void Client::setServerPort(quint16 port)
{
    _server_port = port;
}

QString Client::getServerHostname() const
{
    return _server_hostname;
}

quint16 Client::getServerPort() const
{
    return _server_port;
}

QString Client::getNickname() const
{
    return _nickname;
}

QString Client::getUsername() const
{
    return _nickname;
}

QString Client::getRealname() const
{
    return _realname;
}

void Client::setNickname(const QString &nickname)
{
    _nickname = nickname;
}

void Client::setUsername(const QString &username)
{
    _username = username;
}

void Client::setRealname(const QString &realname)
{
    _realname = realname;
}
