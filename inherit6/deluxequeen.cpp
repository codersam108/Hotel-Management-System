#include "deluxequeen.h"
deluxequeen::deluxequeen()
{
	roomtype = "deluxequeen";
}
deluxequeen::deluxequeen(string roomid, string roomfeatures, string roomdescription, float price, string roomtype) :Room(roomid, roomfeatures, roomdescription, price)
{
	this->roomtype = roomtype;
}
string deluxequeen::getroomtype()
{
	return this->roomtype;
}
void deluxequeen::setroomtype(string roomtype)
{
	this->roomtype = roomtype;
}


