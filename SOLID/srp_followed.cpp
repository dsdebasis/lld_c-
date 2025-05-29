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

class PrintInvoice{
    private:
    ShopingCart* shop_cart;
    
    public:
    PrintInvoice(ShopingCart* cart){
      this->shop_cart = cart;
    }

    void getInvoice(){
        cout << "Printing the invoice of shoping_cart " << endl;
        for(auto p: shop_cart->getProducts()){
            cout << " product named " << p->name << " has price " << p->price << endl;
        }

    }

};

class ShopingCartStorage{
    private:
    ShopingCart* shop_cart;

    public:
    ShopingCartStorage(ShopingCart* cart){
               this->shop_cart = cart;
    }

    void saveCartToDb(){
        cout << "Saving the shoping cart to db " << endl;

    }

};
int main(){

    ShopingCart* cart = new ShopingCart();

    cart->addProduct(new Product("bt_speaker ",1220));
    cart->addProduct(new Product("ear_phone ",400));
   
    PrintInvoice* makeInvoice = new PrintInvoice(cart);
    makeInvoice->getInvoice();

    CartPrice* total_item_price = new CartPrice(cart);

    total_item_price->get_net_price();

    ShopingCartStorage* db = new ShopingCartStorage(cart);
    db->saveCartToDb();
    


    return 0;
}