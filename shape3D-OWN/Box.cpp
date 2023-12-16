#include "Box.h"

Box::Box()
	: length(0.f), width(0.f)
{
}

Box::Box(float length, float width)
	: length(length), width(width)
{
}

Box::Box(float height, float length, float width)
	: Shape3D(height), length(length), width(width)
{
}

float Box::getLength() const
{
	return this->length;
}

float Box::getWidth() const
{
	return this->width;
}

void Box::setLength(float length)
{
	this->length = length;
}

void Box::setWidth(float width)
{
	this->width = width;
}

float Box::baseArea() const
{
	return ((2 * length * width) + (2 * length * Shape3D::getHeight()) + (2 * width * Shape3D::getHeight()));
}

float Box::volume() const
{
	return (length * width * Shape3D::getHeight());
}

string Box::toString() const
{
	return Shape3D::toString() + "\nLength: " + to_string(this->length) + "\nWidth: " + to_string(this->width) + "\nArea: " + to_string(baseArea()) + "\nVolume:" + to_string(volume());
}

Box* Box::clone() const
{
	return new Box(*this);
}

Box::~Box()
{
}
