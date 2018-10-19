#ifndef __SELLORDER__
#define __SELLORDER__

#include <iostream>
#include <string>
#include <sstream>

class SellOrder{
	private:
		std::string m_name;
		int m_volume;
		double m_price;
		long m_orderTime;
	
	public:
		//default constructor which defines an order name as "EmptyOrder" 
		//and initialises all other variables to 0
		SellOrder();
		
		//copy constructor which assigns the membar variables of a specified 'sellorder' to
		//the current SellOrder object
		SellOrder(SellOrder& sellorder);
		
		//customised constructor which defines an order based upon 
		//the specified variables passed through the parameters
		SellOrder(const std::string& name, int volume, double price, long orderTime);
			
		//default constructor provided by the compiler
		~SellOrder();
		
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
		
		//prints the SellOrder passed through the parameters
		std::string print(SellOrder sellorder);
		
		//operator comparing the price of two orders and returns true if the current object 
		//buy order price is less than the specified 'rhs' price
		bool operator<(const SellOrder& rhs);
		
		//assignment operator setting the member variables of the current object 
		//to the member variables of the specified 'rhs' member variables
		SellOrder operator=(const SellOrder& rhs);
		
		//operator which returns true if the current object 
		//and specified 'rhs' have the same member variables
		bool operator==(const SellOrder& rhs);
		
		//operator overloading for the output stream
		friend std::ostream& operator<<(std::ostream &os, const SellOrder &sellorder);
};

inline std::string SellOrder::getName() const {
	return m_name;
}

inline void SellOrder::setName(const std::string& name) {
	m_name = name;
}

inline int SellOrder::getVolume() const {
	return m_volume;
}

inline void SellOrder::setVolume(int volume) {
	m_volume = volume;
}

inline double SellOrder::getPrice() const {
	return m_price;
}

inline void SellOrder::setPrice(double price) {
	m_price = price;
}

inline long SellOrder::getOrderTime() const {
	return m_orderTime;
}

inline void SellOrder::setOrderTime(long orderTime) {
	m_orderTime = orderTime;
}

inline std::string SellOrder::print(SellOrder sellorder) {
	std::stringstream ss;
	ss << sellorder.getName() << " | ";
	ss << sellorder.getVolume() << " | ";
	ss << sellorder.getPrice() << " | ";
	ss << sellorder.getOrderTime();
		
	return ss.str();
}

inline bool SellOrder::operator<(const SellOrder& rhs) {
	return m_price < rhs.m_price;
}

inline SellOrder SellOrder::operator=(const SellOrder& rhs) {
	m_name = rhs.m_name;
	m_volume = rhs.m_volume;
	m_price = rhs.m_price;
	m_orderTime = rhs.m_orderTime;
	
	return *this;
}

inline bool SellOrder::operator==(const SellOrder& rhs) {
	if (m_name == rhs.m_name &&	m_volume == rhs.m_volume && m_price == rhs.m_price && m_orderTime == rhs.m_orderTime) {
		return true;
	}
	return false;
}

inline std::ostream& operator<<(std::ostream &os, const SellOrder &sellorder) {
	os << sellorder.m_name << " | " << sellorder.m_volume << " | " << sellorder.m_price << " | " << sellorder.m_orderTime;
	return os;
}

#endif