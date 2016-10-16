/*
 * Temple.hpp
 *
 *  Created on: Oct 16, 2016
 *      Author: xander
 */

#ifndef OBJECTIVE_TEMPLE_HPP_
#define OBJECTIVE_TEMPLE_HPP_
#include "Objective.hpp"
class Temple : public Objective
{
public:
	Temple();
	virtual int produceGold() const ;
	virtual int produceSilver() const ;
	virtual int produceWood() const ;
	virtual ~Temple();
};
typedef Temple* TemplePtr;


#endif /* OBJECTIVE_TEMPLE_HPP_ */
