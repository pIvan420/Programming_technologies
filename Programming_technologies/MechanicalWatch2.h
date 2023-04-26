#pragma once
#include "Watch2.h"
using namespace WatchNameSpace;

class MechanicalWatch2 : public Watch2
{
private:
	string mechanism_type;
public:
	MechanicalWatch2(string name, int price, string country, string mechanism_type);
	~MechanicalWatch2();
	string get_mechanism_type();
};

