#pragma once

#include <QApplication>
#include <QWidget>
#include <QUiLoader>
#include <QFile>
#include <QWidget>
#include <QObject>
#include <QString>
#include <QLabel>
#include <QFileDialog>

#include "IImageView.h"

class ImageView: public QObject, public IImageView {
    Q_OBJECT
    public:
        ImageView();
        void displayImage(unsigned char* data, int width, int height, int channels) override;
        void show() override;
        void setOnOpenFileCallback(std::function<void(const std::string&)>) override; 

    private:
        void loadUi();
        QWidget* m_window;
        QAction* m_openFileAction;
        QLabel* m_imageLabel;
          
    private slots:
        void onOpenFileTriggered();
    
};