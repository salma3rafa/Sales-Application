#include "OrderItem.h"
#include<iostream>
using namespace std;

OrderItem::OrderItem()
{

}

OrderItem::~OrderItem()
{
    //dtor
}
double OrderItem::operator++()
{
    return this->quantity++;
}
double OrderItem::operator--()
{
    return this->quantity--;
}

OrderItem OrderItem::operator+=(int n)
{
    OrderItem order;
    order.quantity=quantity+n;
    return order;
}
OrderItem OrderItem::operator-=(int n)
{
    OrderItem order;
    order.quantity=quantity-n;
    return order;
}
void OrderItem::readOrderItem()//creates an item
{
    cout<<"Order item's id : ";
    cin>>id;
   cout<<"Enter the product quantity : ";
   cin>>this->quantity;
}
void OrderItem::setId(int id)
{
    this->id=id;
}
void OrderItem::setPrice(double price)
{
    this->sale_price=price;
}
double OrderItem::getPrice()
{
    return sale_price;
}
int OrderItem::getOrderItemId()
{
    return this->id;
}
void OrderItem::setQuantity(double quantity)
{
    this->quantity=quantity;
}
double OrderItem::getQuantity()
{
    return this->quantity;
}
void OrderItem::print()//prints items
{
    cout<<"OrderItem's id : "<<this->getOrderItemId()<<"\n";
    cout<<"Orderitem's quantity : "<<this->getQuantity()<<"\n";
    cout<<"Orderitem's price : "<<this->getPrice()<<"\n";
}
