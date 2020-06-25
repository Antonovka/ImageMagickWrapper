#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <Magick++.h>
#include <map>
#include <iostream>

class ImageProcessing
{
    std::map<std::string, Magick::Image> images;

public:
    ImageProcessing();

    std::string load(std::string name, std::string path);

    std::string write(std::string name, std::string path);

    std::string blur(std::string name, std::string to_name, std::string radius, std::string sigma = "0.5");

    std::string zoom(std::string name, std::string to_name, std::string newWidth, std::string newHeight);

};

#endif // IMAGEPROCESSING_H
