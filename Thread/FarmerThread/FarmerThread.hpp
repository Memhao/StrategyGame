/*
 * FarmerThread.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: xander
 */

#ifndef THREAD_FARMERTHREAD_HPP_
#define THREAD_FARMERTHREAD_HPP_
#include "../Thread.hpp"
#include "../../Resource/GoldResource.hpp"
#include "../../Resource/SilverResource.hpp"
#include "../../Resource/WoodResource.hpp"
#include "../../Mutex/Mutex.hpp"
class FarmerThread
{
	GoldResourcePtr _gold;
	SilverResourcePtr _silver;
	WoodResourcePtr _wood;

	GoldResourcePtr _aqgold;
	SilverResourcePtr _aqsilver;
	WoodResourcePtr _aqwood;
	Mutex _mutex;
public:
	FarmerThread(GoldResourcePtr gold, SilverResourcePtr silver ,WoodResourcePtr wood);
	void aquireResource(WoodResourcePtr);
	void start();
	~FarmerThread();
};



#endif /* THREAD_FARMERTHREAD_HPP_ */
