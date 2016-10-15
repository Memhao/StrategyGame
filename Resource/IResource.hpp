/*
 * IResource.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: xander
 */

#ifndef RESOURCE_IRESOURCE_HPP_
#define RESOURCE_IRESOURCE_HPP_
#include "../Condition/ConditionMutex.hpp"
class IResource;
typedef IResource* IResourcePtr;
class IResource
{
private:
	int _value;
	ConditionMutex _mutex;
public:
	IResource(int initval = 0):_value(initval){}
	int getAmount() const
	{
		return _value;
	}
	void increaseAmount(int value)
	{
		_mutex.lock();
		_value += value;
		_mutex.unlock();
	}
	void decreaseAmount(int value)
	{
		_mutex.lock();
		if((_value-value) <= 0)
		_value = 0;
		else
			_value -= value;
		_mutex.unlock();
	}

};



#endif /* RESOURCE_IRESOURCE_HPP_ */
