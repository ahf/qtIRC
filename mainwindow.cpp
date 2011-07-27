#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "nicknameinusemessagehandler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _client = new Client(this);

    connect(_client, SIGNAL(ReceivedMessage(Message)), SLOT(ReceivedMessage(Message)));
    connect(_client, SIGNAL(NicknameChanged(QString,QString)), SLOT(NicknameChanged(QString, QString)));

    _client->setServerHostname("irc.0x90.dk");
    _client->setServerPort(6697);

    _client->setNickname("dongs");
    _client->setUsername("dings");
    _client->setRealname(QString::fromUtf8("Alexander Færøy"));

    _client->registerMessageHandler("433", new NicknameInUseMessageHandler);

    _client->connectToServer();
}

void MainWindow::NicknameChanged(const QString &oldNickname, const QString &newNickname)
{
    append(QString("Nickname Changed: %1 -> %2").arg(oldNickname).arg(newNickname));
}

void MainWindow::ReceivedMessage(const Message &message)
{
    QString prefix = message.getPrefix();
    QString command = message.getCommand();
    QString target = message.getTarget();
    QString arguments = message.getArguments().join(" ");

    if (prefix.isEmpty())
        append(QString("%1 %2 %3").arg(command).arg(target).arg(arguments));
    else
        append(QString("%1 %2 %3 %4").arg(prefix).arg(command).arg(target).arg(arguments));
}

void MainWindow::append(const QString& text)
{
    ui->textView->append(QString("<font style='color: red;'>%1</font>").arg(text));
}

MainWindow::~MainWindow()
{
    delete ui;
}
