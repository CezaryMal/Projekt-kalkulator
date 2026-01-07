#include "ui_format.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <cmath>

using namespace std;

const int tableWidth = 29;

// ---------- helpers ----------

static void printTop() {
    cout << "+-----------------------------+\n";
}

static void printMid() {
    cout << "+--------------+--------------+\n";
}

static string center(const string &txt)
{
    int padding = (tableWidth - 2 - (int)txt.size()) / 2;
    if (padding < 0) padding = 0;

    ostringstream o;
    o << "|"
      << setw(padding + txt.size()) << txt
      << setw(tableWidth - 1 - padding - (int)txt.size()) << " "
      << "|\n";

    return o.str();
}

// ---------- ekran ----------

void clearout()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void border()
{
    printMid();
}

// ---------- MENU ----------

void showmenu(const vector<MenuItem> &items, const string &title)
{
    clearout();

    printTop();
    cout << center(title);
    printTop();

    for (auto &i : items)
    {
        ostringstream l;

        if (i.displayId)
            l << i.id << " - " << i.label;
        else
            l << i.label;

        cout << center(l.str());
    }

    printTop();
}

// ---------- PAUZA ----------

void waitEnter()
{
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// ---------- FORMAT LICZB ----------

string formatNumber(long double value)
{
    long double rounded = llround(value);

    // liczby calkowite bez .00000
    if (fabsl(value - rounded) < 1e-12L)
    {
        ostringstream out;
        out << fixed << setprecision(0) << rounded;
        return out.str();
    }

    ostringstream out;
    out << fixed << setprecision(5) << value;

    string s = out.str();

    // usuwanie zer koncowych
    while (!s.empty() && s.back() == '0')
        s.pop_back();

    if (!s.empty() && s.back() == '.')
        s.pop_back();

    return s;
}

// ---------- WCZYTYWANIE (BEZ ZAPETLANIA) ----------

long double readsafecheck(const string &prompt)
{
    while (true)
    {
        cout << prompt;

        string line;
        getline(cin, line);

        if (line.empty())
            continue;

        try
        {
            long double v = stold(line);
            return v;
        }
        catch (...)
        {
            cout << "Invalid input. Try again.\n";
        }
    }
}

// ---------- TABELA 2-WIERSZE ----------

void resultTable(const string& title,
                 const string& label1, long double v1,
                 const string& label2, long double v2,
                 const string& resultLabel, long double result)
{
    printTop();
    cout << center(title);
    printTop();

    cout << center(label1 + ": " + formatNumber(v1));
    cout << center(label2 + ": " + formatNumber(v2));
    border();
    cout << center(resultLabel + ": " + formatNumber(result));
    printTop();
}

// ---------- TABELA 1-WIERSZ ----------

void resultTable(const string& title,
                 const string& label1, long double value)
{
    printTop();
    cout << center(title);
    printTop();
    cout << center(label1 + ": " + formatNumber(value));
    printTop();
}

// ---------- ABOUT ----------

void showAbout()
{
    clearout();

    printTop();
    cout << center("ABOUT");
    printTop();

    cout << center("Calculator project");
    cout << center("Group D2");
    cout << center("Authors:");
    cout << center("C. Malgorzaciak");
    cout << center("P. Podlezynski");
    cout << center("K. Losicki");
    cout << center("D. Plachta");
    cout << center("K. Kramarski");

    printTop();
    waitEnter();
}
