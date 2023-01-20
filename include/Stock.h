#ifndef STOCK_H
#define STOCK_H
#include<iostream>
#include"../include/Product.h"
using namespace std;
class Stock
{
    friend istream&operator>>(istream&in,Stock&s);
    friend ostream&operator<<(ostream&out,Stock&s);
    public:
        Stock();
        Stock(int);
        virtual ~Stock();
        void updateStock(int,double);
        void addProduct();
        void editProduct(int);
        void deleteProduct(int);
        void productCount();
        double getQuantity(int);
        void print();
       double Search(int id);
       double getProductQuantity(int id);
       double searchForPrice(int);
       void calcProfit(int);
       void saveToFile();

    protected:

    private:
        int Count,Size;
        Product*productList;
};

#endif // STOCK_H
