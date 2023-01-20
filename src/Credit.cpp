#include "Credit.h"
#include<string>
#include<iostream>
using namespace std;
Credit::Credit()
{
    //ctor
}

Credit::~Credit()
{
    //dtor
}
void Credit::makePay()//takes a credit data with overriding the same fun name in payment
{
    cout<<"Credit number : ";
    cin>>this->number;
    cout<<"Type : ";
    cin>>this->type;
    cout<<"Expire date : ";
    cin>>this->expireDate;
    Payment::makePay();
}
void Credit::setCredit(std::string number,std::string type,std::string date)
{
    this->number=number;
    this->type=type;
    this->expireDate=date;
}
std::string Credit::getNumber()
{
    return this->number;
}
std::string Credit::getType()
{
    return this->type;
}
std::string Credit::getExpireDate()
{
    return this->expireDate;
}
