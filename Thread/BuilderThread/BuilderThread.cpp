/*
 * BuilderThread.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: xander
 */
#include "BuilderThread.hpp"
#include <iostream>
BuilderThread::BuilderThread(GoldResourcePtr gold,SilverResourcePtr silver,WoodResourcePtr wood,ObjectiveThreadPtr objectiveThread):
	_objectiveThread(objectiveThread)
{
	_gold = new ResourceContainer(gold);
	_silver = new ResourceContainer(silver);
	_wood = new ResourceContainer(wood);
}

BuilderThread::~BuilderThread()
{

}
void
BuilderThread::run()
{

	_lock.lock();
	ObjectivePtr objective = _objectiveThread->getObjective();
	if(objective)
	{
		_gold->getResourceAmount(objective->getGoldPrice());
		_silver->getResourceAmount(objective->getSilverPrice());
		_wood->getResourceAmount(objective->getWoodPrice());
		// if here : that's mean enough resources
		std::cout<<"__________________________"<<std::endl<<"__________________"<<std::endl;
		_objectiveThread->start();

	}
	_lock.unlock();
}
