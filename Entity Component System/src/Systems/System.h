#pragma once
#include <vector>

class System
{
public:
	virtual void start() {};
	virtual void stop() {};

	virtual void beginTick() {};
	virtual void endTick() {};
	
	virtual void update() {};
	virtual void draw() {};

protected:

};