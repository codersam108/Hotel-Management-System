#pragma once
#include"Customer.h"
#include"Room.h"
#include"amenities.h"
#include<vector>
class Booking
{
private:
	string bookingid, bookingdate, bookingtime;
	vector<amenities>amenitieslist;
	Customer customer;
	Room room;
	float totalprice;
	
public:
	Booking(Customer customer,Room room,string bookingid, string bookingdate, string bookingtime);
	string getbookingid();
	string getbookingdate();
	string getbookingtime();
	float gettotalprice();
	string getcid();
	string getrid();
	void settotalprice(float totalprice);
	void setbookingid(string bookingid);
	void setbookingdate(string bookingdate);
	void setbookingtime(string bookingtime); 
	bool addamenities(amenities obj);
	bool removeamenities(amenities obj);
	bool totalmoney();
	
};

