/*
 * Price.hpp
 *
 *  Created on: Oct 17, 2016
 *      Author: xander
 */

#ifndef OBJECTIVE_PRICE_HPP_
#define OBJECTIVE_PRICE_HPP_
class Price
{
private:
	int _gold;
	int _silver;
	int _wood;
public:
	Price(int gold,int silver,int wood);
	~Price();
	int getGold() const;
	int getSilver() const;
	int getWood() const;
};




#endif /* OBJECTIVE_PRICE_HPP_ */
