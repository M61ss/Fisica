#include "objects.h"
#include "motions.h"
#include <locale.h>
#define LINE std::cout << "-------------------------------\n"

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "en-US");
	Entity entity(56.6);
	entity.setVelocity(5);
	entity.setAcceleration(0);

	// entity, time, travelled, radiant
	RectilinearMotion motion(entity, 0, 0, 60);
	motion.moveForward(3);
	motion.display();
	LINE;
	motion.refreshInclination(30);
	motion.moveForward(3);
	motion.display();
	LINE;
	motion.refreshInclination(150);
	motion.moveForward(3);
	motion.display();
	LINE;
	motion.refreshInclination(-30);
	motion.moveForward(3);
	motion.display();
	LINE;
	motion.refreshInclination(30);
	motion.moveForward(3);
	motion.display();
	LINE;

	//system("pause");
	return 0;
}