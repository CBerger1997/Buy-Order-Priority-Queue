#include <priorityqueue.h>
#include <buyorder.h>
#include <sellorder.h>
#include <gtest/gtest.h>
#include <sstream>
#include <string>

//----------------------------------------------------------------------------------------
//-----------------------------QUEUEBUYORDERCONSTRUCTOR-----------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueConstructorBuyOrder, TickerConstructor) {
	PriorityQueue<BuyOrder> queue("VOD.L");
	EXPECT_EQ("VOD.L", queue.getTicker());
}

TEST(QueueConstructorBuyOrder, CopyConstructor) {
	PriorityQueue<BuyOrder> queue1("VOD.L");
	BuyOrder order("order 1", 100, 32.6, 123456789);
	queue1.add(order);
	PriorityQueue<BuyOrder> queue2(queue1);
	
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
//-----------------------------QUEUESELLORDERCONSTRUCTOR----------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueConstructorSellOrder, TickerConstructor) {
	PriorityQueue<SellOrder> queue("VOD.L");
	EXPECT_EQ("VOD.L", queue.getTicker());
}

TEST(QueueConstructorSellOrder, CopyConstructor) {
	PriorityQueue<SellOrder> queue1("VOD.L");
	SellOrder order("order 1", 100, 32.6, 123456789);
	queue1.add(order);
	PriorityQueue<SellOrder> queue2(queue1);
	
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
//-----------------------------QUEUEBUYORDERMANIPULATOR-----------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueManipulationBuyOrder, CHeckingEmptyQueue) {
	PriorityQueue<BuyOrder> queue;
	
	EXPECT_EQ("EmptyOrder", queue.getOrderFromIndex(0).getName());
}

TEST(QueueManipulationBuyOrder, AddingToQueue) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	queue.add(order);
	EXPECT_EQ(order.getName(), queue.getOrderFromIndex(0).getName());
	EXPECT_EQ(order.getVolume(), queue.getOrderFromIndex(0).getVolume());
	EXPECT_EQ(order.getPrice(), queue.getOrderFromIndex(0).getPrice());
	EXPECT_EQ(order.getOrderTime(), queue.getOrderFromIndex(0).getOrderTime());
}

TEST(QueueManipulationBuyOrder, AddingMultipleToQueue) {
	PriorityQueue<BuyOrder> queue;
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

TEST(QueueManipulationBuyOrder, CreatingNewQueueArray) {
	PriorityQueue<BuyOrder> queue;
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

TEST(QueueManipulationBuyOrder, CreatingMultipleNewQueueArrays) {
	PriorityQueue<BuyOrder> queue;
	
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
//-----------------------------QUEUESELLORDERMANIPULATOR----------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueManipulationSellOrder, CHeckingEmptyQueue) {
	PriorityQueue<SellOrder> queue;
	
	EXPECT_EQ("EmptyOrder", queue.getOrderFromIndex(0).getName());
}

TEST(QueueManipulationSellOrder, AddingMultipleToQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 123456789);
	
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

TEST(QueueManipulationSellOrder, CreatingNewQueueArray) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 123456789);
	
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

TEST(QueueManipulationSellOrder, CreatingMultipleNewQueueArrays) {
	PriorityQueue<SellOrder> queue;
	
	for(int i = 0; i < 200; i++) {
		std::stringstream ss;
		ss << i + 1 << " order";
		SellOrder order(ss.str(), 100, 32.6, i);
		queue.add(order);
	}
	
	for(int i = 0; i < 200; i++) {
		std::stringstream ss;
		ss << i + 1<< " order";
		EXPECT_EQ(ss.str(), queue.getOrderFromIndex(i).getName());
	}	
}

TEST(QueueManipulationSellOrder, AddingToQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 123456789);
	queue.add(order);
	EXPECT_EQ(order.getName(), queue.getOrderFromIndex(0).getName());
	EXPECT_EQ(order.getVolume(), queue.getOrderFromIndex(0).getVolume());
	EXPECT_EQ(order.getPrice(), queue.getOrderFromIndex(0).getPrice());
	EXPECT_EQ(order.getOrderTime(), queue.getOrderFromIndex(0).getOrderTime());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUEBUYORDERPRIORITY--------------------------------------
//----------------------------------------------------------------------------------------

TEST(QueuePriorityBuyOrder, GetHighestPriorityByPriceOfOneOrderInQueue) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfOneOrderTime) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfTwoPrices) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfTwoOrderTimes) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePriorityBuyOrder, RemovePriorityOrderFromQueue) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	queue.add(order1);
	queue.add(order2);
	queue.removeHighestPriorityOrder();
	EXPECT_EQ("EmptyOrder", queue.getOrderFromIndex(1).getName());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUESELLORDERPRIORITY-------------------------------------
//----------------------------------------------------------------------------------------
TEST(QueuePrioritySellOrder, GetHighestPriorityByPriceOfOneOrderInQueue) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfOneOrderTime) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfTwoPrices) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order1.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfTwoOrderTimes) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 37.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2.getName(), queue.highestPriorityOrder().getName());
}

TEST(QueuePrioritySellOrder, RemovePriorityOrderFromQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order1("order 1", 100, 35.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);
	queue.add(order1);
	queue.add(order2);
	queue.removeHighestPriorityOrder();
	EXPECT_EQ("EmptyOrder", queue.getOrderFromIndex(1).getName());
}