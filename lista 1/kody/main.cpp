#include <iostream> // Include the iostream library for input and output operations
#include <vector> 
#include <algorithm> // narzedzia operujace 
#include <fstream> // bedizemy uzywac ofstream zeby zapisac tam wyniki w  wyniki.csv
#include <random> //  generator liczb losowych , zazwuczaj uzwyalem cstdlib i ctime ale wyprobuje tą

//zad1 

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

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    std::vector<int> v(20);

    for( int i=0; i<= v.size()-1; i++){
        v[i] = dist(gen);
    }
    std::cout <<"przed sortowaniem:\n";
    for(int x: v){
        std::cout<< x <<" ";
    } 
    MERGE_SORT(v,0,v.size()-1);

    std::cout<<"\n";
    std::cout<< " Po sortowaniu ";
    for (int x : v) {
        std::cout << x << " ";

    }

    return 0;
}