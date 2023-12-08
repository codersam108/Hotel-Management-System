#pragma once
#include"Room.h"
class deluxespa:public Room
{
private:
	string roomtype;
public:
	deluxespa();
	deluxespa(string roomid, string roomfeatures, string roomdescription, float price, string roomtype);
	string getroomtype();
	void setroomtype(string roomtype);
	
	
};

