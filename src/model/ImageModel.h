#pragma once

#include "stb_image.h"
#include <memory>
#include <string>

struct ImageDeleter{
    void operator()(unsigned char* ptr) const{
        stbi_image_free(ptr);
    }
};

class ImageModel{
    public:
        ImageModel();
        void loadImage(const std::string& filepath);
        int getWidth() const;
        int getChannels() const;
        int getHeight() const;
        const unsigned char* getData() const;

    private:
        std::unique_ptr<unsigned char, ImageDeleter> data;
        int m_width, m_height, m_channels;
};

