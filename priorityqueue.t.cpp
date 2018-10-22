#include <priorityqueue.h>
#include <buyorder.h>
#include <sellorder.h>
#include <gtest/gtest.h>

//----------------------------------------------------------------------------------------
//-----------------------------QUEUEBUYORDERCONSTRUCTOR-----------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueConstructorBuyOrder, TickerConstructor) {
	PriorityQueue<BuyOrder> queue("VOD.L");
	EXPECT_EQ("VOD.L", queue.getTicker());
}

TEST(QueueConstructorBuyOrder, CopyConstructor) {
	PriorityQueue<BuyOrder> queue1("VOD.L");
	BuyOrder order("order 1", 100, 32.6, 1);
	queue1.add(order);
	PriorityQueue<BuyOrder> queue2(queue1);
	
	EXPECT_EQ(queue1.getTicker(), queue2.getTicker());
	EXPECT_EQ(queue1.length(), queue2.length());
	for(int i = 0; i < queue1.length(); i++) {
		EXPECT_EQ(queue1.highestPriorityItem(), queue2.highestPriorityItem());	
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
	SellOrder order("order 1", 100, 32.6, 1);
	queue1.add(order);
	PriorityQueue<SellOrder> queue2(queue1);
	
	EXPECT_EQ(queue1.getTicker(), queue2.getTicker());
	EXPECT_EQ(queue1.length(), queue2.length());
	for(int i = 0; i < queue1.length(); i++) {
		EXPECT_EQ(queue1.highestPriorityItem(), queue2.highestPriorityItem());
	}
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUEBUYORDERMANIPULATOR-----------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueManipulationBuyOrder, CheckingEmptyQueue) {
	PriorityQueue<BuyOrder> queue;
	
	EXPECT_EQ(true, queue.isEmpty());
}

TEST(QueueManipulationBuyOrder, AddingToQueue) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order("order 1", 100, 32.6, 1);
	queue.add(order);
	EXPECT_EQ(order, queue.highestPriorityItem());
}

TEST(QueueManipulationBuyOrder, AddingMultipleToQueue) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order("order 1", 100, 32.6, 1);
	
	for(int i = 0; i < 5; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(order, queue.highestPriorityItem());
	}
}

TEST(QueueManipulationBuyOrder, CreatingNewQueueArray) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order("order 1", 100, 32.6, 1);
	
	for(int i = 0; i < 20; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 20; i++) {
		EXPECT_EQ(order, queue.highestPriorityItem());
	}
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUESELLORDERMANIPULATOR----------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueManipulationSellOrder, CheckingEmptyQueue) {
	PriorityQueue<SellOrder> queue;
	
	EXPECT_EQ(true, queue.isEmpty());
}

TEST(QueueManipulationSellOrder, AddingMultipleToQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 1);
	
	for(int i = 0; i < 5; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(order, queue.highestPriorityItem());
	}
}

TEST(QueueManipulationSellOrder, CreatingNewQueueArray) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 1);
	
	for(int i = 0; i < 20; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 20; i++) {
		EXPECT_EQ(order, queue.highestPriorityItem());

	}
}

TEST(QueueManipulationSellOrder, AddingToQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 1);
	queue.add(order);
	EXPECT_EQ(order, queue.highestPriorityItem());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUEBUYORDERPRIORITY--------------------------------------
//----------------------------------------------------------------------------------------

TEST(QueuePriorityBuyOrder, GetHighestPriorityByPriceOfOneOrderInQueue) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfOneOrderTime) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfTwoOrdersFirstPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 37.0, 2);
	BuyOrder order2("order 2", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfTwoOrdersSecondPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfTwoOrderTimes) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfThreeOrdersFirstPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 38.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	BuyOrder order3("order 3", 100, 35.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfThreeOrdersSecondPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 38.0, 1);
	BuyOrder order3("order 3", 100, 37.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfThreeOrdersThirdPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	BuyOrder order3("order 3", 100, 38.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3, queue.highestPriorityItem());
}

TEST(QueuePriorityBuyOrder, GetHighestPriorityOfThreeOrderTimes) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 3);
	BuyOrder order2("order 2", 100, 38.0, 2);
	BuyOrder order3("order 3", 100, 38.0, 1);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3, queue.highestPriorityItem());
}

TEST(QueuePriorityBuyOrder, RemovePriorityOrderFromQueue) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	queue.add(order1);
	queue.add(order2);
	queue.removeHighestPriorityItem();
	EXPECT_EQ(order1, queue.highestPriorityItem());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUESELLORDERPRIORITY-------------------------------------
//----------------------------------------------------------------------------------------
TEST(QueuePrioritySellOrder, GetHighestPriorityByPriceOfOneOrderInQueue) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfOneOrderTime) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfTwoOrdersFirstPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfTwoOrdersSecondPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 37.0, 2);
	SellOrder order2("order 2", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfTwoOrderTimes) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 37.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfThreeOrdersFirstPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);
	SellOrder order3("order 3", 100, 38.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfThreeOrdersSecondPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 38.0, 2);
	SellOrder order2("order 2", 100, 36.0, 1);
	SellOrder order3("order 3", 100, 37.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfThreeOrdersThirdPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 38.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);
	SellOrder order3("order 3", 100, 35.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3, queue.highestPriorityItem());
}

TEST(QueuePrioritySellOrder, GetHighestPriorityOfThreeOrderTimes) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 3);
	SellOrder order2("order 2", 100, 38.0, 2);
	SellOrder order3("order 3", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3, queue.highestPriorityItem());
}

TEST(QueuePrioritySellOrder, RemovePriorityOrderFromQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order1("order 1", 100, 37.0, 2);
	SellOrder order2("order 2", 100, 35.0, 1);
	queue.add(order1);
	queue.add(order2);
	queue.removeHighestPriorityItem();
	EXPECT_EQ(order1, queue.highestPriorityItem());
}