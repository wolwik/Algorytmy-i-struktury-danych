
/*

ZADANIE 2

sortowanie przez wstawianie: układanie kart. bierzemy dowolny element z nieposortowanego zbioru i dodajemy gdzies do posortowanego

start od 1 (pierwszy element jest sam z sobą posortowany)
* stabilny (przesuwamy, porównujemy elementy obok siebie)
* złożoność: w zależności od ułożenia danych, działa najszybciej, gdy liczby będą już posortowane

*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int counter = 0;

int RandomArray(int tab[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 100; 
    return 0;
}

int Print(int tab[], int n) {
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    return 0;
}

int InsertSortGrowing(int tab[], int n) {
    for (int i = 1; i < n; i++) {
        int x = tab[i];
        int j = i - 1;
        while (j >= 0 && (++counter, tab[j] > x)) {
            tab[j + 1] = tab[j]; // dla listy posortowanej malejąco n=4950
            j--;
        }
        tab[j + 1] = x;
    }
    return 0;
}

int InsertSortDescend(int tab[], int n) {
     for (int i = 1; i < n; i++) {
        int x = tab[i];
        int j = i - 1;
        while (j >= 0 && (++counter, tab[j] < x)) { // zmiana > na <
            tab[j + 1] = tab[j]; // dla listy posortowanej rosnąco n=4950
            j--;
        }
        tab[j + 1] = x;
    }
    return 0;
}



int main() {

    const int N = 100;    
    int A[N];
    
    setlocale(LC_CTYPE, "Polish");

    RandomArray(A, N);
    cout << "Tablica przed sortowaniem:" << endl;
    Print(A, N);
    cout << endl;
    cout << endl;

    InsertSortGrowing(A, N);

    cout << "Tablica po sortowaniu ROSNĄCO:" << endl;
    Print(A, N);
    cout << endl;
    
    cout << "    Ilość porównań: " << counter << endl;
    counter = 0;
    cout << endl;

    InsertSortGrowing(A, N);
    
    cout << "Sortowanie posortowanej już tablicy: " << endl;
    Print(A, N);
    cout << endl;
    
    cout << "    Ilość porównań: " << counter << endl;
    cout << endl;
    counter = 0;
   
    InsertSortDescend(A, N);
    cout << "Tablica po sortowaniu MALEJĄCO:" << endl;
    Print(A, N);
    cout << endl;
    
    cout << "    Ilość porównań: " << counter << endl;
    cout << endl;
    counter = 0;

    
/*
int numbers[100] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
        30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
        40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
        50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
        60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
        70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
        80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
        90, 91, 92, 93, 94, 95, 96, 97, 98, 99
};

    cout << "Tablica przed posortowaniem:" << endl;
    Print(numbers, 100);
    cout << endl;

    InsertSortReverse(numbers, 100);

    cout << "Tablica po posortowaniu:" << endl;
    Print(numbers, 100);
    cout << endl;
    

    cout << "ilosc porównan: " << counter << endl;
    counter = 0;

*/


    return 0;
}