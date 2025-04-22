#pragma once

#include <QApplication>
#include <QWidget>
#include <QUiLoader>
#include <QFile>
#include <QWidget>

class ImageView{

    public:
        ImageView();
        void show();

    private:
        void loadUi();
        
        QWidget* m_window;
        

};