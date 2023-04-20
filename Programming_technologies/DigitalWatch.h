#pragma once
#include "Watch.h"
#include "MechanicalWatch.h"

class DigitalWatch : public Watch
{
private:
	bool pedometer;
public:
	DigitalWatch(string name, int price, string country, bool pedometer);
	~DigitalWatch();
	bool is_pedometer();
};