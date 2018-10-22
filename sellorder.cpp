#include <sellorder.h>
#include <iostream>
#include <string>

SellOrder::SellOrder() 
: m_name("EmptyOrder"), m_volume(0), m_price(0), m_orderTime(0) {

}

SellOrder::SellOrder(const SellOrder& sellorder)
: m_name(sellorder.m_name), m_volume(sellorder.m_volume), m_price(sellorder.m_price), m_orderTime(sellorder.m_orderTime) {

}

SellOrder::SellOrder(const std::string& name, int volume, double price, long orderTime)
: m_name(name), m_volume(volume), m_price(price), m_orderTime(orderTime) {
	
}

SellOrder::~SellOrder() {

}