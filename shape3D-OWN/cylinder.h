#pragma once
#include "Shape3D.h"


class Cylinder : public Shape3D {
private:
	float radius;
	string orientering;
public: 
	Cylinder();
	Cylinder(float radius, const string& orientering);

	Cylinder(float height, float radius, const string& orientering);

	float getRadius() const;
	string getOrientering() const;
	void setRadius(float radius);
	void setOrientering(const string& orientering);

	string toString() const override;
	float baseArea() const override;
	float volume() const override;
	Cylinder* clone() const override;

	virtual ~Cylinder();
};