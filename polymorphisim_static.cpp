#include<iostream>
#include<string>

using namespace std;

class Car{
    private:
    string brand;
    string model;

    int gear = 0;

    public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        cout << " A new car brand " << brand << " model " << model << " has been created" << endl;
    }

    void shiftGear(){
        gear++;
        cout << "Car of " << brand << " brand of model " << model << " has shifted to gear " << gear << endl;
    }

    void shiftGear(int gear){
        this->gear = gear;
        cout << "Car of " << brand << " brand of model " << model << " has shifted to gear " << gear << endl;
    }
};
int main (){

    Car c1("Honda", "Civic");
    c1.shiftGear();
    c1.shiftGear(3);
    return 0;


}