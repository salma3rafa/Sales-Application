#ifndef CREDIT_H
#define CREDIT_H
#include"../include/Payment.h"
#include<string>
class Credit:public Payment
{
    public:
        Credit();
        virtual ~Credit();
        void makePay();
        void setCredit(std::string,std::string,std::string);
        std::string number;
        std::string type;
        std::string expireDate;
        std::string getNumber();
        std::string getType();
        std::string getExpireDate();

    protected:

    private:
};

#endif // CREDIT_H
