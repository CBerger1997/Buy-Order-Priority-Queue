#include <sellorder.h>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

TEST(SellOrderConstructor, ValidInput) {
	SellOrder s1 ("order 1", 100, 32.56, 123456789);
	EXPECT_EQ("order 1", s1.getName());
	EXPECT_EQ(100, s1.getVolume());
	EXPECT_EQ(32.56, s1.getPrice());
	EXPECT_EQ(123456789, s1.getOrderTime());
}

TEST(SellOrderConstructor, ZeroInput) {
	SellOrder s1 ("", 0, 0.0, 0);
	EXPECT_EQ("", s1.getName());
	EXPECT_EQ(0, s1.getVolume());
	EXPECT_EQ(0.0, s1.getPrice());
	EXPECT_EQ(0, s1.getOrderTime());
}

TEST(SellOrderConstructor, NegativeInput) {
	SellOrder s1 ("", -100, -32.56, -123456789);
	EXPECT_EQ("", s1.getName());
	EXPECT_EQ(-100, s1.getVolume());
	EXPECT_EQ(-32.56, s1.getPrice());
	EXPECT_EQ(-123456789, s1.getOrderTime());
}

TEST(SellOrderConstructor, CopyConstructor) {
	SellOrder s1 ("order 1", 100, 32.56, 123456789);
	SellOrder s2(s1);
	EXPECT_EQ(s1.getName(),s2.getName());
	EXPECT_EQ(s1.getVolume(),s2.getVolume());
	EXPECT_EQ(s1.getPrice(),s2.getPrice());
	EXPECT_EQ(s1.getOrderTime(),s2.getOrderTime());
}

TEST(SellOrderCopyConstructor, ValidInput) {
	SellOrder s1 ("order 1", 100, 32.56, 123456789);
	SellOrder s2(s1);
	EXPECT_EQ("order 1", s2.getName());
	EXPECT_EQ(100, s2.getVolume());
	EXPECT_EQ(32.56, s2.getPrice());
	EXPECT_EQ(123456789, s2.getOrderTime());
}

TEST(SellOrderCopyConstructor, ZeroInput) {
	SellOrder s1 ("", 0, 0.0, 0);
	SellOrder s2(s1);
	EXPECT_EQ("", s2.getName());
	EXPECT_EQ(0, s2.getVolume());
	EXPECT_EQ(0.0, s2.getPrice());
	EXPECT_EQ(0, s2.getOrderTime());
}

TEST(SellOrderCopyConstructor, NegativeInput) {
	SellOrder s1 ("", -100, -32.56, -123456789);
	SellOrder s2(s1);
	EXPECT_EQ("", s2.getName());
	EXPECT_EQ(-100, s2.getVolume());
	EXPECT_EQ(-32.56, s2.getPrice());
	EXPECT_EQ(-123456789, s2.getOrderTime());
}

//----------------------------------------------------------------------------------------

TEST(SellOrderObjectOutput, ObjectStream) {
	SellOrder s1 ("order 1", 100, 32.56, 123456789);
			
	EXPECT_EQ("order 1 | 100 | 32.56 | 123456789", s1.print(s1));
}