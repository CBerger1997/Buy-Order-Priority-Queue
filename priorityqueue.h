#ifndef __PRIORITYQUEUE__
#define __PRIORITYQUEUE__

#include <buyorder.h>
#include <iostream>

class PriorityQueue {
	private:
		BuyOrder *m_buyOrderQueue;
		int m_arrayCurCapacity;
		int m_arrayMaxCapacity;		
		void Resize();

		
	public:
		PriorityQueue();
		~PriorityQueue();
		
		BuyOrder getQueueFromIndex(int index) const;
		BuyOrder HighestPriorityOrder();		
		void addOrderToQueue(BuyOrder newOrder);
		void removeHighestPriorityOrder();
		int length();
		friend std::ostream& operator<<(std::ostream& os, PriorityQueue priorityqueue);
		
};

inline BuyOrder PriorityQueue::getQueueFromIndex(int index) const {
	return m_buyOrderQueue[index];
}

inline std::ostream& operator<<(std::ostream& os, PriorityQueue priorityqueue) {
	for(int i = 0; i < priorityqueue.length(); i++) {
		os << priorityqueue.m_buyOrderQueue[i] << '\n';
	}
	return os;
}

inline int PriorityQueue::length() {
	return m_arrayCurCapacity;
}
#endif