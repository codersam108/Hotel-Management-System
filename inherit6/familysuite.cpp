#include "familysuite.h"
familysuite::familysuite()
{
	roomtype = "Family suite";
}
familysuite::familysuite(string roomid, string roomfeatures, string roomdescription, float price, string rootype) :Room(roomid, roomfeatures, roomdescription, price)
{
	this->roomtype = roomtype;
}
string familysuite::getroomtype()
{
	return this->roomtype;
}
void familysuite::setroomtype(string roomtype)
{
	this->roomtype = roomtype;
}
