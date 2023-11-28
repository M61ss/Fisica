#include "objects.h"
#include "motions.h"
#include <locale.h>

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "en-US");
	Entity entity(56.6);
	entity.setVelocity(3.4);
	entity.setAcceleration(4.03);

	// entity, time, travelled, x_trav, y_trav, radiant
	RectilinearMotion motion(entity, 0, 0, 0, 0, 60);
	motion.moveForward(23.6);
	motion.display();

	//system("pause");
	return 0;
}