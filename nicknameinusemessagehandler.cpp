#include "nicknameinusemessagehandler.h"

#include "client.h"
#include "message.h"

NicknameInUseMessageHandler::NicknameInUseMessageHandler()
{
}

void NicknameInUseMessageHandler::handle(Client *client, const Message &)
{
    QString oldNickname = client->getNickname();
    QString newNickname = oldNickname + "_";

    client->sendNick(newNickname);
}
