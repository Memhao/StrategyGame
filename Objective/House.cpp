/*
 * House.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: xander
 */

#include "House.hpp"

House::House(Price price):Objective(price)
{
	_gold = 5;
	_silver = 5;
	_wood = 5;
}
int
House::produceGold() const
{
	return _gold;
}
int
House::produceSilver() const
{
	return _silver;
}
int
House::produceWood() const
{
	return _wood;
}
House::~House()
{

}
