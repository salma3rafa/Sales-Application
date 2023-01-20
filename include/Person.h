#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#include "../include/Customer.h" //<-2 use "" not <>
using namespace std;
class Person : public Customer //<-14 public inheritance not protected
{
public:
    Person();
    virtual ~Person();
    void setPersonData(std::string,std::string);
    void readData();  //13- syntax readPersonData not readpersonData
    void print();
    std::string getBillingAddress();
    std::string getFullName();
protected:

private:
    std::string billing_address, fullName;
};

#endif // PERSON_H
