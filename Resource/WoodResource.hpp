/*
 * WoodResource.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: xander
 */

#ifndef RESOURCE_WOODRESOURCE_HPP_
#define RESOURCE_WOODRESOURCE_HPP_
#include "IResource.hpp"
class WoodResource : public IResource
{
public:
	WoodResource(int initval = 0):IResource(initval)
{

}
	~WoodResource()
	{

	}
};
typedef WoodResource* WoodResourcePtr;



#endif /* RESOURCE_WOODRESOURCE_HPP_ */
