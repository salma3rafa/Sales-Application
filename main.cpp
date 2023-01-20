#include <iostream>
#include"../include/Customers.h"
#include"../include/Stock.h"
#include"../include/Transaction.h"
#include <cstdlib>          // cls
#include <windows.h>        // Sleep
#include <bits/stdc++.h>    // stringstream
#include <windows.h>        // SetConsoleTextAttribute
/*
Dear me if u got insane and decided to read this code to remember your feelings when you were coding it
i'm the old selfish version of u. u suffered a lot when you were writing this code not because it was hard to be written.. nope because u were having a lot of
problems in your life but u didn't give up u just decided to suffer with this assignment during suffering with your life so please if you're rude with yourself
and i know u're as always please the future me ..just don't blame urself and be good with u as u've been struggling your whole life
You wanted to just give up and forget about this task and your whole life but u found ur way to come back every time..please be proud of yourself even if you didn't
achieve your goals or even anything u survived alone honey u faced your hard time alone and it's a big win
maybe you haven't done anything but you tried to save yourself and keep your health.. i'm proud of u honey it's not your fault it was
their fault they made u bad they made u weird but u are still pretty and strong.. iam proud of u please be good and i hope one day that u find
yourself and happiness..bye
*/
using namespace std;
HANDLE cout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

/** ASSISTANT INLINE FUNCTIONS **/
inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    Sleep(sec*1000);
    if (clear_screen) system("cls");
}

inline void printline(string msg, bool end_line = true, int color_code=5)
{
    SetConsoleTextAttribute(cout_handle, color_code);
  //  SetConsoleTextAttribute(cout_handle, color_code);
    cout <<  msg << (end_line?"\n":"\t");
}
int main()
{
    Customers c(300);
    Stock s(200);
    Product p;
    Payment pay;
    Transaction*trans;
    int Count=0,Size;
    cout<<"Enter transaction's size : ";
    cin>>Size;
    trans=new Transaction[Size];
    printline("START APPLICATION ....",1,6);
    wait_or_clear(1,1);
    int key=-1;
            while(key!=0){
           cout<<"_________________________________________Sales order Application________________________________________________________"
            <<"\n"
            <<"\n"
            <<"0-leaving\n"
            <<"1-Add new customer\n"
            <<"2-Update customer\n"
            <<"3-Delete customer\n"
            <<"4-Add new order\n"
            <<"5-Print customer's oder\n"
            <<"6-Update order\n"
            <<"7-Update order's quantity\n"
            <<"8-Pay order\n"
            <<"9-Print customers\n"
            <<"10-print stock data\n"
            <<"11-print transaction\n"
            <<"12-Add new product \n"
            <<"13-Update product\n"
            <<"14-Update stock\n"
            <<"15-Calculate profit \n"
            <<"16-Delete product\n"
            <<"17-To go back to menu\n";
            cout<<"________________________________________________________________________________________________________________________\n";
            cout<<"Enter your keyword\n";
                    cin>>key;
            switch(key)
            {
            case 1:
                {
                    c.addCustomer();
                }break;
            case 2:
                {
                    c.editCustomer();
                }break;
            case 3:
                {
                    c.deleteCustomer();
                }break;
                case 4:
                    {
                            int id;
                            cout<<"Enter the product id to check before making order : ";
                            cin>>id;
                          if( s.Search(id)==-1){
                            cout<<"id isn't found\n";
                          }else{
                                   double quantity=s.Search(id);

                                   double oquantity;
                                   cout<<"Enter the order's quantity : ";
                                   cin>>oquantity;
                                   if(oquantity<=quantity)
                                   {
                                        c.createOrder(s.searchForPrice(id));
                                       double mquantity=s.getProductQuantity(id)-oquantity;
                                       s.updateStock(id,mquantity);
                                  }else{cout<<"This quantity of product isn't avaliable\n";}
                               }
                    }break;
                case 5:
                    {
                        int id;
                        cout<<"Enter customer's id to print : ";
                        cin>>id;
                        c.printCustomerOrders(id);
                    }break;
                    case 6:
                        {
                            c.UpdateOrder();
                        }break;
                    case 7:
                        {

                            cout<<"1-for adding 1,2for deleting 1,3 for adding n,4 for deleting n\n";
                            int x,id;
                            cin>>x;
                            cout<<"Enter product id : ";
                            cin>>id;
                            if(s.Search(id)==-1)
                            {
                                cout<<"Product isn't found\n";
                            }else{
                            c.UpdateQuantity();
                            double pQuantity,quantity=s.Search(id);
                            if(x==1)
                            {
                                pQuantity=quantity-1;
                                s.updateStock(id,pQuantity);
                            }else if(x==2)
                            {
                                pQuantity=quantity+1;
                                s.updateStock(id,pQuantity);
                            }else if(x==3)
                            {
                               int n;
                               cout<<"Enter the number of product to Update : ";
                               cin>>n;
                                pQuantity=quantity-n;
                                s.updateStock(id,pQuantity);
                            }else if(x==4)
                            {
                                 int n;
                               cout<<"Enter the number of product to Update : ";
                               cin>>n;
                                pQuantity=quantity-n;
                                s.updateStock(id,pQuantity);
                            }
                        }break;
                    case 8:
                        {
                            int customerId,orderId;
                            cout<<"Enter customer's id& order id : ";
                            cin>>customerId>>orderId;
                            if(c.findOrder(customerId,orderId)&&c.seacrchForStatues(customerId,orderId)==0){
                            Transaction tran;
                            tran.takePay();
                            trans[Count]=tran;
                            Count++;
                            }
                        }break;
                    case 9:
                        {
                            c.print();
                        }break;
                    case 10:
                        {
                            s.print();
                            s.productCount();

                        }break;
                    case 11:
                        {
                            for(int i=0;i<Count;i++)
                            {
                                cout<<trans[i]<<"  ";
                                trans[i].totalTran();
                            }
                            cout<<"Count: "<<Count<<"\n";
                            cout<<"\n";

                        }break;
                    case 12:
                        {
                            s.addProduct();
                        }break;
                    case 13:
                        {
                            cout<<"Enter product's id to check before editing \n";
                            cin>>id;
                            s.editProduct(id);
                        }break;
                    case 14:
                        {
                            double quantity;
                            int id;
                            cout<<"Enter product's id to check \n";
                            cin>>id;
                            cout<<"Enter product's quantity to Update \n";
                            cin>>quantity;
                            s.updateStock(id,quantity);
                        }break;
                    case 15:
                        {
                            int id;
                            cout<<"Product id : ";
                            cin>>id;
                            s.calcProfit(id);
                        }break;
                    case 16:
                        {
                            int id;
                            cout<<"Enter product's id to check before deleting \n";
                            cin>>id;
                            s.deleteProduct(id);
                        }break;
                    case 17:
                        {
                            main();
                        }break;
                    delete []trans;

            }

            }

            }
            cout<<"Nice to see u, we wish to never see you again \03 \n";





    return 0;
}
