#pragma once

#include <vector>

#include "Components/Component.h"

class Entity {
public:
	virtual ~Entity();

	template<typename T>
	std::vector<T*> getComponents(bool isRecursive = false) const;

	void pushComponent(Component* component);

protected:
	std::vector<Component*> m_components;
};

template<typename T>
inline std::vector<T*> Entity::getComponents(bool isRecursive) const
{
	std::vector<T*> results;
	for (auto &pComp : m_components)
	{
		T* comp = dynamic_cast<T*>(pComp);
		if (comp != nullptr)
		{
			results.push_back(comp);
		}
	}

	if (isRecursive)
	{
		for (auto &comp : results)
		{
			Component* c = static_cast<Component*>(comp);

			std::vector<T*> cChildren = c->getChildren<T>(isRecursive);

			for (auto &cChildrenComp : cChildren)
			{
				results.push_back(cChildrenComp);
			}
		}
	}
	
	return results;
}
