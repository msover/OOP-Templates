#include "Service.h"

Service::Service(Repo& repo) : repo{repo} {}

void Service::add(const std::string& name, double value) {
    repo.add(Item{name, value});
}

const std::vector<Item>& Service::getAll() const {
    return repo.getAll();
}
