/*
 * Price.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: xander
 */
#include "Price.hpp"

Price::Price(int gold,int silver,int wood):
	_gold(gold),
	_silver(silver),
	_wood(wood)
{

}
Price::~Price()
{

}
int Price::getGold() const
{
	return _gold;
}
int Price::getSilver() const
{
	return _silver;
}
int Price::getWood() const
{
	return _wood;
}
