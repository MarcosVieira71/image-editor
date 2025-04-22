#include "Presenter.h"
#include <iostream>

Presenter::Presenter(IImageView& view, ImageModel* model): m_view(&view){
    
    m_view->setOnOpenFileCallback([this](const std::string& file){
        this->mock(file);
    });
}

void Presenter::initialize(){
    m_view->show();
}

void Presenter::mock(const std::string& file){
    std::cout << file << std::endl;
}