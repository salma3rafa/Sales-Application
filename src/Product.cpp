#include "Product.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>//set width
using namespace std;
istream&operator>>(istream&in,Product&p)
{
    in>>p.id;
    in>>p.type>>p.price>>p.sale_price>>p.quantity;
    cin.ignore();
    getline(cin,p.name);
    cin.ignore();
    getline(cin,p.number);
    return in;

}
ostream&operator<<(ostream&out,Product&p)
{
    out<<p.id<<p.name<<p.number<<p.price<<p.type<<p.sale_price<<p.quantity;
    return out;
}

Product::Product()
{
    //ctor
}

Product::~Product()
{
    //dtor
}
void Product::setProductData()
{
    cout<<"name : ";
    cin.ignore();
    getline(cin,name);
    cout<<"number : ";
    getline(cin,number);
    cout<<"price : ";
    cin>>price;
    cout<<"type : ";
    cin>>type;
    cout<<"sale price :  ";
    cin>>sale_price;
    cout<<"quantity : ";
    cin>>quantity;
    cout<<endl;
}
void Product::setPrice(double price)
{
    this->sale_price=price;
}
double Product::getSalePrice()
{
    return this->sale_price;
}
void Product::setId(int id)
{
    this->id=id;
}
int Product::getId()
{
    return this->id;
}
int Product::getType()
{
    return this->type;
}
double Product::getPrice()
{
    return this->price;
}
std::string Product::getName()
{
    return this->name;
}
std::string Product::getNumber()
{
    return this->number;
}
void Product::update()//updates products data if found
{
    bool found=0;
    int id;
    cout<<"Enter id to check before Updating : ";
    cin>>id;
    if(id==this->getId())
    {
       found=1;
    }else{
        found=0;
    }
    if(found)
    {
        setProductData();
    }else
    {
        cout<<"This product's id isn't found please check your data before trying again \n";
    }
}
void Product::setQuantity(double pquantity)
{
    this->quantity=pquantity;

}
double Product::getQuantity()
{
    return this->quantity;
}
/*void Product::saveTo(ofstream output)
{

     output<<getId()<<" , "<<getName()<<" , "<<getNumber()<<" , "<<getPrice()<<" , "<<getSalePrice()<<" , "<<getQuantity()<<endl;

}*/
void Product::print()//prints product's data
{
    cout<<std::left;
     cout<<setw(10)<<getId()<<setw(10)<<getName()<<setw(8)<<getNumber()<<setw(8)<<getPrice()<<setw(9)<<getSalePrice()<<setw(20)<<getQuantity()<<setw(10)<<endl;
}
