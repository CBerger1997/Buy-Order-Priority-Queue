#include <priorityqueue.h>
#include <buyorder.h>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

//----------------------------------------------------------------------------------------

TEST(QueueConstructor, TickerConstructor) {
	PriorityQueue queue("VOD.L");
	EXPECT_EQ("VOD.L", queue.getTicker());
}

//----------------------------------------------------------------------------------------

TEST(QueueManipulation, EmptyQueue) {
	PriorityQueue queue;
	
	EXPECT_EQ("EMPTYORDER", queue.getOrderFromIndex(0).getName());
}

TEST(QueueManipulation, AddingToQueue) {
	PriorityQueue queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	queue.addOrderToQueue(order);
	EXPECT_EQ(order.getName(), queue.getOrderFromIndex(0).getName());
}

TEST(QueueManipulation, AddingMultipleToQueue) {
	PriorityQueue queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	
	for(int i = 0; i < 5; i++) {
		queue.addOrderToQueue(order);
	}
	
	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(order.getName(), queue.getOrderFromIndex(i).getName());
	}
}

TEST(QueueManipulation, CreatingNewArray) {
	PriorityQueue queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	
	for(int i = 0; i < 20; i++) {
		queue.addOrderToQueue(order);
	}
	
	for(int i = 0; i < 20; i++) {
		EXPECT_EQ(order.getName(), queue.getOrderFromIndex(i).getName());
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
		EXPECT_EQ(ss.str(), queue.getOrderFromIndex(i).getName());
	}
	
	//queue.print();
}

//----------------------------------------------------------------------------------------

TEST(QueuePriority, GetHighestPriorityOfOnePrice) {
	PriorityQueue queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.addOrderToQueue(order1);

	EXPECT_EQ(order1.getName(), queue.HighestPriorityOrder().getName());
}

TEST(QueuePriority, GetHighestPriorityOfOneOrderTime) {
	PriorityQueue queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.addOrderToQueue(order1);

	EXPECT_EQ(order1.getName(), queue.HighestPriorityOrder().getName());
}

TEST(QueuePriority, GetHighestPriorityOfTwoPrices) {
	PriorityQueue queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);

	queue.addOrderToQueue(order1);
	queue.addOrderToQueue(order2);

	EXPECT_EQ(order2.getName(), queue.HighestPriorityOrder().getName());
}

TEST(QueuePriority, GetHighestPriorityOfTwoOrderTimes) {
	PriorityQueue queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);

	queue.addOrderToQueue(order1);
	queue.addOrderToQueue(order2);

	EXPECT_EQ(order2.getName(), queue.HighestPriorityOrder().getName());
}


TEST(QueuePriority, RemovePriorityOrderFromQueue) {
	PriorityQueue queue;
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	queue.addOrderToQueue(order1);
	queue.addOrderToQueue(order2);
	queue.removeHighestPriorityOrder();
	EXPECT_EQ("EmptyOrder", queue.getOrderFromIndex(1).getName());
}