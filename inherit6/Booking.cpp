#include "Booking.h"
Booking::Booking(Customer customer, Room room, string bookingid, string bookingdate, string bookingtime,float totalprice)
{
	this->bookingid = bookingid;
	this->bookingdate = bookingdate;
	this->bookingtime = bookingtime;
	this->customer = customer;
	this->room = room;
	this->totalprice = totalprice;
}
string Booking::getbookingid()
{
	return this->bookingid;
}
string Booking::getbookingdate()
{
	return this->bookingdate;
}
string Booking::getbookingtime()
{
	return this->bookingtime;
}
float Booking::gettotalprice()
{
	return this->totalprice;
}
void Booking::settotalprice(float totalprice)
{
	this->totalprice = totalprice;
}
void Booking::setbookingid(string bookingid)
{
	this->bookingid = bookingid;
}
void Booking::setbookingdate(string bookingdate)
{
	this->bookingdate = bookingdate;
}
void Booking::setbookingtime(string bookingtime)
{
	this->bookingtime = bookingtime;
}
bool Booking::addamenities(amenities obj)
{
	bool flag = false;
	int x;
	for (x = 0; x < amenitieslist.size(); x++)
	{
		if (obj.getid() == amenitieslist[x].getid())
		{
			flag = true;
			
			break;
		}
	}
	if (flag == true)
	{
		return false;
	}
	else
	{
		amenitieslist.push_back(obj);
		return true;
	}
}
bool Booking::removeamenities(amenities obj)
{
	bool flag = false;
	int x,idx;
	for (x = 0; x < amenitieslist.size(); x++)
	{
		if (obj.getid() == amenitieslist[x].getid())
		{
			flag = true;
			idx = x;
			break;
		}
	}
	if (flag == false)
	{
		return false;
	}
	else
	{
		amenitieslist.erase(amenitieslist.begin() + idx);
		return true;
	}
}
bool Booking::totalmoney()
{
	int x;
	float amenitiessum = 0;
	float totalsum;
	if (customer.getstatus() == "Active" || customer.getstatus() == "active" || customer.getstatus() == "ACTIVE")
	{
		if (room.getroomdescription() == "Family suite" || room.getroomdescription() == "family suite" || room.getroomdescription() == "FAMILY SUITE" || room.getroomdescription() == "Family Suite" || room.getroomdescription() == "FAMILY suite" || room.getroomdescription() == "family SUITE")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() - (room.getprice() * (15.0 / 100.0))) + amenitiessum);
			totalprice = totalsum - (totalsum * (5.0 / 100.0));
		}

		else if (room.getroomdescription() == "Deluxe Queen" || room.getroomdescription() == "DELUXE QUEEN" || room.getroomdescription() == "DELUXE queen" || room.getroomdescription() == "deluxe queen" || room.getroomdescription() == "deluxe QUEEN")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() - (room.getprice() * (10.0 / 100.0))) + amenitiessum);
			totalprice = totalsum - (totalsum * (5.0 / 100.0));
		}
		else if (room.getroomdescription() == "Deluxe two queen" || room.getroomdescription() == "DELUXE TWO QUEEN" || room.getroomdescription() == "Deluxe Two Queen")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() - (room.getprice() * (5.0 / 100.0))) + amenitiessum);
			totalprice = totalsum - (totalsum * (5.0 / 100.0));
		}
		else if (room.getroomdescription() == "Deluxe Spa" || room.getroomdescription() == "DELUXE SPA" || room.getroomdescription() == "Deluxe spa" || room.getroomdescription() == "deluxe Spa" || room.getroomdescription() == "deluxe spa")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() + 50) + amenitiessum);
			totalprice = totalsum - (totalsum * (5.0 / 100.0));
		}
		else if (room.getroomdescription() == "Two bedroom family suite" || room.getroomdescription() == "TWO BEDROOM FAMILY SUITE" || room.getroomdescription() == "two bedroom family suite")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() - (room.getprice() * (5.0 / 100.0))) + amenitiessum);
			totalprice = totalsum - (totalsum * (5.0 / 100.0));
		}
		else
		{
			return false;
		}
	}
	else if (customer.getstatus() == "VIP" || customer.getstatus() == "Vip" || customer.getstatus() == "vip")
	{
		if (room.getroomdescription() == "Family suite" || room.getroomdescription() == "family suite" || room.getroomdescription() == "FAMILY SUITE" || room.getroomdescription() == "Family Suite" || room.getroomdescription() == "FAMILY suite" || room.getroomdescription() == "family SUITE")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() - (room.getprice() * (15.0 / 100.0))) + amenitiessum);
			totalprice = totalsum - (totalsum * (10.0 / 100.0));
		}

		else if (room.getroomdescription() == "Deluxe Queen" || room.getroomdescription() == "DELUXE QUEEN" || room.getroomdescription() == "DELUXE queen" || room.getroomdescription() == "deluxe queen" || room.getroomdescription() == "deluxe QUEEN")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() - (room.getprice() * (10.0 / 100.0))) + amenitiessum);
			totalprice = totalsum - (totalsum * (10.0 / 100.0));
		}
		else if (room.getroomdescription() == "Deluxe two queen" || room.getroomdescription() == "DELUXE TWO QUEEN" || room.getroomdescription() == "Deluxe Two Queen")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() - (room.getprice() * (5.0 / 100.0))) + amenitiessum);
			totalprice = totalsum - (totalsum * (10.0 / 100.0));
		}
		else if (room.getroomdescription() == "Deluxe Spa" || room.getroomdescription() == "DELUXE SPA" || room.getroomdescription() == "Deluxe spa" || room.getroomdescription() == "deluxe Spa" || room.getroomdescription() == "deluxe spa")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() + 50) + amenitiessum);
			totalprice = totalsum - (totalsum * (10.0 / 100.0));
		}
		else if (room.getroomdescription() == "Two bedroom family suite" || room.getroomdescription() == "TWO BEDROOM FAMILY SUITE" || room.getroomdescription() == "two bedroom family suite")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() - (room.getprice() * (5.0 / 100.0))) + amenitiessum);
			totalprice = totalsum - (totalsum * (10.0 / 100.0));
		}
		else
		{
			return false;
		}
		
	}
	else
	{
		if (room.getroomdescription() == "Family suite" || room.getroomdescription() == "family suite" || room.getroomdescription() == "FAMILY SUITE" || room.getroomdescription() == "Family Suite" || room.getroomdescription() == "FAMILY suite" || room.getroomdescription() == "family SUITE")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = (room.getprice() + amenitiessum);
			totalprice = totalsum;
		}

		else if (room.getroomdescription() == "Deluxe Queen" || room.getroomdescription() == "DELUXE QUEEN" || room.getroomdescription() == "DELUXE queen" || room.getroomdescription() == "deluxe queen" || room.getroomdescription() == "deluxe QUEEN")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = (room.getprice()  + amenitiessum);
			totalprice = totalsum;
		}
		else if (room.getroomdescription() == "Deluxe two queen" || room.getroomdescription() == "DELUXE TWO QUEEN" || room.getroomdescription() == "Deluxe Two Queen")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = (room.getprice() + amenitiessum);
			totalprice = totalsum;
		}
		else if (room.getroomdescription() == "Deluxe Spa" || room.getroomdescription() == "DELUXE SPA" || room.getroomdescription() == "Deluxe spa" || room.getroomdescription() == "deluxe Spa" || room.getroomdescription() == "deluxe spa")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = ((room.getprice() + 50) + amenitiessum);
			totalprice = totalsum;
		}
		else if (room.getroomdescription() == "Two bedroom family suite" || room.getroomdescription() == "TWO BEDROOM FAMILY SUITE" || room.getroomdescription() == "two bedroom family suite")
		{
			for (x = 0; x < amenitieslist.size(); x++)
			{
				amenitiessum = amenitiessum + amenitieslist[x].getprice();
			}
			totalsum = (room.getprice() + amenitiessum);
			totalprice = totalsum;
		}
		else
		{
			return false;
		}
	}
}

 
