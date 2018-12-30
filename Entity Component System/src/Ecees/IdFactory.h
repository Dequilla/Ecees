#pragma once

#include <deque>

#include "Misc.h"

typedef unsigned long long Identifier;

class ECEES_API IdFactory
{
public:
	Identifier getUnique();
	void freeIdentifier(Identifier id);

protected:
	Identifier m_currentIdentifier = 0;
	std::deque<Identifier> m_freeIdentifiers;
};