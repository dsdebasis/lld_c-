#include<iostream>
using namespace std;

class DataBase{
    public:
    virtual void save(string data) = 0;
    
};  

class MySqlDb : public DataBase{
    public:
    void save(string data){
        cout << "Saving to MySql " << data << " data saved to mysql" << endl;
    }
};

class MongoDb : public DataBase{
    public:
    void save(string data){
        cout << "Saving to MongoDb " << data << " data saved to MongoDb" << endl;
    }
};

//high level module looseley coupled with low level module

class UserService{
   private:
   DataBase* db;

   public:
   UserService(DataBase* db_ref):db(db_ref){}

   void saveToDb(string data){
     db->save(data);
   }

};


int main(){
    MySqlDb mysql;
    MongoDb mongo;

    UserService service_1(&mysql);
    UserService service_2(&mongo);

    service_1.saveToDb("Debasis ");
    service_2.saveToDb("Papu");
    return 0;
}