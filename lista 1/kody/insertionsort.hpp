#include <vector>



void INSERTION_SORT(std::vector<int>& v, long long& porównanie, long long& przypisanie){
    for( int j=1; j<=v.size()-1; j++){
        int key = v[j];
        przypisanie++;
        int i=j-1;
        while (i>=0 && (++porównanie && v[i]>key)){
            v[i+1]=v[i];
            przypisanie++;
            i--;
        }
        v[i+1]=key;
        przypisanie++;
    }
}

void INSERTION_SORT2(std::vector<int>& v, long long& porównanie, long long& przypisanie){
    int n = v.size();
    for (int j=1; j<n-1; j=j+2) {
        int el1=v[j], el2=v[j+1];
        przypisanie += 2;
        int Larger=0;
        int Smaller=0;
        porównanie++;
        if(el1>el2){
            Larger=el1;
            Smaller=el2;
            przypisanie+=2;
        }
        else {
            Larger=el2;
            Smaller=el1;
            przypisanie+=2;
        }
        int i =j-1;
        while (i>=0 && (++porównanie && v[i]> Larger)){
            v[i+2]= v[i];
            przypisanie++;
            i--;
        }
        v[i+2]=Larger;
        przypisanie++;
        //wstawilismy wiekszy elemnt , teraz bierzemy mniejszy i od miejsca wiekszego indeksujemy
        while (i>=0 && (++porównanie && v[i] > Smaller)){
            v[i+1]=v[i];
            przypisanie++;
            i--;
        }
        v[i+1]=Smaller;
        przypisanie++;
    }
    //sprawdzamy tlyko  czy przypadkiem nasza tablica nie byla parzysta, bo wtedy nam umyka ostatnia liczba bo sie przesuwamy o dwa
    if (v.size()%2==0){
        int key= v.back();
        przypisanie++;
        int i = v.size() -  2 ;
        while ( i>= 0 && v[i]> key){
            v[i + 1] = v[i];
            przypisanie++;
            i--;
        }
        v[i + 1] = key;
        przypisanie++;

    }
}