/*
 * BuilderThread.hpp
 *
 *  Created on: Oct 17, 2016
 *      Author: xander
 */

#ifndef THREAD_BUILDERTHREAD_BUILDERTHREAD_HPP_
#define THREAD_BUILDERTHREAD_BUILDERTHREAD_HPP_
#include"../Thread.hpp"
#include"../../Mutex/Mutex.hpp"
#include"../../Objective/Objective.hpp"
#include"../../Resource/GoldResource.hpp"
#include"../../Resource/SilverResource.hpp"
#include"../../Resource/WoodResource.hpp"
#include"../../Resource/ResourceContainer.hpp"
#include"../../Thread/ObjectiveThread/ObjectiveThread.hpp"
class BuilderThread: public Thread
{
	ResourceContainerPtr _gold;
	ResourceContainerPtr _silver;
	ResourceContainerPtr _wood;
	ObjectiveThreadPtr _objectiveThread;
	ConditionMutex _lock;
public:
	BuilderThread(GoldResourcePtr ,SilverResourcePtr ,WoodResourcePtr ,ObjectiveThreadPtr );
	virtual ~BuilderThread();
	virtual void run();
};
typedef BuilderThread* BuilderThreadPtr;



#endif /* THREAD_BUILDERTHREAD_BUILDERTHREAD_HPP_ */
