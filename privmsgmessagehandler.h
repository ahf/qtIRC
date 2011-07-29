#ifndef PRIVMSGMESSAGEHANDLER_H
#define PRIVMSGMESSAGEHANDLER_H

#include "messagehandler.h"
#include "client.h"
#include "message.h"

#include <QSystemTrayIcon>

class PrivmsgMessageHandler : public MessageHandler
{
public:
    PrivmsgMessageHandler();

    virtual void handle(Client *client, const Message &message);

private:
    QSystemTrayIcon *_tray_icon;
};

#endif // PRIVMSGMESSAGEHANDLER_H
