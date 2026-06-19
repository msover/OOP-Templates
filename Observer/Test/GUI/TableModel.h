#ifndef TEST_TABLEMODEL_H
#define TEST_TABLEMODEL_H

#include <QAbstractTableModel>
#include "../observer/Observer.h"
#include "../service/Service.h"

// Instantiate one TableModel per MainWindow, passing the shared Service.
class TableModel : public QAbstractTableModel, public Observer {
    Q_OBJECT
    Service& service;
public:
    explicit TableModel(Service& service, QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void update() override;
    Item itemAt(int row) const;
};

#endif //TEST_TABLEMODEL_H
