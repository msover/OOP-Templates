#include "TableModel.h"

TableModel::TableModel(Service& service, QObject* parent)
    : QAbstractTableModel{parent}, service{service} {}

int TableModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) return 0;
    return static_cast<int>(service.getAll().size());
}

int TableModel::columnCount(const QModelIndex& parent) const {
    if (parent.isValid()) return 0;
    return 2;
}

Qt::ItemFlags TableModel::flags(const QModelIndex& index) const {
    if (!index.isValid()) return Qt::NoItemFlags;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant TableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) return {};
    const auto& items = service.getAll();
    if (index.row() >= static_cast<int>(items.size())) return {};

    const auto& item = items[index.row()];

    if (role == Qt::DisplayRole) {
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

void TableModel::update() {
    beginResetModel();
    endResetModel();
}
