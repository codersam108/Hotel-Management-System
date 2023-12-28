#include<iostream>
#include<fstream>
#include<vector>
#include"amenities.h"
#include"Booking.h"
#include"Customer.h"
#include"Room.h"
#include<string>
using namespace std;
int x;
vector<Booking>bookinglist;
vector<Customer>customerlist;
vector<Room>roomlist;
vector<amenities>amenitieslist;
vector<Customer>readdataforcustomer();
vector<Room>readdataforroom();
vector<amenities>readdataforamenities();
vector<Booking>readdataforbooking();
int index1, index2;
void writedataforcustomer()
{
	ofstream fw("Customerdetails.txt", ios::out |ios::app);
	for (x = 0; x < customerlist.size(); x++)
	{
		fw << customerlist[x].getcustomername() << endl;
		fw << customerlist[x].getcustomerid() << endl;
		fw << customerlist[x].getstatus() << endl;
	}
	fw.close();
	
}
void writedataforroom()
{
	ofstream fw("Roomdetails.txt", ios::out |ios::app);
	for (x = 0; x < roomlist.size(); x++)
	{
		fw << roomlist[x].getroomid() << endl;
		fw << roomlist[x].getroomfeatures() << endl;
		fw << roomlist[x].getroomdescription() << endl;
		fw << roomlist[x].getprice() << endl;
	}
	fw.close();
}
void writedataforamenities()
{
	ofstream fw("Amenitieslist.txt", ios::app |ios::out);
	for (x = 0; x < amenitieslist.size(); x++)
	{
		fw << amenitieslist[x].getid() << endl;
		fw << amenitieslist[x].getname() << endl;
		fw << amenitieslist[x].getdescription() << endl;
		fw << amenitieslist[x].getprice() << endl;
	}
	fw.close();
}
void writedataforbooking()
{
	ofstream fw("Bookingdetails.txt", ios::app | ios::out);
	for (x = 0; x < bookinglist.size(); x++)
	{
		fw << bookinglist[x].getbookingid() << endl;
		fw << bookinglist[x].getbookingdate() << endl;
		fw << bookinglist[x].getbookingtime() << endl;
		fw << bookinglist[x].getcid() << endl;
		fw << bookinglist[x].getrid() << endl;
		fw << bookinglist[x].gettotalprice() << endl;
	}
	fw.close();
}
vector<Customer>readdataforcustomer()
{
	vector<Customer>customerlist;
	ifstream fr("Customerdetails.txt", ios::in);
	if (!fr)
	{
		cout << "File not found " << endl;
	}
	else
	{
		while (!fr.eof())
		{
			string customerid, status, customername;
			getline(fr, customername);
			if (customername.empty())
			{
				break;
			}
			getline(fr, customerid);
			getline(fr, status);
			Customer obj(customerid, customername, status);
			customerlist.push_back(obj);
		}
		return customerlist;
	}
	fr.close();
}
vector<Room>readdataforroom()
{
	vector<Room>roomlist;
	ifstream fr("Roomdetails.txt", ios::in);
	if (!fr)
	{
		cout << "Sorry file not found " << endl;
	}
	else
	{
		while (!fr.eof())
		{
			string roomid, roomfeatures, roomdescription;
			float price;
			getline(fr, roomid);
			if (roomid.empty())
			{
				break;
			}
			getline(fr, roomfeatures);
			getline(fr, roomdescription);
			cin >> price;
			Room obj(roomid, roomfeatures, roomdescription, price);
			roomlist.push_back(obj);
		}
		return roomlist;
	}
	fr.close();
}
vector<amenities>readdataforamenities()
{
	vector<amenities>amenitieslist;
	ifstream fr("Amenitieslist.txt", ios::in);
	if (!fr.eof())
	{
		cout << "Sorry file not found" << endl;
	}
	else
	{
		while (!fr.eof())
		{
			string id, name, description;
			float price;
			getline(fr, id);
			getline(fr, name);
			if (name.empty())
			{
				break;
			}
			getline(fr, description);
			fr >> price;
			amenities obj(id, name, description, price);
			amenitieslist.push_back(obj);
		}
		return amenitieslist;
	}
	fr.close();
}
vector<Booking>readdataforbooking()
{
	vector<Booking>bookinglist;
	ifstream fr("Bookingdetails.txt", ios::in);
	if (!fr)
	{
		cout << "Sorry file not found " << endl;
	}
	else
	{
		while (!fr.eof())
		{
			string bookingid, bookingdate, bookingtime;
			float totalprice;
			Customer customer;
			Room room;
			getline(fr, bookingid);
			getline(fr, bookingdate);
			getline(fr, bookingtime);
			string id;
			id = customer.getcustomerid();
			getline(fr, id);
			string idd;
			idd = room.getroomid();
			getline(fr, idd);
			fr >> totalprice;
			Booking obj(customer,room, bookingid, bookingdate, bookingtime);
			bookinglist.push_back(obj);
		}
		return bookinglist;
	}
	fr.close();
}
bool checkid(string ci)
{
	bool flag = false;
	for (x = 0; x < customerlist.size(); x++)
	{
		if (customerlist[x].getcustomerid() == ci)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
bool checkroomid(string ri)
{
	bool flag = false;
	for (x = 0; x < roomlist.size(); x++)
	{
		if (roomlist[x].getroomid() == ri)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
void addcustomer()
{
	Customer();
	string ci, cn, st;
	float dis;
	while (true)
	{
		cout << "Enter the customer name " << endl;
		getline(cin, cn);
		if (cn == "")
		{
			cout << "Sorry the customer name cant be blank,pls enter a valid customer name " << endl;

		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the customer id " << endl;
		getline(cin, ci);
		if (ci == "")
		{
			cout << "Sorry the customer id cant be blank,pls enter a valid customer id " << endl;

		}
		else if (checkid(ci) == true)
		{
			cout << "Sorry the custoomer id u entered is already in the database,pls enter a new id  " << endl;

		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the status of the customer " << endl;
		getline(cin, st);
		if (st == "")
		{
			cout << "Sorry the customer status cant be blank,pls enter a valid customer status" << endl;
		}
		else
		{
			break;
		}
	}
	Customer obj(ci, cn, st);
	customerlist.push_back(obj);
	writedataforcustomer();
	cout << "Customer added successfully" << endl;
}
void editcustomer()
{
	string findid, cn, st;
	float dis;
	bool flag;
	int idx;
	

	while (true)
	{
		cout << "Enter the id of the customer which u wanna edit " << endl;
		getline(cin, findid);
		if (findid == "")
		{
			cout << "Sorry the id cant be blank,pls enter a valid id " << endl;

		}
		else
		{
			break;
		}
	}
	flag = false;
	for (x = 0; x < customerlist.size(); x++)
	{
		if (customerlist[x].getcustomerid() == findid)
		{
			flag = true;
			idx = x;
			break;
			
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in our database,pls enter the correct id against which u want to edit the customer details" << endl;
	}
	else
	{
		while (true)
		{
			cout << "Enter the customer name " << endl;
			getline(cin, cn);
			if (cn == "")
			{
				cout << "Sorry the customer name cant be blank,pls enter a valid customer name " << endl;

			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "Enter the status of the customer " << endl;
			getline(cin, st);
			if (st == "")
			{
				cout << "Sorry the customer status cant be blank,pls enter a valid customer status" << endl;
			}
			else
			{
				break;
			}
		}
		Customer obje(cn, findid, st);
		customerlist[idx] = obje;
		writedataforcustomer();
		cout << "Customer details edited successfully" << endl;
	}
	
}
void deletecustomer()
{
	string findid;
	int idx;
	cout << "Enter the id of the customer which u wanna delete from the database " << endl;
	getline(cin, findid);
	bool flag = false;
	for (x = 0; x < customerlist.size(); x++)
	{
		if (customerlist[x].getcustomerid() == findid)
		{
			flag = true;
			idx = x;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in the database,pls enter a valid id " << endl;
	}
	else
	{
		customerlist.erase(customerlist.begin() + idx);
		writedataforcustomer();
		cout << "Customer deleted success from the database " << endl;
	}
}
void addroom()
{
	Room();
	string ri, rf, rd;
	float pr;
	while (true)
	{
		cout << "Enter the room id " << endl;
		getline(cin, ri);
		if (ri == "")
		{
			cout << "Sorry the room id cant be blank,pls enter a valid room id " << endl;
		}
		else if (checkroomid(ri) == true)
		{
			cout << "Sorry the room id u entered already exists in the database,pls enter a new room id" << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the room features" << endl;
		getline(cin, rf);
		if (rf == "")
		{
			cout << "Sorry the room features cant be blank,pls enter valid room features" << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the room description" << endl;
		getline(cin, rd);
		if (rd == "")
		{
			cout << "Sorry the room description cant be blank,pls enter valid room description" << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the price of the room" << endl;
		cin >> pr;
		if (pr == 0.0)
		{
			cout << "Sorry the price cant be 0,pls enter a valid price for the room " << endl;
		}
		else
		{
			break;
		}
	}
	Room obj1(ri, rf, rd, pr);
	roomlist.push_back(obj1);
	writedataforroom();
	cout << "Room added successfully" << endl;
}
void editroom()
{
	string findroomid;
	
	string ri, rf, rd;
	float pr;
	int idx;
	cout << "Enter the room id which u wanna edit" << endl;
	getline(cin, findroomid);
	bool flag = false;
	for (x = 0; x < roomlist.size(); x++)
	{
		if (findroomid == roomlist[x].getroomid())
		{
			flag = true;
			idx = x;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in our database pls enter a valid room id " << endl;
	}
	else
	{
		while (true)
		{
			cout << "Enter the room id " << endl;
			getline(cin, ri);
			if (ri == "")
			{
				cout << "Sorry the room id cant be blank,pls enter a valid room id " << endl;
			}
			else if (checkroomid(ri) == true)
			{
				cout << "Sorry the room id u entered already exists in the database,pls enter a new room id" << endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "Enter the room features" << endl;
			getline(cin, rf);
			if (rf == "")
			{
				cout << "Sorry the room features cant be blank,pls enter valid room features" << endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "Enter the room description" << endl;
			getline(cin, rd);
			if (rd == "")
			{
				cout << "Sorry the room description cant be blank,pls enter valid room description" << endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "Enter the price of the room" << endl;
			cin >> pr;
			if (pr == 0.0)
			{
				cout << "Sorry the price cant be 0,pls enter a valid price for the room " << endl;
			}
			else
			{
				break;
			}
		}
		Room obj2(ri, rf, rd, pr);
		roomlist[idx] = obj2;
		writedataforroom();
		cout << "Room details edited successfully" << endl;
	}
}
void deleteroom()
{
	string findid;
	int idx;
	cout << "Enter the id of the room which u wanna delete from the database " << endl;
	getline(cin, findid);
	bool flag = false;

	for (x = 0; x < roomlist.size(); x++)
	{
		if (roomlist[x].getroomid() == findid)
		{
			flag = true;
			 idx = x;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in the databse,pls enter the id again " << endl;

	}
	else
	{
		roomlist.erase(roomlist.begin() + idx);
		writedataforroom();
		cout << "Room Successfully deleted from the database " << endl;
	}
}

bool checkamenitieid(string findid)
{
	bool flag = false;
	for (x = 0; x < amenitieslist.size(); x++)
	{
		if (amenitieslist[x].getid() == findid)
		{
			flag = true;
			break;
		}
	}
	return flag;
}
void addamenities()
{
	string amenitiesid, amenitiesname, amenitiesdescription;
	float amenitiesprice;
	while (true)
	{
		cout << "Enter the id of amenitie" << endl;
		getline(cin, amenitiesid);
		if (amenitiesid == "")
		{
			cout << "Sorry the amenities id cant be blank,pls enter a valid amenities id " << endl;
		}
		else if (checkamenitieid(amenitiesid) == true)
		{
			cout << "Sorry the amenities id u entered is already in the database,pls enter a unique amenities id " << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the name of the amenities " << endl;
		getline(cin, amenitiesname);
		if (amenitiesname == "")
		{
			cout << "Sorry the amenities name cant be blank,pls enter a valid amenities name " << endl;
		}
		else
		{
			break;
		}

	}
	while (true)
	{
		cout << "Enter the Description of the amenitie" << endl;
		getline(cin, amenitiesdescription);
		if (amenitiesdescription == "")
		{
			cout << "Sorry the description cant be blank,pls enter a valid description" << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the price of the amenities" << endl;
		cin >> amenitiesprice;
		if (amenitiesprice == 0)
		{
			cout << "Sorry the price of the amenities cant be blank,pls enter a valid id for the amenities " << endl;
		}
		else
		{
			break;
		}
	}
	amenities object(amenitiesid, amenitiesname, amenitiesdescription, amenitiesprice);
	amenitieslist.push_back(object);
	writedataforamenities();
	cout << "Amenity added successfully in the database" << endl;
}
void editamenities()
{
	string findid;
	bool flag;
	int idx;
	while (true)
	{
		cout << "Enter the id against which u wanna edit the details of the amenities" << endl;
		getline(cin, findid);
		if (findid == "")
		{
			cout << "Sorry the id u entered cant be blank,pls enter a valid id" << endl;
		}
		else
		{
			break;
		}
	}
	flag = false;
	for (x = 0; x < amenitieslist.size(); x++)
	{
		if (amenitieslist[x].getid() == findid)
		{
		
			flag = true;
			idx = x;
			break;
		}
	}
	if (flag == false)
	{
		cout << "Sorry the id which u entered against which u wanna edit the amenities list is not in the database,pls enter a valid id" << endl;
	}
	else
	{
		string amenitiesname, amenitiesdescription;
		float amenitiesprice;
		
		while (true)
		{
			cout << "Enter the name of the amenities " << endl;
			getline(cin, amenitiesname);
			if (amenitiesname == "")
			{
				cout << "Sorry the amenities name cant be blank,pls enter a valid amenities name " << endl;
			}
			else
			{
				break;
			}

		}
		while (true)
		{
			cout << "Enter the Description of the amenitie" << endl;
			getline(cin, amenitiesdescription);
			if (amenitiesdescription == "")
			{
				cout << "Sorry the description cant be blank,pls enter a valid description" << endl;
			}
			else
			{
				break;
			}
		}
		while (true)
		{
			cout << "Enter the price of the amenities" << endl;
			cin >> amenitiesprice;
			if (amenitiesprice == 0)
			{
				cout << "Sorry the price of the amenities cant be blank,pls enter a valid id for the amenities " << endl;
			}
			else
			{
				break;
			}
		}
		amenities object(findid, amenitiesname, amenitiesdescription, amenitiesprice);
		amenitieslist[idx] = object;
		writedataforamenities();
		cout << "Amenity edited successfully in the database" << endl;
	}
}
void deleteamenities()
{
	string findid;
	int idx;
	cout << "Enter the id of the amenity which u wanna delete from the database" << endl;
	getline(cin, findid);
	bool flag = false;
	for (x = 0; x < amenitieslist.size(); x++)
	{
		if (amenitieslist[x].getid () == findid)
		{
			idx = x;
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "SOrry the id u entered is not in the databse pls enter a valid id" << endl;

	}
	else
	{
		amenitieslist.erase(amenitieslist.begin() + idx);
		writedataforamenities();
		cout << "Amenity successfully deleted from the database" << endl;
	}

}
bool checkbookingid(string bid)
{
	bool flag = false;
	for (x = 0; x < bookinglist.size(); x++)
	{
		if (bookinglist[x].getbookingid() == bid)
		{
			flag = true;
			break;
		}
	}
	return flag;
}


void bookingroom()
{
	string cid, rid, bid, bd, bt;
	int idx;
	string ch;
	while (true)
	{
		cout << "Enter the booking id for the customer" << endl;
		getline(cin, bid);
		if (bid == "")
		{
			cout << "Sorry the id u entered cant be blank,pls enter a valid id" << endl;
		}
		else if (checkbookingid(bid) == true)
		{
			cout << "Sorry pls enter a new booking id for the customer,already existing id is there against what u entered" << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the booking date " << endl;
		getline(cin, bd);
		if (bd == "")
		{
			cout << "Sorry the date cant be blank,pls enter a valid date " << endl;
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the time of the booking" << endl;
		getline(cin, bt);
		if (bt == "")
		{
			cout << "Sorry the booking time cant be blank,pls enter a valid booking time " << endl;

		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "Enter the customer id against which u wanna do the booking " << endl;
		getline(cin, cid);
		bool flag = false;
		
		for (x = 0; x < customerlist.size(); x++)
		{
			if (customerlist[x].getcustomerid() == cid)
			{
				index1 = x;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << "Sorry the id u entered is not in the database,pls enter the id again" << endl;
		}
		else
		{
			break;
		}
	}

	while (true)
	{
		int idl;
		cout << "Enter the room id against which u wanna do the booking" << endl;
		getline(cin, rid);
		bool k = false;
		for (x = 0; x < roomlist.size(); x++)
		{
			if (rid == roomlist[x].getroomid())
			{
				k = true;
				idl = x;
				break;
			}
		}
		if (k == false)
		{
			cout << "Sorry the id u entered is not in the database,pls enter a valid room id " << endl;
		}
		else
		{
			break;
		}
	}
	Booking obj(customerlist[index1], roomlist[index2], bid, bd, bt);
	bookinglist.push_back(obj);
	writedataforbooking();
	while (true)
	{
		string yes;
		string amenity;
		cout << "The following number of amenities are available " << endl;
		cout << "1.Free wifi" << endl;
		cout << "2.TV with netflix" << endl;
		cout << "3.Laundry containing washer and dryer" << endl;
		cout << "4.Air Conditioner" << endl;
		cout << "5.Heater" << endl;
		cout << "6.Coffee Machine" << endl;
		cout << "7.Breakfast" << endl;
		cout << "8.Lunch" << endl;
		cout << "9.Dinner" << endl;
		cout << "10.Undercover Barbeque area" << endl;
		cout << "11.Electric Blankers" << endl;
		cout << "12.Toasters" << endl;
		cout << "13.Microwave" << endl;
		cout << "**********" << endl;
		
			cout << "Enter the id of the amenitie which u wanna add in the room " << endl;
			getline(cin, amenity);
			bool gunda = false;
			for (x = 0; x < amenitieslist.size(); x++)
			{
				if (amenitieslist[x].getid() == amenity)
				{
					gunda = true;
					idx = x;
					break;
				}
			}

			if (gunda == false)
			{
				cout << "Sorry the amenity id u entered is not in our database,pls enter the amenity id again" << endl;
			}
			else
			{
				
				obj.addamenities(amenitieslist[idx]);
				cout << "Amenities successfully added in the room" << endl;
			}
			cout << "Do u want to add more amenities or not " << endl;
			getline(cin, yes);
			if (yes == "NO" || yes == "no" || yes == "No" || yes == "nO")
			{
				break;
			}
		
	}
	while (true)
	{
		string newid;
		int sam;
		cout << "DO u want to remove any amenities from the room?" << endl;
		getline(cin, ch);
		if (ch == "yes" || ch == "YES" || ch == "Yes")
		{
			cout << "Enter the id of the amenity which u wanna remove from the room " << endl;
			getline(cin, newid);
			bool any = false;
			for (x = 0; x < amenitieslist.size(); x++)
			{
				if (newid == amenitieslist[x].getid())
				{
					sam = x;
					any = true;
					break;
				}
			}
			if (any == false)
			{
				cout << "Sorry the id u entered is not in the database,pls enter a valid id " << endl;
			}
			else
			{
				obj.removeamenities(amenitieslist[sam]);
				cout << "Amenity is deleted from the room" << endl;
			}
		}
		else
		{
			break;
		}
	}
}
void showsummary()
{
	string id;
	int idx;
	cout << "Enter the booking id against which u want the summary" << endl;
	getline(cin, id);
	bool flag = false;
	for (x = 0; x < bookinglist.size(); x++)
	{
		if (id == bookinglist[x].getbookingid())
		{
			flag = true;
			idx = x;
			break;

		}
	}
	if (flag == false)
	{
		cout << "Sorry the id u entered is not in the database,pls enter a valid booking id" << endl;
	}
	else
	{
		
		cout << "The booking date is " << bookinglist[idx].getbookingdate() << endl;
		cout << "The time of booking was " << bookinglist[idx].getbookingtime() << endl;
		cout << "The id of the customer which booked the room is " << bookinglist[idx].getcid() << endl;
		cout << "The id of the room which the customer booked is " << bookinglist[idx].getrid() << endl;
		bookinglist[idx].totalmoney();
		cout << "The total fare for the customer is " << bookinglist[idx].gettotalprice() << endl;
		
	}
}
int main()
{
	int choice;
	readdataforcustomer();
	readdataforroom();
	readdataforamenities();
	readdataforbooking();
	while (true)
	{
		cout << "***** Welcome to Hotel Management System******* " << endl;
		cout << "1.Add Customer in the database" << endl;
		cout << "2.Add room in the database " << endl;
		cout << "3.Add Amenities in the database" << endl;
		cout << "4.Edit customer details from the database " << endl;
		cout << "5.Edit room details from the database " << endl;
		cout << "6.Edit Amenities from the database " << endl;
		cout << "7.Delete Customer details from the database " << endl;
		cout << "8.Delete Room details from the database " << endl;
		cout << "9.Delete amenities details from the database " << endl;
		cout << "10.Do booking for the customer" << endl;
		cout << "11.Display the summary " << endl;
		cout << "Enter the choice " << endl;
		cin >> choice;
		getchar();
		switch (choice)
		{
		case 1:
		{
			addcustomer();
			break;
		}
		case 2:
		{
			addroom();
			break;
		}
		case 3:
		{
			addamenities();
			break;
		}
		case 4:
		{
			editcustomer();
			break;
		}
		case 5:
		{
			editroom();
			break;

		}
		case 6:
		{
			editamenities();
			break;
		}
		case 7:
		{
			deletecustomer();
			break;
		}
		case 8:
		{
			deleteroom();
			break;
		}
		case 9:
		{
			deleteamenities();
			break;
		}
		case 10:
		{
			bookingroom();
			break;
		}
		case 11:
			showsummary();
			break;
		}
	}
}
