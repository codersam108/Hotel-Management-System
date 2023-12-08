#include "deluxe2queen.h"
deluxe2queen::deluxe2queen()
{
	roomtype = "Deluxe 2 queen";
}
deluxe2queen::deluxe2queen(string roomid, string roomfeatures, string roomdescription, float price, string roomtype) :Room(roomid, roomfeatures, roomdescription, price)
{
	this->roomtype = roomtype;
}
string deluxe2queen::getroomtype()
{
	return this->roomtype;
}
void deluxe2queen::setroomtype(string roomtype)
{
	this->roomtype = roomtype;
}
