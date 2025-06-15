#ifndef TOMATO_APP_H
#define TOMATO_APP_H

#include <vector>
#include <string>
#include "models/User.h"
#include "models/Resturant.h"
#include "models/Cart.h"
#include "managers/ResturantManager.h"
#include "managers/OrderManager.h"
#include "strategy/PaymentStrategy.h"
#include "strategy/UpiPaymnetStrategy.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledFactory.h"
#include "services/NotificationService.h"
#include "utils/Time.h"
using namespace std;

class ZomatoApp {
public:
    ZomatoApp() {
        initializeRestaurants();
    }

    void initializeRestaurants() {
        Resturant* resturant1 = new Resturant("Bikaner", "Delhi");
        resturant1->addMenuItem(MenuItem("P1", "Chole Bhature", 120));
        resturant1->addMenuItem(MenuItem("P2", "Samosa", 15));

        Resturant* resturant2 = new Resturant("Haldiram", "Kolkata");
        resturant2->addMenuItem(MenuItem("P1", "Raj Kachori", 80));
        resturant2->addMenuItem(MenuItem("P2", "Pav Bhaji", 100));
        resturant2->addMenuItem(MenuItem("P3", "Dhokla", 50));

        Resturant* resturant3 = new Resturant("Saravana Bhavan", "Chennai");
        resturant3->addMenuItem(MenuItem("P1", "Masala Dosa", 90));
        resturant3->addMenuItem(MenuItem("P2", "Idli Vada", 60));
        resturant3->addMenuItem(MenuItem("P3", "Filter Coffee", 30));

        ResturantManager* resturantManager = ResturantManager::getInstance();
        resturantManager->addResturant(resturant1);
        resturantManager->addResturant(resturant2);
        resturantManager->addResturant(resturant3);

        // Add other sample restaurants...
    }

    vector<Resturant*> searchRestaurants(const string& location) {
        return ResturantManager::getInstance()->searchByLocation(location);
    }

    void selectResturant(User* user, Resturant* restaurant) {
        Cart* cart = user->getCart();
        cart->setResturant(restaurant);
    }

    void addToCart(User* user, const string& itemCode) {
        Resturant* resturant = user->getCart()->getResturant();
        if (!resturant) {
            cout << "Please select a restaurant first." << endl;
            return;
        }
        for (const auto& item : resturant->getMenu()) {
            if (item.getId() == itemCode) {
                user->getCart()->addItem(item);
                break;
            }
        }
    }

    Order* checkoutNow(User* user, const string& orderType, PaymentStrategy* paymentStrategy) {
        return checkout(user, orderType, paymentStrategy, new NowOrderFactory());
    }

    Order* checkoutScheduled(User* user, const string& orderType, PaymentStrategy* paymentStrategy, const string& scheduleTime) {
        return checkout(user, orderType, paymentStrategy, new ScheduledOrderFactory(scheduleTime));
    }

    Order* checkout(User* user, const string& orderType, 
        PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
        if (user->getCart()->isEmpty())
        return nullptr;

        Cart* userCart = user->getCart();
        Resturant* orderedRestaurant = userCart->getResturant();
        vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalPrice();

        Order* order = orderFactory->createOrder(user, userCart, orderedRestaurant, itemsOrdered, paymentStrategy, totalCost, orderType);
        OrderManager::getInstance()->addOrder(order);
        return order;
    }

    void payForOrder(User* user, Order* order) {
        bool isPaymentSuccess = order->processPayment();

        // clear user cart if payment is successful.
        if(isPaymentSuccess) {
            NotificationService* notification = new NotificationService();
            notification->notify(order);
            user->getCart()->clear();
        }  
    }

    void printUserCart(User* user) {
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : user->getCart()->getItems()) {
            cout << item.getId() << " : " << item.getName() << " : ₹" << item.getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : ₹" << user->getCart()->getTotalPrice() << endl;
    }
};

#endif // TOMATO_APP_H
