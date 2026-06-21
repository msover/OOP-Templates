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
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    service.addObserver(tableModel);
    service.addObserver(this);

    connect(ui->addButton, &QPushButton::clicked, this, [this]() {
        // auto selectedList = this->ui->tableView->selectionModel()->selectedRows();
        //if (selectedList.empty()) { return; }
        // auto row = selectedList.front().row();
        auto name = this->ui->nameLineEdit->text().toStdString();
        int value = this->ui->valueLineEdit->text().toInt();
        this->ui->nameLineEdit->clear();
        this->ui->valueLineEdit->clear();
        if (!name.empty())
            this->service.add(name, value);
    });

}

void MainWindow::update() {
}

MainWindow::~MainWindow() {
    delete ui;
}
