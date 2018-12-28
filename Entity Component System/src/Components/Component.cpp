#include "Component.h"

void Component::pushChild(Component * child)
{
	m_children.push_back(child);
}

void Component::setParent(Component * parent)
{
	m_parent = parent;
}

Component * Component::getParent()
{
	return m_parent;
}

std::vector<Component*> Component::getAllChildren()
{
	return m_children;
}
