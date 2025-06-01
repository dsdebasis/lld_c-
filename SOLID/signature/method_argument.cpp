#include <iostream>
using namespace std;

class Parent {
      public:
      virtual void print(string msg){
         cout << "Parent " << msg <<endl;
           cout << "callign from parent ";
      }
};

class Child : public Parent {
      public:
      void print(string msg) override{
         cout << "Child " << msg <<endl;
         
      }
};

class Client {
    private:
    Parent* p;

    public:
    Client(Parent* p){
        this->p = p;
    }
    void printMsg(string msg){
        p->print(msg);
      

    }

};
int main(){
    Parent* p = new Parent();
    Parent* c = new Child();
//here we apply liskov substitution principle ->that the child class should repalce or behave like the parent class without braking the functionality

    Client* clnt = new Client(c);

    clnt->printMsg("Hello");
    return 0;
}