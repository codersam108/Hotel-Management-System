#include "deluxespa.h"
deluxespa::deluxespa()
{
	roomtype = "Deluxe Spa";
}
deluxespa::deluxespa(string roomid, string roomfeatures, string roomdescription, float price, string roomtype) :Room(roomid, roomfeatures, roomdescription, price)
{
	this->roomtype = roomtype;
}
string deluxespa::getroomtype()
{
	return this->roomtype;
}
void deluxespa::setroomtype(string roomtype)
{
	this->roomtype = roomtype;
}
