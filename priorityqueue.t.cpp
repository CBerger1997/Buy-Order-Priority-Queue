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
		EXPECT_EQ(queue1.highestPriorityData().getName(), queue2.highestPriorityData().getName());
		EXPECT_EQ(queue1.highestPriorityData().getVolume(), queue2.highestPriorityData().getVolume());
		EXPECT_EQ(queue1.highestPriorityData().getPrice(), queue2.highestPriorityData().getPrice());
		EXPECT_EQ(queue1.highestPriorityData().getOrderTime(), queue2.highestPriorityData().getOrderTime());	
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
		EXPECT_EQ(queue1.highestPriorityData().getName(), queue2.highestPriorityData().getName());
		EXPECT_EQ(queue1.highestPriorityData().getVolume(), queue2.highestPriorityData().getVolume());
		EXPECT_EQ(queue1.highestPriorityData().getPrice(), queue2.highestPriorityData().getPrice());
		EXPECT_EQ(queue1.highestPriorityData().getOrderTime(), queue2.highestPriorityData().getOrderTime());	
	}
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUEBUYORDERMANIPULATOR-----------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueManipulationBuyOrder, CHeckingEmptyQueue) {
	PriorityQueue<BuyOrder> queue;
	
	EXPECT_EQ("EmptyOrder", queue.highestPriorityData().getName());
}

TEST(QueueManipulationBuyOrder, AddingToQueue) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	queue.add(order);
	EXPECT_EQ(order.getName(), queue.highestPriorityData().getName());
	EXPECT_EQ(order.getVolume(), queue.highestPriorityData().getVolume());
	EXPECT_EQ(order.getPrice(), queue.highestPriorityData().getPrice());
	EXPECT_EQ(order.getOrderTime(), queue.highestPriorityData().getOrderTime());
}

TEST(QueueManipulationBuyOrder, AddingMultipleToQueue) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	
	for(int i = 0; i < 5; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(order.getName(), queue.highestPriorityData().getName());
		EXPECT_EQ(order.getVolume(), queue.highestPriorityData().getVolume());
		EXPECT_EQ(order.getPrice(), queue.highestPriorityData().getPrice());
		EXPECT_EQ(order.getOrderTime(), queue.highestPriorityData().getOrderTime());
	}
}

TEST(QueueManipulationBuyOrder, CreatingNewQueueArray) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order("order 1", 100, 32.6, 123456789);
	
	for(int i = 0; i < 20; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 20; i++) {
		EXPECT_EQ(order.getName(), queue.highestPriorityData().getName());
		EXPECT_EQ(order.getVolume(), queue.highestPriorityData().getVolume());
		EXPECT_EQ(order.getPrice(), queue.highestPriorityData().getPrice());
		EXPECT_EQ(order.getOrderTime(), queue.highestPriorityData().getOrderTime());

	}
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUESELLORDERMANIPULATOR----------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueManipulationSellOrder, CHeckingEmptyQueue) {
	PriorityQueue<SellOrder> queue;
	
	EXPECT_EQ("EmptyOrder", queue.highestPriorityData().getName());
	
	queue.print();
}

TEST(QueueManipulationSellOrder, AddingMultipleToQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 123456789);
	
	for(int i = 0; i < 5; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(order.getName(), queue.highestPriorityData().getName());
		EXPECT_EQ(order.getVolume(), queue.highestPriorityData().getVolume());
		EXPECT_EQ(order.getPrice(), queue.highestPriorityData().getPrice());
		EXPECT_EQ(order.getOrderTime(), queue.highestPriorityData().getOrderTime());
	}
}

TEST(QueueManipulationSellOrder, CreatingNewQueueArray) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 123456789);
	
	for(int i = 0; i < 20; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 20; i++) {
		EXPECT_EQ(order.getName(), queue.highestPriorityData().getName());
		EXPECT_EQ(order.getVolume(), queue.highestPriorityData().getVolume());
		EXPECT_EQ(order.getPrice(), queue.highestPriorityData().getPrice());
		EXPECT_EQ(order.getOrderTime(), queue.highestPriorityData().getOrderTime());

	}
}

TEST(QueueManipulationSellOrder, AddingToQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 123456789);
	queue.add(order);
	EXPECT_EQ(order.getName(), queue.highestPriorityData().getName());
	EXPECT_EQ(order.getVolume(), queue.highestPriorityData().getVolume());
	EXPECT_EQ(order.getPrice(), queue.highestPriorityData().getPrice());
	EXPECT_EQ(order.getOrderTime(), queue.highestPriorityData().getOrderTime());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUEBUYORDERPRIORITY--------------------------------------
//----------------------------------------------------------------------------------------

TEST(QueuePriorityBuyOrder, GetHighestPriorityByPriceOfOneOrderInQueue) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfOneOrderTime) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfTwoPrices) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfTwoOrderTimes) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfThreePricesFirstPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 38.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	BuyOrder order3("order 3", 100, 35.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order1.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfThreePricesSecondPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 38.0, 1);
	BuyOrder order3("order 3", 100, 37.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order2.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfThreePricesThirdPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	BuyOrder order3("order 3", 100, 38.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfThreeOrderTimes) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 3);
	BuyOrder order2("order 2", 100, 38.0, 2);
	BuyOrder order3("order 3", 100, 38.0, 1);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePriorityBuyOrder, RemovePriorityOrderFromQueue) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	queue.add(order1);
	queue.add(order2);
	queue.removeHighestPriorityData();
	EXPECT_EQ("order 1", queue.highestPriorityData().getName());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUESELLORDERPRIORITY-------------------------------------
//----------------------------------------------------------------------------------------
TEST(QueuePrioritySellOrder, GetHighestPriorityByPriceOfOneOrderInQueue) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfOneOrderTime) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfTwoPrices) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order1.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfTwoOrderTimes) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 37.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfThreePricesFirstPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);
	SellOrder order3("order 3", 100, 38.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order1.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfThreePricesSecondPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 38.0, 2);
	SellOrder order2("order 2", 100, 36.0, 1);
	SellOrder order3("order 3", 100, 37.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order2.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfThreePricesThirdPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 38.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);
	SellOrder order3("order 3", 100, 35.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfThreeOrderTimes) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 3);
	SellOrder order2("order 2", 100, 38.0, 2);
	SellOrder order3("order 3", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3.getName(), queue.highestPriorityData().getName());
}

TEST(QueuePrioritySellOrder, RemovePriorityOrderFromQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order1("order 1", 100, 37.0, 2);
	SellOrder order2("order 2", 100, 35.0, 1);
	queue.add(order1);
	queue.add(order2);
	queue.removeHighestPriorityData();
	EXPECT_EQ("order 1", queue.highestPriorityData().getName());
}