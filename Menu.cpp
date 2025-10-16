#include "Menu.h"
#include <iostream>
void Menu::showMenu() {
        std::cout << "Menu:" << std::endl;
        int i = 1;
        for (const auto& item : items) {
            std::cout << i << ". " << item.name << ": $" << item.price << std::endl;
            i++;
        }
        std::cout << "--------------------------" << std::endl;
    }
Menu::Menu(const std::vector<ItemMenu>& its) : items(its) {}