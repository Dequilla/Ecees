#pragma once

#include "../Components/PositionComponent.h"
#include "System.h"

class PositionSystem : public System
{
public:
	virtual void start() override;
	virtual void stop() override;

	PositionComponent* registerComponent(PositionComponent* component);

protected:
	std::vector<PositionComponent*> m_components;
};