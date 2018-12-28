#include "Component.h"

Component::Component(Component * parent)
	: m_parent(parent)
{
}

Component::~Component()
{
	for (auto &child : m_children)
	{
		delete child;
		child = nullptr;
	}
}

void Component::pushChild(Component* child)
{
	child->setParent(this);
	m_children.push_back(child);
}

void Component::setParent(Component* parent)
{
	m_parent = parent;
}

Component* Component::getParent() const
{
	return m_parent;
}

std::vector<Component*> Component::getAllChildren() const
{
	return m_children;
}
