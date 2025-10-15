#include "Menu.h"
#include <iostream>
void Menu::showMenu() {
        for (const auto& item : items) {
            std::cout << item.name << ": $" << item.price << std::endl;
        }
    }