#include "Presenter.h"
#include <iostream>

Presenter::Presenter(ImageView* view, ImageModel* model) : m_view(view){

}

void Presenter::initialize(){
    m_view->show();
}