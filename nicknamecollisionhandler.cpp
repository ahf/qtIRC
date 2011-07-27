#include "nicknamecollisionhandler.h"

NicknameCollisionHandler::NicknameCollisionHandler(QObject *parent) :
    QObject(parent)
{
}

QString NicknameCollisionHandler::handleNicknameCollision(const QString &currentNickname)
{
    return currentNickname + "_";
}
