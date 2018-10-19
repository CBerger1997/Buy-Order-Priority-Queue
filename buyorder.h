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
		// Constructs a BuyOrder object
		BuyOrder();
		
		// Constructs a BuyOrder object and sets memeber values equalt to the specified 'buyorder'
		BuyOrder(BuyOrder& buyorder);
		
		// Constructs a BuyOrder based upon the specified variables passed through the parameters
		BuyOrder(const std::string& name, int volume, double price, long orderTime);
			
		// Default constructor provided by the compiler
		~BuyOrder();
		
		// Returns the name of the order
		std::string getName() const;  
		
		// Sets the name of the order
		void setName(const std::string& name);
		
		// Returns the volume of the order
		int getVolume() const;
		
		// Sets the volume of the order
		void setVolume(int volume);
		
		// Returns the price of the order
		double getPrice() const;
		
		// Sets the price of the order
		void setPrice(double price);
		
		// Returns the order time of the order
		long getOrderTime() const;
		
		// Sets the order time of the order
		void setOrderTime(long orderTime);
		
		// Prints the BuyOrder passed through the parameters
		std::string print(BuyOrder buyorder);
		
		// Operator comparing the price of two orders and returns true if the current object 
		// Buy order price is less than the specified 'rhs' price
		// Or if the prices are equal then returns true if the order time of this object is
		// Less than that of the specified 'rhs' otherwise returns false
		bool operator<(const BuyOrder& rhs);
		
		// Assignment operator setting the member variables of the current object 
		// To the member variables of the specified 'rhs' member variables
		BuyOrder operator=(const BuyOrder& rhs);
		
		// Operator which returns true if the current object 
		// And specified 'rhs' have the same member variables
		bool operator==(const BuyOrder& rhs);
		
		// Operator overloading for the output stream
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
	if (m_price == rhs.m_price) {
		if (m_orderTime > rhs.m_orderTime) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (m_price < rhs.m_price) {
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