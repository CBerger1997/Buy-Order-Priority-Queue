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

TEST(QueueConstructor, CopyConstructor) {
	PriorityQueue queue1("VOD.L");
	BuyOrder order("order 1", 100, 32.6, 123456789);
	queue1.add(order);
	PriorityQueue queue2(queue1);
	
	EXPECT_EQ(queue1.getTicker(), queue2.getTicker());
	EXPECT_EQ(queue1.length(), queue2.length());
	for(int i = 0; i < queue1.length(); i++) {
		EXPECT_EQ(queue1.getOrderFromIndex(i).getName(), queue2.getOrderFromIndex(i).getName());
		EXPECT_EQ(queue1.getOrderFromIndex(i).getVolume(), queue2.getOrderFromIndex(i).getVolume());
		EXPECT_EQ(queue1.getOrderFromIndex(i).getPrice(), queue2.getOrderFromIndex(i).getPrice());
		EXPECT_EQ(queue1.getOrderFromIndex(i).getOrderTime(), queue2.getOrderFromIndex(i).getOrderTime());	
	}
}

//----------------------------------------------------------------------------------------

TEST(QueueManipulation, CHeckingEmptyQueue) {
	PriorityQueue queue;
	
	EXPECT_EQ("EMPTYORDER", queue.getOrderFromIndex(0).getName());
}

TEST(QueueManipulation, AddingToQueue) {
	PriorityQueue queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	queue.add(order);
	EXPECT_EQ(order.getName(), queue.getOrderFromIndex(0).getName());
	EXPECT_EQ(order.getVolume(), queue.getOrderFromIndex(0).getVolume());
	EXPECT_EQ(order.getPrice(), queue.getOrderFromIndex(0).getPrice());
	EXPECT_EQ(order.getOrderTime(), queue.getOrderFromIndex(0).getOrderTime());
}

TEST(QueueManipulation, AddingMultipleToQueue) {
	PriorityQueue queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	
	for(int i = 0; i < 5; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(order.getName(), queue.getOrderFromIndex(i).getName());
		EXPECT_EQ(order.getVolume(), queue.getOrderFromIndex(i).getVolume());
		EXPECT_EQ(order.getPrice(), queue.getOrderFromIndex(i).getPrice());
		EXPECT_EQ(order.getOrderTime(), queue.getOrderFromIndex(i).getOrderTime());
	}
}

TEST(QueueManipulation, CreatingNewQueueArray) {
	PriorityQueue queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	
	for(int i = 0; i < 20; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 20; i++) {
		EXPECT_EQ(order.getName(), queue.getOrderFromIndex(i).getName());
		EXPECT_EQ(order.getVolume(), queue.getOrderFromIndex(i).getVolume());
		EXPECT_EQ(order.getPrice(), queue.getOrderFromIndex(i).getPrice());
		EXPECT_EQ(order.getOrderTime(), queue.getOrderFromIndex(i).getOrderTime());

	}
}

TEST(QueueManipulation, CreatingMultipleNewQueueArrays) {
	PriorityQueue queue;
	
	for(int i = 0; i < 200; i++) {
		std::stringstream ss;
		ss << i + 1 << " order\n";
		BuyOrder order(ss.str(), 100, 32.6, i);
		queue.add(order);
	}
	
	for(int i = 0; i < 200; i++) {
		std::stringstream ss;
		ss << i + 1<< " order\n";
		EXPECT_EQ(ss.str(), queue.getOrderFromIndex(i).getName());
	}
}

//----------------------------------------------------------------------------------------

TEST(QueuePriority, GetHighestPriorityByPriceOfOneOrderInQueue) {
	PriorityQueue queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePriority, GetHighestPriorityOfOneOrderTime) {
	PriorityQueue queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePriority, GetHighestPriorityOfTwoPrices) {
	PriorityQueue queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePriority, GetHighestPriorityOfTwoOrderTimes) {
	PriorityQueue queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2.getName(), queue.highestPriorityOrder().getName());
}


TEST(QueuePriority, RemovePriorityOrderFromQueue) {
	PriorityQueue queue;
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	queue.add(order1);
	queue.add(order2);
	queue.removeHighestPriorityOrder();
	EXPECT_EQ("EmptyOrder", queue.getOrderFromIndex(1).getName());
}