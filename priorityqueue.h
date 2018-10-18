#ifndef __PRIORITYQUEUE__
#define __PRIORITYQUEUE__

#include <buyorder.h>

class PriorityQueue {
	private:
		BuyOrder *m_buyOrderQueue;
		int m_arrayCurCapacity;
		int m_arrayMaxCapacity;
		
	public:
		PriorityQueue();
		~PriorityQueue();
		
		BuyOrder getQueueFromIndex(int index) const;
		
		void addOrderToQueue(BuyOrder newOrder);
		BuyOrder getHighestPriorityOrder();
		void removeHighestPriorityOrder();
		void createNewPriorityQueue();
};

inline BuyOrder PriorityQueue::getQueueFromIndex(int index) const {
	return m_buyOrderQueue[index];
}

#endif