#ifndef __PRIORITYQUEUE__
#define __PRIORITYQUEUE__

#include <iostream>
#include <sstream>
#include <vector>

template <class T>
class PriorityQueue {
	private:
		std::vector<T> m_priorityQueue;	
		std::string m_ticker;

	public:
		// Constructs an empty queue
		PriorityQueue();
		
		// Constructs a queue and sets memeber values equalt to the specified 'priorityqueue'
		PriorityQueue(const PriorityQueue& priorityQueue);
		
		// Constructs a queue and assigns the ticker value
		PriorityQueue(const std::string& ticker);
		
		// Destorys this object
		~PriorityQueue();
		
		// Gets the ticker of the queue
		std::string getTicker() const;
		
		// Sets the ticker of the queue
		void setTicker(const std::string& ticker);
		
		// Returns the highest priority item in the queue
		T highestPriorityItem();

		// Adds the specified 'item' to the priority queue
		// The queue will automatically resize when required
		void add(T newItem);
		
		// Removes the highest priority item from the queue
		void removeHighestPriorityItem();
		
		// Returns true if the queue is empty otherwise returns false
		bool isEmpty();
		
		// Returns the length of the priority queue
		size_t length();
		
		// Prints the priority queue to the output stream
		void print();		
};

//----------------------------------------------------------------------------------------
//----------------------------------INLINE FUNCTIONS--------------------------------------
//----------------------------------------------------------------------------------------

template <class T>
inline std::string PriorityQueue<T>::getTicker() const {
	return m_ticker;
}

template <class T>
inline void PriorityQueue<T>::setTicker(const std::string& ticker) {
	m_ticker = ticker;
}

template <class T>
inline size_t PriorityQueue<T>::length() {
	return m_priorityQueue.size();
}

template <class T>
inline bool PriorityQueue<T>::isEmpty() {
	return m_priorityQueue.size() == 0;
}

//----------------------------------------------------------------------------------------
//----------------------------------TEMPLATE FUNCTIONS--------------------------------------
//----------------------------------------------------------------------------------------

template <class T>
PriorityQueue<T>::PriorityQueue() : m_ticker("") {

}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& priorityQueue) : m_ticker(priorityQueue.m_ticker) {	
	for (int i = 0; i < priorityQueue.m_priorityQueue.size(); i++) {
		m_priorityQueue.push_back(priorityQueue.m_priorityQueue[i]);
	}
}

template <class T>
PriorityQueue<T>::PriorityQueue(const std::string& ticker) : m_ticker(ticker) {
}

template <class T>
PriorityQueue<T>::~PriorityQueue() {
}

template <class T>
void PriorityQueue<T>::add(T newItem) {
	m_priorityQueue.push_back(newItem);
}

template <class T>
T PriorityQueue<T>::highestPriorityItem() {
	T highestPriorityItem;	
	highestPriorityItem = m_priorityQueue[0];
	
	if (!isEmpty()) {
		for (int i = 1; i < m_priorityQueue.size(); i++) {
			if (highestPriorityItem < m_priorityQueue[i]) {
				highestPriorityItem = m_priorityQueue[i];
			}
		}
	}	
	return highestPriorityItem;
}

template <class T>
void PriorityQueue<T>::removeHighestPriorityItem() {
	T itemToRemove;
	
	itemToRemove = highestPriorityItem();
	
	for (int i = 0; i < m_priorityQueue.size(); i++) {	
		if (m_priorityQueue[i] == itemToRemove) {
			m_priorityQueue.erase(m_priorityQueue.begin()+i);
			return;
		}
	}
}

template <class T>
void PriorityQueue<T>::print() {
	std::stringstream ss;
	
	for (int i = 0; i < m_priorityQueue.size(); i++) {
		ss << m_priorityQueue[i] << '\n';
	}
	
	std::cout << ss.str();
}
#endif