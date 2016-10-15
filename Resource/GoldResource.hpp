/*
 * GoldResource.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: xander
 */

#ifndef RESOURCE_GOLDRESOURCE_HPP_
#define RESOURCE_GOLDRESOURCE_HPP_
#include "IResource.hpp"
class GoldResource : public IResource
{
public:
	GoldResource(int initval):IResource(initval)
{

}
	~GoldResource()
	{

	}
};
typedef GoldResource* GoldResourcePtr;


#endif /* RESOURCE_GOLDRESOURCE_HPP_ */
