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