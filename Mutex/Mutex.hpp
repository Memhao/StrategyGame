/*
 * Mutex.hpp
 *
 *  Created on: Oct 6, 2016
 *      Author: xander
 */

#ifndef MUTEX_MUTEX_HPP_
#define MUTEX_MUTEX_HPP_
#include <pthread.h>
#include <unistd.h>
class Mutex
{
public:
	Mutex();
	void lock();
	bool tryLock();
	void unlock();
	~Mutex();
protected:
	pthread_mutex_t _lock;
private:
	Mutex(const Mutex&);
	Mutex& operator=(const Mutex&);
};



#endif /* MUTEX_MUTEX_HPP_ */
