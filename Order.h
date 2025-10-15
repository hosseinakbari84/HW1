#pragma once
#include "ItemMenu.h"
#include "Student.h"
#include <vector>
#include <iostream>
enum OrderStatus { PENDING, COMPLETED, CANCELLED };
struct OrderItem
{
    ItemMenu product;
    int count;
};

class Order{
    protected:
    std::vector<OrderItem> items;
    double totalPrice;
    OrderStatus status;
    static int orderID;
    Student customer;
    public:
    void changeOrder(const std::vector<OrderItem>& newItems);
    Order(const std::vector<OrderItem>& its, Student cust);
    void cancelOrder();
    void completeOrder();

};