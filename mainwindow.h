#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "client.h"
#include "hostmask.h"

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
    void onReturnPressed();
    void onPrivmsgReceived(const Hostmask& hostmask, const QString& target, const QString& text);

private:
    void append(const QString& line);

    Ui::MainWindow *ui;
    Client *_client;
};

#endif // MAINWINDOW_H
