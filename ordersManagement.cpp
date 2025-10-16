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

    std::string line;
    while (std::getline(inFile, line))
    {
        Order newOrder;
        std::stringstream ss(line);
        std::string part;
        std::vector<std::string> parts;
        while (std::getline(ss, part, ','))
        {
            if (!part.empty())
            {
                parts.push_back(part);
            }
        }
        newOrder.orderID = std::stoi(parts[0]);
        newOrder.customer.name = parts[1];
        newOrder.customer.studentID = std::stoi(parts[2]);
        int statusInt = std::stoi(parts[3]);
        newOrder.status = static_cast<OrderStatus>(statusInt);
        int itemCount = std::stoi(parts[4]);
        for (int i = 0; i < itemCount; ++i)
        {
            OrderItem item;
            item.product.name = parts[5 + i * 3];
            item.product.price = std::stod(parts[5 + i * 3 + 1]);
            item.count = std::stoi(parts[5 + i * 3 + 2]);
            newOrder.items.push_back(item);
        }
        parts.clear();
        newOrder.totalPrice = 0.0;
        for (const auto &item : newOrder.items)
        {
            newOrder.totalPrice += item.product.price * item.count;
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
        outFile << current->orderID << "," << current->customer.getName() << "," << current->customer.getID() << "," << current->status << "," << current->items.size() << ",";
        for (const auto &item : current->items)
        {
            outFile << item.product.name << "," << item.product.price << "," << item.count << ",";
        }
        current = current->nextOrder;
        outFile << std::endl;
    }
    outFile.close();
    std::cout << "Data saved." << std::endl;
}