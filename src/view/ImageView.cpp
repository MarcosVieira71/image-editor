#include "ImageView.h"
#include <QAction>
#include <iostream>

ImageView::ImageView(){
    loadUi();
    QAction* openFileAction = m_window->findChild<QAction*>("openFileAction");
    QObject::connect(openFileAction, &QAction::triggered, this, &ImageView::onOpenFileTriggered);
}

void ImageView::loadUi(){
    QFile file("../ui/MainWindowImage.ui");
    
    QUiLoader loader; 
    m_window = loader.load(&file);

    file.close();
}

void ImageView::onOpenFileTriggered() {
    QString fileName = QFileDialog::getOpenFileName(
        nullptr,                        
        "Abrir imagem",                
        "",                        
        "Imagens (*.png *.jpg *.jpeg *.bmp *.tiff *.gif);;Todos os arquivos (*)"
    );

    if (!fileName.isEmpty() && m_openFileCallback ) {
        m_openFileCallback(fileName.toStdString());
    } 
}

void ImageView::setOnOpenFileCallback(std::function<void(const std::string&)> callback){
    m_openFileCallback = std::move(callback);
}


void ImageView::show() {
    m_window->show();
}