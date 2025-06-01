#include <iostream>
using namespace std;

class MySqlDb{
    public:
    void save(string data){
        cout << "Saving to MySql " << data << " data saved to mysql" << endl;
    }
};

class MongoDb{
    public:
    void save(string data){
        cout << "Saving to MongoDb " << data << " data saved to MongoDb" << endl;
    }
};

//User Service is tightly coupled to MySql and MongoDb
//which violates SOLID priciple

class UserService{
     private:
     MySqlDb* sqlDb;
     MongoDb* mongoDb;

     public:
     void saveToMySql(string data){
         sqlDb->save(data);
     }
     void saveToMongoDb(string data){
         mongoDb->save(data);
     }
};

int main(){
    UserService* userService = new UserService();
    userService->saveToMySql("Hello");
    userService->saveToMongoDb("Hello");
    return 0;
}