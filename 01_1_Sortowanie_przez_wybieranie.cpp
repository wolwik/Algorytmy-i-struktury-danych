
/*

ZADANIE 1

SORTOWANIE PRZEZ WYBIERANIE - wyszukuje element, ktory ma byc na zadanej pozycji i zamienia z tym, ktory tam jest.
* złożoność: n^2. nawet gdy już są ustawione rosnąco, musi przeszukać całą tablicę do końca, bo nie wie, gdzie jest minimum
* sortowanie w miejscu
* algorytm niestabilny 

start od 0
for ma sie zatrzymac na i <= n-2
zamieniac elementy po wewnętrznym for, nie w nim

*/



#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int counter = 0;

int RandomArray(int tab[], int n){
    srand(time(0));
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 100;
    return 0;
}

int Print(int tab[], int n){
    for (int i = 0; i < n; i++) {
        cout <<  tab[i] << " ";
    }
    return 0;
}

int SelectSort(int tab[], int n){
    for (int i = 0; i <= n-2; i++) {
        int min = i;
        for (int j = i+1; j <= n-1; j++) {
            counter++;
            if (tab[j] < tab[min]) {
                min = j;
            }
        }
        swap(tab[min], tab[i]);
    }
    return 0;
}

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
    cout << "ilosc porównan z działania algorytmu: " << counter << endl;
    cout << "Ilość porównań ze wzoru: " << n*(n-1)/2 << endl;
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


