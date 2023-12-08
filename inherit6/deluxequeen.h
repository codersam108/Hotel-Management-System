#pragma once
#include"Room.h"
class deluxequeen:public Room
{
private:
	string roomtype;
public:
	deluxequeen();
	deluxequeen(string roomid, string roomfeatures, string roomdescription, float price, string roomtype);
	string getroomtype();
	void setroomtype(string roomtype);
	
};

