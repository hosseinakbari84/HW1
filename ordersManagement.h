#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Order.h"
#include "Orders.h"
#include "Menu.h"
#include "ItemMenu.h"
#include "Student.h"
inline Orders ordersList;
void ReadOrdersFromFile();
void WriteOrdersToFile();
void addNewOrderToList(Menu& restaurantMenu);
