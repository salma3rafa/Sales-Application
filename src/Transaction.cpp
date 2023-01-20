#include "Transaction.h"
#include<iostream>
using namespace std;

Transaction::Transaction()
{
     payAmount=0;
    Count=0;
    transaction_date=time(0);
    pay=new Payment*[400];
}
Transaction::~Transaction()
{
    //dtor
}
ostream&operator<<(ostream&out,Transaction&t)//prints transaction date
{
     t.dt = ctime(&t.transaction_date);
     cout<<"date : ";
     out<<t.dt;
}
/*Transaction Transaction:: operator+(Order&o,Payment&p)
{
     Transaction tran;
     tran.payAmount=o.total+p.amount
      return  tran;
}*/
void Transaction::takePay()//takes pay with a way of the three options
{
    int type;
    cout<<"1-Credit, 2-Cash, 3-Check \n";
    cout<<"Type : ";
    cin>>type;
     if (type == 1)
    {
       Payment* credit= new Credit();
       credit->makePay();
        pay[Count] = credit;

    }
    else  if (type == 2)
    {
        Payment* cash= new Cash();
       cash->makePay();
        pay[Count] = cash;

    }else
    {
        Payment* check= new Check();
         check->makePay();
        pay[Count] = check;
    }
    Count++;
}
void Transaction::totalTran()//prints all transaction
{

    for(int i=0;i<Count;i++)
    {
        payAmount+=pay[i]->pay();
    }
    cout<<"Total transaction : "<<payAmount<<"\n";
}
void Transaction::setPAy(double pay)
{
    this->payAmount=pay;
}
double Transaction::getPay()
{
    return this->payAmount;
}
