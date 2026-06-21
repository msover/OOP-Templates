#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(Service& service, double minValue, TableModel& model, QWidget* parent)
    : QMainWindow{parent}, ui{new Ui::MainWindow}, service{service}, model{model}, proxyModel{minValue, this}
{
    ui->setupUi(this);
    proxyModel.setSourceModel(&model);
    ui->tableView->setModel(&proxyModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
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
