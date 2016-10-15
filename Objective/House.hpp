/*
 * House.hpp
 *
 *  Created on: Oct 16, 2016
 *      Author: xander
 */

#ifndef OBJECTIVE_HOUSE_HPP_
#define OBJECTIVE_HOUSE_HPP_
#include "Objective.hpp"
class House : public Objective
{
public:
	House();
	virtual int produceGold() const ;
	virtual int produceSilver() const ;
	virtual int produceWood() const ;
	virtual ~House();
};
typedef House* HousePtr;



#endif /* OBJECTIVE_HOUSE_HPP_ */
