#ifndef TEST_TABLEMODEL_H
#define TEST_TABLEMODEL_H

#include <QAbstractTableModel>
#include "../Service/Service.h"

class TableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    explicit TableModel(Service& service, QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void update();

private:
    Service& service;
};

#endif // TEST_TABLEMODEL_H
