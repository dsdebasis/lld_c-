#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/Time.h"

using namespace std;

class ScheduledOrderFactory : public OrderFactory {
private:
    string scheduledTime;
public:
    ScheduledOrderFactory(string scheduleTime){
        this->scheduledTime = scheduleTime;
    }    

    Order* createOrder(User* user, Cart* cart, Resturant* resturant, const vector<MenuItem>& menuItems,
                        PaymentStrategy* paymentStrategy, double totalCost, const string& orderType) override {
        Order* order = nullptr;

        if(orderType == "Delivery") {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        } 
        else {
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(resturant->getLocation());
        }
        order->setUser(user);
        order->setResturant(resturant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(scheduledTime);
        order->setTotal(totalCost);
        return order;
    }
};

#endif