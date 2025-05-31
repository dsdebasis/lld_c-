#include<iostream>
#include<vector>

using namespace std;
class Product{
    public:
    string name;
    double price;

    Product(string name, double price){
           this->name = name;
           this->price = price;      
    }
};

//shopingCart onlu responsible for cart related business logic
class ShopingCart{
    private:
    vector<Product*>products;
    
    public:
    void addProduct(Product* p){
         products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

 

};

class CartPrice{
    private:
    ShopingCart* shop_cart;
    double total_price = 0;

    public:
    CartPrice(ShopingCart* cart){
        this->shop_cart = cart;
    }
    void get_net_price(){
         cout << "calculatig total price " << endl;

      
         for(auto crt :shop_cart->getProducts()) {
            cout << " price is " << crt->price << endl;
            total_price += crt->price;
         }
         cout << " Netprice is " << total_price <<endl;

    }
};

class Persistance{
    private:
    ShopingCart* cart;

    public:
    virtual void save(ShopingCart* crt)= 0;
};


class MongoPersitance : public Persistance{
    public:
      void save(ShopingCart* crt) override{
           cout << " Saving the cart to MongoDb" << endl;
      }
};
class MySqlPersistance : public Persistance{
    public:
      void save(ShopingCart* crt) override{
           cout << " Saving the cart to MySql" << endl;
      }
};
class RedisPersitance : public Persistance{
     public:
      void save(ShopingCart* crt) override{
           cout << " Saving the cart to redis db " << endl;
      }
};

int main(){

    ShopingCart* cart = new ShopingCart();

    cart->addProduct(new Product("bt_speaker ",1220));
    cart->addProduct(new Product("ear_phone ",400));

    CartPrice* total_item_price = new CartPrice(cart);

    total_item_price->get_net_price();

    MongoPersitance* mongo = new MongoPersitance();
    RedisPersitance* redis = new RedisPersitance();
    
    mongo->save(cart);
    redis->save(cart);
    


    return 0;
}