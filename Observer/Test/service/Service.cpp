#include "Service.h"

Service::Service(Repo& repo) : repo(repo) {}

void Service::addObserver(Observer* o) { repo.addObserver(o); }

void Service::add(const std::string& name, int value) {
    repo.add(Item{name, value});
}

const std::vector<Item>& Service::getAll() const {
    return repo.getAll();
}
