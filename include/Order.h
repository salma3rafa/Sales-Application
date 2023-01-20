#ifndef ORDER_H
#define ORDER_H
#include"../include/OrderItem.h"
#include<iostream>
#include<ctime>
class Order
{
    friend istream&operator>>(istream&in,Order&o);
    friend ostream&operator<<(ostream&out,Order&o);
    public:
        Order();
        virtual ~Order();
        void createOrder(double);
        void UpdateOrder(int statues);
        void editOrder(int order_id);
        void setOrder(int,int,double);
        int getId();
        void setTotal(double);
        int getNumber();
        double getTotal();
        void UpdateQuantity();
        void print();
        int getStatues();
        void findTotal();
        void setId(int);

    protected:

    private:
        int id,number,statues,Count;
        double total;
        char* dt;
        OrderItem*order;
        time_t date;

};

#endif // ORDER_H
