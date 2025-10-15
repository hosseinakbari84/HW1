#pragma once
#include <iostream>
#include <vector>
#include "Order.h"
#include "Orders.h"
#include "Menu.h"
#include "ItemMenu.h"
#include "Student.h"
Orders ordersList;
void ReadOrdersFromFile(std::ifstream& file);
void WriteOrdersToFile(std::ofstream& file);
void addNewOrderToList(Menu& restaurantMenu);
