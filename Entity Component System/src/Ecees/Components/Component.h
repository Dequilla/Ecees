#pragma once

#include <vector>
#include <deque>

#include "../Misc.h"
#include "../IdFactory.h"

#define REGISTER_COMPONENT_TYPE(typeName) \
virtual const char* getTypeName() const override { return #typeName; }

class ECEES_API Component {
public:
	virtual const char* getTypeName() const = 0;

	Component(Component* parent = nullptr);
	virtual ~Component();

	virtual void pushChild(Component* child);
	virtual void setParent(Component* parent);

	virtual Component* detachChild(Identifier id);

	virtual Component* getParent() const;

	template<typename T>
	std::vector<T*> getChildren(bool isRecursive = false) const;
	std::vector<Component*> getAllChildren() const;

protected:
	std::vector<Component*> m_children;
	Component* m_parent = nullptr;

	Identifier m_identifier = -1;
	static IdFactory m_idFactory;
};

template<typename T>
inline std::vector<T*> Component::getChildren(bool isRecursive) const
{
	std::vector<T*> children;
	for (auto &child : m_children)
	{
		auto pChild = dynamic_cast<T*>(child);
		if (pChild != nullptr)
		{
			children.push_back(pChild);
		}
	}

	if (isRecursive)
	{
		for (auto &pChild : children)
		{
			Component* c = static_cast<Component*>(pChild);

			std::vector<T*> cChildren = c->getChildren<T>(isRecursive);

			for (auto &cChild : cChildren)
			{
				children.push_back(cChild);
			}
		}
	}

	return children;
}
