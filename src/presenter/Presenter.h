#pragma once
#include "view/IImageView.h"
#include "model/ImageModel.h"
#include <memory>

class Presenter{

    public:
        Presenter() = delete;
        Presenter(IImageView& view, ImageModel& model);
        void initialize();
    
    private:
        void loadImage(const std::string& file);
        IImageView* m_view;
        ImageModel* m_model;

};