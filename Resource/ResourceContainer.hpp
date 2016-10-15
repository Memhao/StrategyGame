/*
 * ResourceContainer.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: xander
 */

#ifndef RESOURCE_RESOURCECONTAINER_HPP_
#define RESOURCE_RESOURCECONTAINER_HPP_
#include "IResource.hpp"
#include "../Condition/ConditionMutex.hpp"

class ResourceContainer
{
	IResourcePtr _resource;
	ConditionMutex _mutex;
public:
	ResourceContainer(IResourcePtr res);
	int getResourceAmount(int amount);
	void putResourceAmount(int amount, int notifier);
	~ResourceContainer();
};



#endif /* RESOURCE_RESOURCECONTAINER_HPP_ */
