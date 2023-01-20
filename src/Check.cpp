#include "Check.h"
#include<string>
#include<iostream>
using namespace std;
Check::Check()
{
    //ctor
}

Check::~Check()
{
    //dtor
}
void Check::makePay()//takes a bank data with overriding the same fun name in payment
{
    cout<<"Bank id : ";
    cin>>this->bank_id;
    cout<<"Bank name : ";
    cin>>this->name;
    Payment::makePay();
}
void Check::setBank(std::string id,std::string name)
{
    this->bank_id=id;
    this->name=name;
}
std::string Check::getBankId()
{
    return this->bank_id;
}
std::string Check::getName()
{
    return this->name;
}
