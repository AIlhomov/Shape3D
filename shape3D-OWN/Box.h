#pragma once

#include "Shape3D.h"

class Box : public Shape3D{
private:
	float length;
	float width;
public:
	Box();
	Box(float length, float width);

	Box(float height, float length, float width);

	float getLength() const;
	float getWidth() const;
	void setLength(float length);
	void setWidth(float width);


	float baseArea() const override;
	float volume() const override;
	string toString() const override;
	Box* clone() const override;

	bool operator==(const Box& other); //extra?

	virtual ~Box();
};