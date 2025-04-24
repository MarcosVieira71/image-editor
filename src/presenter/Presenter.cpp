#include "Presenter.h"
#include <iostream>

Presenter::Presenter(IImageView& view, ImageModel& model): m_view(&view), m_model(&model)
{
    m_view->setOnOpenFileCallback([this](const std::string& file){
        this->loadImage(file);
    });
    
    m_view->setNegativeButtonCallback([this](bool a){
        if(a){
            m_model->applyNegativeFilter();
            auto data = m_model->getData();
            auto height = m_model->getHeight();
            auto width = m_model->getWidth();
            auto channels = m_model->getChannels();
            m_view->displayImage(data, width, height, channels);
        }
    });
    // TO DO -> pesquisar uma forma melhor de fazer isso das callbacks
}

void Presenter::initialize(){
    m_view->show();
}

void Presenter::loadImage(const std::string& file){
    m_model->loadImage(file);
    
    auto data = m_model->getData();
    auto height = m_model->getHeight();
    auto width = m_model->getWidth();
    auto channels = m_model->getChannels();

    m_view->displayImage(data, width, height, channels);
    
}