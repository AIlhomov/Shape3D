#include "Shape3DHandler.h"

Shape3DHandler::Shape3DHandler()
	: nrOfShapes(0)
{
	for (int i = 0; i < CAPACITY; i++) {
		shapes[i] = nullptr;
	}
	//shapes = new Shape3D[CAPACITY]{ nullptr };
}

Shape3DHandler::~Shape3DHandler()
{
	for (int i = 0; i < nrOfShapes; i++) {
		delete shapes[i];
		//shapes[i] = nullptr;
	}
	//delete[] shapes;
}

void Shape3DHandler::addBox(float height, float length, float width)
{
	this->shapes[nrOfShapes++] = new Box(height, length, width);
}

void Shape3DHandler::addCylinder(float height, float radius, const string& orientering)
{
	this->shapes[nrOfShapes++] = new Cylinder(height, radius, orientering);
}

bool Shape3DHandler::removeBox(float height, float length, float width)
{
	for (int i = 0; i < nrOfShapes; i++) {
		Box* b = dynamic_cast<Box*>(shapes[i]);
		if (b) {
			Box* temp = new Box(height, length, width);

			if (shapes[i] == temp) {
				delete shapes[i];

				shapes[i] = shapes[nrOfShapes];
				shapes[nrOfShapes] = nullptr;

				delete temp;
				return true;
			}

		}
	}
	

	return false;
}

bool Shape3DHandler::removeCylinder(float height, float radius, const string& orientering)
{
	for (int i = 0; i < nrOfShapes; i++) {
		Cylinder* cyl = dynamic_cast<Cylinder*>(shapes[i]);
		if (cyl) {
			Cylinder* temp = new Cylinder(height, radius, orientering);
			if (shapes[i] == temp) {
				delete shapes[i];
				shapes[i] = shapes[nrOfShapes];
				shapes[nrOfShapes] = nullptr;
				delete temp;
				return true;
			}
		}
	}

	return false;
}

Shape3DHandler::Shape3DHandler(const Shape3DHandler& other)
{
	if (this != &other) {
		deleteEverything();
		this->nrOfShapes = other.nrOfShapes;

		for (int i = 0; i < nrOfShapes; i++) {
			shapes[i] = other.shapes[i]->clone();
		}
	}
}

Shape3DHandler Shape3DHandler::operator=(const Shape3DHandler& other)
{
	if (this != &other) {
		deleteEverything();
		this->nrOfShapes = other.nrOfShapes;

		for (int i = 0; i < nrOfShapes; i++) {
			shapes[i] = other.shapes[i]->clone();
		}
	}

	return *this;
}

int Shape3DHandler::nrOfBoxes() const
{
	int counter = 0;

	for (int i = 0; i < nrOfShapes; i++) {
		Box* b = dynamic_cast<Box*>(shapes[i]);
		if (b) counter++;
	}

	return counter;
}

int Shape3DHandler::nrOfCylinders() const
{
	int counter = 0;
	for (int i = 0; i < nrOfShapes; i++) {
		Cylinder* c = dynamic_cast<Cylinder*>(shapes[i]);
		if (c) counter++;
	}
	return counter;
}

float Shape3DHandler::averageValueHeightAll() const
{
	float average = 0.f;
	for (int i = 0; i < nrOfShapes; i++) {
		average += shapes[i]->getHeight();
	}
	return average / nrOfShapes;
}

float Shape3DHandler::averageValueHeightBox() const
{
	float average = 0.f;
	int countBox = 0;
	for (int i = 0; i < nrOfShapes; i++){
		Box* b = dynamic_cast<Box*>(shapes[i]);
		if (b) {
			average += b->getHeight();
			countBox++;
		}
	}

	return average / countBox;
}

float Shape3DHandler::averageValueHeightCylinder() const
{
	float average = 0.f;
	int countCylinder = 0;

	for (int i = 0; i < nrOfShapes; i++) {
		Cylinder* c = dynamic_cast<Cylinder*>(shapes[i]);
		if (c) {
			average += c->getHeight();
			countCylinder++;
		}
	}
	return average / countCylinder;
}

void Shape3DHandler::showEverything()
{
	for (int i = 0; i < nrOfShapes; i++) {
		cout << shapes[i]->clone()->toString();
	}
}

void Shape3DHandler::deleteEverything()
{
	for (int i = 0; i < nrOfShapes; i++) {
		delete shapes[i];
	}
	delete[] shapes;
	this->nrOfShapes = 0;

}
