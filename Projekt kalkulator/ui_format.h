#pragma once
#include <string>
#include <vector>

struct MenuItem {
    MenuItem() = default;
    MenuItem(int idValue, const std::string& text)
        : id(idValue), label(text), displayId(true) {}
    MenuItem(const char* text)
        : id(0), label(text), displayId(false) {}
    MenuItem(const std::string& text)
        : id(0), label(text), displayId(false) {}

    int id = 0;
    std::string label;
    bool displayId = true;
};

void clearout();
void waitEnter();
void border();
std::string formatNumber(long double value);

void showmenu(const std::vector<MenuItem>& items, const std::string& title);
void showAbout();

void resultTable(const std::string& title,
                 const std::string& label1, long double v1,
                 const std::string& label2, long double v2,
                 const std::string& resultLabel, long double result);

void resultTable(const std::string& title,
                 const std::string& label1, long double value);

long double readsafecheck(const std::string& prompt);
void showAbout();
