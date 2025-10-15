#include "Order.h"

void Order::changeStatus(OrderStatus newStatus) {
    status = newStatus;
}
void Order::changeOrder(const std::vector<ItemMenu>& newItems) {
        if (status == PENDING) {
            items = newItems;
        }
        else {
            std::cout << "Order cannot be changed as it is not in PENDING status." << std::endl;
            return;
        }
    }
