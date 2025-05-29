#include<iostream>
#include<vector>

using namespace std;

//without following  Single Responsible priciple
class Product{
    public:
    string name;
    double price;

    //calling the constructor
    Product(string nme, double prc){
          this->name = nme;
          this->price = prc;  
    }

};

class ShopingCart{
    private:
    vector<Product*>products;

    public:
    void addProduct(Product* p){
         products.push_back(p);
         cout << "One product named " << p->name << " hasbeen added to the cart" << endl;

    }
    //returns all products in the shoping cart
    const vector<Product*>& getProducts(){
        return products;
    }
    double netPrice(){
        double totalPrice = 0;

        for(auto p :products){
            totalPrice+=p->price;
        }

        return totalPrice;
    }
    //shopingCart has multiple responsibility;

    void printInvoice(){
        cout << "Printing all the prodcut price" <<endl;
        for(auto p : products){
            cout << "product name-->" << p->name << " having price " << p->price <<" Rs." << endl;

        }
        cout << "Total Price is " << netPrice() << endl; 
    }

    void saveToDb(){
        cout << "Saving shoping cart to database" << endl;
    }
};


int main(){

    ShopingCart* myCart = new ShopingCart();
    myCart->addProduct(new Product("bluetooth_sp ",915.50));
    myCart->addProduct(new Product("laptop ",34000));

    myCart->printInvoice();
    myCart->saveToDb();
    return 0;

}