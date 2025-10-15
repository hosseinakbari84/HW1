#include "Menu.h"
#include <iostream>
void Menu::showMenu() {
        std::cout << "Menu:" << std::endl;
        int i = 1;
        for (const auto& item : items) {
            std::cout << i << ". " << item.name << ": $" << item.price << std::endl;
            i++;
        }
    }
Menu::Menu(const std::vector<ItemMenu>& its) : items(its) {}