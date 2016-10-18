/*
 * Temple.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: xander
 */

#include "Temple.hpp"

Temple::Temple(Price price):Objective(price)
{
	_gold = 10;
	_silver = 5;
	_wood = 7;
}
int
Temple::produceGold() const
{
	return _gold;
}
int
Temple::produceSilver() const
{
	return _silver;
}
int
Temple::produceWood() const
{
	return _wood;
}
Temple::~Temple()
{

}
