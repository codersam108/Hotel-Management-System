#pragma once
#include<iostream>
using namespace std;
class Room
{
private:
	string roomid, roomfeatures, roomdescription;
	float price;
public:
	Room();
	Room(string roomid, string roomfeatures, string roomdescription, float price);
    string getroomid();
	string getroomfeatures();
	string getroomdescription();
	float getprice();
	void setroomid(string roomid);
	void setroomfeatures(string roomfeatures);
	void setroomdescription(string roomdescription);
	void setprice(float price);
	
};

