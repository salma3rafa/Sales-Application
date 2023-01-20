#include "Stock.h"
#include"../include/Product.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

istream&operator>>(istream&in,Stock&s)
{
    in>>s.Count;
    return in;
}
ostream&operator<<(ostream&out,Stock&s)
{
    out<<s.Count;
    return out;
}
Stock::Stock()
{

}
Stock::Stock(int s)
{
    Size=s;
    Count=0;
    productList=new Product[Size];
}
Stock::~Stock()
{
}
void Stock::addProduct()//checks if product's id is valid if valid it creates a new products and increasing the array's counter
{
    int id;
    bool found=0;
    cout<<"Enter product id to check \n";
    cin>>id;
    for(int i=0;i<Count;i++)
    {
        if(productList[i].getId()==id)
        {
            found=1;
            break;
        }
    }if(found)
    {
        cout<<"Invalid\n";
    }else{
    Product product;
    product.setId(id);
    product.setProductData();
    productList[Count]=product;
    Count++;
    }

}
/*void Stock::saveToFile()
{
    ofstream output("Products.txt");
    for(int i=0;i<Count;i++)
    {
       // productList[i].saveTo(output);
    }
    output.close();

}*/
double Stock::Search(int id)//searches for product if found returns its quantity if not returns -1
{
    bool found=0;
   for(int i=0;i<Count;i++)
   {
       if(productList->getId()==id)
       {
           found=1;
           return productList[i].getQuantity();
       }
   }if(found==0)
   {
       return -1;
   }
}
void Stock::editProduct(int id)
{
    bool edit=0;
    for(int i=0;i<Count;i++)
    {
        if(productList->getId()==id)
        {
            productList[i].setProductData();
            edit=1;
        }break;
    }
    if(edit)
        cout<<"Product's edited\n";
    else
        cout<<"Product isn't found \n";
}
void Stock::deleteProduct(int id)//deletes an product if found
{
    bool Delete=0;
    for(int i=0;i<Count;i++)
    {
        if(productList->getId()==id)
        {
            if(i==Count-1)
            {
                Count--;
            }else
            {
                productList[Count-1];
                Count--;
            }Delete=1;
            break;
        }
    }if(Delete)
        cout<<"Product's deleted \n";
    else
        cout<<"Product isn't found\n";
}
double Stock::getQuantity(int product_id)
{
    bool found=0;
    for(int i=0;i<Count;i++)
    {
        if(productList[i].getId()==product_id)
        {
            found=1;
            return  productList[i].getQuantity();
        }
    }
    if(found==0)
    {
       return -1;
    }
}
void Stock::updateStock(int product_id,double quantity)//updates stock with product's id if found updates its quantity
{
    bool found=0;
    for(int i=0;i<Count;i++)
    {
        if(productList[i].getId()==product_id)
        {
            productList[i].setQuantity(quantity);
            found=1;
            break;
        }
    }if(found==0)
           cout<<"NOT FOUND\n";
}
double Stock::getProductQuantity(int id)//gets product's quantity if found
{
    bool found=0;
    for(int i=0;i<Count;i++)
    {
        if(productList[i].getId()==id)
        {
            found=1;
            double p;
            return productList[i].getQuantity();
        }break;
    }if(found==0)
    {
         return -1;
    }
}
 double Stock::searchForPrice(int id)//if an product exists it returns its sale price
 {
     bool found=0;
     for(int i=0;i<Count;i++)
     {
         if(productList[i].getId()==id)
         {
             found=1;
             return productList[i].getSalePrice();
         }
     }if(found==0)
     {
         cout<<"This product isn't available\n";
     }
 }
 void Stock::calcProfit(int productid)//find the profit of product
 {
     bool found =0;
     double profit;
     for(int i=0;i<Count;i++)
     {
         if(productList[i].getId()==productid)
         {
             found=1;
             profit=productList[i].getSalePrice()-productList[i].getPrice();
             break;
         }
     }if(found)
         cout<<"Profit : "<<profit<<endl;
 }
void Stock::productCount()//prints the number of products
{
    cout<<"The total products "<<this->Count<<"\n";
}
void Stock::print()//prints all products in stock
{
    cout<<"_______________________________________________________________________________________________________\n";
    cout<<"id\tname\tnumber\tprice\tsale price\tquantity \n";
    for(int i=0;i<Count;i++)
    {
            productList[i].print();
    }
    cout<<"_______________________________________________________________________________________________________\n";
}
