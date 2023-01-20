#include "../include/Person.h" //<-12 use "" not <>
#include<iostream>
using namespace std;
Person::Person()
{
    //ctor
}

Person::~Person()
{
    //dtor
}
void Person::readData()//reads the person data with overriding to the same fun in customer class(base class)
{
    Customer::readData();
    cout << "Enter full name : ";
    getline(cin, fullName);
    cout << "Enter billing address : ";
    getline(cin, billing_address);
}
void Person::setPersonData(string fullname,string billingaddress)
{
    this->fullName=fullname;
    this->billing_address=billingaddress;

}
std::string Person::getFullName()
{
    return this->fullName;
}
std::string Person::getBillingAddress()
{
    return this->billing_address;
}
void Person::print()//prints a person data with overriding to the same fun in customer class
{
    Customer::print();
    cout << "full name   billing address   \n";
    cout<<"\n";
    cout << this->getFullName()<<"   " << this->getBillingAddress() << endl;
}
