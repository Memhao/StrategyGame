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
#include "Objective/Temple.hpp"
#include "Thread/ObjectiveThread/ObjectiveThread.hpp"
#include "Thread/BuilderThread/BuilderThread.hpp"
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
	GoldResourcePtr aqgl = new GoldResource(150);
	SilverResourcePtr aqsl = new SilverResource(300);
	WoodResourcePtr wr1 = new WoodResource(0);

	SilverResourcePtr osr = new SilverResource(0);
	GoldResourcePtr ogr = new GoldResource(0);
	cout<<"Wood wr:"<<wr->getAmount()<<endl;
	cout<<"Wood wr1:"<<wr1->getAmount()<<endl;
	cout<<"Wood aqwr:"<<aqwr->getAmount()<<endl;

	ObjectiveThreadPtr obj = new ObjectiveThread(ogr,osr,wr,new House(Price(10,10,50)));
	ObjectiveThreadPtr church = new ObjectiveThread(ogr,osr,wr,new Temple(Price(16,13,9)));
	BuilderThreadPtr build = new BuilderThread(ogr,osr,wr,obj);
	BuilderThreadPtr build1 = new BuilderThread(ogr,osr,wr,church);
	CollectorThread<WoodResource>* ct = new CollectorThread<WoodResource>(wr);
	CollectorThread<WoodResource>* ct1 = new CollectorThread<WoodResource>(wr1);
	CollectorThread<SilverResource>* sl = new CollectorThread<SilverResource>(osr);
	CollectorThread<GoldResource>* gl = new CollectorThread<GoldResource>(ogr);


	ct->aquireResource(aqwr);
	ct1->aquireResource(aqwr);
	sl->aquireResource(aqsl);
	gl->aquireResource(aqgl);

	ct->start();
	ct1->start();
	sl->start();
	gl->start();
	/*
	 * @see builder thread should not start till enough resource occurs
	 */
	build->start();
	build1->start();
	ct->stop();
	ct1->stop();
	sl->stop();
	gl->stop();
	build->stop();
	build1->stop();
	cout<<"Wood wr:"<<wr->getAmount()<<endl;
	cout<<"Wood wr1:"<<wr1->getAmount()<<endl;
	cout<<"Wood aqwr:"<<aqwr->getAmount()<<endl;
	cout<<"Gold :"<<ogr->getAmount()<<endl;
	cout<<"Silver :"<<osr->getAmount()<<endl;
	return 0;
}
