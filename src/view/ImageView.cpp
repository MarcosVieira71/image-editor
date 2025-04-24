#include "ImageView.h"
#include <QAction>
#include <iostream>

ImageView::ImageView(){
    loadUi();
    m_imageLabel = m_window->findChild<QLabel*>("ImageLabel");
    m_negativeRadioButton = m_window->findChild<QRadioButton*>("negativeRadio");
    m_openFileAction = m_window->findChild<QAction*>("openFileAction");
    QObject::connect(m_openFileAction, &QAction::triggered, this, &ImageView::onOpenFileTriggered);
    QObject::connect(m_negativeRadioButton, &QRadioButton::toggled, this, &ImageView::onRadioButtonToggled);


}


void ImageView::displayImage(const unsigned char* data, int width, int height, int channels){
    QImage::Format format;
    switch (channels) {
        case 1: format = QImage::Format_Grayscale8; break;
        case 3: format = QImage::Format_RGB888; break;
        case 4: format = QImage::Format_RGBA8888; break;
        default:
            std::cerr << "Número de canais não suportado: " << channels << std::endl;
            return;
    }

    QImage image(data, width, height, width * channels, format);
    m_imageLabel->setPixmap(QPixmap::fromImage(image));
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

void ImageView::onRadioButtonToggled(bool checked){
    if(checked){
        m_negativeButtonCallback(checked);
    }
}

void ImageView::setOnOpenFileCallback(std::function<void(const std::string&)> callback){
    m_openFileCallback = std::move(callback);
}

void ImageView::setNegativeButtonCallback(std::function<void(bool)> callback){
    m_negativeButtonCallback = std::move(callback);
}


void ImageView::show() {
    m_window->show();
}