/*
 * Condition.cpp
 *
 *  Created on: Oct 12, 2016
 *      Author: xander
 */


#include "ConditionMutex.hpp"
#include <sys/time.h>
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
ConditionMutex::twait()
{
	struct timespec timeToWait;
	struct timeval now;
	gettimeofday(&now,NULL);
	timeToWait.tv_sec = now.tv_sec+5;
	timeToWait.tv_sec = now.tv_sec+5;
	pthread_cond_timedwait(&_cond,&_lock,&timeToWait);
}
void
ConditionMutex::wait()
{
	pthread_cond_wait(&_cond,&_lock);
}
