#ifndef USER_H
#define USER_H

#include <string>
#include "Cart.h"
using namespace std;

class User {
    private:
        int userId;
        string userName;
        string address;
        Cart* cart;

    public:
        User(int id, const string& name, const string& address) {
            this->userId = id;
            this->userName = name;
            this->address = address;
            this->cart = new Cart();
        }
        
        ~User() {
            delete cart;
        }

        string getName() const{
             return userName;
        }

        void setName(const string &n){
             userName = n;
        }

        string getAddress() const{
             return address;
        }

        void setAddress(const string &a){
             address = a;
        }

        Cart* getCart(){
             return cart;
        }
};
#endif