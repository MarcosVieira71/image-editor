class ImageView;
class ImageModel;

class Presenter{

    Presenter() = delete;
    Presenter(ImageView* view, ImageModel* model);

    public:

    
    private:

        ImageView* view;
        ImageModel* model;

};