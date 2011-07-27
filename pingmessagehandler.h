#ifndef PINGMESSAGEHANDLER_H
#define PINGMESSAGEHANDLER_H

#include "message.h"
#include "client.h"
#include "messagehandler.h"

class PingMessageHandler : public MessageHandler
{
public:
    PingMessageHandler();
    virtual void handle(Client *client, const Message& message);
};

#endif // PINGMESSAGEHANDLER_H
