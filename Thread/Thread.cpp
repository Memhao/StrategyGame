/*
 * Thread.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: xander
 */
#include"Thread.hpp"

#include<unistd.h>
#include<iostream>
#include<pthread.h>
Thread::Thread():_threadID(0)
{
}
Thread::~Thread()
{

}
unsigned int
Thread::id() const
{
	return _threadID;
}
void
Thread::start()
{
	if(pthread_create(&_threadID,NULL,&Thread::entry,this) != 0)
	{
		std::cout<<"Creating thread fail!"<<std::endl;
	};
	std::cout<<"Creating thread with id:"<<id()<<"succeded"<<std::endl;
}

void
Thread::stop()
{
	if(pthread_join(_threadID,NULL))
	{
		std::cout<<"Joining thread fail!"<<std::endl;
	}
}

void
Thread::manageTask()
{
	run();
}
void *
Thread::entry(void *arg)
{
	reinterpret_cast<Thread*>(arg)->manageTask();
	return NULL;
}

