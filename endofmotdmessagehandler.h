#ifndef ENDOFMOTDMESSAGEHANDLER_H
#define ENDOFMOTDMESSAGEHANDLER_H

#include "messagehandler.h"
#include "client.h"
#include "message.h"

class EndOfMOTDMessageHandler : public MessageHandler
{
public:
    EndOfMOTDMessageHandler();

    virtual void handle(Client *client, const Message &message);
};

#endif // ENDOFMOTDMESSAGEHANDLER_H
