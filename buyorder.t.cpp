#include <buyorder.h>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

TEST(Constructor, ValidInput) {
	BuyOrder b1 ("order 1", 100, 32.56, 123456789);
	EXPECT_EQ("order 1", b1.getName());
	EXPECT_EQ(100, b1.getVolume());
	EXPECT_EQ(32.56, b1.getPrice());
	EXPECT_EQ(123456789, b1.getOrderTime());
}

TEST(Constructor, ZeroInput) {
	BuyOrder b1 ("", 0, 0.0, 0);
	EXPECT_EQ("", b1.getName());
	EXPECT_EQ(0, b1.getVolume());
	EXPECT_EQ(0.0, b1.getPrice());
	EXPECT_EQ(0, b1.getOrderTime());
}

TEST(Constructor, NegativeInput) {
	BuyOrder b1 ("", -100, -32.56, -123456789);
	EXPECT_EQ("", b1.getName());
	EXPECT_EQ(-100, b1.getVolume());
	EXPECT_EQ(-32.56, b1.getPrice());
	EXPECT_EQ(-123456789, b1.getOrderTime());
}

TEST(Constructor, CopyConstructor) {
	BuyOrder b1 ("order 1", 100, 32.56, 123456789);
	BuyOrder b2(b1);
	EXPECT_EQ(b1.getName(),b2.getName());
	EXPECT_EQ(b1.getVolume(),b2.getVolume());
	EXPECT_EQ(b1.getPrice(),b2.getPrice());
	EXPECT_EQ(b1.getOrderTime(),b2.getOrderTime());
}

TEST(ObjectOutput, ObjectStream) {
	BuyOrder b1 ("order 1", 100, 32.56, 123456789);
			
	EXPECT_EQ("order 1 | 100 | 32.56 | 123456789", b1.print(b1));
}