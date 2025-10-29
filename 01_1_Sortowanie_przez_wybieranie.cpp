
/*
    SELECTION SORT (Sortowanie przez wybieranie)

    Polega na wyszukiwaniu najmniejszego elementu w nieposortowanej części tablicy
    i zamianie go z pierwszym elementem tej części.

    Cechy:
    - Złożoność czasowa: O(n^2) (niezależnie od uporządkowania danych)
    - Złożoność pamięciowa: O(1)
    - Sortowanie w miejscu (in-place)
    - Algorytm niestabilny

    Schemat:
    1. Dla każdego indeksu i (od 0 do n-2):
       a. Znajdź indeks najmniejszego elementu w zakresie [i, n-1]
       b. Zamień element o indeksie min z elementem o indeksie i
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int counter = 0;

// Funkcja wypełnia tablicę losowymi liczbami z zakresu 0–99
int RandomArray(int tab[], int n){
    srand(time(0));
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 100;
    return 0;
}

// Funkcja wypisuje zawartość tablicy
int Print(int tab[], int n){
    for (int i = 0; i < n; i++) {
        cout <<  tab[i] << " ";
    }
    return 0;
}

// Funkcja sortująca
int SelectSort(int tab[], int n){
    for (int i = 0; i <= n-2; i++) {
        int min = i;
        for (int j = i+1; j <= n-1; j++) {
            counter++;
            if (tab[j] < tab[min]) {
                min = j;
            }
        }
        swap(tab[min], tab[i]); // Zamiana znalezionego minimum z bieżacym elementem
    }
    return 0;
}

// Funkcja testująca działanie algorytmu sortowania (dla tablicy o podanym rozmiarze)
void sortTest(int tab[], int n) {
    cout << "Sortowanie tablicy z " << n << " liczbami" << endl;
    RandomArray(tab, n);
    cout << "Tablica przed posortowaniem:" << endl;
    Print(tab, n);
    cout << endl;
    SelectSort(tab, n);
    cout << "Tablica posortowana: " << endl;
    Print(tab, n);
    cout << endl;
    cout << "Liczba porównań wykonanych przez algorytm: " << counter << endl; // Złożoność czasowa 
    cout << "Liczba porównań teoretyczna (n*(n-1)/2): " << n*(n-1)/2 << endl;
    counter = 0;
}

int main() {
    const int N = 50;
    const int M = 100;
    const int K = 200;

    int R[N], S[M], T[K];

    sortTest(R, N); // (50*49)/2 = 1225
    sortTest(S, M); // (100*99)/2 = 4950
    sortTest(T, K); // (200*199)/2 = 19900

    return 0;
}



