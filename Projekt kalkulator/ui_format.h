// ui_format.h
#pragma once
#include <string>
#include <vector>

// Struktura opisuje pojedynczy element menu wyswietlany w konsoli
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

// Czysci konsole niezaleznie od systemu operacyjnego
void clearout();
// Wyswietla komunikat o nacisnieciu Enter i wstrzymuje dalsze dzialanie
void waitEnter();
// Rysuje ramke z tytulem oraz elementami menu
void showmenu(const std::vector<MenuItem>& items, const std::string& title);
// Formatuje liczbe zmiennoprzecinkowa usuwajac zbedne zera
std::string formatNumber(long double value);
