#include "Customer.h"
Customer::Customer()
{
	customerid = "";
	customername = "";
	status = "";
    
}
Customer::Customer(string customerid, string customername, string status)
{
	this->customerid = customerid;
	this->customername = customername;
	this->status = status;
	
}
string Customer::getcustomerid()
{
	return this->customerid;
}
string Customer::getcustomername()
{
	return this->customername;
}
string Customer::getstatus()
{
	return this->status;
}

void Customer::setcustomerid(string customerid)
{
	this->customerid = customerid;
}
void Customer::setcustomername(string customername)
{
	this->customername = customername;
}
void Customer::setstatus(string status)
{
	this->status = status;
}