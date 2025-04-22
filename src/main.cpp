#include <QApplication>
#include <QWidget>
#include <QUiLoader>
#include <QFile>
#include <QPushButton>
#include <QOpenGLWidget>

#include <memory>
#include "presenter/Presenter.h"
#include "model/ImageModel.h"
#include "view/ImageView.h"

#include <iostream>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    auto view = ImageView();
    auto model = ImageModel();
    auto presenter = std::make_unique<Presenter>(view, &model);
    
    presenter->initialize();
    
    return app.exec();
}
