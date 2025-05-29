#include <iostream>
#include <string>

// making a abstractin classs
using namespace std;

class Car
{

public:

  /*
    here we abstract out all the methods , basically we just have the concept of the methods , we do not have any implementation , we just have the concept . The implementation will be done in the child classes
 */
    virtual void startEnginee() = 0;
    virtual void stopEnginee() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;

    virtual void refuel(int litr) = 0;
    virtual void repair() = 0;

    virtual ~Car() {}
};

// this is the child class who is making the implementation of the abstract class
class RacingCar : public Car
{

public:
    string brand;
    string model;
    int fuel = 0;
    bool isEngineeOn = false;
    int currentGear =0;
    int currentSpeed=0;

    int isInRepair = false;

    RacingCar(string brand, string model)
    {

        this->brand = brand;
        this->model = model;
        
        cout << " A new car brand " << brand << " model " << model << " has been created" << endl;
      
    }

    void startEnginee()
    {
        isEngineeOn = true;
        cout << "RacingCar of " << brand << " brand of model " << model << " has started engine " << endl;
    }
    
    void stopEnginee(){
         isEngineeOn = false;
         cout << "RacingCar of " << brand << " brand of model " << model << " has stopped engine " << endl;
    }
    void shiftGear(int gear){
        currentGear = gear;
        
        cout << "RacingCar of " << brand << " brand of model " << model << " has shifted to gear " << currentGear << endl;
    }

    void accelerate(){
        currentSpeed++;
        cout << "RacingCar of " << brand << " brand of model " << model << " has accelerated to speed " << currentSpeed << endl;
    }
    void brake(){
        currentSpeed--;
        cout << "RacingCar of " << brand << " brand of model " << model << " has brakeed to speed " << currentSpeed << endl;
    }

    void refuel(int litr){
        fuel = litr;
        cout << "RacingCar of " << brand << " brand of model " << model << " has refueled " << litr << " litre" << endl;
    }
    void repair(){
        if(isInRepair) return;
        isInRepair = true;
        cout << "RacingCar of " << brand << " brand of model " << model << " has repaired" << endl;
    }
};

int main()
{
    Car *car = new RacingCar("Bugatti", "Veyron");
    car->startEnginee();
    car->shiftGear(3);
    car->accelerate();
    car->brake();
    car->stopEnginee();
    return 0;
}