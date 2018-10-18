#ifndef __BUYORDER__
#define __BUYORDER__

#include <iostream>
#include <string>
#include <sstream>

class BuyOrder{
	private:
		std::string m_name;
		int m_volume;
		double m_price;
		long m_orderTime;
		
	public:
		//default constructor which defines an order name as "EmptyOrder" 
		//and initialises all other variables to 0
		BuyOrder();
		
		//customised constructor which defines an order based upon 
		//the specified variables passed through the parameters
		BuyOrder(const std::string& name, int volume, double price, long orderTime);
			
		//default constructor provided by the compiler
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
		
		//prints the BuyOrder passed through the parameters
		std::string print(BuyOrder buyorder);
		
		//operator comparing the price of two orders and returns true if the current object 
		//buy order price is less than the specified 'rhs' price
		bool operator<(const BuyOrder& rhs);
		
		//assignment operator setting the member variables of the current object 
		//to the member variables of the specified 'rhs' member variables
		BuyOrder operator=(const BuyOrder& rhs);
		
		//operator which returns true if the current object 
		//and specified 'rhs' have the same member variables
		bool operator==(const BuyOrder& rhs);
		
		//operator overloading for the output stream
		friend std::ostream& operator<<(std::ostream &os, const BuyOrder &buyorder);
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

inline std::string BuyOrder::print(BuyOrder buyorder) {
	std::stringstream ss;
	ss << buyorder.getName() << " | ";
	ss << buyorder.getVolume() << " | ";
	ss << buyorder.getPrice() << " | ";
	ss << buyorder.getOrderTime();
		
	return ss.str();
}

inline bool BuyOrder::operator<(const BuyOrder& rhs) {
	if(m_price < rhs.m_price) {
		return true;
	}
	else {
		return false;
	}
}

inline BuyOrder BuyOrder::operator=(const BuyOrder& rhs) {
	m_name = rhs.m_name;
	m_volume = rhs.m_volume;
	m_price = rhs.m_price;
	m_orderTime = rhs.m_orderTime;
	
	return *this;
}

inline bool BuyOrder::operator==(const BuyOrder& rhs) {
	if (m_name == rhs.m_name &&	m_volume == rhs.m_volume && m_price == rhs.m_price && m_orderTime == rhs.m_orderTime) {
		return true;
	}
	return false;
}

inline std::ostream& operator<<(std::ostream &os, const BuyOrder &buyorder) {
	os << buyorder.m_name << " | " << buyorder.m_volume << " | " << buyorder.m_price << " | " << buyorder.m_orderTime;
	return os;
}

#endif