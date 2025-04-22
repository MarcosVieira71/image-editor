#pragma once

#include <functional>
#include <string>

class IImageView {
    public:
        virtual void setOnOpenFileCallback(std::function<void(const std::string&)>) = 0;
        virtual void show() = 0;
        virtual ~IImageView() = default;
       
        protected:
            std::function<void(const std::string&)> m_openFileCallback;

};

