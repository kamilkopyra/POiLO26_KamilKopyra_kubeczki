#include <iostream>
#include <vector>
#include "TCup.h"
#include "TSubstance.h"

using namespace std;

int main() 
{
	/*for (int i = 0; i < 4; i++)
	{cout << substancje[i].get_name() << ": " << substancje[i].get_ro() << "kg/m3\n";}
	cout << "\n\n\n";
	*/

	TCup kubek1(100);
	kubek1.add(substance_menu[0], 15);
	kubek1.add(substance_menu[1], 30);
	kubek1.add("oliwa", 60);

	kubek1.show();

	
	TCup kubek2(150);

	kubek2.add(substance_menu[0], 40);
	kubek2.add(substance_menu[1], 50);
	kubek2.add("krew", 50);
	//kubek2.show();
	TCup::AddToVolume(kubek2, "krew", 50);
	kubek2.show();


	TCup::transferLiquid(kubek1, kubek2, 50);

	
	
	kubek1.show();
	kubek2.show();

	TCup::transferLiquid(kubek2, kubek1, -1);

	kubek1.show();
	kubek2.show();

	
	TCup::AddToMass(kubek1, "woda", 50);
	kubek1.show();
	TCup::AddToVolume(kubek2, "oliwa", 50);
	kubek1.show();


	/*
	TCup::transferLiquid(kubek2, kubek3, 10000);


	kubek1.show();
	kubek2.show();
	kubek3.show();
	*/
}