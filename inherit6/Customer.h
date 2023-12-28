#pragma once
#include<iostream>
using namespace std;
class Customer
{
private:
	string customerid, status, customername;
	
public:
	Customer();
	Customer(string customerid, string customername, string status);
	string getcustomerid();
	string getcustomername();
	string getstatus();
	
	void setcustomerid(string customerid);
	void setcustomername(string customername);
	void setstatus(string status);
	
};

