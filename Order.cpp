#include "Order.h"

int Order::orderID = 0;

void Order::changeOrder(const std::vector<ItemMenu>& newItems) {
        if (status == PENDING) {
            items = newItems;
            totalPrice = 0.0;
            for (const auto& item : items) {
                totalPrice += item.price;
            }
        }
        else {
            std::cout << "Order cannot be changed as it is not in PENDING status." << std::endl;
            return;
        }
    }
Order::Order(const std::vector<ItemMenu>& its, Student cust) : items(its), customer(cust), status(PENDING) {
        totalPrice = 0.0;
        for (const auto& item : items) {
            totalPrice += item.price;
        }
        orderID++;
    }

void Order::cancelOrder() {
        if (status == PENDING) {
            status = CANCELLED;
            std::cout << "Order has been cancelled." << std::endl;
        }
        else {
            std::cout << "Order cannot be cancelled as it is not in PENDING status." << std::endl;
        }
    }

void Order::completeOrder() {
        if (status == PENDING) {
            status = COMPLETED;
            std::cout << "Order has been completed." << std::endl;
        }
        else {
            std::cout << "Order cannot be completed as it is not in PENDING status." << std::endl;
        }
    }