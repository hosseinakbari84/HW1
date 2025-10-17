#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ordersManagement.h"

int main()
{
    std::cout << "Loading data..." << std::endl;
    ReadOrdersFromFile();

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
        std::cout << "1. Show Menu" << std::endl;
        std::cout << "2. New Order" << std::endl;
        std::cout << "3. Deliver Order" << std::endl;
        std::cout << "4. Cancel Order" << std::endl;
        std::cout << "5. Change Order" << std::endl;
        std::cout << "6. Review Orders" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cin >> input;
        switch (input)
        {
        case 0:
            std::cout << "Exiting the program." << std::endl;
            goto endofProgram;
            break;
        case 1:
            restaurantMenu.showMenu();
            break;
        case 2:
            restaurantMenu.showMenu();
            addNewOrderToList(restaurantMenu);
            break;
        case 3:
            std::cout << "Enter Order ID to deliver: ";
            int orderID;
            std::cin >> orderID;
            deliverOrder(orderID);
            break;
        case 4:
            std::cout << "Enter Order ID to cancel: ";
            std::cin >> orderID;
            cancelOrder(orderID);
            break;
        case 5:
            changeTheOrder(restaurantMenu);
            break;
        case 6:
            ordersList.displayOrders();
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }
    endofProgram:
    std::cout << "Saving data..." << std::endl;
    WriteOrdersToFile();
    std::cout << "Goodbye!" << std::endl;
    return 0;
}
