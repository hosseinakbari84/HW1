#pragma once
#include "ItemMenu.h"
#include <iostream>
#include <vector>
class Menu {
    public:
    std::vector<ItemMenu> items;
    Menu(const std::vector<ItemMenu>& its);
    void showMenu();
};