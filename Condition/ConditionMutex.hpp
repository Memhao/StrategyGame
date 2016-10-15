/*
 * Condition.hpp
 *
 *  Created on: Oct 12, 2016
 *      Author: xander
 */

#ifndef THREAD_CONDITION_HPP_
#define THREAD_CONDITION_HPP_
#include "../Mutex/Mutex.hpp"
class ConditionMutex : public Mutex
{
	pthread_cond_t _cond;
	ConditionMutex(const ConditionMutex&);
	ConditionMutex& operator=(const ConditionMutex&);
public:
	ConditionMutex();
	~ConditionMutex();
	void wait();
	void notify();
};



#endif /* THREAD_CONDITION_HPP_ */
