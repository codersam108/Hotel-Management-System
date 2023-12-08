#pragma once
#include"Room.h"
class deluxe2queen:public Room
{
private:
	string roomtype;
public:
	deluxe2queen();
	deluxe2queen(string roomid, string roomfeatures, string roomdescription, float price, string roomtype);
	string getroomtype();
	void setroomtype(string roomtype);
	
};

