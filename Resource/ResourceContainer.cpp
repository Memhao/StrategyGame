/*
 * ResourceContainer.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: xander
 */
#include "ResourceContainer.hpp"
#include <iostream>
ResourceContainer::ResourceContainer(IResourcePtr res):
	_resource(res)
{

}

int
ResourceContainer::getResourceAmount(int amount)
{
	int retAmount = 0;
	_mutex.lock();
	while(true)
	{
		if(_resource->getAmount()<amount)
		{
			std::cout<<"Waiting for resource...."<<std::endl;
			_mutex.wait();
		}
		retAmount = amount;
		_resource->decreaseAmount(amount);
		break;
	}
	_mutex.unlock();
	return retAmount;
}
void
ResourceContainer::putResourceAmount(int amount, int notifier)
{
	_mutex.lock();
	_resource->increaseAmount(amount);

	if(_resource->getAmount() >= notifier)
	{
		_mutex.notify();
	}
	_mutex.unlock();

}
ResourceContainer::~ResourceContainer()
{
	delete _resource;
}
