#include<iostream>
using namespace std;

class Burger{
     public:
        virtual void prepare() = 0;
        virtual ~Burger() {}
};

class BasicBurger: public Burger{
    public:
        void prepare() override{
            cout << "Basic Burger is prepared, with tomato, bread, onion" << endl;
        }
};

class PremiumBurger: public Burger{
    public:
        void prepare() override{
            cout << "Premium Burger is prepared- with , mushroom ,banana , tomato , bread , onion " << endl;
        }
};

class StandardBurger: public Burger{
    public:
        void prepare() override{
            cout << "Standard Burger is prepared with , tomato , bread,onion ,masala" << endl;
        }
};

class BasicFruitBurger: public Burger{
    public:
        void prepare() override{
            cout << "Basic Fruit Burger is prepared, with banana , apple , tomato , bread , onion " << endl;
        }
};

class StandardFruitBurger: public Burger{
    public:
        void prepare() override{
            cout << "Standard Fruit Burger is prepared- with  ,banana , apple , cashew , bread  " << endl;
        }
};

class PremiumFruitBurger: public Burger{
    public:
        void prepare() override{
            cout << "Premium Fruit Burger is prepared- with  Pineapple , orange ,ice , curd ,banana , apple , tomato , bread , onion " << endl;
        }
};


class RoastedBread{
    public:
    virtual void prepare() = 0;
  
};  

class BasicRoastedBread: public RoastedBread{
    public:
    void prepare() override{
        cout << "Basic Roasted Bread is prepared, with alu, bread, onion" << endl;
    }
};

class MasalaRoastedBread: public RoastedBread{
    public:
    void prepare() override{
        cout << "Masala Roasted Bread is prepared- with  , Masala , bread , onion " << endl;
    }
};

class BasicVegRoastedBread: public RoastedBread{
    public:
    void prepare() override{
        cout << "Basic Veg Roasted Bread is prepared, with alu, bread, tomato, onion, chickpeas" << endl;
    }
};

class PremiumVegRoastedBread: public RoastedBread{
    public:
    void prepare() override{
        cout << "Premium Veg Roasted Bread is prepared- with  , Masala ,mushroom ,bread , onion " << endl;
    }
};

class MealFactory{
    public:
    virtual Burger* createBurger(string& type)=0;
    virtual RoastedBread* createRoastedBread(string& type)=0;
    virtual ~MealFactory() {}
};

class SinghBurger : public MealFactory{
public:
Burger* createBurger(string& type) override{
     if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
}

RoastedBread* createRoastedBread(string& type) override{
   if (type == "basic") {
            return new BasicRoastedBread();
        } else if (type == "standard") {
            return new MasalaRoastedBread();
        } 
        else {
            cout << "Invalid Garlic bread type! " << endl;
            return nullptr;
        }
    }

};

class KingBurger : public MealFactory{
public:
    Burger* createBurger(string& type) override{
        if (type == "basic") {
                return new BasicFruitBurger();
            } else if (type == "standard") {
                return new StandardFruitBurger();
            } else if (type == "premium") {
                return new PremiumFruitBurger();
            } else {
                cout << "Invalid burger type! " << endl;
                return nullptr;
            }
    }

    RoastedBread* createRoastedBread(string& type) override{
        if (type == "basic") {
                return new BasicVegRoastedBread();
            } else if (type == "standard") {
                return new PremiumVegRoastedBread();
            } 
            else {
                cout << "Invalid Garlic bread type! " << endl;
                return nullptr;
            }
    }
};

int main(){
    string burgerType = "standard";
    string breadType = "standard";
    
    MealFactory* factory = new KingBurger();
    Burger* burger = factory->createBurger(burgerType);
    RoastedBread* bread = factory->createRoastedBread(breadType);
    burger->prepare();
    bread->prepare();

    return 0;
}