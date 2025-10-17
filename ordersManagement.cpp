#include "ordersManagement.h"
void addNewOrderToList(Menu &restaurantMenu)
{
    Student* newCustomer = nullptr;
    std::cout << "Enter your student ID: (0 to go back) ";
    int studentID;
    std::cin >> studentID;
    if (studentID == 0)
        return;
    if (studentID < 10000000 || studentID > 99999999)
    {
        std::cout << "Invalid student ID. Order not created." << std::endl;
        return;
    }
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    if(name.empty())
    {
        std::cout << "Name cannot be empty. Order not created." << std::endl;
        return;
    }
     if (studentsList.findStudentByID(studentID) != nullptr && studentsList.findStudentByID(studentID)->getName() != name)
    {
        std::cout << "Name does not match the student ID. Order not created." << std::endl;
        return;
    }
    if (studentsList.findStudentByID(studentID) != nullptr)
    {
        newCustomer = studentsList.findStudentByID(studentID);
    }
    else
    {
        newCustomer = new Student(name, studentID);
        studentsList.addStudent(newCustomer);
    }
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
    auto *newOrder = new Order(*orderItems, newCustomer);
    delete orderItems;
    newOrder->orderer->ordersID.push_back(newOrder->orderID);
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

        if (studentsList.findStudentByID(std::stoi(parts[2])) != nullptr)
        {
            newOrder.orderer = studentsList.findStudentByID(std::stoi(parts[2]));
        }
        else
        {
            Student* newStudent = new Student(parts[1], std::stoi(parts[2]));
            studentsList.addStudent(newStudent);
            newOrder.orderer = newStudent;
        }
        newOrder.orderer->ordersID.push_back(newOrder.orderID);

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
        outFile << current->orderID << "," << current->orderer->getName() << "," << current->orderer->getID() << "," << current->status << "," << current->items.size() << ",";
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


void deliverOrder(int orderID)
{
    if(orderID == 0)
        return;
    Order *current = ordersList.head;
    while (current)
    {
        if (current->orderID == orderID)
        {
            current->completeOrder();
            std::cout << "Order " << orderID << " marked as completed." << std::endl;
            return;
        }
        current = current->nextOrder;
    }
    std::cout << "Order ID " << orderID << " not found." << std::endl;
}

void cancelOrder(int orderID)
{
    if(orderID == 0)
        return;
    Order *current = ordersList.head;
    while (current)
    {
        if (current->orderID == orderID)
        {
            current->cancelOrder();
            return;
        }
        current = current->nextOrder;
    }
    std::cout << "Order ID " << orderID << " not found." << std::endl;
}
std::vector<OrderItem>& getNewItemsFromUser(Menu &restaurantMenu)
{
    restaurantMenu.showMenu();
    auto *newItems = new std::vector<OrderItem>;
    int itemIndex, quantity;
    while (true)
    {
        std::cout << "Enter item number and quantity for the new order (0 0 to finish):" << std::endl;
        std::cin >> itemIndex >> quantity;
        if (itemIndex == 0 && quantity == 0)
            break;
        if (itemIndex < 1 || itemIndex > restaurantMenu.items.size() || quantity <= 0)
        {
            std::cout << "Invalid input. Try again." << std::endl;
            continue;
        }
        newItems->push_back(OrderItem{restaurantMenu.items[itemIndex - 1], quantity});
    }
    return *newItems;
}

void changeOrder(int orderID, const std::vector<OrderItem>& newItems)
{
    Order *current = ordersList.head;
    while (current)
    {
        if (current->orderID == orderID)
        {
            current->items = newItems;
            std::cout << "Order " << orderID << " has been updated." << std::endl;
            return;
        }
        current = current->nextOrder;
    }
    std::cout << "Order ID " << orderID << " not found." << std::endl;
}

void changeTheOrder(Menu &restaurantMenu)
{
    std::cout << "Enter Order ID to change: ";
    int orderID;
    std::cin >> orderID;
    auto newItems = getNewItemsFromUser(restaurantMenu);
    changeOrder(orderID, newItems);
}