#pragma once
#include "ItemMenu.h"
#include "Student.h"
#include <vector>
#include <iostream>
enum OrderStatus { PENDING, COMPLETED, CANCELLED };
class Order{
    protected:
    std::vector<ItemMenu> items;
    double totalPrice;
    OrderStatus status;
    static int orderID;
    Student customer;
    public:
    void changeOrder(const std::vector<ItemMenu>& newItems);
    Order(const std::vector<ItemMenu>& its, Student cust);
    void cancelOrder();
    void completeOrder();

};