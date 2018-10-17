#include <buyorder.h>
#include <gtest/gtest.h>

TEST(Constructor, orderName) {
	BuyOrder b1 ("order 1", 100, 32.56, 123456789);
	EXPECT_EQ("order 1", b1.getName());
}

TEST(Constructor, orderVolume) {
	BuyOrder b1 ("order 1", 100, 32.56, 123456789);
	EXPECT_EQ(100, b1.getVolume());
}

TEST(Constructor, orderPrice) {
	BuyOrder b1 ("order 1", 100, 32.56, 123456789);
	EXPECT_EQ(32.56, b1.getPrice());
}

TEST(Constructor, orderTime) {
	BuyOrder b1 ("order 1", 100, 32.56, 123456789);
	EXPECT_EQ(123456789, b1.getOrderTime());
}