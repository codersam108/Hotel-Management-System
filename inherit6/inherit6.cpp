#include<iostream>
#include<vector>
#include"amenities.h"
#include"Customer.h"
#include"Room.h"
#include<string>
using namespace std;
int x;
vector<Customer>customerlist;
vector<Room>roomlist;
vector<amenities>amenitieslist;
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
	Customer obj(cn, ci, st);
	customerlist.push_back(obj);
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
		cout << "Customer details edited successfully" << endl;
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
		cout << "Room details edited successfully" << endl;
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
	}
}

