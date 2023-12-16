#include "Shape3DHandler.h"


int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Shape3DHandler s;


	s.addBox(10.f, 20.f, 30.f);
	//s.addBox(10.f, 20.f, 30.f);
	//s.addBox(302, 321, 30);
	//s.addBox(62, 3452, 30);
	//s.addBox(754, 20, 30);
	//s.addBox(69, 1, 2);
	//s.removeBox(10.f, 20.f, 30.f);
	s.addCylinder(4.f, 5.f, "Vertical");

	s.removeBox(10.f, 20.f, 30.f);

	s.removeCylinder(4.f, 5.f, "Vertical");

	s.showEverything();
	cout << endl;
	//cout << endl << "All average heights: " << s.averageValueHeightAll() << endl;

	//cout << "Average Box height: " << s.averageValueHeightBox() << endl;

	//cout << s.nrOfBoxes() + s.nrOfCylinders();

	return 0;
}