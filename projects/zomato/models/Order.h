#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Resturant.h"
#include "MenuItem.h"
#include "../strategy/PaymentStrategy.h"
#include "../utils/Time.h"

using namespace std;


class Order{
protected:
   static int nextOrderId;
   int orderId;
   User* user;
   Resturant* resturant;
   vector<MenuItem> items;
   double total;
   string scheduled;
   PaymentStrategy* paymentStrategy;   

public:
    Order(){
        user = nullptr;
        resturant = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        scheduled = "";
        orderId = ++nextOrderId;
    }
    virtual ~Order(){
        delete paymentStrategy;
    }

    bool processPayment(){
        if(paymentStrategy ){
            paymentStrategy->pay(total);
            return true;
        } else{
            cout << "Please choose a payment mehtod" << endl;
            return false;
        }
    }

    virtual string getType() const= 0;

    int getOrderId() const{
        return orderId;
    }

    void setUser(User* u){
        user = u;
    }

    User* getUser() const{
        return user;
    }
    void setResturant(Resturant* r){
        resturant = r;
    }

    Resturant* getResturant() const{
           return resturant; 
    }

    void setItems(const vector<MenuItem>& i){
       items = i;
       total = 0.0;
       for(auto &i : items){
           total += i.getPrice();
       }
    }
    const vector<MenuItem>& getItems() const{
        return items;
    }

    void setPaymentStrategy(PaymentStrategy* p){
        paymentStrategy = p;
    }

    void setScheduled(const string& s){
        scheduled = s;
    }
    string getScheduled() const{
        return scheduled;
    }

    double getTotal() const{
        return total;
    }

    void setTotal(double t){
        this->total = t;
    }

};
int Order::nextOrderId = 0;

#endif