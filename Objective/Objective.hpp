/*
 * Objective.hpp
 *
 *  Created on: Oct 16, 2016
 *      Author: xander
 */

#ifndef OBJECTIVE_OBJECTIVE_HPP_
#define OBJECTIVE_OBJECTIVE_HPP_
#include "Price.hpp"
class Objective
{
private :
	Price _price;
protected:
	int _gold;
	int _silver;
	int _wood;
public:
	Objective(Price price):_price(price),_gold(0),_silver(0),_wood(0){}
	virtual int produceGold() const = 0;
	virtual int produceSilver() const = 0;
	virtual int produceWood() const = 0;
	virtual int getGoldPrice() const { return _price.getGold();}
	virtual int getSilverPrice() const { return _price.getSilver();}
	virtual int getWoodPrice() const { return _price.getWood();}
	virtual ~Objective(){};
};
typedef Objective* ObjectivePtr;



#endif /* OBJECTIVE_OBJECTIVE_HPP_ */
