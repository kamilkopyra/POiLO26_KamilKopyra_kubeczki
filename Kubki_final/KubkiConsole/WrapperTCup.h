#pragma once 
#include "TCup.h" 

class WrapperTCup
{
	TCup* cup = new TCup(200);

public:
	~WrapperTCup();

	void add(TSubstance substance, double volume_in_ml);
	void add(std::string name, double volume_in_ml);
	void show();
};
