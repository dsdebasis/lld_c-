#include<iostream>
using namespace std;
class Animal{
  
};

class Dog:public Animal{
    
};

class Parent {
     public:
     virtual Animal* getAnimal(){
        cout << "Parent returning animal instance" << endl;
         return new Animal();
     }

};

class Child:public Parent{
    public:
    Animal* getAnimal() override{
        cout << "Child returning Dog instance" << endl;
        return new Dog();
    }
};
class Clinet{
    private:
    Parent* p;

    public:
    Clinet(Parent* p){
          this->p = p;

    }
    void takeAnimal(){
        p->getAnimal();
    } 
};
int main(){

    Parent* p = new Parent();
    Child* c = new Child();
    // Clinet* clnt = new Clinet(p);
    
    // clnt->takeAnimal();
    Clinet* clnt2 = new Clinet(c);
    clnt2->takeAnimal();
    return 0;
}