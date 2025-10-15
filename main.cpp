#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "ItemMenu.h"
#include "Order.h"
#include "Student.h"
// to be completed
void addOrder(Menu& restaurantMenu)
{
    std::vector<OrderItem> orderItems;
    int itemIndex, quantity;
    std::cout << "Enter item number and quantity (0 0 to finish):" << std::endl;
    while (true)
    {
        std::cin >> itemIndex >> quantity;
        if (itemIndex == 0 && quantity == 0)
            break;
        if (itemIndex < 1 || itemIndex > restaurantMenu.items.size() || quantity <= 0)
        {
            std::cout << "Invalid input. Try again." << std::endl;
            continue;
        }
        orderItems.push_back(OrderItem{restaurantMenu.items[itemIndex - 1], quantity});
    }
}

int main()
{
    Menu restaurantMenu = std::vector<ItemMenu>{
        ItemMenu("Burger", 5.99),
        ItemMenu("Pizza", 8.99),
        ItemMenu("Salad", 4.99),
        ItemMenu("Soda", 1.99),
        ItemMenu("Ice Cream", 3.49),
        ItemMenu("Coffee", 2.49),
        ItemMenu("Tea", 1.49),
        ItemMenu("Fries", 2.99),
        ItemMenu("Chicken Wings", 6.99),
        ItemMenu("Steak", 14.99)};
    int input;
    std::cout << "Welcome to the Restaurant!" << std::endl;
    while (1)
    {
        std::cin >> input;
        std::cout << "1. Show Menu" << std::endl;
        std::cout << "2. New Order" << std::endl;
        std::cout << "3. Deliver Order" << std::endl;
        std::cout << "4. Cancel Order" << std::endl;
        std::cout << "5. Change Order" << std::endl;
        std::cout << "6. Review Orders" << std::endl;
        std::cout << "0. Exit" << std::endl;
        switch (input)
        {
        case 0:
            std::cout << "Exiting the program." << std::endl;
            return 0;
        case 1:
            restaurantMenu.showMenu();
            break;
        case 2:
            addOrder(restaurantMenu);
            break;
        case 3:
            // Code to deliver an order
            break;
        case 4:
            // Code to cancel an order
            break;
        case 5:
            // Code to change an order
            break;
        case 6:
            // Code to review orders
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
    return 0;
}
