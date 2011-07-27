#ifndef HOSTMASK_H
#define HOSTMASK_H

#include <QString>

class Hostmask
{
public:
    QString getNickname() const;
    QString getUsername() const;
    QString getHostname() const;
    QString toString() const;

    static Hostmask parse(const QString& l);

protected:
    Hostmask(const QString& nickname, const QString& username, const QString& hostname);

private:
    QString _nickname;
    QString _username;
    QString _hostname;
};

#endif // HOSTMASK_H
