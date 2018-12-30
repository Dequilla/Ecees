#pragma once

#include "../Entity/Entity.h"
#include "../Misc.h"

#include "System.h"

class ECEES_API EntitySystem : public System
{
public:
	virtual ~EntitySystem() override;

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