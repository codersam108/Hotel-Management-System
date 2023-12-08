#include "amenities.h"
amenities::amenities()
{
	id = "1234567890";
	name = "Kesariya";
	description = "Very tasty";
	price = 500.0;
}
amenities::amenities(string id, string name, string description, float price)
{
	this->id = id;
	this->name = name;
	this->description = description;
	this->price = price;
}
string amenities::getid()
{
	return this->id;
}
string amenities::getname()
{
	return this->name;
}
string amenities::getdescription()
{
	return this->description;
}
float amenities::getprice()
{
	return this->price;
}
void amenities::setid(string id)
{
	this->id = id;
}
void amenities::setname(string name)
{
	this->name = name;
}
void amenities::setdescription(string description)
{
	this->description = description;
}
void amenities::setprice(float price)
{
	this->price = price;
}