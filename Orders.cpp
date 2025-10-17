#include "Orders.h"
void Orders::addOrder(Order *newOrder)
{
    if (!head)
    {
        head = newOrder;
    }
    else
    {
        Order *current = head;
        while (current->nextOrder)
        {
            current = current->nextOrder;
        }
        current->nextOrder = newOrder;
    }
}

Orders::Orders() : head(nullptr) {}
Orders::~Orders()
{
    Order *current = head;
    while (current)
    {
        Order *toDelete = current;
        current = current->nextOrder;
        delete toDelete;
    }
}
void Orders::displayOrders()
{
    Order *current = head;
    while (current)
    {
        std::cout << "Order ID: " << current->orderID << "\n";
        std::cout << "Student: " << current->orderer->getName() << "\n";
        std::cout << "Student ID: " << current->orderer->getID() << "\n";
        std::cout << "Items:\n";
        for (const auto &item : current->items)
        {
            std::cout << "- " << item.product.name << " (" << item.count << "): $" << item.product.price << " = $" << item.product.price * item.count << "\n";
        }
        std::cout << "Total Price: $" << current->totalPrice << "\n";
        std::cout << "Status: ";
        if (current->status == PENDING)
            std::cout << "PENDING\n";
        else if (current->status == COMPLETED)
            std::cout << "\033[32m" << "COMPLETED" << "\033[0m\n";
        else if (current->status == CANCELLED)
            std::cout << "\033[31m" << "CANCELLED" << "\033[0m\n"; 
        std::cout << "--------------------------\n";
        current = current->nextOrder;
    }
}

Order* Orders::findOrderByID(int orderID)
{
    Order *current = head;
    while (current)
    {
        if (current->orderID == orderID)
        {
            return current;
        }
        current = current->nextOrder;
    }
    return nullptr;
}