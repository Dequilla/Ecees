#pragma once

#include <Ecees/Ecees.h>
#include <SFML/Graphics.hpp>

class RectComponent : 
	public Component,
	public sf::Rect<double>
{
public:
	RectComponent(
		double top = 0.0,
		double left = 0.0,
		double width = 0.0,
		double height = 0.0)
	{
		this->top = top;
		this->left = left;
		this->width = width;
		this->height = height;
	}

protected:

};