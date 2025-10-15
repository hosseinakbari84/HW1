#pragma once
#include "ItemMenu.h"
#include <iostream>
#include <vector>
class Menu{
    protected:
    std::vector<ItemMenu> items;
    public:
    void showMenu();
};