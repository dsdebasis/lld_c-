#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include "./OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/Time.h"
#include "../strategy/PaymentStrategy.h"

#include <vector>
#include <string>
using namespace std;

class NowOrderFactory : public OrderFactory {
public:
    Order* createOrder(User* user, Cart* cart, Resturant* resturant, const vector<MenuItem>& menuItems,
    PaymentStrategy* paymentStrategy, double totalCost, const string& orderType) override  {
        Order* order = nullptr;
        if (orderType == "Delivery") {
            auto deliveryOrder = new  DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        }
        else {
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(resturant->getLocation());
            order = pickupOrder;
        }
        order->setUser(user);
        order->setResturant(resturant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(Time::getCurrentTime());
        order->setTotal(totalCost);
        return order;
    }
    
};

#endif