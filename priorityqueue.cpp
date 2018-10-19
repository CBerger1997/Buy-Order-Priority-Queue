#include <priorityqueue.h>
#include <buyorder.h>

PriorityQueue::PriorityQueue() {
	m_nextAvailableIndex = 0;
	m_maxIndex = 15;
	m_ticker = "";	
	m_buyOrderQueue = new BuyOrder[m_maxIndex];
	BuyOrder emptyOrder;
	emptyOrder.setName("EMPTYORDER");
	m_buyOrderQueue[0] = emptyOrder;
}

PriorityQueue::PriorityQueue(PriorityQueue& priorityqueue) {
	m_nextAvailableIndex = priorityqueue.m_nextAvailableIndex;
	m_maxIndex = priorityqueue.m_maxIndex;
	m_ticker = priorityqueue.m_ticker;
	m_buyOrderQueue = new BuyOrder[m_maxIndex];
	
	for(int i = 0; i < priorityqueue.m_maxIndex; i++) {
		m_buyOrderQueue[i] = priorityqueue.m_buyOrderQueue[i];
	}
}


PriorityQueue::PriorityQueue(std::string ticker) : m_ticker(ticker) {
	m_nextAvailableIndex = 0;
	m_maxIndex = 15;	
	m_buyOrderQueue = new BuyOrder[m_maxIndex];
	BuyOrder emptyOrder;
	emptyOrder.setName("EMPTYORDER");
	m_buyOrderQueue[0] = emptyOrder;
}

PriorityQueue::~PriorityQueue() {
	delete[] m_buyOrderQueue;
}

void PriorityQueue::add(BuyOrder newOrder) {
	m_buyOrderQueue[m_nextAvailableIndex] = newOrder;
	m_nextAvailableIndex++;
	
	if(m_nextAvailableIndex >= m_maxIndex)
	{
		resize();
	}
}

void PriorityQueue::resize() {
	m_maxIndex += 15;
	BuyOrder* newQueue = new BuyOrder[m_maxIndex];
	std::copy(m_buyOrderQueue, m_buyOrderQueue + std::min(m_maxIndex - 15, m_maxIndex), newQueue);
	delete[] m_buyOrderQueue;
	m_buyOrderQueue = newQueue;
}

BuyOrder PriorityQueue::highestPriorityOrder() {
	BuyOrder highestOrder;	
	highestOrder = m_buyOrderQueue[0];
	
	if(m_nextAvailableIndex > 0) {
		for(int i = 1; i < m_nextAvailableIndex; i++) {
			if(highestOrder.getPrice() == m_buyOrderQueue[i].getPrice()) {
				if(highestOrder.getOrderTime() > m_buyOrderQueue[i].getOrderTime()) {
					highestOrder = m_buyOrderQueue[i];
				}
			}
			else if(highestOrder < m_buyOrderQueue[i]) {
				highestOrder = m_buyOrderQueue[i];
			}
		}
	}
	
	return highestOrder;
}

void PriorityQueue::removeHighestPriorityOrder() {
	BuyOrder orderToRemove;
	BuyOrder emptyOrder;
	emptyOrder.setName("EmptyOrder");
	
	orderToRemove = highestPriorityOrder();
	
	for(int i = 0; i < m_nextAvailableIndex; i++) {		
		if(m_buyOrderQueue[i] == orderToRemove) {
			std::copy(m_buyOrderQueue + i + 1, m_buyOrderQueue + m_maxIndex - 1, m_buyOrderQueue + i);
			return;
		}
	}
}