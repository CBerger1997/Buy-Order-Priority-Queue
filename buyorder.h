#ifndef __BUYORDER__
#define __BUYORDER__

#include <iostream>
#include <string>

class BuyOrder{
	private:
		std::string m_name;
		int m_volume;
		double m_price;
		long m_orderTime;
		
	public:
		BuyOrder();
		
		BuyOrder(const std::string& name, int volume, double price, long orderTime);
				
		~BuyOrder();
		
		//returns the name of the order
		std::string getName() const;  
		
		//sets the name of the order
		void setName(const std::string& name);
		
		//returns the volume of the order
		int getVolume() const;
		
		//sets the volume of the order
		void setVolume(int volume);
		
		//returns the price of the order
		double getPrice() const;
		
		//sets the price of the order
		void setPrice(double price);
		
		//returns the order time of the order
		long getOrderTime() const;
		
		//sets the order time of the order
		void setOrderTime(long orderTime);
};

inline std::string BuyOrder::getName() const {
	return m_name;
}

inline void BuyOrder::setName(const std::string& name) {
	m_name = name;
}

inline int BuyOrder::getVolume() const {
	return m_volume;
}

inline void BuyOrder::setVolume(int volume) {
	m_volume = volume;
}

inline double BuyOrder::getPrice() const {
	return m_price;
}

inline void BuyOrder::setPrice(double price) {
	m_price = price;
}

inline long BuyOrder::getOrderTime() const {
	return m_orderTime;
}

inline void BuyOrder::setOrderTime(long orderTime) {
	m_orderTime = orderTime;
}
#endif