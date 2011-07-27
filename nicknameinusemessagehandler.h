#ifndef NICKNAMEINUSEMESSAGEHANDLER_H
#define NICKNAMEINUSEMESSAGEHANDLER_H

#include "messagehandler.h"

class NicknameInUseMessageHandler : public MessageHandler
{
public:
    NicknameInUseMessageHandler();
    virtual void handle(Client* client, const Message &message);
};

#endif // NICKNAMEINUSEMESSAGEHANDLER_H
