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

    MainWindow w1{service, model};
    MainWindow w2{service, model};
    w1.setWindowTitle("Observer Window 1");
    w2.setWindowTitle("Observer Window 2");
    w1.show();
    w2.show();

    return app.exec();
}
