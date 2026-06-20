#include <QApplication>
#include "Repo/Repo.h"
#include "Service/Service.h"
#include "GUI/MainWindow.h"
#include "GUI/TableModel.h"

int main(int argc, char* argv[]) {
    QApplication app{argc, argv};

    Repo repo;
    Service service{repo};
    TableModel model{service};

    MainWindow w1{service, 0.0, model};
    MainWindow w2{service, 50.0, model};
    w1.show();
    w2.show();

    return app.exec();
}
