#include "ImageView.h"
#include <QAction>
#include <iostream>

ImageView::ImageView(){
    loadUi();
    QAction* openFileAction = m_window->findChild<QAction*>("openFileAction");

}

void ImageView::loadUi(){
    QFile file("../ui/MainWindowImage.ui");
    
    QUiLoader loader; 
    m_window = loader.load(&file);

    file.close();
}


void ImageView::show() {
    m_window->show();
}