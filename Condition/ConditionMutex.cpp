/*
 * Condition.cpp
 *
 *  Created on: Oct 12, 2016
 *      Author: xander
 */


#include "ConditionMutex.hpp"

ConditionMutex::ConditionMutex()
{
	pthread_cond_init(&_cond,NULL);
}
ConditionMutex::~ConditionMutex()
{
	pthread_cond_destroy(&_cond);
}
void
ConditionMutex::notify()
{
	pthread_cond_signal(&_cond);
}
void
ConditionMutex::wait()
{
	pthread_cond_wait(&_cond,&_lock);
}
