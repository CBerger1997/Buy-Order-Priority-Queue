#include <priorityqueue.h>
#include <buyorder.h>

PriorityQueue::PriorityQueue() {
	m_arrayCurCapacity = 0;
	m_arrayMaxCapacity = 15;
	m_ticker = "";
	
	m_buyOrderQueue = new BuyOrder[m_arrayMaxCapacity];
	BuyOrder emptyOrder;
	emptyOrder.setName("EMPTYORDER");
	m_buyOrderQueue[0] = emptyOrder;
}

PriorityQueue::PriorityQueue(std::string ticker) : m_ticker(ticker) {
	m_arrayCurCapacity = 0;
	m_arrayMaxCapacity = 15;
	
	m_buyOrderQueue = new BuyOrder[m_arrayMaxCapacity];
	BuyOrder emptyOrder;
	emptyOrder.setName("EMPTYORDER");
	m_buyOrderQueue[0] = emptyOrder;
}

PriorityQueue::~PriorityQueue() {
	delete[] m_buyOrderQueue;
}

void PriorityQueue::add(BuyOrder newOrder) {
	m_buyOrderQueue[m_arrayCurCapacity] = newOrder;
	m_arrayCurCapacity++;
	
	if(m_arrayCurCapacity >= m_arrayMaxCapacity)
	{
		resize();
	}
}

void PriorityQueue::resize() {
	m_arrayMaxCapacity += 15;
	BuyOrder* newQueue = new BuyOrder[m_arrayMaxCapacity];
	std::copy(m_buyOrderQueue, m_buyOrderQueue + std::min(m_arrayMaxCapacity - 15, m_arrayMaxCapacity), newQueue);
	delete[] m_buyOrderQueue;
	m_buyOrderQueue = newQueue;
}

BuyOrder PriorityQueue::highestPriorityOrder() {
	BuyOrder highestOrder;	
	highestOrder = m_buyOrderQueue[0];
	
	if(m_arrayCurCapacity > 0) {
		for(int i = 1; i < m_arrayCurCapacity; i++) {
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
	
	for(int i = 0; i < m_arrayCurCapacity; i++) {
		
		if(m_buyOrderQueue[i] == orderToRemove) {
			m_buyOrderQueue[i] = emptyOrder;
		}
	}
}
