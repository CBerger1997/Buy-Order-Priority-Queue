#ifndef __PRIORITYQUEUE__
#define __PRIORITYQUEUE__

#include <buyorder.h>
#include <sellorder.h>
#include <iostream>
#include <typeinfo>

template <class T>
class PriorityQueue {
	private:
		T *m_PriorityQueue;
		int m_nextAvailableIndex;
		int m_capacity;
		std::string m_ticker;
		
		//
		void resize();

	public:
		// Constructs an empty queue
		PriorityQueue();
		
		// Constructs a queue and sets memeber values equalt to the specified 'priorityqueue'
		PriorityQueue(PriorityQueue& priorityqueue);
		
		// Constructs a queue and assigns the ticker value
		PriorityQueue(std::string ticker);
		
		// Destorys this object
		~PriorityQueue();
		
		// Gets the ticker of the queue
		std::string getTicker() const;
		
		// Sets the ticker of the queue
		void setTicker(const std::string& ticker);
		
		// Returns the highest priority item in the queue
		// The highest priority item contains the highest price and/or shortest time
		T highestPriorityItem();

		// Adds the specified 'item' to the priority queue
		// The queue will automatically resize when required
		void add(T newItem);
		
		// Removes the highest priority item from the queue
		// The highest priority item contains the highest price and/or shortest time
		void removeHighestPriorityItem();
		
		// Returns the length of the priority queue
		int length();
		
		// Prints the priority queue to the output stream
		void print();		
};

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
		ss << m_PriorityQueue[i] << '\n';
	}
	
	std::cout << ss.str();
}

template <class T>
PriorityQueue<T>::PriorityQueue() : m_nextAvailableIndex(0), m_capacity(15), m_ticker("") {
	m_PriorityQueue = new T[m_capacity];

}

template <class T>
PriorityQueue<T>::PriorityQueue(PriorityQueue& priorityqueue) : m_nextAvailableIndex(priorityqueue.m_nextAvailableIndex), m_capacity(priorityqueue.m_capacity), m_ticker(priorityqueue.m_ticker) {
	m_PriorityQueue = new T[m_capacity];
	
	for(int i = 0; i < priorityqueue.m_capacity; i++) {
		m_PriorityQueue[i] = priorityqueue.m_PriorityQueue[i];
	}
}

template <class T>
PriorityQueue<T>::PriorityQueue(std::string ticker) : m_ticker(ticker) {
	m_nextAvailableIndex = 0;
	m_capacity = 15;	
	m_PriorityQueue = new T[m_capacity];
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
	delete[] m_PriorityQueue;
}

template <class T>
void PriorityQueue<T>::add(T newItem) {
	m_PriorityQueue[m_nextAvailableIndex] = newItem;
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
	std::copy(m_PriorityQueue, m_PriorityQueue + std::min(m_capacity - 15, m_capacity), newQueue);
	delete[] m_PriorityQueue;
	m_PriorityQueue = newQueue;
}

template <class T>
T PriorityQueue<T>::highestPriorityItem() {
	T highestPriorityItem;	
	highestPriorityItem = m_PriorityQueue[0];
	
	if(m_nextAvailableIndex > 0) {
		for(int i = 0; i < m_nextAvailableIndex; i++) {
			if(highestPriorityItem.getName() == "EmptyOrder") {
				highestPriorityItem = m_PriorityQueue[i];
			}
			else if(m_PriorityQueue[i].getName() == "EmptyOrder") {
				continue;
			}
			else if(highestPriorityItem < m_PriorityQueue[i]) {
				highestPriorityItem = m_PriorityQueue[i];
			}
		}
	}
	
	return highestPriorityItem;
}

template <class T>
void PriorityQueue<T>::removeHighestPriorityItem() {
	T itemToRemove;
	
	itemToRemove = highestPriorityItem();
	
	for(int i = 0; i < m_nextAvailableIndex; i++) {		
		if(m_PriorityQueue[i] == itemToRemove) {
			std::copy(m_PriorityQueue + i + 1, m_PriorityQueue + m_capacity - 1, m_PriorityQueue + i);
			return;
		}
	}
}
#endif