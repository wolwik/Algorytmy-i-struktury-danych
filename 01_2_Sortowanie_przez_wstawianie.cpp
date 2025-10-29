
/*
    SORTOWANIE PRZEZ WSTAWIANIE (Insertion Sort)

    Idea:
    Przypomina układanie kart w dłoni – bierzemy kolejny element z nieposortowanej części
    i „wstawiamy” go we właściwe miejsce wśród już posortowanych.

    Cechy:
    - Algorytm stabilny (nie zmienia kolejności równych elementów)
    - Sortowanie w miejscu (in-place)
    - Działa bardzo dobrze dla małych lub częściowo uporządkowanych zbiorów
    
    Złożoność:
    - O(n²) w przypadku odwrotnego porządku (najgorszy przypadek)
    - O(n) dla tablicy już posortowanej (najlepszy przypadek)
    - O(n²) średnio
    
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int counter = 0;

// Funkcja wypełnia tablicę losowymi liczbami z zakresu 0–99
int RandomArray(int tab[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 100; 
    return 0;
}

// Funkcja wypisuje zawartość tablicy
int Print(int tab[], int n) {
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    return 0;
}

// Funkcja sortująca rosnąco
int InsertSortGrowing(int tab[], int n) {
    for (int i = 1; i < n; i++) {
        int x = tab[i];
        int j = i - 1;
        while (j >= 0 && (++counter, tab[j] > x)) {
            tab[j + 1] = tab[j]; 
            j--;
        }
        tab[j + 1] = x;
    }
    return 0;
}

// Funkcja sortująca malejąco
int InsertSortDescend(int tab[], int n) {
     for (int i = 1; i < n; i++) {
        int x = tab[i];
        int j = i - 1;
        while (j >= 0 && (++counter, tab[j] < x)) { // Zamiana ">" na "<"
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

    return 0;

}
