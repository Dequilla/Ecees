#pragma once

#include "Component.h"

class PositionComponent : public Component 
{
public:
	PositionComponent(double x, double y)
		: m_x(x), m_y(y) {}

	void setX(double x);
	void setY(double y);
	void set(double x, double y);

	double getX() const;
	double getY() const;

	REGISTER_COMPONENT_TYPE(PositionComponent);

protected:
	double m_x, m_y;
};