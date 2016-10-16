/*
 * CollecterThread.hpp
 *
 *  Created on: Oct 15, 2016
 *      Author: xander
 */

#ifndef THREAD_FARMERTHREAD_COLLECTERTHREAD_HPP_
#define THREAD_FARMERTHREAD_COLLECTERTHREAD_HPP_
#include "../Thread.hpp"
template<typename T, int t_amount = 1>
class CollectorThread : public Thread
{

	T* _resource;
	T* _aquiredResource;
	Mutex _mutex;
public:
	CollectorThread(T* resource)
{
		_aquiredResource = NULL;
		_resource = resource;
}
	void aquireWoodResource(T* aqresource)
	{
		_aquiredResource = aqresource;
	}
	void minning()
	{
		_aquiredResource->decreaseAmount(t_amount);
		_resource->increaseAmount(t_amount);

		std::cout<<_aquiredResource->getAmount()<<std::endl;
		std::cout<<"The resource has been increased by"<< t_amount <<"by thread:"<<id()<<";"<<std::endl;
	}
	virtual void run()
	{
		_mutex.lock();

			while(_aquiredResource->getAmount()>0)
			{
				minning();
			}
			std::cout<<"The resource has been nullified:"<<_aquiredResource->getAmount()<<std::endl;
		_mutex.unlock();
	}
	~CollectorThread()
	{

	}

};





#endif /* THREAD_FARMERTHREAD_COLLECTERTHREAD_HPP_ */
