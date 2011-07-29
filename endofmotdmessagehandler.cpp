#include "endofmotdmessagehandler.h"

EndOfMOTDMessageHandler::EndOfMOTDMessageHandler()
{
}

void EndOfMOTDMessageHandler::handle(Client *client, const Message &message)
{
    client->sendJoin("#TheCamp");
}
