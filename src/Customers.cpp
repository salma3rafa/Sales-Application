#include "../include/Customers.h"  //<-7 use "" not <>
#include<iostream>
using namespace std;
Customers::Customers(int s)
{
    Size = s;
    customers = new Customer * [Size];
    Count = 0;
}

Customers::~Customers()
{
    //dtor
}
void Customers::addCustomer()//this fun takes a type and passed on it makes an obj of the customer and creates a new cust then increases the counter of array
                                                //if the id is already exist then it prints an invalid message
{
    bool found=0;
    int type,id;
    cout << "1-person \n 2-Company \n";
    cout << "Enter customer's type : ";
    cin>>type;
    cout<<"Enter customer's id to check\n";
    cin>>id;
    for(int i=0;i<Count;i++)
    {
        if(customers[i]->getId()==id)
        {
            found=1;
            break;
        }
    }if(found)
    {
        cout<<"Invalid id \n";
    }else{
    if (type == 1)
    {
        Customer* customer = new Person();
        customer->setId(id);
        customer->readData();
        customers[Count] = customer;

    }
    else  if (type == 2)
    {
        Customer* customer = new Company();
        customer->setId(id);
        customer->readData();
        customers[Count] = customer;

    }
    Count++;
    }
}
void Customers::editCustomer()//this fun takes an id if found then it edits the customer's id if not found it prints a message with it
{
    int id;
    cout<<"Enter id to edit : ";
    cin>>id;
    bool edit=0;
    for(int i=0; i<Count; i++)
    {
        if(customers[i]->getId()==id)
        {
            customers[i]->readData();
            edit=1;
        }
        break;

    }
    if(edit)
        cout<<"Customer's edited \n";
    else
        cout<<"NOT FOUND \n";

}
void Customers::deleteCustomer()//it deletes the customer if found and decreasing the counter
{
    int id;
    cout<<"enter id to check before deleting : ";
    cin>>id;
    bool deleted=0;
    for(int i=0; i<Count; i++)
    {
        if(customers[i]->getId()==id)
        {

            if(i==Count-1)
            {
                Count--;
            }
        }
        else
        {
            customers[i]=customers[Count-1];
            Count--;
        }
        deleted=1;
        break;


    }
    if(deleted)
    {
        cout<<"Customer's deleted \n";
    }
    else
        cout<<"NOT FOUND \n";

}
int Customers::seacrchForStatues(int customerId,int orderId)//takes the customer's id if found calls a fun in the customer with the same name and gives it an order's id to return its statues if found
{
    bool found=0;
    for(int i=0;i<Count;i++)
    {
        if(customers[i]->getId()==customerId)
        {
            found=1;
            return customers[i]->searchForStatues(orderId);
            break;
        }
    }if(found==0)
    {
        return -1;
    }
}
void Customers::createOrder(double price)//it creates an order if the customer found in the system and gives the fun in customer class the price of order from stock
{
    int id;
    cout<<"Enter customer's id to check before making any order : ";
    cin>>id;
    bool found=0;
    for(int i=0;i<Count;i++)
    {
        if(customers[i]->getId()==id)
        {
           customers[i]->createOrder(price);
           found=1;break;
        }
    }if(found==0)
    {
        cout<<"CUSTOMER ISN'T FOUND \n";
    }

}
void Customers::UpdateOrder()//this fun search for a customer with its id if found it calls the fun in customer class with the same name to update order
{
    int id;
    cout<<"Enter customer's id to check before updating : ";
    cin>>id;
    bool found=0;
    for(int i=0;i<Count;i++)
    {
        if(customers[i]->getId()==id)
        {
            customers[i]->UpdateOrder();
            found=1;
        }break;
    }if(found==0)
    {
        cout<<"CUSTOMER ISN'T FOUND \n";
    }

}
void Customers::UpdateQuantity()//calls a fun with same name in customer class to update quantity if customer is found
{
    bool found=0;
    int id;
    cout<<"Enter customer's id : ";
    cin>>id;
    for(int i=0;i<Count;i++)
    {
        if(customers[i]->getId()==id)
        {
            customers[i]->UpdateQuantity();
            found=1;
            break;
        }
    }if(found==0)
     cout<<"CUSTOMER ISN'T FOUND \n";

}
double Customers::findOrder(int customerId,int orderId)//this fun takes a customer id and their order id if the customer found it searches for their order if found this fun returns the order's total price
{
    bool found=0;
    for(int i=0;i<Count;i++)
    {
        if(customers[i]->getId()==customerId)
        {
            found=1;
          return  customers[i]->findOrder(orderId);
        }
    }if(!found)
    {
        cout<<"Customer isn't found\n";
        return -1;
    }
}
void Customers::print()//prints all customers
{
    for (int i = 0; i < Count; i++)
    {
        cout<<"________________________________________________________________________________________________________________________\n";
        customers[i]->print();
          cout<<"________________________________________________________________________________________________________________________\n";
        cout<<"\n";
    }
}
void Customers::printCustomerOrders(int id)//prints a customer's orders if the customer found
{
    bool found=0;
    for(int i=0;i<Count;i++)
    {
        if(customers[i]->getId()==id)
        {
            customers[i]->printOrders();
            found =1;
        }
    }if(found==0)
    {
        cout<<"Customer isn't found\n";
    }
}
