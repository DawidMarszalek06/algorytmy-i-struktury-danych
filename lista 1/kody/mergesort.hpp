
#include <vector> 




void MERGE(std::vector<int>& v, int left, int mid, int right) { //tworzymy funkcje merge pomocnicza scalajaca do fucnkji MERGE_SORT
    int length1= mid - left + 1; // obliczenie długości pierwszej części
    int length2= right - mid; // obliczenie długości drugiej części
    std::vector<int> vL(length1); // tworzymy wektor vL o długości length1
    std::vector<int> vR(length2); // tworzymy wektor vR o długości length2
    for (int i=0; i < length1; i++) { // kopiujemy elementy z lewej części do vL
        vL[i] = v[left + i];
    }
    for (int j=0; j < length2; j++) { // kopiujemy elementy z prawej części do vR
        vR[j] = v[mid + 1 + j];
    }
    int i=0, j=0;
    for( int k=left; k<=right;k++){
        if( (i < length1) && ( (j >= length2) || (vL[i]<=vR[j]) )){
            v[k]=vL[i];
            i++;
        }
        else{
            v[k]=vR[j];
            j++;
        
        }
    }
}

void MERGE_SORT(std::vector<int>& v, int left, int right) { // definicja funkcji MERGE_SORT
    int mid=0;
    if (left < right) {
        mid= (left + right) / 2; // obliczenie indeksu środkowego
    
    MERGE_SORT(v,left,mid);
    MERGE_SORT(v,mid+1,right);
    MERGE(v,left,mid,right);
    }
}


//druga czesc czyli merge sort dzielacy na  trzy 
void MERGE3(std::vector<int>& v, int left, int mid1, int mid2, int right) { 
    int length1 = mid1 - left + 1;  
    int length2 = mid2 - mid1;       
    int length3 = right - mid2; 

    std::vector<int> vL(length1); 
    std::vector<int> vM(length2); // zmienia sie to ze dodajemy  czesc 3  do srodka 
    std::vector<int> vR(length3); 
    for (int i = 0; i < length1; i++) { 
        vL[i] = v[left + i];
    }
    for (int j = 0; j < length2; j++) { 
        vM[j] = v[mid1 + 1 + j];
    }
    for (int m = 0; m < length3; m++) { 
        vR[m] = v[mid2 + 1 + m];
    }

    int i = 0, j = 0, m = 0;
    for (int k = left; k <= right; k++) {
        // Sprawdzamy, która z trzech podtablic ma najmniejszy element 
        if ((i < length1) && (j >= length2 || vL[i] <= vM[j]) && (m >= length3 || vL[i] <= vR[m])) {
            v[k] = vL[i];
            i++;
        } else if ((j < length2) && (m >= length3 || vM[j] <= vR[m])) {
            v[k] = vM[j];
            j++;
        } else {
            v[k] = vR[m];
            m++;
        }
    }
}

void MERGE_SORT3(std::vector<int>& v, int left, int right) { // definicja funkcji MERGE_SORT3
    if (left < right) {
        int mid1 = left + (right - left) / 3;     // obliczenie pierwszego punktu podziału
        int mid2 = left + 2 * (right - left) / 3; // obliczenie drugiego punktu podziału

        MERGE_SORT3(v, left, mid1);          // wywołanie dla lewej części
        MERGE_SORT3(v, mid1 + 1, mid2);      // wywołanie dla środkowej części
        MERGE_SORT3(v, mid2 + 1, right);     // wywołanie dla prawej części

        MERGE3(v, left, mid1, mid2, right);   // scalenie trzech części
    }
}