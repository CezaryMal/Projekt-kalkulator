/*
Projekt kalkulatora konsolowego w C++

Semest 1 Grupa D2
1. Cezary Małgorzaciak
2. Patryk Podleżyński
3. Kacper Łosicki
4. Dawid Płachta
5. Krzysiek Kramarski


*/


#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;


void waitEnter() {//Do pauzowania programu
    cout << "\nPress [Enter] to continue...";
    cin.get();
	cin.clear();// czyści błąd strumienia jeśli wystąpił np. jak ktoś przypadkiem cokolwiek napisze zamiast tylko wcisnąć enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
void clearout() {//Ta funkcja odpowiedzialna jest za sprawdzenie systemu na jakim jest używany program i umożliwić czyszczenie terminala.
	//Dodałem to ze względu pisania na początku kodu na Mac'u a potem testowanie na Windowsie
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

void showmenu() {//Pokazuje menu kalkulatora !!!To do zmiany w formatowanie tabeli
    cout << "Choose from menu:" << endl;
    cout << "1. Addition" << endl;//dodawanie
	cout << "2. Substract" << endl;//odejmowanie
	cout << "3. Multiplication" << endl;//mnożenie
	cout << "4. Division" << endl;//dzielenie
	cout << "5. Exponentiation" << endl;//potęgowanie
	cout << "6. Root" << endl;//pierwiastkowanie
	cout << "7. Pi constant" << endl;//stała pi
	cout << "8. Euler's number" << endl;//stała e
    cout << "0. Exit" << endl;
}


int main() {
	setlocale(LC_ALL, "");//Ustawienie lokalizacji na polską żeby obsługiwać polskie znaki
    while (true) {// Pętla do ciągłego działania programu
        clearout();
        showmenu();
        string choice;
        cout << "Input your choice: ";
        cin >> choice;


        if (choice == "0") {//Wyjście z programu
            clearout();
            cout << "See you next time!" << endl;
            this_thread::sleep_for(chrono::seconds(2));// tu czeka program 3 sekundy zanim zamknie się po wyświetleniu wiadomości [możemy to zmienić]
            return 0;
        }


        else if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {//Wspólny if bo na tych samych podanych liczbach może działać
            long double a = 0.0L, b = 0.0L;// to inicjalizacja a i b za każdym razem żeby nie przeniosło z porzednich działań
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            if (choice == "1") {//tu napisać dodawanie
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
                result = a + b;// chwilowo dodałem w ten sposób ale chyba bym zmienił na funkcję wywoływaną
                cout << result;
            }
            else if (choice == "2") {//tu odejmowanie
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
                cout << result;
            }
            else if (choice == "3") {//tu mnożenie
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;
                cout << result;
            }
            else if (choice == "4") {//tu dzielenie
                cout << "DOKOŃCZYĆ KODOWANIE" << endl;//Tu wypadałoby dodać sprawdzanie żeby nieprzyjmowało 0
                cout << result;
            }
            waitEnter();

        }

        else if (choice == "5") {
            long double a = 0.0L, b = 0.0L;// to inicjalizacja a i b za każdym razem żeby nie przeniosło z porzednich działań
            cout << "Input a: "; cin >> a;
            cout << "To the power of: "; cin >> b;
            //Tu napisać potęgowanie
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            waitEnter();
        }

        else if (choice == "6") {
            long double a = 0.0L, n = 2.0L;//n=2 bo podstawowym pierwiastkiem jest kwadratowy
            // to inicjalizacja a i b za każdym razem żeby nie przeniosło z porzednich działań
            cout << "Input a: "; cin >> a;
            cout << "N of root: "; cin >> n;
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;
            waitEnter();

        }

        else if (choice == "7") {
            cout << "DOKOŃCZYĆ KODOWANIE" << endl;// tu obliczanie pi [gościu mówił o 10 miejscu po przecinku to bym zrobił do 15 chyba]
            waitEnter();
        }

        else if (choice == "8") {
            cout << "DOKOŃCZYĆ KODOWANIE" << endl; // tu obliczanie e [e bym tak samo 15 po przecinku]
            waitEnter();
        }
        else {
            cout << "Unnknown choice. Input 0-8." << endl;//Tu oczywiste zwrócenie informacji o błędnym wyborze z menu
            waitEnter();
        }

    }
    return 0;
}

