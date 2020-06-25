#include "imageprocessing.h"

using namespace std;

ImageProcessing::ImageProcessing()
{
}

std::string ImageProcessing::load(std::string name, std::string path)
{
    try
    {
         Magick::Image newImage;
         newImage.read(path);

         images[name] = newImage;
    }
    catch (Magick::Exception& error)
    {
        cout << error.what() << endl;
        return error.what();
    }
    catch (...)
    {
        cout << "catch (...)" << endl;
        return "catch (...)";
    }

    return "";
}

string ImageProcessing::write(string name, string path)
{
    if (images.find(name) == images.end())
    {
        return "Wrong image name";
    }

    try
    {
         images[name].write(path);
    }
    catch (Magick::Exception& error)
    {
        return error.what();
    }

    return "";
}

string ImageProcessing::blur(string name, string to_name, string radius, string sigma)
{
    if (images.find(name) == images.end())
    {
        return "Wrong image name";
    }

    Magick::Image newImage = images[name];

    double _radius, _sigma;

    try
    {
         _radius = stod(radius);
    }
    catch (...)
    {
        return "Wrong radius";
    }

    try
    {
         _sigma = stod(sigma);
    }
    catch (...)
    {
        return "Wrong sigma";
    }

    newImage.blur(_radius, _sigma);

    images[to_name] = newImage;

    return "";
}

string ImageProcessing::zoom(string name, string to_name, string newWidth, string newHeight)
{
    if (images.find(name) == images.end())
    {
        return "Wrong image name";
    }

    Magick::Image newImage = images[name];

    uint32_t _newWidth, _newHeight;

    try
    {
         _newWidth = stoi(newWidth);
    }
    catch (...)
    {
        return "Wrong new width";
    }

    try
    {
         _newHeight = stoi(newHeight);
    }
    catch (...)
    {
        return "Wrong new height";
    }

    newImage.zoom(Magick::Geometry{_newWidth, _newHeight});


    images[to_name] = newImage;

    return "";
}
