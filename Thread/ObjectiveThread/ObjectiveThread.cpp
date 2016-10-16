/*
 * ObjectiveThread.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: xander
 */

#include "ObjectiveThread.hpp"
#include <iostream>
#include <unistd.h>
ObjectiveThread::ObjectiveThread(GoldResourcePtr gold, SilverResourcePtr silver, WoodResourcePtr wood,ObjectivePtr obj ):
_gold(gold),
_silver(silver),
_wood(wood)
{
	_objective = obj;
}

void
ObjectiveThread::produceResource()
{
	_gold->increaseAmount(_objective->produceGold());
	_silver->increaseAmount(_objective->produceSilver());
	_wood->increaseAmount(_objective->produceWood());
	std::cout<<"The gold has been increased by"<< _objective->produceGold() <<"by thread:"<<id()<<";"<<std::endl;
	std::cout<<"The silver has been increased by"<< _objective->produceSilver() <<"by thread:"<<id()<<";"<<std::endl;
	std::cout<<"The wood has been increased by"<< _objective->produceWood() <<"by thread:"<<id()<<";"<<std::endl;
}
void
ObjectiveThread::run()
{
	_mutex.lock();

//	while(true)
//	{
//		sleep(2);
		produceResource();
//	}
//	std::cout<<"ResourceProduced"<<std::endl;
	_mutex.unlock();
}
ObjectivePtr
ObjectiveThread::getObjective() const
{
	return _objective;
}
ObjectiveThread::~ObjectiveThread()
{

}
