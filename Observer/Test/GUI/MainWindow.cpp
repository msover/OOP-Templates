#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(Service& service, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , service(service)
    , tableModel(new TableModel(service, this))
{
    ui->setupUi(this);
    ui->tableView->setModel(tableModel);

    service.addObserver(tableModel);
    service.addObserver(this);

    connect(ui->addButton, &QPushButton::clicked, this, [this]() {
        auto name = this->ui->nameLineEdit->text().toStdString();
        int value = this->ui->valueLineEdit->text().toInt();
        if (!name.empty())
            this->service.add(name, value);
    });

}

void MainWindow::update() {
    // called when the repo changes — refresh any UI state that depends on data
    // e.g. update labels, enable/disable buttons, etc.
}

MainWindow::~MainWindow() {
    delete ui;
}
