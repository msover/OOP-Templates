#include "TableModel.h"

#include <qsize.h>

TableModel::TableModel(Service& service, QObject* parent)
    : QAbstractTableModel{parent}, service{service} {}

int TableModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) return 0;
    return static_cast<int>(service.getAll().size());
}

int TableModel::columnCount(const QModelIndex& parent) const {
    if (parent.isValid()) return 0;
    return 1;
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
            return QString::fromStdString(item.toString());
    }
    return {};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) return {};
    return "Data";
}

void TableModel::update() {
    beginResetModel();
    endResetModel();
}
