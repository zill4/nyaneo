#ifndef RECTANGLE_H
# define RECTANGLE_H

#include "globals.h"

class Rectange 
{
public:
    Rectange() {}

    Rectange(int x, int y, int width, int height) :
    _x(x),
    _y(y),
    _width(width),
    _height(height)
    {}
    private:
    int _x, _y, _width, _height;
}