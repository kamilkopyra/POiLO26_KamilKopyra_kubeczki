#include "TCup.h"
#include <string>
using namespace std;

void TCup::add(TSubstance substance, double volume_in_ml)
{
	int flag = 1;


	float volume = getAbsoluteVolume() * 1000;
	//cout << volume << "\n";
	int max = get_volume();
	//cout << "max: " << max <<" \n";
	//cout << "volume: " <<  volume << " \n";
	//cout << "sum: " << volume_in_ml + volume << " \n";
	//cout << "in_ml: " << volume_in_ml  << " \n";

	if (volume_in_ml + volume < max) {
		for (int i = 0; i < substances.size(); i++)
		{
			string name_check = substances[i].get_name();
			string name = substance.get_name();

			if (name == name_check)
			{
				volumes[i] = volumes[i] + volume_in_ml / 1e6;
				flag = 0;
			}
		}


		if (flag == 1) {
			substances.push_back(substance);
			volumes.push_back(volume_in_ml / 1e6);
		}
	}
	else { cout << "W kubku nie ma wystarczajacej ilosci wolnego miejsca. Operacja anulowana...\n"; }

}
void TCup::add(std::string name, double volume_in_ml)
{
	int _id = get_substance_id(name);



	if (_id >= 0)
	{
		this->add(substance_menu[_id], volume_in_ml);
	}
}

int TCup::get_substance_id(string name)
{
	int count = substance_menu.size();
	int _id = -1;
	bool run = true;

	while (run)
	{
		_id += 1;
		string sub_name = substance_menu[_id].get_name();

		if (sub_name == name) run = false;

		if ((_id + 1 == count) && (run == true))
		{
			std::cout << "Nie znaleziono płynu o podanej nazwie: \" " << name << "\"!\n";
			run = false;
			_id = -1;

		}
	}
	return _id;
}

float TCup::getAbsoluteMass()
{
	int count = substances.size();
	double Mass = 0;
	for (int i = 0; i < count; i++)
	{
		Mass = Mass + (substances[i].get_ro() * volumes[i] * 1000);
	}

	return Mass;
}
float TCup::getAbsoluteVolume()
{
	int count = substances.size();
	double volume = 0;
	for (int i = 0; i < count; i++)
	{
		volume = volume + volumes[i] * 1000;
	}
	return volume;
}
int TCup::getIndex(string name)
{
	int found = 0;
	int k = 0;
	for (int i = 0; i < substances.size(); i++)
	{
		string name_check = substances[i].get_name();


		if (name == name_check)
		{
			k = i;
			found = 1;
			break;
		}

	}
	if (found == 0)
	{
		k = -1;
	}
	return k;
}
int TCup::checkIfValidIndex(int k)
{
	if (k == -1)
	{
		cout << "Substancja nie istnieje\n";
		return 0;
	}

	return 1;
}

float TCup::getSingleVolume(string name)
{
	int k = getIndex(name);
	int ch = checkIfValidIndex(k);

	if (ch == 1)
	{
		double single_volume = volumes[k] * 1000;
		return single_volume;
	}

	else return 0;
}
float TCup::getSingleMass(string name)
{
	int k = getIndex(name);
	int ch = checkIfValidIndex(k);
	if (ch == 1)
	{
		double single_mass = (substances[k].get_ro() * volumes[k] * 1000);
		return single_mass;
	}

	return 0;
}

void TCup::print_coe_mass()
{
	int count = substances.size();
	float Mass = getAbsoluteMass();

	cout << "\n Mass coe:";
	for (int i = 0; i < count; i++)
	{
		double single_mass = (substances[i].get_ro() * volumes[i] * 1000);
		double mass_coe = single_mass / Mass;
		cout << mass_coe * 100 << " - ";

	}

}
void TCup::print_coe_vol()
{
	int count = substances.size();
	double volume = getAbsoluteVolume();


	cout << "\n Volume coe:";
	for (int i = 0; i < count; i++)
	{
		double single_volume = volumes[i] * 1000;
		double volume_coe = single_volume / volume;
		cout << volume_coe * 100 << " - ";

	}

}

double TCup::return_coe_vol(string name)
{

	int k = getIndex(name);
	int ch = checkIfValidIndex(k);
	if (ch == 0) { return 0; }
	double volume_coe;
	double volume = getAbsoluteVolume();



	double single_volume = volumes[k] * 1000;
	volume_coe = single_volume / volume;

	std::cout << "volume_coe:" << volume_coe * 100 << "\n";
	return volume_coe * 100;

}
double TCup::return_coe_mass(string name)
{
	int k = getIndex(name);
	int ch = checkIfValidIndex(k);
	if (ch == 0) { return 0; }
	double mass_coe;
	double Mass = getAbsoluteMass();

	float single_mass = getSingleMass(name);
	mass_coe = single_mass / Mass;
	std::cout << name << ":mass coe: " << mass_coe * 100 << "\n";
	return mass_coe * 100;

}
void TCup::showTransferInfo(TCup from, TCup to, float volume)
{
}
double TCup::roundSmallToZero(double value, double threshold = 1e-4)
{
	return (abs(value) < threshold) ? 0.0 : value;
}

void TCup::show()
{
	int count = substances.size();
	for (int i = 0; i < count; i++)
	{
		double mass = substances[i].get_ro() * volumes[i] * 1000;

		std::cout << substances[i].get_name()
			<< "; volume: " << roundSmallToZero(volumes[i] * 1e6) << "ml"
			<< "; mass: " << roundSmallToZero(mass) << "g" << endl;
	}

	print_coe_vol();
	print_coe_mass();

	std::cout << "calkowita objetosc: " << roundSmallToZero(getAbsoluteVolume()) << "\n";
	std::cout << "\n\n\n";

}

float TCup::howMuchToAdd_Mass(string name, float percent)
{
	float Mass = getAbsoluteMass();
	int k = 0;
	float single_mass = getSingleMass(name);

	if (single_mass == 0)
	{
		return -1;
	}

	float add = 0;

	add = (single_mass - percent / 100 * Mass) / (percent / 100 - 1);

	cout << "Zeby uzyskac " << percent << "% " << name << " nalezy dolac : " << add << "[g]\n";

	return add;
}

float TCup::howMuchToAdd_Volume(string name, float percent)
{
	float Volume = getAbsoluteVolume();
	int k = 0;
	float single_volume = getSingleVolume(name);

	if (single_volume == 0)
	{
		return -1;
	}

	float add = 0;

	add = (single_volume - percent / 100 * Volume) / (percent / 100 - 1);

	cout << "Zeby uzyskac " << percent << "% " << name << " nalezy dolac : " << add * 1000 << "[ml]\n";

	return add * 1000;
}


void TCup::AddToMass(TCup& cup, string name, float percent)
{

	float add_m = cup.howMuchToAdd_Mass(name, percent);
	if (add_m == -1) { cout << "Brak zawartosci. ERROR"; }
	else
	{
		int ID = cup.get_substance_id(name);
		float ro = cup.substances[ID].get_ro();
		float vol = add_m / ro * 1000;
		cup.add(name, vol);
	}
}


void TCup::AddToVolume(TCup& cup, string name, float percent)
{
	float add = cup.howMuchToAdd_Volume(name, percent);
	if (add == -1) { cout << "Brak zawartosci. ERROR \n"; }
	else
	{
		cup.add(name, add);
	}


}

void TCup::transferLiquid(TCup& from, TCup& to, float volume)
{
	if (volume > 0) { cout << "Przelewanie " << volume << "[ml] cieczy \n\n"; }

	float abs_volume = from.getAbsoluteVolume();
	float vol = volume / 1000;
	if (volume / 1000 > abs_volume && volume != -1)
	{
		cout << "W kubku nie ma zadanej objetosci cieczy. Zostanie przelana cala zawartosc\n";
		vol = abs_volume;
	}

	if (volume == -1)
	{
		cout << "Przelewanie całej zawartości\n";
		vol = abs_volume;
	}

	float ratio = vol / abs_volume;

	if (volume > 0 || volume == -1) {
		for (int i = 0; i < from.volumes.size(); i++)
		{
			int found = 0;
			int k;
			string fromName = from.substances[i].get_name();
			string toName;

			for (int j = 0; j < to.volumes.size(); j++)
			{
				k = j;
				toName = to.substances[j].get_name();
				if (fromName == toName)
				{
					found = 1;
					break;
				}

			}
			if (found == 0)
			{
				//co jesli cieczy nie było w drugim kubku a jest w pierwszym
				to.add(fromName, 0);
				toName = fromName;
				k = to.volumes.size() - 1;

			}
			float diff = from.volumes[i] * ratio;

			from.volumes[i] -= diff;
			to.volumes[k] += diff;
		}

		if (volume == -1 || volume / 1000 > abs_volume)
		{

			from.volumes.clear();
			from.substances.clear();

		}
		//from.showTransferInfo(from, to, volume);

	}

	else { cout << "ERROR, nie mozna przelac ujemnej wartosci cieczy \n"; }

}


int TCup::get_volume()
{
	return volume;
}

string TCup::info(int _id)
{
	string info = "Kubek #" + to_string(_id) + "\n";
	int count = substances.size();

	for (int i = 0; i < count; i++)
	{
		string ml = std::to_string(volumes[i] * 1e6);
		info += substances[i].get_name() + ": " + ml + "ml\n";
	}

	return info;
}

vector<TCup*> cups_pnt;

