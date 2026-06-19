#include "TableModel.h"

TableModel::TableModel(Service& service, QObject* parent)
    : QAbstractTableModel(parent), service(service) {}

int TableModel::rowCount(const QModelIndex&) const {
    return static_cast<int>(service.getAll().size());
}

int TableModel::columnCount(const QModelIndex&) const {
    return 2;
}

QVariant TableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) return {};
    if (role == Qt::DisplayRole) {
        const auto& item = service.getAll().at(index.row());
        switch (index.column()) {
            case 0: return QString::fromStdString(item.getName());
            case 1: return item.getValue();
        }
    }
    return {};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) return {};
    switch (section) {
        case 0: return "Name";
        case 1: return "Value";
    }
    return {};
}

Qt::ItemFlags TableModel::flags(const QModelIndex& index) const {
    if (!index.isValid()) return Qt::NoItemFlags;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void TableModel::update() {
    beginResetModel();
    endResetModel();
}

Item TableModel::itemAt(int row) const {
    return service.getAll().at(row);
}
