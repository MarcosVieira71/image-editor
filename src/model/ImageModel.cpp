#define STB_IMAGE_IMPLEMENTATION
#include "ImageModel.h"
#include <iostream>

ImageModel::ImageModel(){

}

int ImageModel::getChannels() const{
    return m_channels;
}

int ImageModel::getWidth() const{
    return m_width;
}

int ImageModel::getHeight() const{
    return m_height;
}

const unsigned char* ImageModel::getData() const{
    return data.get();
}

void ImageModel::loadImage(const std::string& filepath){

    auto rawData = stbi_load(filepath.c_str(), &m_width, &m_height, &m_channels, 0);
    data.reset(rawData);

}