#pragma once

#include <QApplication>
#include <QWidget>
#include <QUiLoader>
#include <QFile>
#include <QWidget>
#include <QObject>
#include <QString>
#include <QFileDialog>

#include "IImageView.h"

class ImageView: public QObject, public IImageView {
    Q_OBJECT
    public:
        ImageView();
        void show() override;
        void setOnOpenFileCallback(std::function<void(const std::string&)>) override; 

    private:
        void loadUi();
        QWidget* m_window;
          
    private slots:
        void onOpenFileTriggered();
    
};