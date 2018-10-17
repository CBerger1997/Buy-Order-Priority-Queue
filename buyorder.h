#ifndef __BUYORDER__
#define __BUYORDER__

#include <iostream>
#include <string>

class BuyOrder{
	private:
		std::string m_name;
		int m_volume;
		double m_price;
		int m_orderTime;
		
	public:
		BuyOrder();
		
		BuyOrder(const std::string& name, int volume, double price, int orderTime);
		
		BuyOrder(const std::string& name);
		
		~BuyOrder();
		
		//returns the name of the order
		inline std::string getName() const {return m_name;} 
		
		//sets the name of the order
		inline void setName(const std::string& name) {m_name = name;}
		
		//returns the volume of the order
		inline int getVolume() const {return m_volume;}
		
		//sets the volume of the order
		inline void setVolume(int volume) {m_volume = volume;}
		
		//returns the price of the order
		inline double getPrice() const {return m_price;}
		
		//sets the price of the order
		inline void setPrice(double price) {m_price = price;}
		
		//returns the order time of the order
		inline int getOrderTime() const {return m_orderTime;}
		
		//sets the order time of the order
		inline void setOrderTime(int orderTime) {m_orderTime = orderTime;}
};

#endif