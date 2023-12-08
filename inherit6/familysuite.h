#pragma once
#include"Room.h"
class familysuite:public Room
{
private:
	string roomtype;
public:
	familysuite();
	familysuite(string roomid, string roomfeatures, string roomdescription, float price, string roomtype);
	string getroomtype();
	void setroomtype(string roomtype);
	

};

