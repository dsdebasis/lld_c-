#ifndef CREDIT_CARD_PAYMENT_STRATEGY
#define CREDIT_CARD_PAYMENT_STRATEGY

#include "PaymentStrategy.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class CreditCardPaymentStrategy : public PaymentStrategy {
private:
    string cardNumber ;

public:
    CreditCardPaymentStrategy(const string& cardN) {
        cardNumber = cardN;
    }
    void pay(double amount) {
         cout << "Paid ₹" << amount << " using Credit Card (" << cardNumber << ")" << endl;
    }
};

#endif