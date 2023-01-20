#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<string>
#include"../include/Order.h"
using namespace std;
class Customer
{
    friend istream& operator>>(istream& in, Customer& c);
    friend ostream& operator<<(ostream& out, Customer& c);
public:
    Customer();
    virtual ~Customer();
    virtual void readData() ;
    void setData(std::string);
    int getId();
    std::string getPhone();
    virtual void print();
    void createOrder(double);
    void UpdateOrder();
    void UpdateQuantity();
    void printOrders();
    double findOrder(int);
    void setId(int);
    int searchForStatues(int);

protected:
    int id;
    std::string phone;
private:
    int Count;
    Order**orderList;

};

#endif // CUSTOMER_H

