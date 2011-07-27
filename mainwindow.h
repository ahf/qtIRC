#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "client.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void NicknameChanged(const QString& oldNickname, const QString& newNickname);
    void ReceivedMessage(const Message& message);

private:
    void append(const QString& text);

    Ui::MainWindow *ui;
    Client *_client;
};

#endif // MAINWINDOW_H
