#include <buyorder.h>
#include <iostream>
#include <string>

BuyOrder::BuyOrder() {
}

BuyOrder::BuyOrder(const std::string& name, int volume, double price, int orderTime)
: m_name(name), m_volume(volume), m_price(price), m_orderTime(orderTime) {
	
}

BuyOrder::BuyOrder(const std::string& name)
: m_name(name), m_volume(0), m_price(0), m_orderTime(0) {
	
}

BuyOrder::~BuyOrder() {
	
}