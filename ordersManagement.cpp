#include <iostream>
#include <vector>
#include "Order.h"
#include "Orders.h"
#include "Menu.h"
#include "ItemMenu.h"
#include "Student.h"


Orders ordersList;
void addNewOrderToList(Menu& restaurantMenu){
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Enter your student ID: ";
    int studentID;
    std::cin >> studentID;
    Student customer(name, studentID);
    auto *orderItems = new std::vector<OrderItem>;
    int itemIndex, quantity;
    while (true)
    {
        std::cout << "Enter item number and quantity (0 0 to finish):" << std::endl;
        std::cin >> itemIndex >> quantity;
        if (itemIndex == 0 && quantity == 0)
            break;
        if (itemIndex < 1 || itemIndex > restaurantMenu.items.size() || quantity <= 0)
        {
            std::cout << "Invalid input. Try again." << std::endl;
            continue;
        }
        orderItems->push_back(OrderItem{restaurantMenu.items[itemIndex - 1], quantity});
    }
    auto newOrder = new Order(*orderItems, customer);
    delete orderItems;
    ordersList.addOrder(newOrder);
    std::cout << "Order added successfully!" << std::endl;
}


