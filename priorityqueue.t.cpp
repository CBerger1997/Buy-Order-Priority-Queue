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
	EXPECT_EQ(queue1.highestPriorityItem(), queue2.highestPriorityItem());	
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
	EXPECT_EQ(queue1.highestPriorityItem(), queue2.highestPriorityItem());
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
	EXPECT_EQ(1, queue.length());
}

TEST(QueueManipulationBuyOrder, AddingMultipleToQueue) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order("order 1", 100, 32.6, 1);
	
	for(int i = 0; i < 5; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(5, queue.length());
	}
}

TEST(QueueManipulationBuyOrder, CreatingNewQueueArray) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order("order 1", 100, 32.6, 1);
	
	for(int i = 0; i < 20; i++) {
		queue.add(order);
	}
	
	EXPECT_EQ(20, queue.length());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUESELLORDERMANIPULATOR----------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueManipulationSellOrder, CheckingEmptyQueue) {
	PriorityQueue<SellOrder> queue;
	
	EXPECT_EQ(true, queue.isEmpty());
}

TEST(QueueManipulationSellOrder, AddingToQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 1);
	queue.add(order);
	EXPECT_EQ(1, queue.length());
}

TEST(QueueManipulationSellOrder, AddingMultipleToQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 1);
	
	for(int i = 0; i < 5; i++) {
		queue.add(order);
	}
	
	for(int i = 0; i < 5; i++) {
		EXPECT_EQ(5, queue.length());
	}
}

TEST(QueueManipulationSellOrder, CreatingNewQueueArray) {
	PriorityQueue<SellOrder> queue;
	SellOrder order("order 1", 100, 32.6, 1);
	
	for(int i = 0; i < 20; i++) {
		queue.add(order);
	}
	
	EXPECT_EQ(20, queue.length());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUEBUYORDERPRICEPRIORITY--------------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueOrderPricePriorityBuyOrder, GetHighestPriorityByPriceOfOneOrderInQueue) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderPricePriorityBuyOrder, GetHighestPriorityOfTwoOrdersFirstPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 37.0, 2);
	BuyOrder order2("order 2", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderPricePriorityBuyOrder, GetHighestPriorityOfTwoOrdersSecondPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueueOrderPricePriorityBuyOrder, GetHighestPriorityOfThreeOrdersFirstPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 38.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	BuyOrder order3("order 3", 100, 35.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderPricePriorityBuyOrder, GetHighestPriorityOfThreeOrdersSecondPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 38.0, 1);
	BuyOrder order3("order 3", 100, 37.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueueOrderPricePriorityBuyOrder, GetHighestPriorityOfThreeOrdersThirdPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	BuyOrder order3("order 3", 100, 38.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3, queue.highestPriorityItem());
}

TEST(QueueOrderPricePriorityBuyOrder, RemovePriorityOrderFromQueue) {
	PriorityQueue<BuyOrder> queue;
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 37.0, 1);
	queue.add(order1);
	queue.add(order2);
	queue.removeHighestPriorityItem();
	EXPECT_EQ(order1, queue.highestPriorityItem());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUEBUYORDERTIMEPRIORITY--------------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueOrderTimePriorityBuyOrder, GetHighestPriorityOfOneOrderTime) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderTimePriorityBuyOrder, GetHighestPriorityOfTwoOrderTimesFirstPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	BuyOrder order2("order 2", 100, 35.0, 2);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderTimePriorityBuyOrder, GetHighestPriorityOfTwoOrderTimesSecondPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 2);
	BuyOrder order2("order 2", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueueOrderTimePriorityBuyOrder, GetHighestPriorityOfThreeOrderTimesFirstPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 1);
	BuyOrder order2("order 2", 100, 35.0, 2);
	BuyOrder order3("order 3", 100, 35.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderTimePriorityBuyOrder, GetHighestPriorityOfThreeOrderTimesSecondPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 3);
	BuyOrder order2("order 2", 100, 35.0, 1);
	BuyOrder order3("order 3", 100, 35.0, 2);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueueOrderTimePriorityBuyOrder, GetHighestPriorityOfThreeOrderTimesThirdPosition) {
	PriorityQueue<BuyOrder> queue;
	
	BuyOrder order1("order 1", 100, 35.0, 3);
	BuyOrder order2("order 2", 100, 35.0, 2);
	BuyOrder order3("order 3", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3, queue.highestPriorityItem());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUESELLORDERPRICEPRIORITY-------------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueOrderPricePrioritySellOrder, GetHighestPriorityByPriceOfOneOrderInQueue) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderPricePrioritySellOrder, GetHighestPriorityOfTwoOrdersFirstPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderPricePrioritySellOrder, GetHighestPriorityOfTwoOrdersSecondPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 37.0, 2);
	SellOrder order2("order 2", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueueOrderPricePrioritySellOrder, GetHighestPriorityOfThreeOrdersFirstPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);
	SellOrder order3("order 3", 100, 38.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderPricePrioritySellOrder, GetHighestPriorityOfThreeOrdersSecondPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 38.0, 2);
	SellOrder order2("order 2", 100, 36.0, 1);
	SellOrder order3("order 3", 100, 37.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueueOrderPricePrioritySellOrder, GetHighestPriorityOfThreeOrdersThirdPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 38.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);
	SellOrder order3("order 3", 100, 35.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3, queue.highestPriorityItem());
}

TEST(QueueOrderPricePrioritySellOrder, RemovePriorityOrderFromQueue) {
	PriorityQueue<SellOrder> queue;
	SellOrder order1("order 1", 100, 37.0, 2);
	SellOrder order2("order 2", 100, 35.0, 1);
	queue.add(order1);
	queue.add(order2);
	queue.removeHighestPriorityItem();
	EXPECT_EQ(order1, queue.highestPriorityItem());
}

//----------------------------------------------------------------------------------------
//-----------------------------QUEUESELLORDERTIMEPRIORITY-------------------------------------
//----------------------------------------------------------------------------------------

TEST(QueueOrderTimePrioritySellOrder, GetHighestPriorityOfOneOrderTime) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 1);
	
	queue.add(order1);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderTimePrioritySellOrder, GetHighestPriorityOfTwoOrderTimesFirstPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 37.0, 1);
	SellOrder order2("order 2", 100, 37.0, 2);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderTimePrioritySellOrder, GetHighestPriorityOfTwoOrderTimesSecondPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 37.0, 2);
	SellOrder order2("order 2", 100, 37.0, 1);

	queue.add(order1);
	queue.add(order2);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueueOrderTimePrioritySellOrder, GetHighestPriorityOfThreeOrderTimesFirstPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 1);
	SellOrder order2("order 2", 100, 35.0, 2);
	SellOrder order3("order 3", 100, 35.0, 3);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order1, queue.highestPriorityItem());
}

TEST(QueueOrderTimePrioritySellOrder, GetHighestPriorityOfThreeOrderTimesSecondPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 3);
	SellOrder order2("order 2", 100, 35.0, 1);
	SellOrder order3("order 3", 100, 35.0, 2);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order2, queue.highestPriorityItem());
}

TEST(QueueOrderTimePrioritySellOrder, GetHighestPriorityOfThreeOrderTimesThirdPosition) {
	PriorityQueue<SellOrder> queue;
	
	SellOrder order1("order 1", 100, 35.0, 3);
	SellOrder order2("order 2", 100, 35.0, 2);
	SellOrder order3("order 3", 100, 35.0, 1);

	queue.add(order1);
	queue.add(order2);
	queue.add(order3);

	EXPECT_EQ(order3, queue.highestPriorityItem());
}