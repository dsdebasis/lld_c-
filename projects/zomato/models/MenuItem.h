#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
using namespace std;

class MenuItem {
        string id;
        string name;
        double price;
    public:    
        MenuItem(const string& id,const string& name, const double& price) {
            this->id = id;
            this->name = name;
            this->price = price;
        }

        string getId() const{
            return id;
        }

        void setId(const string &i) {
            id = i;
            
        }
        string getName() {
            return name;
        }

        void setName(const string &n) {
            name = n;
        }
        
        double getPrice() {
            return price;
        }

        void setPrice(const double &p) {
            price = p;
        }
};

#endif