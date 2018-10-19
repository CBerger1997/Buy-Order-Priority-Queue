#include <buyorder.h>
#include <iostream>
#include <string>

BuyOrder::BuyOrder() {
	m_name = "EmptyOrder";
	m_volume = 0;
	m_price = 0;
	m_orderTime = 0;
}

BuyOrder::BuyOrder(BuyOrder& buyorder) {
	m_name = buyorder.m_name;
	m_volume = buyorder.m_volume;
	m_price = buyorder.m_price;
	m_orderTime = buyorder.m_orderTime;
}

BuyOrder::BuyOrder(const std::string& name, int volume, double price, long orderTime)
: m_name(name), m_volume(volume), m_price(price), m_orderTime(orderTime) {
	
}

BuyOrder::~BuyOrder() {
	
}