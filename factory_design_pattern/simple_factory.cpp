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

class StandardBurger: public Burger{
      public:
      void prepare() override{
            cout << "Standard Burger is prepared with , tomato , bread,onion ,masala" << endl;
      }
};

class PremiumBurger: public Burger{
      public:
      void prepare() override{
            cout << "Premium Burger is prepared- with , mushroom ,banana , tomato , bread , onion " << endl;
      }
};

class BurgerFactory{
      public:
      static Burger* createBurger(string& type){
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

int main (){
    string type = "basic";
    
    BurgerFactory* factory = new BurgerFactory();
    Burger* burger = factory->createBurger(type);
    burger->prepare();

    return 0;
}