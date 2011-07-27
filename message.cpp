#include "message.h"

#include <QtDebug>

Message::Message(const QString& prefix, const QString& target, const QString& command, const QString& raw, const QStringList& arguments) :
    _prefix(prefix),
    _target(target),
    _command(command),
    _raw_line(raw),
    _arguments(arguments)
{
}

Message Message::parse(const QString &l)
{
    QString prefix;
    QString target;
    QString command;
    QStringList arguments;
    QString raw(l);
    QString line(l);

    int pos = 0;

    if (line.startsWith(':'))
    {
        pos = line.indexOf(' ', 1);
        prefix = line.mid(1, pos - 1);
        line = line.mid(pos + 1, line.length());
    }

    if (-1 != (pos = line.indexOf(" :")))
    {
        QString tmp(line.mid(pos + 2, line.length()));
        arguments.append(line.left(pos).split(' '));
        arguments.append(tmp.split(' '));
    }
    else
    {
        arguments = line.split(' ');
    }

    if (! arguments.isEmpty())
    {
        command = arguments.front();
        arguments.pop_front();
    }

    if (! arguments.isEmpty())
    {
        target = arguments.front();
        arguments.pop_front();
    }

    return Message(prefix, target, command, raw, arguments);
}

QString Message::getPrefix() const
{
    return _prefix;
}

QString Message::getTarget() const
{
    return _target;
}

QString Message::getCommand() const
{
    return _command;
}

QString Message::getRawLine() const
{
    return _raw_line;
}

QStringList Message::getArguments() const
{
    return _arguments;
}
