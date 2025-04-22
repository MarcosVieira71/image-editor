#pragma once
#include "view/IImageView.h"
#include <memory>

class ImageModel;

class Presenter{

    public:
        Presenter() = delete;
        Presenter(IImageView& view, ImageModel* model);
        void initialize();
    
    private:
        void mock(const std::string& file);
        IImageView* m_view;
        ImageModel* m_model;

};