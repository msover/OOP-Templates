#ifndef TEST_SERVICE_H
#define TEST_SERVICE_H

#include "../repository/Repo.h"

class Service {
    Repo& repo;
public:
    explicit Service(Repo& repo);
    void addObserver(Observer* o);
    void add(const std::string& name, int value);
    const std::vector<Item>& getAll() const;
};

#endif //TEST_SERVICE_H
