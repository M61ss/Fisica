#include "objects.h"
#include "motions.h"
#include <locale.h>
#define LINE std::cout << "-------------------------------\n"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "en-US");
	Entity entity(56.6);
	entity.setVelocity(3);
	entity.setAcceleration(2);

	// entity, time, travelled, x_trav, y_trav, radiant
	RectilinearMotion motion(entity, 0, 0, 0, 0, 60);
	motion.moveForward(4);
	motion.display();
	LINE;
	motion.refreshInclination(30);
	motion.moveForward(5);
	motion.display();

	//system("pause");
	return 0;
}