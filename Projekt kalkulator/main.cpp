/*
Projekt kalkulatora konsolowego w C++

Semest 1 Grupa D2
1. Cezary Ma³gorzaciak
2. Patryk Podle¿yñski
3. Kacper £osicki
4. Dawid P³achta
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
	cin.clear();// czyœci b³¹d strumienia jeœli wyst¹pi³ np. jak ktoœ przypadkiem cokolwiek napisze zamiast tylko wcisn¹æ enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
void clearout() {//Ta funkcja odpowiedzialna jest za sprawdzenie systemu na jakim jest u¿ywany program i umo¿liwiæ czyszczenie terminala.
	//Doda³em to ze wzglêdu pisania na pocz¹tku kodu na Mac'u a potem testowanie na Windowsie
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
	cout << "3. Multiplication" << endl;//mno¿enie
	cout << "4. Division" << endl;//dzielenie
	cout << "5. Exponentiation" << endl;//potêgowanie
	cout << "6. Root" << endl;//pierwiastkowanie
	cout << "7. Pi constant" << endl;//sta³a pi
	cout << "8. Euler's number" << endl;//sta³a e
    cout << "9. Sinus" << endl;//obliczanie sinusa
	cout << "10. Cosinus" << endl;//obliczanie cosinusa
	cout << "11. Tanges" << endl;//obliczanie tangensa
	cout << "12. Cotanges" << endl;//obliczanie cotangensa
    cout << "0. Exit" << endl;
}


int main() {
	setlocale(LC_ALL, "");//Ustawienie lokalizacji na polsk¹ ¿eby obs³ugiwaæ polskie znaki
    while (true) {// Pêtla do ci¹g³ego dzia³ania programu
        clearout();
        showmenu();
        string choice;
        cout << "Input your choice: ";
        cin >> choice;


        if (choice == "0") {//Wyjœcie z programu
            clearout();
            cout << "See you next time!" << endl;
            this_thread::sleep_for(chrono::seconds(2));// tu czeka program 3 sekundy zanim zamknie siê po wyœwietleniu wiadomoœci [mo¿emy to zmieniæ]
            return 0;
        }


        else if (choice == "1" || choice == "2" || choice == "3" || choice == "4") {//Wspólny if bo na tych samych podanych liczbach mo¿e dzia³aæ
            long double a = 0.0L, b = 0.0L;// to inicjalizacja a i b za ka¿dym razem ¿eby nie przenios³o z porzednich dzia³añ
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            if (choice == "1") {//tu napisaæ dodawanie
                cout << "DOKOÑCZYÆ KODOWANIE" << endl;
                result = a + b;// chwilowo doda³em w ten sposób ale chyba bym zmieni³ na funkcjê wywo³ywan¹
                cout << result;
            }
            else if (choice == "2") {//tu odejmowanie
                cout << "DOKOÑCZYÆ KODOWANIE" << endl;
                cout << result;
            }
            else if (choice == "3") {//tu mno¿enie
                cout << "DOKOÑCZYÆ KODOWANIE" << endl;
                cout << result;
            }
            else if (choice == "4") {//tu dzielenie
                cout << "DOKOÑCZYÆ KODOWANIE" << endl;//Tu wypada³oby dodaæ sprawdzanie ¿eby nieprzyjmowa³o 0
                cout << result;
            }
            waitEnter();

        }

        else if (choice == "5") {
            long double a = 0.0L, b = 0.0L;// to inicjalizacja a i b za ka¿dym razem ¿eby nie przenios³o z porzednich dzia³añ
            cout << "Input a: "; cin >> a;
            cout << "To the power of: "; cin >> b;
            //Tu napisaæ potêgowanie
            cout << "DOKOÑCZYÆ KODOWANIE" << endl;
            waitEnter();
        }

        else if (choice == "6") {
            long double a = 0.0L, n = 2.0L;//n=2 bo podstawowym pierwiastkiem jest kwadratowy
            // to inicjalizacja a i b za ka¿dym razem ¿eby nie przenios³o z porzednich dzia³añ
            cout << "Input a: "; cin >> a;
            cout << "N of root: "; cin >> n;
            cout << "DOKOÑCZYÆ KODOWANIE" << endl;
            waitEnter();

        }

        else if (choice == "7") {
            cout << "DOKOÑCZYÆ KODOWANIE" << endl;// tu obliczanie pi [goœciu mówi³ o 10 miejscu po przecinku to bym zrobi³ do 15 chyba]
            waitEnter();
        }

        else if (choice == "8") {
            cout << "DOKOÑCZYÆ KODOWANIE" << endl; // tu obliczanie e [e bym tak samo 15 po przecinku]
            waitEnter();
        }
        else if (choice == "9") {
            long double a = 0.0L, b = 0.0L;// to inicjalizacja a i b za ka¿dym razem ¿eby nie przenios³o z porzednich dzia³añ
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            cout << "DOKOÑCZYÆ KODOWANIE" << endl; // tu obliczanie sinus
            waitEnter();
        }
        else if (choice == "10") {
            long double a = 0.0L, b = 0.0L;// to inicjalizacja a i b za ka¿dym razem ¿eby nie przenios³o z porzednich dzia³añ
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            cout << "DOKOÑCZYÆ KODOWANIE" << endl; // tu obliczanie cosiuns
            waitEnter();
        }
        else if (choice == "11") {
            long double a = 0.0L, b = 0.0L;// to inicjalizacja a i b za ka¿dym razem ¿eby nie przenios³o z porzednich dzia³añ
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            cout << "DOKOÑCZYÆ KODOWANIE" << endl; // tu obliczanie tanges
            waitEnter();
        }
        else if (choice == "12") {
            long double a = 0.0L, b = 0.0L;// to inicjalizacja a i b za ka¿dym razem ¿eby nie przenios³o z porzednich dzia³añ
            long double result = 0.0L;
            cout << "Input a: "; cin >> a;
            cout << "Input b: "; cin >> b;
            cout << "DOKOÑCZYÆ KODOWANIE" << endl; // tu obliczanie cotanges
            waitEnter();
        }
        else {
            cout << "Unnknown choice. Input 0-12." << endl;//Tu oczywiste zwrócenie informacji o b³êdnym wyborze z menu
            waitEnter();
        }

    }
    return 0;
}

