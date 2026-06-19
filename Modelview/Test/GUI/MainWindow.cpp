#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(Service& service, TableModel& model, QWidget* parent)
    : QMainWindow{parent}, ui{new Ui::MainWindow}, service{service}, model{model}
{
    ui->setupUi(this);
    ui->tableView->setModel(&model);
    connect(ui->addButton, &QPushButton::clicked, this, [this]() {
        auto name = ui->nameEdit->text().trimmed().toStdString();
        auto value = ui->valueEdit->text().toDouble();
        if (name.empty()) return;
        this->service.add(name, value);
        this->model.update();
        ui->nameEdit->clear();
        ui->valueEdit->clear();
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

