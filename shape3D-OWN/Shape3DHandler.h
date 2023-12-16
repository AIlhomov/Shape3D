#ifndef SHAPE3DHANDLER_H
#define SHAPE3DHANDLER_H

#include "Cylinder.h"
#include "Box.h"

class Shape3DHandler {
private:
	static const int CAPACITY = 15;
	Shape3D *shapes[CAPACITY];
	int nrOfShapes;
public:
	Shape3DHandler();
	virtual ~Shape3DHandler();


	//Adders
	void addBox(float height, float length, float width);
	void addCylinder(float height, float radius, const string& orientering);
	//Removers
	bool removeBox(float height, float length, float width);
	bool removeCylinder(float height, float radius, const string& orientering);
	//Copy constructor
	Shape3DHandler(const Shape3DHandler& other);
	//assignment operator
	Shape3DHandler operator=(const Shape3DHandler& other);

	int nrOfBoxes() const;
	int nrOfCylinders() const;

	//Average value using only height
	float averageValueHeightAll() const;
	float averageValueHeightBox() const;
	float averageValueHeightCylinder() const;

	void showEverything();

	void deleteEverything();
};















#endif