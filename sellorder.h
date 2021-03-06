#ifndef __SELLORDER__
#define __SELLORDER__

#include <string>
#include <sstream>

class SellOrder{
	private:
		std::string m_name;
		int m_volume;
		double m_price;
		long m_orderTime;
	
	public:
		// Constructs a SellOrder object
		SellOrder();
		
		// Constructs a SellOrder object and sets memeber values equalt to the specified 'sellorder'
		SellOrder(const SellOrder& sellorder);
		
		// Constructs a SellOrder based upon the specified variables passed through the parameters
		SellOrder(const std::string& name, int volume, double price, long orderTime);
			
		// Default constructor provided by the compiler
		~SellOrder();
		
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
		
		// Prints the SellOrder passed through the parameters
		std::string print(SellOrder sellorder);
		
		// Operator comparing the price of two orders and returns true if the current object 
		// Sell order price is greater than the specified 'rhs' price
		// If the prices are equal then returns true if the order time of this object is
		// Less than that of the specified 'rhs' otherwise returns false
		bool operator<(const SellOrder& rhs);

		// Assignment operator setting the member variables of the current object 
		// To the member variables of the specified 'rhs' member variables
		SellOrder operator=(const SellOrder& rhs);
		
		// Operator which returns true if the current object 
		// And specified 'rhs' have the same member variables
		bool operator==(const SellOrder& rhs) const;
		
		// Operator overloading for the output stream
		friend std::ostream& operator<<(std::ostream &os, const SellOrder &sellorder);
};

//----------------------------------------------------------------------------------------
//----------------------------------INLINE FUNCTIONS--------------------------------------
//----------------------------------------------------------------------------------------

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
	if (this->getName() == "EmptyOrder") {
		return true;
	}
	else if (rhs.getName() == "EmptyOrder") {
		return false;
	}
	else if (m_price == rhs.m_price) {
		return m_orderTime > rhs.m_orderTime;
	}
	else {
		return m_price > rhs.m_price;
	}
}


inline SellOrder SellOrder::operator=(const SellOrder& rhs) {
	m_name = rhs.m_name;
	m_volume = rhs.m_volume;
	m_price = rhs.m_price;
	m_orderTime = rhs.m_orderTime;
	
	return *this;
}

inline bool SellOrder::operator==(const SellOrder& rhs) const {
	if (this->m_name == rhs.m_name && this->m_volume == rhs.m_volume && this->m_price == rhs.m_price && this->m_orderTime == rhs.m_orderTime) {
		return true;
	}
	return false;
}

inline std::ostream& operator<<(std::ostream &os, const SellOrder &sellorder) {
	os << sellorder.m_name << " | " << sellorder.m_volume << " | " << sellorder.m_price << " | " << sellorder.m_orderTime;
	return os;
}

#endif