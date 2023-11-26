#include "objects.h"
#include "motions.h"

int main(int argc, char* argv[]) {
	Entity entity(56.6);
	entity.setVelocity(3.4);
	entity.setAcceleration(4.03);

	RectilinearMotion motion(entity, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED, NOT_SPECIFIED);
	motion.moveForward(23.6, NOT_SPECIFIED);
	motion.moveForward(5, NOT_SPECIFIED);
	
	std::cout << "Space travelled is: " << motion.getTravelledSpace() << " m.\n";

	system("pause");
	return 0;
}