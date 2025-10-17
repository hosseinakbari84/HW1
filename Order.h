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
    public:
    std::vector<OrderItem> items;
    double totalPrice;
    OrderStatus status;
    static int ordercounter;
    int orderID;
    Student* orderer;
    void changeOrder(const std::vector<OrderItem>& newItems);
    Order(const std::vector<OrderItem>& its, Student *cust);
    Order();
    void cancelOrder();
    void completeOrder();
    void printOrder() const;
    Order* nextOrder = nullptr;

};