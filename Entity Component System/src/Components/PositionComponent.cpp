#include "PositionComponent.h"

void PositionComponent::setX(double x)
{
	m_x = x;
}

void PositionComponent::setY(double y)
{
	m_y = y;
}

void PositionComponent::set(double x, double y)
{
	m_x = x;
	m_y = y;
}

double PositionComponent::getX() const
{
	return m_x;
}

double PositionComponent::getY() const
{
	return m_y;
}
