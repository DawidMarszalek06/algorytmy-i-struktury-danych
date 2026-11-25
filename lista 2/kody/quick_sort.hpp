#include<iostream>
#include<vector>

// funkcja dla jendego pivota 
int PARTITION(std::vector<int>& v, int left, int right, long long& porównanie, long long& przypisanie) {
    int pivot = v[right];
    przypisanie++;
    int i = left - 1;
    for (int j = left; j <= right-1; j++) {
        porównanie++;
        if (v[j] < pivot) {
            i++;
            std::swap(v[i], v[j]);
            przypisanie= przypisanie + 3;
        }
    }
    std::swap(v[i + 1], v[right]);
    przypisanie= przypisanie + 3;
    return i + 1;
}

void QUICK_SORT(std::vector<int>& v, int left, int right, long long& porównanie, long long& przypisanie) {
    if (left < right) {
        int pivotIndex = PARTITION(v, left, right, porównanie, przypisanie);
        QUICK_SORT(v, left, pivotIndex - 1, porównanie, przypisanie);
        QUICK_SORT(v, pivotIndex + 1, right, porównanie, przypisanie);
    }
}
//funkcja dla dwoch pivotoów

void DUAL_PIVOT_PARTITION(std::vector<int>& v, int left, int right, int& pivot1, int& pivot2, long long& porównanie, long long& przypisanie){
    porównanie++;
    if(v[left] > v[right]){
        std::swap(v[left], v[right]);
        przypisanie+=3;
    }
    pivot1 = v[left];
    pivot2 = v[right];
    przypisanie +=2;

    int left_wsk=left+1;
    int right_wsk=right-1;
    int i= left+1;

    while (i<=right_wsk){
        porównanie++;
        if (v[i]< pivot1){
            std::swap(v[i], v[left_wsk]);
            przypisanie+=3;
            left_wsk+=1;
            i+=1;
        }
        else {
            porównanie++;
            if(v[i] > pivot2){
                std::swap( v[i], v[right_wsk]); //tutaj nie dodajemy i tlyko swapujemy duza liczbe z mniejsza, duza idzie na prawy kraniec+-eps .
                przypisanie+=3;
                right_wsk=right_wsk-1;
            }
           else{
            i+=1;
           }    
        }
    }

    left_wsk-=1;
    right_wsk+=1;
    std::swap(v[left],v[left_wsk]);
    std::swap(v[right],v[right_wsk]);
    przypisanie+=6;

    pivot1=left_wsk;
    pivot2=right_wsk;
}