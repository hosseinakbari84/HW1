#pragma once
#include "Order.h"

class Orders
{
public:
Order *head;
    Orders();
    ~Orders();
    void addOrder(Order *newOrder);
    void displayOrders();
};