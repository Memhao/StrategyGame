/*
 * SilverResource.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: xander
 */

#ifndef RESOURCE_SILVERRESOURCE_HPP_
#define RESOURCE_SILVERRESOURCE_HPP_
#include "IResource.hpp"

class SilverResource : public IResource
{
public:
	SilverResource(int initval):IResource(initval)
{

}
	~SilverResource()
	{

	}
};
typedef SilverResource* SilverResourcePtr;



#endif /* RESOURCE_SILVERRESOURCE_HPP_ */
