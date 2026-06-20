#ifndef TEST_PROXYTABLEMODEL_H
#define TEST_PROXYTABLEMODEL_H

#include <QSortFilterProxyModel>

class ProxyTableModel : public QSortFilterProxyModel {
    Q_OBJECT
    double minValue;
public:
    explicit ProxyTableModel(double minValue, QObject* parent = nullptr)
        : QSortFilterProxyModel(parent), minValue(minValue) {}
protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override {
        auto value = sourceModel()->index(sourceRow, 1, sourceParent).data().toDouble();
        return value >= minValue;
    }
};

#endif // TEST_PROXYTABLEMODEL_H
