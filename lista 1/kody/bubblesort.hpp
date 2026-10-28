#include <vector>
#include <utility>

void BUBBLE_SORT(std::vector<int>& v, long long& porównanie, long long& przypisanie) {

    bool zamiana;
    do {
        zamiana = false; 
        for (int i = 0; i < v.size()- 1; i++) { 
            porównanie++;
            if (v[i] > v[i + 1]) {
                std::swap(v[i], v[i + 1]);
                zamiana = true;
                przypisanie= przypisanie + 3;
            }
        }
    } while (zamiana==true); 
}