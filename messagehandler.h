#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>

class Client;
class Message;

class MessageHandler : public QObject
{
    Q_OBJECT

protected:
    MessageHandler();

public:
    virtual void handle(Client* client, const Message &message) = 0;
};

#endif // MESSAGEHANDLER_H
