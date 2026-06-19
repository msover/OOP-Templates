#include <QApplication>
#include "GUI/MainWindow.h"
#include "repository/Repo.h"
#include "service/Service.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Repo repo;
    Service service{repo};

    MainWindow w1{service};
    MainWindow w2{service};
    MainWindow w3{service};
    w1.show();
    w2.show();
    w3.show();

    return app.exec();
}
