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
        std::cout << "Student: " << current->customer.getName() << "\n";
        std::cout << "Student ID: " << current->customer.getID() << "\n";
        std::cout << "Items:\n";
        for (const auto &item : current->items)
        {
            std::cout << "- " << item.product.name << " (" << item.count << "): $" << item.product.price << " = $" << item.product.price * item.count << "\n";
        }
        std::cout << "Total Price: $" << current->totalPrice << "\n";
        std::cout << "Status: " << (current->status == OrderStatus::PENDING ? "Pending" : (current->status == OrderStatus::COMPLETED ? "Completed" : "Cancelled")) << "\n";
        std::cout << "--------------------------\n";
        current = current->nextOrder;
    }
}