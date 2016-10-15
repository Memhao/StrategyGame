/*
 * ObjectiveThread.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: xander
 */

#ifndef THREAD_OBJECTIVETHREAD_OBJECTIVETHREAD_HPP_
#define THREAD_OBJECTIVETHREAD_OBJECTIVETHREAD_HPP_
#include"../Thread.hpp"
#include"../../Resource/GoldResource.hpp"
#include"../../Resource/SilverResource.hpp"
#include"../../Resource/WoodResource.hpp"
#include"../../Mutex/Mutex.hpp"
#include"../../Objective/Objective.hpp"
class ObjectiveThread : public Thread
{
	ObjectivePtr _objective;
	GoldResourcePtr _gold;
	SilverResourcePtr _silver;
	WoodResourcePtr _wood;

	Mutex _mutex;
public:
	ObjectiveThread(GoldResourcePtr gold, SilverResourcePtr silver, WoodResourcePtr wood,ObjectivePtr obj );
	void produceResource();
	virtual void run();
	~ObjectiveThread();
};
typedef ObjectiveThread* ObjectiveThreadPtr;


#endif /* THREAD_OBJECTIVETHREAD_OBJECTIVETHREAD_HPP_ */
