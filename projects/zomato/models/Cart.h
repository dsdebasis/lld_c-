#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include <string>

#include "Resturant.h"
#include "MenuItem.h"

using namespace std;

class Cart{
    private:
        Resturant* resturant;
        vector<MenuItem> items;

    public:
        Cart(){
            resturant = nullptr;
        }
        
        void addItem(const MenuItem& item){
            if(!resturant){
                cerr << "Add a resturant before adding a menu item" << endl;
                return;
            }
            items.push_back(item);
        }

        double getTotalPrice() const{
               double sum = 0;

               for(const auto& item : items){
                   sum += item->getPrice();
               }
               return sum;
        }

        bool isEmpty() {
            return (!resturant || items.empty());
        }
        
        void clear(){
            resturant = nullptr;
            items.clear();
        }

        void setResturant(Resturant* r){
            this->resturant = r;
        }

        Resturant* getResturant() const{
            return resturant;
        }
        const vector<MenuItem>& getItems() const{
            return items;
        }
             
};

#endif
