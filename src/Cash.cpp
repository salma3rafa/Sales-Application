#include "Cash.h"
#include<iostream>
using namespace std;
Cash::Cash()
{
    //ctor
}

Cash::~Cash()
{
    //dtor
}
void Cash::makePay()//takes a cash value with overriding the same fun name in payment
{
    cout<<"Enter cash value : ";
    cin>>this->cashValue;
    Payment::makePay();
}
void Cash::setCash(double cash)
{
    this->cashValue=cash;
}
double Cash::getCashValue()
{
    return this->cashValue;
}
