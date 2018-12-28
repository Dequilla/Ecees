#pragma once

#include "../Entity.h"
#include "System.h"

class EntitySystem : public System
{
public:
	virtual void start() override;
	virtual void stop() override;

	virtual void beginTick() override;
	virtual void endTick() override;

	virtual void update() override;
	virtual void draw() override;

	Entity* registerEntity(Entity* entity);

protected:
	std::vector<Entity*> m_entities;
};