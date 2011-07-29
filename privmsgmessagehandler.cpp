#include "privmsgmessagehandler.h"
#include "hostmask.h"

PrivmsgMessageHandler::PrivmsgMessageHandler()
{
    _tray_icon = new QSystemTrayIcon(this);
    _tray_icon->show();
}

void PrivmsgMessageHandler::handle(Client *client, const Message &message)
{
    QString target = message.getTarget();
    QString text = message.getArguments().join(" ");
    Hostmask from = Hostmask::parse(message.getPrefix());

    client->didReceivePrivmsg(from, target, text);

    _tray_icon->showMessage("Message Received", text);
}
