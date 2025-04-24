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
    return m_data.get();
}

void ImageModel::loadImage(const std::string& filepath){

    auto rawData = stbi_load(filepath.c_str(), &m_width, &m_height, &m_channels, 0);
    m_data.reset(rawData);

}
unsigned char& ImageModel::pixel(int x, int y, int channel) {
    int index = (y * m_width + x) * m_channels + channel;
    return m_data.get()[index];
}

void ImageModel::applyNegativeFilter(){
    for(int x = 0; x < m_width; x++){
        for(int y = 0; y < m_height; y++){
            for(int c = 0; c < m_channels; c++){
                pixel(x, y, c) = 255 - pixel(x, y, c);
            }
        }
    }
}