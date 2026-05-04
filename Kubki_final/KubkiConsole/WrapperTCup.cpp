#include "WrapperTCup.h" 
#include <iostream> 
#include <vector> 

using namespace std;


WrapperTCup::~WrapperTCup()
{
	delete cup;
	cup = nullptr;
}

void WrapperTCup::add(TSubstance substance, double volume_in_ml)
{
	cup->add(substance, volume_in_ml);
}

void WrapperTCup::add(std::string name, double volume_in_ml)
{
	cup->add(name, volume_in_ml);
}

void WrapperTCup::show()
{
	std::vector<TSubstance> substances = cup->get_cup_substances();
	std::vector<double> volumes = cup->get_cup_volumes();
	int count = substances.size();
	for (int i = 0; i < count; i++)
	{
		double mass = substances[i].get_ro() * volumes[i] * 1000;

		std::cout << substances[i].get_name()
			<< "; volume: " <<(volumes[i] * 1e6) << "ml"
			<< "; mass: " << (mass) << "g" << endl;
	}
	cup->print_coe_mass();
	cup->print_coe_vol();

	std::cout << "calkowita objetosc: " << cup->getAbsoluteVolume() << "\n";
	std::cout << "\n\n\n";

}
