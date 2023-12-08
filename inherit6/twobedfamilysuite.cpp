#include "twobedfamilysuite.h"
twobedfamilysuite::twobedfamilysuite()
{
	roomtype = "Two bed family suite";
}
twobedfamilysuite::twobedfamilysuite(string roomid, string roomfeatures, string roomdescription, float price, string roomtype) :Room(roomid, roomfeatures, roomdescription, price)
{
	this->roomtype = roomtype;
}
string twobedfamilysuite::getroomtype()
{
	return this->roomtype;
}
void twobedfamilysuite::setroomtype(string roomtype)
{
	this->roomtype = roomtype;
}

