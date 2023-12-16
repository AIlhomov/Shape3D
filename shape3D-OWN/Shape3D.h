#ifndef SHAPE3D_H
#define SHAPE3D_H

#include <iostream>
#include <string>

using namespace std;

class Shape3D
{
public:
	Shape3D();
	virtual ~Shape3D();
	
	//Constructor for -> cylinder -> Shape3DHandler
	Shape3D(float height);

	float getHeight() const;

	virtual float baseArea() const = 0;
	virtual float volume() const = 0;
	virtual string toString() const = 0;
	virtual Shape3D* clone() const = 0;

private:
	float height;
};







#endif
