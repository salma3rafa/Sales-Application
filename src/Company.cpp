#include "../include/Company.h" //<-1 use "" not <>
#include<iostream>
using namespace std;
Company::Company()
{
    //ctor
}

Company::~Company()
{
    //dtor
}
void Company::readData()//reads the company data with overriding to the same fun in customer class(base class)
{
    Customer::readData();
    cout<<"Enter full name : ";
    getline(cin,location);
    cout<<"Enter company name : ";
    getline(cin,company_name);
    cout<<"\n";
}
void Company::setCompanyData(std::string location,std::string company_name)
{
    this->location=location;
    this->company_name=company_name;
}
std::string Company::getCompanyName()
{
    return this->company_name;
}
std::string Company::getLocation()
{
    return this->location;
}
void Company ::print()//prints a company data with overriding to the same fun in customer class
{
     Customer::print();
    cout<<"name   location\n";
    cout<<"\n";
    cout<<this->getCompanyName()<<"   "<<this->getLocation()<<endl;
}
