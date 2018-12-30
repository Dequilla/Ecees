#pragma once
#include <vector>

#include "../Misc.h"

class ECEES_API System
{
public:
	virtual ~System() {};

	virtual void start() {};
	virtual void stop() {};

	virtual void beginTick() {};
	virtual void endTick() {};
	
	virtual void update() {};
	virtual void draw() {};

protected:

};