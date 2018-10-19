#ifndef __PRIORITYQUEUE__
#define __PRIORITYQUEUE__

#include <buyorder.h>
#include <iostream>

class PriorityQueue {
	private:
		BuyOrder *m_buyOrderQueue;
		int m_nextAvailableIndex;
		int m_maxIndex;		
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
		
		PriorityQueue(std::string ticker);
		
		//default constructor provided by the compiler
		~PriorityQueue();
		
		//gets the ticker of the order
		std::string getTicker() const;
		
		//sets the ticker of the order
		void setTicker(const std::string& ticker);
		
		//returns an order based upon the specified 'index'
		BuyOrder getOrderFromIndex(int index) const;
		
		//returns the highest priority order in the queue
		//The highest priority order contains the highest price and/or shortest time
		BuyOrder highestPriorityOrder();	

		//adds the specified 'order' to the priority queue 
		void add(BuyOrder newOrder);
		
		//removes the highest priority order from the queue
		//The highest priority order contains the highest price and/or shortest time
		void removeHighestPriorityOrder();
		
		//returns the length of the priority queue
		int length();
		
		//prints the priority queue to the output stream
		void print();
		
		//operator overloading for the output stream
		friend std::ostream& operator<<(std::ostream& os, PriorityQueue priorityqueue);
		
};

inline BuyOrder PriorityQueue::getOrderFromIndex(int index) const {
	return m_buyOrderQueue[index];
}

inline std::string PriorityQueue::getTicker() const {
	return m_ticker;
}
		
inline void PriorityQueue::setTicker(const std::string& ticker) {
	m_ticker = ticker;
}

inline std::ostream& operator<<(std::ostream& os, PriorityQueue priorityqueue) {
	for(int i = 0; i < priorityqueue.length(); i++) {
		os << priorityqueue.m_buyOrderQueue[i] << '\n';
	}
	return os;
}

inline int PriorityQueue::length() {
	return m_nextAvailableIndex;
}

inline void PriorityQueue::print() {
	std::cout << *this;
}
#endif