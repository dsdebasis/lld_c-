#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

using namespace std;

class UpiPaymentStrategy : public PaymentStrategy {
private:
    string mobileNo;
public:
    UpiPaymentStrategy(const string& mob) {
        mobileNo = mob;
    }
    void pay(double amount) override{
        cout << "Paying " << amount << " using UPI on " << mobileNo << endl;
    }
};

#endif