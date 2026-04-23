#pragma once
#pragma once
#include <iostream>
#include <vector>
#include "TSubstance.h"

class TCup
{

	std::vector<TSubstance> substances;
	std::vector<double> volumes;

public:
	TCup(int volume) {
		this->volume = volume;
	}

	void add(TSubstance substance, double volume_in_ml);
	void add(std::string name, double volume_in_ml);
	void show();
	double return_coe_vol(std::string name);
	double return_coe_mass(std::string name);
	float howMuchToAdd_Mass(std::string name, float percent);
	float howMuchToAdd_Volume(std::string name, float percent);
	static void AddToMass(TCup& cup, std::string name, float mass);
	static void AddToVolume(TCup& cup, std::string name, float volume);
	float getSingleVolume(std::string name);
	static void transferLiquid(TCup& from, TCup& to, float volume);
	int get_volume();
	std::string info(int _id);

	std::vector<TSubstance> get_cup_substances() {
		return substances;
	}

	std::vector<double> get_cup_volumes() {
		return volumes;
	}
	int get_substance_id(std::string name);
	
private:

	void print_coe_vol();
	void print_coe_mass();
	float getAbsoluteMass();
	float getSingleMass(std::string name);
	float getAbsoluteVolume();
	int getIndex(std::string name);
	int checkIfValidIndex(int k);
	void showTransferInfo(TCup from, TCup to, float volume);
	double roundSmallToZero(double value, double threshold);
	int volume;

};

extern std::vector<TCup*> cups_pnt;


