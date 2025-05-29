#include <iostream>
#include <string>

using namespace std;

class Car
{
protected:
    string brand;
    string model;
    int fuel = 0;
    bool isEngineeOn = false;
    int currentGear = 0;
    int currentSpeed = 0;
    int isInRepair = false;

public:
    Car(string b, string m)
    {
        this->brand = b;
        this->model = m;
        cout << " A new car brand " << brand << " model " << model << " has been created" << endl;
    }
    void startEnginee()
    {
        isEngineeOn = true;
        cout  << brand << " brand of model " << model << " has started engine " << endl;
    }

    void stopEnginee()
    {
        isEngineeOn = false;
        cout  << brand << " brand of model " << model << " has stopped engine " << endl;
    }
    void shiftGear(int gear)
    {
        currentGear = gear;

        cout  << brand << " brand of model " << model << " has shifted to gear " << currentGear << endl;
    }

    void accelerate()
    {
        currentSpeed++;
        cout  << brand << " brand of model " << model << " has accelerated to speed " << currentSpeed << endl;
    }
    void brake()
    {
        currentSpeed--;
        cout  << brand << " brand of model " << model << " has brakeed to speed " << currentSpeed << endl;
    }

    void refuel(int litr)
    {
        fuel = litr;
        cout << brand << " brand of model " << model << " has refueled " << litr << " litre" << endl;
    }
    void repair()
    {
        if (isInRepair)
            return;
        isInRepair = true;
        cout << brand << " brand of model " << model << " has repaired" << endl;
    }
    virtual ~Car() {}
};

class MannualCar : public Car
{
public:
    MannualCar(string b, string m) : Car(b, m) {}

    //special feature for mannual car
    void stearing(){
            cout << "MannualCar of " << brand << " brand of model " << model << " shifted stearing " << endl;
     }
};

class AutomaticCar : public Car
{
public:
    AutomaticCar(string b, string m) : Car(b, m) {
          cout << "AutomaticCar of " << brand << " brand of model " << model << " has shifted to gear " << currentGear << endl;
    }

    
        
      
    
};

int main()
{
    MannualCar* car = new MannualCar("Maruti", "m-800");
  
    
    //we did not define these methods ,still we can use them , as they are defined in the parent class

    car->startEnginee();
    car->shiftGear(2);
    car->accelerate();
    car->brake();
    // spefific to mannual car
    car->stearing();
    car->stopEnginee();

    cout << "First car ends here -------------------" << endl;
   AutomaticCar* car2 = new AutomaticCar("Honda", "City");
    car2->startEnginee();
    car2->shiftGear(4);
    car2->accelerate();
    car2->brake();

    car2->stopEnginee();
    return 0;
}