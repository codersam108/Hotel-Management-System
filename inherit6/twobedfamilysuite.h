#pragma once
#include"Room.h"
class twobedfamilysuite:public Room
{
private:
	string roomtype;
public:
	twobedfamilysuite();
	twobedfamilysuite(string roomid, string roomfeatures, string roomdescription, float price, string roomtype);
	string getroomtype();
	void setroomtype(string roomtype);

};

