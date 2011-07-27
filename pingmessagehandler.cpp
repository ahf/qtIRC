#include "pingmessagehandler.h"

PingMessageHandler::PingMessageHandler()
{
}

void PingMessageHandler::handle(Client *client, const Message &message)
{
    QString pongMessage = message.getTarget();
    client->sendPong(pongMessage);
}
