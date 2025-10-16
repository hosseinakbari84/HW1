#include "Order.h"

int Order::ordercounter = 0;

void Order::changeOrder(const std::vector<OrderItem>& newItems) {
        if (status == PENDING) {
            items = newItems;
            totalPrice = 0.0;
            for (const auto& item : items) {
                totalPrice += item.product.price * item.count;
            }
        }
        else {
            std::cout << "Order cannot be changed as it is not in PENDING status." << std::endl;
            return;
        }
    }
Order::Order(const std::vector<OrderItem>& its, Student cust) : items(its), customer(cust), status(PENDING) {
        totalPrice = 0.0;
        for (const auto& item : items) {
            totalPrice += item.product.price * item.count;
        }
        ordercounter++;
        orderID = ordercounter;
        
    }
Order::Order() : totalPrice(0.0), status(PENDING), orderID(0), customer("", 0) {
        ordercounter++;
        nextOrder = nullptr;
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