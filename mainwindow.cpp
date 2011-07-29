#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "nicknameinusemessagehandler.h"
#include "pingmessagehandler.h"
#include "privmsgmessagehandler.h"
#include "endofmotdmessagehandler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->commandInput, SIGNAL(returnPressed()), SLOT(onReturnPressed()));

    _client = new Client(this);

    connect(_client, SIGNAL(PrivmsgReceived(Hostmask,QString,QString)), SLOT(onPrivmsgReceived(Hostmask,QString,QString)));

    _client->setNickname("ahf_");
    _client->setUsername("ahf");
    _client->setRealname(QString::fromUtf8("Alexander Færøy"));

    _client->setServerHostname("irc.inet.tele.dk");
    _client->setServerPort(6667);

    _client->registerMessageHandler("PING", new PingMessageHandler);
    _client->registerMessageHandler("PRIVMSG", new PrivmsgMessageHandler);
    _client->registerMessageHandler("376", new EndOfMOTDMessageHandler);

    _client->connectToServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::append(const QString &line)
{
    ui->chatView->append(line);
}

void MainWindow::onReturnPressed()
{
    QString input;

    input = ui->commandInput->text();

    if (input.isEmpty())
        return;

    if (input.at(0) == '/')
    {
        QString command = input.mid(1);
        _client->sendRaw(command);
    }
    else
    {
        _client->sendPrivmsg("#TheCamp", input);

        QString format;
        format = "<font style='color: blue'>" + _client->getNickname() + "</font> " + input;
        append(format);
    }

    ui->commandInput->clear();
}

void MainWindow::onPrivmsgReceived(const Hostmask &hostmask, const QString &target, const QString &text)
{
    QString format;

    format = "<" + hostmask.getNickname() + "> " + text;

    append(format);
}
