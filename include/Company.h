#ifndef COMPANY_H
#define COMPANY_H
#include<iostream>
#include<string>
#include"Customer.h"
using namespace std;
class Company:public Customer
{
    public:
        Company();
        virtual ~Company();
        void readData(); //11- syntax readPersonData not readpersonData
        void setCompanyData(std::string,std::string);
        void print();
        std::string getCompanyName();
        std::string getLocation();
    protected:

    private:
        std::string location,company_name;
};

#endif // COMPANY_H
