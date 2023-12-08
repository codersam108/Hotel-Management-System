#pragma once
#include<iostream>
using namespace std;
class amenities
{
private:
	string id,name, description;
	float price;
public:
	amenities();
	amenities(string id, string name, string description, float price);
	string getid();
	string getname();
	string getdescription();
	float getprice();
	void setid(string id);
	void setname(string name);
	void setdescription(string description);
	void setprice(float price);
};

