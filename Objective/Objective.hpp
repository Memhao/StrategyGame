/*
 * Objective.hpp
 *
 *  Created on: Oct 16, 2016
 *      Author: xander
 */

#ifndef OBJECTIVE_OBJECTIVE_HPP_
#define OBJECTIVE_OBJECTIVE_HPP_

class Objective
{
protected:
	int _gold;
	int _silver;
	int _wood;
public:

	virtual int produceGold() const = 0;
	virtual int produceSilver() const = 0;
	virtual int produceWood() const = 0;
	virtual ~Objective(){};
};
typedef Objective* ObjectivePtr;



#endif /* OBJECTIVE_OBJECTIVE_HPP_ */
