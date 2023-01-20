#ifndef CHECK_H
#define CHECK_H
#include"../include/Payment.h"
class Check:public Payment
{
    public:
        Check();
        virtual ~Check();
        std::string bank_id;
        std::string name;
        void makePay();
        void setBank(std::string,std::string);
        std::string getBankId();
        std::string getName();

    protected:

    private:
};

#endif // CHECK_H
