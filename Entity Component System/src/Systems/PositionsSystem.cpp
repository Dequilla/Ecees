#include "PositionsSystem.h"

#include <iostream>

void PositionSystem::start()
{
	std::cout << "The position system began with: " << std::endl;
	for (auto &ptr : m_components)
	{
		std::cout << "Pos: " << ptr->getX() << ", " << ptr->getY() << std::endl;
	}
}

void PositionSystem::stop()
{
	std::cout << "The position system stopped with: " << std::endl;
	for (auto &ptr : m_components)
	{
		std::cout << "Pos: " << ptr->getX() << ", " << ptr->getY() << std::endl;
	}
}

PositionComponent* PositionSystem::registerComponent(PositionComponent * component)
{
	m_components.push_back(component);
	return component;
}

