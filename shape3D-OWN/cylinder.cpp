#include "cylinder.h"

#define PI 3.141592

Cylinder::Cylinder()
	: radius(0.f), orientering("Vertical")
{
}

Cylinder::Cylinder(float radius, const string& orientering)
	: radius(radius)
{
	if (orientering == "Vertical" || orientering == "Horizontal") {
		this->orientering = orientering;
	}
}

Cylinder::Cylinder(float height, float radius, const string& orientering)
{
}

float Cylinder::getRadius() const
{
	return this->radius;
}

string Cylinder::getOrientering() const
{
	return this->orientering;
}

void Cylinder::setRadius(float radius)
{
	this->radius = radius;
}

void Cylinder::setOrientering(const string& orientering)
{
	if (orientering == "Vertical" || orientering == "Horizontal") {
		this->orientering = orientering;
	}
}

string Cylinder::toString() const
{
	return Shape3D::toString() + "\nRadius: " + to_string(this->radius) + "\nOrientering: " + this->orientering + "\nArea: " + to_string(baseArea()) + "\nVolume: " + to_string(volume());
}

float Cylinder::baseArea() const
{
	return 2 * PI * this->radius * (this->radius + Shape3D::getHeight());
}

float Cylinder::volume() const
{
	return PI * radius * radius * Shape3D::getHeight();
}

Cylinder* Cylinder::clone() const
{
	return new Cylinder(*this);
}

Cylinder::~Cylinder()
{
}
