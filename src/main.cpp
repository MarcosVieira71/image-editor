#include <QApplication>
#include <QWidget>
#include <QUiLoader>
#include <QFile>
#include <QPushButton>
#include <QOpenGLWidget>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFile file("../ui/MainWindowImage.ui");


    QUiLoader loader;
    QWidget *window = loader.load(&file);

    file.close();

    window->show();
    return app.exec();
}
