#include "Repo.h"

void Repo::add(const Item& item) {
    items.push_back(item);
    notifyAll();
}

const std::vector<Item>& Repo::getAll() const {
    return items;
}
