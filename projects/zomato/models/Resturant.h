#ifndef RESTURANT_H
#define RESTURANT_H

#include <iostream>
#include <string> 
#include <vector>

using namespace std;
#include "MenuItem.h"

class Resturant{
    private:
        static int nextResturantId;
        int resturantId;
        string name;
        string location;
        vector<MenuItem> menu;

    public:
        Resturant(const string& name, const string& location) {
            this->name = name;
            this->location = location;
            this->resturantId = nextResturantId++;
        }
        ~Resturant() {
        // Optional: just for clarity or debug
        cout << "Destroying Restaurant: " << name << ", and clearing its menu." << endl;
        menu.clear();
       }
       
       string getName() const{
             return name;
       }

       void setName(const string &n){
             name = n;
       }

       string getLocation() const{
             return location;
       }

       void setLocation(const string &l){
             location = l;
       }

       void addMenuItem(const MenuItem &item){
            menu.push_back(item);
       }

       const vector<MenuItem>& getMenu() const{
            return menu;
       }
};

int Resturant::nextResturantId = 0;