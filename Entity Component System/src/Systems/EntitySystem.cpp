#include "EntitySystem.h"

EntitySystem::~EntitySystem()
{
	System::~System();

	for (auto &entity : m_entities)
	{
		delete entity;
		entity = nullptr;
	}
}

void EntitySystem::start()
{
}

void EntitySystem::stop()
{
}

void EntitySystem::beginTick()
{
}

void EntitySystem::endTick()
{
}

void EntitySystem::update()
{
}

void EntitySystem::draw()
{
}

Entity* EntitySystem::registerEntity(Entity* entity)
{
	m_entities.push_back(entity);
	return entity;
}
