/*
    BUBBLE SORT – trzy wersje algorytmu

    1. Wersja podstawowa – klasyczna, bez optymalizacji.
    2. Wersja szybsza – skracanie zakresu przeszukiwania po każdym przebiegu.
    3. Wersja z flagą – przerywa działanie, gdy tablica jest już posortowana.

    • Złożoność czasowa: O(n^2)
    • Złożoność pamięciowa: O(1)
    • Sortowanie stabilne
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int counter = 0;


// Tworzy tablicę o losowych wartościach z zakresu 0–99
int RandomArray(int tab[], int n) {
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 100;
    return 0;
}

// Tworzy tablicę o wartościach rosnących
int AscendingArray(int tab[], int n) {
    for (int i = 0; i < n; i++)
        tab[i] = i;
    return 0;
}

// Tworzy tablicę o wartościach malejących
int DescendingArray(int tab[], int n) {
    for (int i = 0; i < n; i++)
        tab[i] = n - i;
    return 0;
}

// Wypisuje zawartość tablicy
int Print(int tab[], int n) {
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl;
    return 0;
}


// Wersja 1 – podstawowa
void BubbleSortBasic(int T[], int n) {
    for (int j = 1; j <= n - 1; j++) {
        for (int i = 0; i <= n - 2; i++) {
            counter++;
            if (T[i] > T[i + 1]) {
                swap(T[i], T[i + 1]);
            }
        }
    }
}

// Wersja 2 – szybsza (pętla wewnętrzna skracana)
void BubbleSortFaster(int T[], int n) {
    for (int j = n - 1; j >= 1; j--) {
        for (int i = 0; i <= j - 1; i++) {
            counter++;
            if (T[i] > T[i + 1]) {
                swap(T[i], T[i + 1]);
            }
        }
    }
}

// Wersja 3 – z flagą (kończy, gdy nie było żadnej zamiany)
void BubbleSortFlag(int T[], int n) {
    for (int j = 1; j <= n - 1; j++) {
        bool flag = false;
        for (int i = 0; i <= n - 2; i++) {
            counter++;
            if (T[i] > T[i + 1]) {
                swap(T[i], T[i + 1]);
                flag = true;
            }
        }
        if (!flag) break; // tablica już posortowana
    }
}


int main() {
    srand(time(0));
    setlocale(LC_CTYPE, "Polish");

    const int N = 100;
    int A[N];


    cout << "SORTOWANIE TABLICY LOSOWEJ" << endl;

    cout << "Tablica na wejsciu: " << endl;
    RandomArray(A, N);
    Print(A, N);
    cout << endl;

    BubbleSortBasic(A, N);
    Print(A, N);
    cout << "Wersja 1, liczba porownan: " << counter << endl;
    counter = 0;
    cout << endl;

    BubbleSortFaster(A, N);
    Print(A, N);
    cout << "Wersja 2, liczba porownan: " << counter << endl;
    counter = 0;
    cout << endl;

    BubbleSortFlag(A, N);
    Print(A, N);
    cout << "Wersja 3, liczba porownan: " << counter << endl;
    counter = 0;
    cout << endl << endl;

  
    cout << "SORTOWANIE TABLICY ROSNĄCEJ" << endl;

    cout << "Tablica na wejsciu: " << endl;
    AscendingArray(A, N);
    Print(A, N);
    cout << endl;

    BubbleSortBasic(A, N);
    Print(A, N);
    cout << "Wersja 1, liczba porownan: " << counter << endl;
    counter = 0;
    cout << endl;

    BubbleSortFaster(A, N);
    Print(A, N);
    cout << "Wersja 2, liczba porownan: " << counter << endl;
    counter = 0;
    cout << endl;

    BubbleSortFlag(A, N);
    Print(A, N);
    cout << "Wersja 3, liczba porownan: " << counter << endl;
    counter = 0;
    cout << endl << endl;


    cout << "SORTOWANIE TABLICY MALEJĄCEJ" << endl;

    cout << "Tablica na wejsciu: " << endl;
    DescendingArray(A, N);
    Print(A, N);
    cout << endl;

    BubbleSortBasic(A, N);
    Print(A, N);
    cout << "Wersja 1, liczba porownan: " << counter << endl;
    counter = 0;
    cout << endl;

    BubbleSortFaster(A, N);
    Print(A, N);
    cout << "Wersja 2, liczba porownan: " << counter << endl;
    counter = 0;
    cout << endl;

    BubbleSortFlag(A, N);
    Print(A, N);
    cout << "Wersja 3, liczba porownan: " << counter << endl;
    counter = 0;
    cout << endl;

    return 0;
}
