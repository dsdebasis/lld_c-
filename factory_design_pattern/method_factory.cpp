#include<iostream>
using namespace std;

class Burger{
    public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger:public Burger{
    public:
    void prepare() override{
        cout << "Basic Burger is prepared, with tomato, bread, onion" << endl;
    }
};

class StandardBurger:public Burger{
    public:
    void prepare() override{
        cout << "Standard Burger is prepared with , tomato , bread,onion ,masala" << endl;
    }
};
class PremiumBurger:public Burger{
    public:
    void prepare() override{
        cout << "Premium Burger is prepared- with , mushroom ,banana , tomato , bread , onion " << endl;
    }
};

class BasicFruitBurger:public Burger{
    public:
    void prepare() override{
        cout << "Premium Burger is prepared- with  ,banana , apple , tomato , bread , onion " << endl;
    }
};

class StandardFruitBurger:public Burger{
    public:
    void prepare() override{
        cout << "Premium Burger is prepared- with  ,ice , curd ,banana , apple , tomato , bread , onion " << endl;
    }
};

class PremiumFruitBurger:public Burger{
    public:
    void prepare() override{
        cout << "Premium Burger is prepared- with  Pineapple , orange ,ice , curd ,banana , apple , tomato , bread , onion " << endl;
    }
};

class BuurgerFactory{
    public:
    virtual Burger* createBurger(string& type)=0;
};
class NormalBurgerFactory:public BuurgerFactory{
    public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicBurger();
        }else if(type == "standard"){
            return new StandardBurger();
        }else if(type == "premium"){
            return new PremiumBurger();
        }else{
            return nullptr;
        }
    }
};

class FruitBurgerFactory:public BuurgerFactory{
    public:
    Burger* createBurger(string& type){
        if(type == "basic"){
            return new BasicFruitBurger();
        }else if(type == "standard"){
            return new StandardFruitBurger();
        }else if(type == "premium"){
            return new PremiumFruitBurger();
        }else{
            return nullptr;
        }
    }
};

int main (){
    string type = "standard";
    BuurgerFactory* factory = new NormalBurgerFactory();
    Burger* burger = factory->createBurger(type);
    burger->prepare(); 

    cout <<"--------------------end------------------" << endl;

    type = "premium";
    factory = new FruitBurgerFactory();
    burger = factory->createBurger(type);
    burger->prepare();
    return 0;
}