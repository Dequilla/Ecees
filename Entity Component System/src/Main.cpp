#include <iostream>

#include "Systems/EntitySystem.h"
#include "Systems/PositionsSystem.h"
#include "Systems/SystemsHandler.h"

int main(int argc, char** argv)
{
	SystemsHandler systems;

	systems.registerSystem(new PositionSystem());
	PositionSystem* ps = systems.getSystems<PositionSystem>()[0];

	systems.registerSystem(new EntitySystem());
	EntitySystem* es = systems.getSystems<EntitySystem>()[0];
	
	Entity* e = es->registerEntity(new Entity());

	e->pushComponent(ps->registerComponent(new PositionComponent(3.f, 3.616f)));
	e->getComponents<PositionComponent>(false)[0]->pushChild(ps->registerComponent(new PositionComponent(3.f, 3.616f)));
	e->getComponents<PositionComponent>(true)[1]->pushChild(ps->registerComponent(new PositionComponent(3.f, 3.616f)));

	e->getComponents<PositionComponent>(false);
	e->getComponents<PositionComponent>(true);


	systems.start();
	for (int x = 0; x < 3; x++)
	{
		systems.beginTick();
		systems.update();
		std::cin.get();
		systems.draw();
		systems.endTick();

		auto comps = e->getComponents<PositionComponent>(false);
		for (auto &comp : comps)
		{
			comp->setX(comp->getX() + 1337);
			comp->setY(comp->getY() - 1337);
		}
	}
	systems.stop();

	std::cin.get();
	return 0;
}