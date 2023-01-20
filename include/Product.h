#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Product
{
    friend istream&operator>>(istream&in,Product&p);
    friend ostream&operator<<(ostream&out,Product&p);
    public:
        Product();
        virtual ~Product();
        int getId();
        int getType();
        double getPrice();
        std::string getName();
        std::string getNumber();
        void update();
        void saveTo(ofstream);
        void setProductData();
        void print();
        void setId(int id);
        double getQuantity();
        double getSalePrice();
        void setQuantity(double);
        void setPrice(double);

    protected:

    private:
        double sale_price;
        int id,type;
        std::string number,name;
        double price,quantity;
};

#endif // PRODUCT_H
