#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TableModel.h"
#include "../Service/Service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(Service& service, TableModel& model, QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    Service& service;
    TableModel& model;
};

#endif // MAINWINDOW_H
