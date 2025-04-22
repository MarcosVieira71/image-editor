#pragma once
#include "view/ImageView.h"

class ImageModel;

class Presenter{

    public:
        Presenter() = delete;
        Presenter(ImageView* view, ImageModel* model);
        void initialize();
    
    private:

        ImageView* m_view;
        ImageModel* m_model;

};