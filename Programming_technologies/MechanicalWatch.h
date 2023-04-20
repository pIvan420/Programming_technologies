#pragma once
#include "Watch.h"
class MechanicalWatch : public Watch
{
private:
	string mechanism_type;
public:
	MechanicalWatch(string name, int price, string country, string mechanism_type);
	~MechanicalWatch();
	string get_mechanism_type();
};