#ifndef NICKNAMECOLLISIONHANDLER_H
#define NICKNAMECOLLISIONHANDLER_H

#include <QObject>

class NicknameCollisionHandler : public QObject
{
    Q_OBJECT

public:
    NicknameCollisionHandler(QObject *parent = 0);

    virtual QString handleNicknameCollision(const QString& currentNickname);
};

#endif // NICKNAMECOLLISIONHANDLER_H
