#pragma once

#include <Ecees/Ecees.h>
#include <SFML/Graphics.hpp>

#include "RectComponent.h"

class PhysicsBody : 
	public Component
{
public:
	PhysicsBody(RectComponent* parent)
		: Component(parent)
	{
	}

	bool bIsStatic = false;
	bool bIsActive = false;
};