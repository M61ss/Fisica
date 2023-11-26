#include "objects.h"
#include "motions.h"

int main(int argc, char* argv[]) {
	Entity entity(56.6);
	entity.setVelocity(3.4);
	entity.setAcceleration(4.03);

	RectilinearMotion motion(entity, 0, 0, 0, 0);
	motion.moveForward(23.6, 0);
	motion.moveForward(5, 0);
	

	std::cout << "Space travelled is: " << motion.getTravelledSpace() << " m.\n";

	system("pause");
	return 0;
}