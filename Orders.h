#pragma once
#include "Order.h"

class Orders
{
private:
    Order *head;

public:
    Orders();
    ~Orders();
    void addOrder(Order *newOrder);
    void displayOrders();
};