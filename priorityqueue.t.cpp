#include <priorityqueue.h>
#include <buyorder.h>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

TEST(QueueManipulation, AddingToQueue) {
	PriorityQueue queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	queue.addOrderToQueue(order);
	EXPECT_EQ(order.getName(), queue.getQueueFromIndex(0).getName());
}

TEST(QueueManipulation, AddingMultipleToQueue) {
	PriorityQueue queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	
	for(int i = 0; i < 5; i++) {
		queue.addOrderToQueue(order);
	}
	
	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(order.getName(), queue.getQueueFromIndex(i).getName());
	}
}

TEST(QueueManipulation, CreatingNewArray) {
	PriorityQueue queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	
	for(int i = 0; i < 20; i++) {
		queue.addOrderToQueue(order);
	}
	
	for(int i = 0; i < 20; i++) {
		EXPECT_EQ(order.getName(), queue.getQueueFromIndex(i).getName());
	}
}

TEST(QueueManipulation, CreatingMultipleNewArrays) {
	PriorityQueue queue;
	
	for(int i = 0; i < 200; i++) {
		std::stringstream ss;
		ss << i + 1 << " order\n";
		BuyOrder order(ss.str(), 100, 32.6, i);
		queue.addOrderToQueue(order);
	}
	
	for(int i = 0; i < 200; i++) {
		std::stringstream ss;
		ss << i + 1<< " order\n";
		EXPECT_EQ(ss.str(), queue.getQueueFromIndex(i).getName());
	}
}

TEST(QueuePriority, HighestPriorityOfTwoPrices) {
	PriorityQueue queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	BuyOrder order2("order 2", 100, 37.0, 2);
	BuyOrder order3("order 3", 100, 33.0, 3);
	BuyOrder order4("order 4", 100, 31.0, 4);

	queue.addOrderToQueue(order1);
	queue.addOrderToQueue(order2);
	queue.addOrderToQueue(order3);
	queue.addOrderToQueue(order4);

	EXPECT_EQ(order2.getName(), queue.getHighestPriorityOrder().getName());
}

TEST(QueuePriority, HighestPriorityOfTwoOrderTimes) {
	PriorityQueue queue;
	
	BuyOrder order1("order 1", 100, 35.0, 10);
	BuyOrder order2("order 2", 100, 35.0, 12);
	BuyOrder order3("order 3", 100, 35.0, 8);
	BuyOrder order4("order 4", 100, 35.0, 17);
	queue.addOrderToQueue(order1);
	queue.addOrderToQueue(order2);
	queue.addOrderToQueue(order3);
	queue.addOrderToQueue(order4);

	EXPECT_EQ(order3.getName(), queue.getHighestPriorityOrder().getName());
}