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
#include <QRadioButton>

#include "IImageView.h"

class ImageView: public QObject, public IImageView {
    Q_OBJECT
    public:
        ImageView();
        void displayImage(const unsigned char* data, int width, int height, int channels) override;
        void show() override;
        void setOnOpenFileCallback(std::function<void(const std::string&)>) override; 
        void setNegativeButtonCallback(std::function<void(bool)>) override; 


    private:
        void loadUi();
        QWidget* m_window;
        QAction* m_openFileAction;
        QLabel* m_imageLabel;
        QRadioButton* m_negativeRadioButton;
          
    private slots:
        void onOpenFileTriggered();
        void onRadioButtonToggled(bool checked);
    
};