#include "SystemsHandler.h"

void SystemsHandler::registerSystem(System * system)
{
	m_systems.push_back(system);
}

void SystemsHandler::start()
{
	for (auto &ptr : m_systems)
	{
		ptr->start();
	}
}

void SystemsHandler::stop()
{
	for (auto &ptr : m_systems)
	{
		ptr->stop();
	}
}

void SystemsHandler::beginTick()
{
	for (auto &ptr : m_systems)
	{
		ptr->beginTick();
	}
}

void SystemsHandler::endTick()
{
	for (auto &ptr : m_systems)
	{
		ptr->endTick();
	}
}

void SystemsHandler::update()
{
	for (auto &ptr : m_systems)
	{
		ptr->update();
	}
}

void SystemsHandler::draw()
{
	for (auto &ptr : m_systems)
	{
		ptr->draw();
	}
}
