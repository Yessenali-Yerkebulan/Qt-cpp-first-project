#include "Rectangle.h"

Rectangle::Rectangle() : Rectangle(1.0, 1.0)
{

}

Rectangle::Rectangle(double width, double length){
    this->width = width;
    this->length = length;
}

double Rectangle::getWidth() const{
    return width;
}

double Rectangle::getLength() const{
    return length;
}

void Rectangle::setWidth(double width){
    this->width = width;
}

void Rectangle::setLength(double length){
    this->length = length;
}

double Rectangle::area() const{
    return length*width;
}
