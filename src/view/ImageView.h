#include <QApplication>
#include <QWidget>
#include <QUiLoader>
#include <QFile>

class ImageView{

    public:
        ImageView(){

            QFile file("ui/MainWindowImage.ui");

            QUiLoader loader;
            QWidget *window = loader.load(&file);

            file.close();
        }

    private:

};