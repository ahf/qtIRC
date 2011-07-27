#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "nicknameinusemessagehandler.h"
#include "pingmessagehandler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->commandInput, SIGNAL(returnPressed()), SLOT(onReturnPressed()));

    _client = new Client(this);

    _client->setNickname("ahf_");
    _client->setUsername("ahf");
    _client->setRealname(QString::fromUtf8("Alexander Færøy"));

    _client->setServerHostname("irc.inet.tele.dk");
    _client->setServerPort(6667);

    _client->registerMessageHandler("PING", new PingMessageHandler);

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
    _client->sendRaw(input);
    ui->commandInput->clear();
}
