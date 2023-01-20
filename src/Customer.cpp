#include "Customer.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
istream& operator>>(istream& in, Customer& c)
{
    in >> c.id;
    getline(in, c.phone);
    return in;
}
ostream& operator<<(ostream& out, Customer& c)
{
    out << c.id;
    out << c.phone;
    return out;
}
Customer::Customer()
{
    orderList=new Order*[200];
    Count=0;
}

Customer::~Customer()
{
    //dtor
}
void Customer::readData()//a virtual fun reads a customer data
{
    cout << "Enter customer's phone : ";
     cin.ignore();
    getline(cin,phone);
}
void Customer::setId(int id)
{
    this->id=id;
}
void Customer::setData( std::string mphone)
{
    this->phone = mphone;
}
int Customer::getId()
{
    return this->id;
}
std::string Customer::getPhone()
{
    return this->phone;
}
void Customer::createOrder(double price)//takes the order id to check if the id already exists if not it calls a fun withe same name in order class and creates a new order with increasing the counter of orders array
{//......overloading function
    int id;
    bool found=0;
    cout<<"Enter order's id to check\n";
    cin>>id;
    for(int i=0;i<Count;i++)
    {
        if(orderList[i]->getId()==id)
        {
            found=1;
            break;
        }
    }if(found==1)
    {
        cout<<"Invalid id\n";
    }else{
    Order*order=new Order();
    order->setId(id);
    order->createOrder(price);
    order->findTotal();
    orderList[Count++]=order;
    }
}
void Customer::UpdateOrder()//checks if the order exists if found it calls the fun with same name to update the order's statues
{//....operator overloading
    int id;
    cout<<"Enter order's id to check : ";
    cin>>id;
    for(int i=0;i<Count;i++)
    {
        if(orderList[i]->getId()==id)
        {int statues;
            cout<<"Enter statues to update : ";
            cin>>statues;
            orderList[i]->UpdateOrder(statues);
            cout<<"ORDER's UPDATED \n";
        }break;
    }

}
int Customer::searchForStatues(int id)//this fun returns order's statues if the order exists
{
    bool found=0;
    for(int i=0;i<Count;i++)
    {
        if(orderList[i]->getId()==id)
        {
            found=1;
            return orderList[i]->getStatues();
            break;
        }
    }if(!found)
    {
        return -1;
    }
}
void Customer::UpdateQuantity()//Updates the order's quantity as the customer likes
{
    bool found=0;
    int id;
    cout<<"Enter order's id : ";
    cin>>id;
    for(int i=0;i<Count;i++)
    {
        if(orderList[i]->getId()==id)
        {
            orderList[i]->UpdateQuantity();
            found=1;
            break;
        }
    }if(found==0)
         cout<<"order isn't found \n";
}
double Customer::findOrder(int id)//search for order if exists returns its total price
{
    bool found=0;
    for(int i=0;i<Count;i++)
    {
        if(orderList[i]->getId()==id)
        {
             found=1;
             return orderList[i]->getTotal();
        }
    }if(!found)
    {
        cout<<"order isn't found\n";
        return -1;
    }
}
void Customer::print()//prints customer's data
                                   //a virtual fun
{
    cout<<" id   phone   \n";
     cout <<endl;
    cout<<this->getId()<<"   "<<this->getPhone()<<endl;
}
void Customer::printOrders()//prints all customer's orders
{
    for(int i=0;i<Count;i++)
    {
        orderList[i]->print();
    }
}
