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
	int status = cup->add(substance, volume_in_ml);
	string name = substance.get_name();
	this->print_add_status(name, status, volume_in_ml);
}

void WrapperTCup::add(std::string name, double volume_in_ml)
{
	int status = cup->add(name, volume_in_ml);
	this->print_add_status(name, status, volume_in_ml);
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

void WrapperTCup::print_add_status(string name, int status, double vol)
{
	switch (status)
	{
	case -1:
		cout << "Nieznana substancja: " << name << endl;
		break;
	case 1:
		cout << "Dodano nowa substancje do kubka \"" << name << "\"";
		cout << " w ilosci: " << vol << "ml.\n";
		break;
	case 2:
		cout << "Dolano \"" << name << "\" do kubka";
		cout << " w ilosci: " << vol << "ml.\n";
		break;
	default:
		cout << "Nieznany status funkcji add: " << status << endl;
		break;
	}
}
