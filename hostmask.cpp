#include "hostmask.h"

Hostmask::Hostmask(const QString& nickname, const QString& username, const QString& hostname) :
    _nickname(nickname),
    _username(username),
    _hostname(hostname)
{
}

QString Hostmask::toString() const
{
    return _nickname + "!" + _username + "@" + _hostname;
}

QString Hostmask::getNickname() const
{
    return _nickname;
}

QString Hostmask::getUsername() const
{
    return _username;
}

QString Hostmask::getHostname() const
{
    return _hostname;
}

Hostmask Hostmask::parse(const QString &l)
{
    QString nickname;
    QString username;
    QString hostname;

    int at_pos = l.indexOf('@');
    int exclamation_mark_pos = l.indexOf('!');

    nickname = l.left(exclamation_mark_pos);
    username = l.mid(exclamation_mark_pos + 1, at_pos);
    hostname = l.mid(at_pos + 1, l.size());

    return Hostmask(nickname, username, hostname);
}
