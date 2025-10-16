#include "ordersManagement.h"

void addNewOrderToList(Menu &restaurantMenu)
{
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Enter your student ID: ";
    int studentID;
    std::cin >> studentID;
    if (studentID < 10000000 || studentID > 99999999)
    {
        std::cout << "Invalid student ID. Order not created." << std::endl;
        return;
    }
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

void ReadOrdersFromFile()
{
    std::ifstream inFile("orders.txt");
    if (!inFile.is_open() || inFile.fail())
    {
        std::cout << "Cannot open orders.txt for reading\n";
        return;
    }

    Order newOrder;
    // Read orders from the file

    while (inFile >> newOrder.orderID)
    {
        // Read order details
        inFile >> newOrder.customer.name;
        inFile >> newOrder.customer.studentID;
        int statusInt;
        inFile >> statusInt;
        newOrder.status = static_cast<OrderStatus>(statusInt);
        int itemCount;
        inFile >> itemCount;
        for (int i = 0; i < itemCount; ++i)
        {
            OrderItem item;
            inFile >> item.product.name;
            inFile >> item.product.price;
            inFile >> item.count;
            newOrder.items.push_back(item);
        }
        ordersList.addOrder(new Order(newOrder));
    }
    inFile.close();
}

void WriteOrdersToFile()
{
    std::ofstream outFile("orders.txt");
    if (!outFile.is_open() || outFile.fail())
    {
        std::cerr << "Cannot open orders.txt for writing\n";
        return;
    }

    auto *current = ordersList.head;
    while (current != nullptr)
    {
        outFile << current->orderID << " " << current->customer.getName() << " " << current->customer.getID() << " " << current->status << " " << current->items.size() << std::endl;
        for (const auto &item : current->items)
        {
            outFile << item.product.name << " " << item.product.price << " " << item.count << std::endl;
        }
        current = current->nextOrder;
    }
    outFile.close();
    std::cout << "Data saved." << std::endl;
}