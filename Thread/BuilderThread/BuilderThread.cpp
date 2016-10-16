/*
 * BuilderThread.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: xander
 */
#include "BuilderThread.hpp"

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
//		_gold->getResourceAmount(0);
//		_silver->getResourceAmount(0);
		_wood->getResourceAmount(20);
		// if here : that's mean enough resources
		_objectiveThread->start();

	}
	_lock.unlock();
}
