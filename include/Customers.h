#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include "../include/Customer.h"  //<-11 use "" not <>
#include<iostream>
#include "../include/Person.h"  //<-12 use "" not <>
#include "../include/Company.h"  //<-13 use "" not <>
using namespace std;
class Customers
{

public:
    Customers(int);
    virtual ~Customers();
    void addCustomer();
    void editCustomer();
    void deleteCustomer();
    void print();
    void createOrder(double);
    void UpdateOrder();
    void UpdateQuantity();
    double findOrder(int,int);
    void printCustomerOrders(int);
    int seacrchForStatues(int,int);


protected:

private:
    Customer** customers;
    int Count, Size;
};
#endif // CUSTOMERS_H
