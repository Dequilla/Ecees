#include "IdFactory.h"

Identifier IdFactory::getUnique()
{
	if (m_freeIdentifiers.size() > 0)
	{
		// Maybe faster with swap and pop using vector
		Identifier id = m_freeIdentifiers.back();
		m_freeIdentifiers.pop_back();
		return id;
	}
	else
	{
		return m_currentIdentifier++;
	}
}

void IdFactory::freeIdentifier(Identifier id)
{
	m_freeIdentifiers.push_back(id);
}
