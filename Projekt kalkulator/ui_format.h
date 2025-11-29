// ui_format.h
#pragma once
#include <string>
#include <vector>

struct MenuItem {
    int id;
    std::string label;
};

void clearout();
void waitEnter();
void showmenu(const std::vector<MenuItem>& items, const std::string& title);
std::string formatNumber(long double value);
