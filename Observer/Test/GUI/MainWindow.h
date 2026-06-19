#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../observer/Observer.h"
#include "../service/Service.h"
#include "TableModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer {
    Q_OBJECT
    Service& service;
    TableModel* tableModel;
public:
    explicit MainWindow(Service& service, QWidget* parent = nullptr);
    ~MainWindow() override;
    void update() override;
private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
