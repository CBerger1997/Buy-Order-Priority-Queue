#ifndef __PRIORITYQUEUE__
#define __PRIORITYQUEUE__

#include <buyorder.h>
#include <sellorder.h>
#include <iostream>
#include <typeinfo>

template <class T>
class PriorityQueue {
	private:
		T *m_orderPriorityQueue;
		int m_nextAvailableIndex;
		int m_capacity;		
		std::string m_ticker;
		void resize();

		
	public:
		//default constructor which defines a priority queue with queue size of 15,
		//adds an order to the queue which is defined as empty
		//and initialises all other variables to 0
		PriorityQueue();
		
		//copy constructor which assigns the membar variables of a specified 'priorityqueue' to
		//the current PriorityQueue object
		PriorityQueue(PriorityQueue& priorityqueue);
		
		//custom constructor to define a ticker for a queue
		PriorityQueue(std::string ticker);
		
		//default constructor provided by the compiler
		~PriorityQueue();
		
		//gets the ticker of the order
		std::string getTicker() const;
		
		//sets the ticker of the order
		void setTicker(const std::string& ticker);
		
		//returns an order based upon the specified 'index'
		T getOrderFromIndex(int index) const;
		
		//returns the highest priority order in the queue
		//The highest priority order contains the highest price and/or shortest time
		T highestPriorityOrder();	

		//adds the specified 'order' to the priority queue
		//the queue will automatically resize when required
		void add(T newOrder);
		
		//removes the highest priority order from the queue
		//The highest priority order contains the highest price and/or shortest time
		void removeHighestPriorityOrder();
		
		//returns the length of the priority queue
		int length();
		
		//prints the priority queue to the output stream
		void print();		
};

template <class T>
inline T PriorityQueue<T>::getOrderFromIndex(int index) const {
	return m_orderPriorityQueue[index];
}

template <class T>
inline std::string PriorityQueue<T>::getTicker() const {
	return m_ticker;
}

template <class T>
inline void PriorityQueue<T>::setTicker(const std::string& ticker) {
	m_ticker = ticker;
}

template <class T>
inline int PriorityQueue<T>::length() {
	return m_nextAvailableIndex;
}

template <class T>
inline void PriorityQueue<T>::print() {
	std::stringstream ss;
	
	for(int i = 0; i < m_capacity; i++) {
		ss << m_orderPriorityQueue[i] << '\n';
	}
	
	std::cout << ss.str();
}

template <class T>
PriorityQueue<T>::PriorityQueue() : m_nextAvailableIndex(0), m_capacity(15), m_ticker("") {
	m_orderPriorityQueue = new T[m_capacity];

}

template <class T>
PriorityQueue<T>::PriorityQueue(PriorityQueue& priorityqueue) : m_nextAvailableIndex(priorityqueue.m_nextAvailableIndex), m_capacity(priorityqueue.m_capacity), m_ticker(priorityqueue.m_ticker) {
	m_orderPriorityQueue = new T[m_capacity];
	
	for(int i = 0; i < priorityqueue.m_capacity; i++) {
		m_orderPriorityQueue[i] = priorityqueue.m_orderPriorityQueue[i];
	}
}


template <class T>
PriorityQueue<T>::PriorityQueue(std::string ticker) : m_ticker(ticker) {
	m_nextAvailableIndex = 0;
	m_capacity = 15;	
	m_orderPriorityQueue = new T[m_capacity];
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
	delete[] m_orderPriorityQueue;
}

template <class T>
void PriorityQueue<T>::add(T newOrder) {
	m_orderPriorityQueue[m_nextAvailableIndex] = newOrder;
	m_nextAvailableIndex++;
	
	if(m_nextAvailableIndex >= m_capacity)
	{
		resize();
	}
}

template <class T>
void PriorityQueue<T>::resize() {
	m_capacity += 15;
	T* newQueue = new T[m_capacity];
	std::copy(m_orderPriorityQueue, m_orderPriorityQueue + std::min(m_capacity - 15, m_capacity), newQueue);
	delete[] m_orderPriorityQueue;
	m_orderPriorityQueue = newQueue;
}

template <class T>
T PriorityQueue<T>::highestPriorityOrder() {
	T highestOrder;	
	highestOrder = m_orderPriorityQueue[0];
	std::stringstream name;
	name << typeid(m_orderPriorityQueue[0]).name();
	std::stringstream type;
	type << name.str().erase(0, 1);
	
	if(m_nextAvailableIndex > 0) {
		for(int i = 1; i < m_nextAvailableIndex; i++) {
			if(highestOrder.getPrice() == m_orderPriorityQueue[i].getPrice()) {
				if(highestOrder.getOrderTime() > m_orderPriorityQueue[i].getOrderTime()) {
					highestOrder = m_orderPriorityQueue[i];
				}
			}
			else {
				if(type.str() == "SellOrder") {
					if(highestOrder > m_orderPriorityQueue[i]) {
						highestOrder = m_orderPriorityQueue[i];
					}
				}
				else {
					if(highestOrder < m_orderPriorityQueue[i]) {
						highestOrder = m_orderPriorityQueue[i];
					}
				}
			}
		}
	}
	
	return highestOrder;
}

template <class T>
void PriorityQueue<T>::removeHighestPriorityOrder() {
	T orderToRemove;
	T emptyOrder;
	emptyOrder.setName("EmptyOrder");
	
	orderToRemove = highestPriorityOrder();
	
	for(int i = 0; i < m_nextAvailableIndex; i++) {		
		if(m_orderPriorityQueue[i] == orderToRemove) {
			std::copy(m_orderPriorityQueue + i + 1, m_orderPriorityQueue + m_capacity - 1, m_orderPriorityQueue + i);
			return;
		}
	}
}
#endif