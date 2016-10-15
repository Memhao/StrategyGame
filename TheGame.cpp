//============================================================================
// Name        : TheGame.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Resource/WoodResource.hpp"
#include "Resource/SilverResource.hpp"
#include "Resource/GoldResource.hpp"

#include "Thread/FarmerThread/CollecterThread.hpp"
#include "Thread/FarmerThread/FarmerThread.hpp"
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	WoodResourcePtr aqWood = new WoodResource(100);
	WoodResourcePtr wood = new WoodResource(0);
	GoldResourcePtr aqGold = new GoldResource(3221);
	GoldResourcePtr gold = new GoldResource(-10);
	SilverResourcePtr aqSilver = new SilverResource(200);
	SilverResourcePtr silver = new SilverResource(10);
//	FarmerThread* farmer = new FarmerThread(wood);
//	farmer->aquireResource(aqWood);
//	farmer->start();
//	farmer->stop();
//	cout<<wood->getAmount()<<endl;
//	WoodCollectorThreadPtr wod = new WoodCollectorThread(wood);
//	wod->aquireWoodResource(aqWood);
//	wod->start();
//	wod->stop();
//	cout<<wood->getAmount()<<endl;

	cout<<"Wood i"<<wood->getAmount()<<endl;
	cout<<"Wood aq"<<aqWood->getAmount()<<endl;
	cout<<"Silver i"<<silver->getAmount()<<endl;
	cout<<"Silver aq"<<aqSilver->getAmount()<<endl;
	cout<<"Gold i"<<gold->getAmount()<<endl;
	cout<<"Gold aq"<<aqGold->getAmount()<<endl;

	cout<<wood->getAmount()<<endl;
	cout<<aqWood->getAmount()<<endl;
	CollectorThread<WoodResource>* ct = new CollectorThread<WoodResource>(wood);
	ct->aquireWoodResource(aqWood);
	ct->start();
	ct->stop();
		cout<<wood->getAmount()<<endl;
		cout<<aqWood->getAmount()<<endl;

	cout<<"__________________________________________________________________"<<endl;
	cout<<silver->getAmount()<<endl;
	cout<<aqSilver->getAmount()<<endl;
	CollectorThread<SilverResource>* st = new CollectorThread<SilverResource>(silver);
	st->aquireWoodResource(aqSilver);
	st->start();
	st->stop();
		cout<<silver->getAmount()<<endl;
		cout<<aqSilver->getAmount()<<endl;

	cout<<"__________________________________________________________________"<<endl;

	cout<<gold->getAmount()<<endl;
	cout<<aqGold->getAmount()<<endl;
	CollectorThread<GoldResource>* gt = new CollectorThread<GoldResource>(gold);
	gt->aquireWoodResource(aqGold);
	gt->start();
	gt->stop();

	cout<<"Wood i"<<wood->getAmount()<<endl;
	cout<<"Wood aq"<<aqWood->getAmount()<<endl;
	cout<<"Silver i"<<silver->getAmount()<<endl;
	cout<<"Silver aq"<<aqSilver->getAmount()<<endl;
	cout<<"Gold i"<<gold->getAmount()<<endl;
	cout<<"Gold aq"<<aqGold->getAmount()<<endl;

	cout<<"__________________________________________________________________"<<endl;


	return 0;
}
