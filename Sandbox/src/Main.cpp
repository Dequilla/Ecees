#include <iostream>

#include "Ecees/Ecees.h"
#include "Ecees/Systems/PositionsSystem.h"

#include <SFML/Graphics.hpp>

// TODO: To components add an id so we can identify each component
//			Use memory address or is that a bad idea?
//		 We need this to remove a certain child or parentand to keep track etc

// Game object handling (entities) -> Have factories?
// With swap and pop you only have to update the id of one object if you use its vector index as an ID
// https://gamedev.stackexchange.com/questions/33888/what-is-the-most-efficient-container-to-store-dynamic-game-objects-in

int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Ecees sandbox");

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

	bool run = true;
	systems.start();
	while (run)
	{
		systems.beginTick();

		sf::Event input;
		while (window.pollEvent(input))
		{
			if (input.type == sf::Event::Closed)
				run = false;
		}

		systems.update();
		systems.draw();
		systems.endTick();
	}
	systems.stop();

	return 0;
}