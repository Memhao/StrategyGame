/*
 * Mutex.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: xander
 */

#include "Mutex.hpp"

Mutex::Mutex()
{
	pthread_mutex_init(&_lock,NULL);
}

void
Mutex::lock()
{
	pthread_mutex_lock(&_lock);
}

void
Mutex::unlock()
{
	pthread_mutex_unlock(&_lock);
}

bool
Mutex::tryLock()
{
	return (pthread_mutex_lock(&_lock) != 0) ? false : true;
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(&_lock);
}
