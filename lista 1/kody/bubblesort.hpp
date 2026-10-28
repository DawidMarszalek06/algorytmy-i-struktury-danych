#include <vector>
#include <utility>

void BUBBLE_SORT(std::vector<int>& v) {

    bool zamiana;
    do {
        zamiana = false; 
        for (int i = 0; i < v.size()- 1; i++) { 
            if (v[i] > v[i + 1]) {
                std::swap(v[i], v[i + 1]);
                zamiana = true;
            }
        }
    } while (zamiana==true); 
}