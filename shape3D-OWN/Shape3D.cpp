#include "Shape3D.h"

Shape3D::Shape3D()
	: height(0)
{
}

Shape3D::~Shape3D()
{
}


Shape3D::Shape3D(float height)
	: height(height)
{
}

float Shape3D::getHeight() const
{
	return	this->height;
}

string Shape3D::toString() const
{
	return "\nHeight: " + to_string(this->height);
}
