#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Order.h"
#include "Orders.h"
#include "Menu.h"
#include "ItemMenu.h"
#include "Student.h"
#include "Students.h"
#include <sstream>
inline Orders ordersList;
inline Students studentsList;
void ReadOrdersFromFile();
void WriteOrdersToFile();
void addNewOrderToList(Menu& restaurantMenu);
void deliverOrder(int orderID);
void cancelOrder(int orderID);
void changeOrder(int orderID, const std::vector<OrderItem>& newItems);
std::vector<OrderItem>& getNewItemsFromUser(Menu &restaurantMenu);
void changeTheOrder(Menu &restaurantMenu);