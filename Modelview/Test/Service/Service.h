#ifndef TEST_SERVICE_H
#define TEST_SERVICE_H

#include <string>
#include <vector>
#include "../Repo/Repo.h"
#include "../Domain/Item.h"

class Service {
public:
    explicit Service(Repo& repo);

    void add(const std::string& name, double value);
    const std::vector<Item>& getAll() const;

private:
    Repo& repo;
};

#endif // TEST_SERVICE_H
