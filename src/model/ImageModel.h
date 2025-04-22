#pragma once

#include "stb_image.h"
#include <string>

class ImageModel{
    public:
        ImageModel();
        void loadImage(const std::string& filepath);
        int getWidth() const;
        int getChannels() const;
        int getHeight() const;
        unsigned char* getData() const;

    private:
        unsigned char* data;
        int m_width, m_height, m_channels;
};

