#include <iostream>
#include <vector>
#include <random>
#include <string>
#include "mergesort.hpp"
#include "insertionsort.hpp"
#include "bubblesort.hpp"

void testuj(const std::vector<int>& base, const std::string& nazwa) {
    std::cout << "========================================\n";
    std::cout << "TEST DLA: " << nazwa << " (N = " << base.size() << ")\n";
    std::cout << "========================================\n";

    long long porownanie = 0, przypisanie = 0;

    // 1. Merge Sort na dwie czesci
    {
        std::vector<int> v = base;
        porownanie = 0; przypisanie = 0;
        MERGE_SORT(v, 0, v.size() - 1, porownanie, przypisanie);
        std::cout << "Merge Sort (2-way):   porownania = " << porownanie << "\t przypisania = " << przypisanie << "\n";
    }

    // 2. Merge Sort na 3 czesci
    {
        std::vector<int> v = base;
        porownanie = 0; przypisanie = 0;
        MERGE_SORT3(v, 0, v.size() - 1, porownanie, przypisanie);
        std::cout << "Merge Sort (3-way):   porownania = " << porownanie << "\t przypisania = " << przypisanie << "\n";
    }

    // 3. Insertion Sort
    {
        std::vector<int> v = base;
        porownanie = 0; przypisanie = 0;
        INSERTION_SORT(v, porownanie, przypisanie);
        std::cout << "Insertion Sort:       porownania = " << porownanie << "\t przypisania = " << przypisanie << "\n";
    }

    // 4. Pairwise Insertion Sort
    {
        std::vector<int> v = base;
        porownanie = 0; przypisanie = 0;
        INSERTION_SORT2(v, porownanie, przypisanie);
        std::cout << "Pairwise Insertion:   porownania = " << porownanie << "\t przypisania = " << przypisanie << "\n";
    }

    // 5. Bubble Sort
    {
        std::vector<int> v = base;
        porownanie = 0; przypisanie = 0;
        BUBBLE_SORT(v, porownanie, przypisanie);
        std::cout << "Bubble Sort:          porownania = " << porownanie << "\t przypisania = " << przypisanie << "\n\n";
    }
}

int main() {
    /*std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    // Tworzymy 3 wektory o zadanych rozmiarach
    std::vector<int> v10(10);
    std::vector<int> v15(15);
    std::vector<int> v20(20);

    // Wypełniamy je losowymi liczbami
    for (int &x : v10) x = dist(gen);
    for (int &x : v15) x = dist(gen);
    for (int &x : v20) x = dist(gen);*/

    std::vector<int> v10 = {42, 15, 88, 3, 27, 91, 14, 63, 50, 5};
    std::vector<int> v15 = {71, 12, 45, 99, 3, 28, 64, 82, 19, 33, 50, 7, 91, 24, 60};
    std::vector<int> v20 = {84, 19, 62, 3, 91, 47, 15, 73, 28, 55, 9, 36, 68, 94, 12, 41, 80, 23, 51, 30};
    // Odpalamy testy dla każdego z nich
    testuj(v10, "Wektor 10 elementow");
    testuj(v15, "Wektor 15 elementow");
    testuj(v20, "Wektor 20 elementow");

    return 0;
}