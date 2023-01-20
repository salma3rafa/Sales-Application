#include "Order.h"
#include<iostream>
using namespace std;
istream&operator>>(istream&in,Order&o)
{
    in>>o.id>>o.number>>o.statues>>o.total>>o.date;
    return in;
}
ostream&operator<<(ostream&out,Order&o)
{
     out<<o.id<<o.number<<o.statues<<o.total<<o.date;
    return out;
}
Order::Order()
{
    this->total=0;
    order=new OrderItem[200];
    Count=0;
    date=time(0);
}

Order::~Order()
{
    //dtor
}
void Order::createOrder(double price)//creates a new order with a list of order items
{
    dt=ctime(&date);
     OrderItem orderItem;
    cout<<"Enter order's number : ";
    cin>>number;
    cout<<"0 for new, 1 for Hold,2  for paid,3 for cancel\n";
    cout<<"Enter statues : ";
    cin>>statues;
    int num;
    cout<<"Number of products : ";
    cin>>num;
    double newPrice;
    for(int i=0;i<num;i++){
    orderItem.readOrderItem();
    newPrice=orderItem.getQuantity()*price;
    orderItem.setPrice(newPrice);
    order[Count++]=orderItem;
    }
}
void Order::setOrder(int number,int statues,double total)
{
    this->number=number;
    this->statues=statues;
    this->total=total;
}
void Order:: findTotal()
{
    for(int i=0;i<Count;i++)
    {
        total+=order[i].getPrice();
    }
}
void Order::setId(int id)
{
    this->id=id;
}

void Order::UpdateOrder(int statues)//updates order's statues
{
    this->statues=statues;
}
int Order::getId()
{
    return this->id;
}
int Order::getNumber()
{
    return this->number;
}
double Order::getTotal()
{
    return this->total;
}
int Order::getStatues()
{
    return this->statues;
}
void Order::UpdateQuantity()//updates item's quantity
{
    bool found=0;
    int id;
    cout<<"Orderitem's id before Updating\n";
    cin>>id;
    for(int i=0;i<Count;i++){
         if(order[i].getOrderItemId()==id) {
                found=1;
           double quantity;
           double price;
           int k;
           cout<<"Enter a keyword to Update : \n"
                  <<"1-For adding 1 \n 2-for deleting 1\n 3-for adding n of quantities\n 4-for deleting n of quantities \n";
           cin>>k;
          if(k==1)
         {
               quantity=order[i].getQuantity()+1;
               price=order[i].getPrice()*quantity;
               order[i].setQuantity(quantity);
               order[i].setPrice(price);
        }else if(k==2)
         {
              quantity=order[i].getQuantity()-1;
              price=order[i].getPrice()*quantity;
             order[i].setQuantity(quantity);
             order[i].setPrice(price);
       }else if(k==3)
        {
             int n;
             cout<<"Enter a number to add to the order : ";
             cin>>n;
             quantity=order[i].getQuantity()+n;
              price=order[i].getPrice()*quantity;
             order[i].setQuantity(quantity);
             order[i].setPrice(price);
      }else if(k==4)
       {
             int n;
             cout<<"Enter a number to from the order : ";
             cin>>n;
            quantity=order[i].getQuantity()-n;
            price=order[i].getPrice()*quantity;
           order[i].setQuantity(quantity);
           order[i].setPrice(price);
      }
         }
    }if(!found)
    {
        cout<<"OrderItem isn't found\n";
    }
}
void Order::print()//prints order with all items
{
    cout<<"________________________________________________________________________________________________________________________\n";
    cout<<"Time : "<<dt<<"\n";
    cout<<"Order's id : "<<this->getId()<<"\n";
    cout<<"Order's statues : "<<this->getStatues()<<"\n";
    cout<<"Total price : "<<this->getTotal()<<"\n";
    for(int i=0;i<Count;i++)
    {
        order[i].print();
        cout<<"________________________________________________________________________________________________________________________\n";
    }
    cout<<"________________________________________________________________________________________________________________________\n";
}
