#include "Component.h"

Component::Component(Component* parent)
{
	this->setParent(parent);

	this->m_identifier = Component::m_idFactory.getUnique();
}

Component::~Component()
{
	for (auto &child : m_children)
	{
		delete child;
		child = nullptr;
	}

	Component::m_idFactory.freeIdentifier(m_identifier);
}

void Component::pushChild(Component* child)
{
	child->setParent(this);
}

void Component::setParent(Component* parent)
{
	if (parent != nullptr)
		parent->m_children.push_back(this);

	if (m_parent != nullptr)
		m_parent->detachChild(this->m_identifier);
	
	m_parent = parent;
}

Component* Component::detachChild(Identifier id)
{
	for (auto &child : m_children)
	{
		if (child->m_identifier == id)
			return child;
	}

	return nullptr;
}

Component* Component::getParent() const
{
	return m_parent;
}

std::vector<Component*> Component::getAllChildren() const
{
	return m_children;
}

IdFactory Component::m_idFactory;