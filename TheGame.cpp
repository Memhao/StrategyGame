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

#include "Objective/House.hpp"
#include "Thread/ObjectiveThread/ObjectiveThread.hpp"
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//
//	WoodResourcePtr aqWood = new WoodResource(100);
//	WoodResourcePtr wood = new WoodResource(0);
//	WoodResourcePtr wood1 = new WoodResource(11);
//	GoldResourcePtr aqGold = new GoldResource(3221);
//	GoldResourcePtr gold = new GoldResource(-10);
//	SilverResourcePtr aqSilver = new SilverResource(200);
//	SilverResourcePtr silver = new SilverResource(10);
//
//	HousePtr house = new House();
//	ObjectiveThreadPtr houseTh = new ObjectiveThread(gold,silver,aqWood,house);
//	houseTh->start();
////	FarmerThread* farmer = new FarmerThread(wood);
////	farmer->aquireResource(aqWood);
////	farmer->start();
////	farmer->stop();
////	cout<<wood->getAmount()<<endl;
////	WoodCollectorThreadPtr wod = new WoodCollectorThread(wood);
////	wod->aquireWoodResource(aqWood);
////	wod->start();
////	wod->stop();
////	cout<<wood->getAmount()<<endl;
//
//	cout<<"Wood i"<<wood->getAmount()<<endl;
//	cout<<"Wood i1"<<wood1->getAmount()<<endl;
//	cout<<"Wood aq"<<aqWood->getAmount()<<endl;
//	cout<<"Silver i"<<silver->getAmount()<<endl;
//	cout<<"Silver aq"<<aqSilver->getAmount()<<endl;
//	cout<<"Gold i"<<gold->getAmount()<<endl;
//	cout<<"Gold aq"<<aqGold->getAmount()<<endl;
//
//	cout<<wood->getAmount()<<endl;
//	cout<<aqWood->getAmount()<<endl;
//	CollectorThread<WoodResource>* ct = new CollectorThread<WoodResource>(wood);
//	CollectorThread<WoodResource>* ct1 = new CollectorThread<WoodResource>(wood);
//	ct->aquireWoodResource(aqWood);
//	ct1->aquireWoodResource(aqWood);
//	ct->start();
//	ct1->start();
//	ct->stop();
//		cout<<wood->getAmount()<<endl;
//		cout<<aqWood->getAmount()<<endl;
//
//	cout<<"__________________________________________________________________"<<endl;
//	cout<<silver->getAmount()<<endl;
//	cout<<aqSilver->getAmount()<<endl;
//	CollectorThread<SilverResource>* st = new CollectorThread<SilverResource>(silver);
//	st->aquireWoodResource(aqSilver);
//	st->start();
//	st->stop();
//		cout<<silver->getAmount()<<endl;
//		cout<<aqSilver->getAmount()<<endl;
//
//	cout<<"__________________________________________________________________"<<endl;
//
//	cout<<gold->getAmount()<<endl;
//	cout<<aqGold->getAmount()<<endl;
//	CollectorThread<GoldResource,3>* gt = new CollectorThread<GoldResource,3>(gold);
//	gt->aquireWoodResource(aqGold);
//	gt->start();
//	gt->stop();
//	houseTh->stop();
//	cout<<"Wood i"<<wood->getAmount()<<endl;
//	cout<<"Wood aq"<<aqWood->getAmount()<<endl;
//	cout<<"Silver i"<<silver->getAmount()<<endl;
//	cout<<"Silver aq"<<aqSilver->getAmount()<<endl;
//	cout<<"Gold i"<<gold->getAmount()<<endl;
//	cout<<"Gold aq"<<aqGold->getAmount()<<endl;
//	cout<<"Wood i1"<<wood1->getAmount()<<endl;
//	cout<<"__________________________________________________________________"<<endl;
//ct1->stop();

	WoodResourcePtr wr = new WoodResource(0);
	WoodResourcePtr aqwr = new WoodResource(200);
	WoodResourcePtr wr1 = new WoodResource(0);

	SilverResourcePtr osr = new SilverResource(0);
	GoldResourcePtr ogr = new GoldResource(0);
	cout<<"Wood wr:"<<wr->getAmount()<<endl;
	cout<<"Wood wr1:"<<wr1->getAmount()<<endl;
	cout<<"Wood aqwr:"<<aqwr->getAmount()<<endl;

	ObjectiveThreadPtr obj = new ObjectiveThread(ogr,osr,wr,new House());
	CollectorThread<WoodResource>* ct = new CollectorThread<WoodResource>(wr);
	CollectorThread<WoodResource>* ct1 = new CollectorThread<WoodResource>(wr1);
	ct->aquireWoodResource(aqwr);
	ct1->aquireWoodResource(aqwr);
	ct->start();
	ct1->start();
	obj->start();

	ct->stop();
	ct1->stop();
	obj->stop();
	cout<<"Wood wr:"<<wr->getAmount()<<endl;
	cout<<"Wood wr1:"<<wr1->getAmount()<<endl;
	cout<<"Wood aqwr:"<<aqwr->getAmount()<<endl;
	return 0;
}
