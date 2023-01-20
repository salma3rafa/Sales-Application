#ifndef ORDERITEM_H
#define ORDERITEM_H
#include<iostream>
#include"../include/Product.h"
#include"../include/Stock.h"
class OrderItem
{
    public:
        OrderItem();
        virtual ~OrderItem();
        double operator++();
         double operator--();
        OrderItem operator+=(int);
        OrderItem operator-=(int);
        void readOrderItem();
        void setQuantity(double);
        double getQuantity();
        void setPrice(double);
        double getPrice();
        int getOrderItemId();
        void setId(int);
        void print();
    protected:

    private:
        int id;
         double quantity;
        double sale_price;
};

#endif // ORDERITEM_H
