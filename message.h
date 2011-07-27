#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QStringList>

class Message
{
public:
    static Message parse(const QString& l);

    QString getPrefix() const;
    QString getTarget() const;
    QString getCommand() const;
    QString getRawLine() const;
    QStringList getArguments() const;

protected:
    Message(const QString& prefix, const QString& target, const QString& command, const QString& raw, const QStringList& arguments);

private:
    QString _prefix;
    QString _target;
    QString _command;
    QString _raw_line;
    QStringList _arguments;

};

#endif // MESSAGE_H
