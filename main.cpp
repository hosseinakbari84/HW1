#include <iostream>
#include <string>
#include <vector>

class ItemMenu {
public:
    std::string name;
    double price;
};
class Menu{
    protected:
    std::vector<ItemMenu> items;
    public:
    void showMenu() {
        for (const auto& item : items) {
            std::cout << item.name << ": $" << item.price << std::endl;
        }
    }
};
class Student{
    protected:
    std::string name;
    int studentID;
    public:
    Student(std::string n, int id) : name(n), studentID(id) {}
};
enum OrderStatus { PENDING, COMPLETED, CANCELLED };
class Order{
    protected:
    std::vector<ItemMenu> items;
    double totalPrice;
    OrderStatus status;
    static int orderID;
    Student customer;
    public:
    void changeStatus(OrderStatus newStatus) {
        status = newStatus;
    }
    void changeOrder(const std::vector<ItemMenu>& newItems) {
        if (status == PENDING) {
            items = newItems;
        }
        else {
            std::cout << "Order cannot be changed as it is not in PENDING status." << std::endl;
            return;
        }
    } 
    

};
int Order::orderID = 0;

