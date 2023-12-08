#include "Room.h"
Room::Room()
{
	roomid = "unknown";
	roomfeatures = "unknown";
	roomdescription = "unknown";
	price = 1000.0;
}
Room::Room(string roomid, string roomfeatures, string roomdescription, float price)
{
	this->roomid = roomid;
	this->roomfeatures = roomfeatures;
	this->roomdescription = roomdescription;
	this->price = price;
}
string Room::getroomid()
{
	return this->roomid;
}
string Room::getroomfeatures()
{
	return this->roomfeatures;
}
string Room::getroomdescription()
{
	return this->roomdescription;
}
float Room::getprice()
{
	return this->price;
}
void Room::setroomid(string roomid)
{
	this->roomid = roomid;
}
void Room::setroomfeatures(string roomfeatures)
{
	this->roomfeatures = roomfeatures;
}
void Room::setroomdescription(string roomdescription)
{
	this->roomdescription = roomdescription;
}
void Room::setprice(float price)
{
	this->price = price;
}
