#pragma once

#include <vector>

#include "System.h"

class SystemsHandler
{
public:
	void registerSystem(System* system);
	
	template<typename T>
	std::vector<T*> getSystems();

	void start();
	void stop();

	void beginTick();
	void endTick();

	void update();
	void draw();

protected:
	std::vector<System*> m_systems;
};

template<typename T>
inline std::vector<T*> SystemsHandler::getSystems()
{
	std::vector<T*> systems;

	for (auto &sys : m_systems)
	{
		T* pSys = dynamic_cast<T*>(sys);
		if(pSys != nullptr)
		{
			systems.push_back(pSys);
		}
	}

	return systems;
}
