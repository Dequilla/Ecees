#include "Entity.h"

Entity::~Entity()
{
	for (auto &ptr : m_components)
	{
		delete ptr;
	}
}

void Entity::pushComponent(Component* component)
{
	m_components.push_back(component);
}
