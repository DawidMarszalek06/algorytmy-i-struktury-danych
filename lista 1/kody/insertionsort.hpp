#include <vector>



void INSERTION_SORT(std::vector<int>& v){
    for( int j=1; j<=v.size()-1; j++){
        int key = v[j];
        int i=j-1;
        while (i>=0 && v[i]>key){
            v[i+1]=v[i];
            i--;
        }
        v[i+1]=key;
    }
}

void INSERTION_SORT2(std::vector<int>& v){
    int n = v.size();
    for (int j=1; j<n-1; j=j+2) {
        int el1=v[j], el2=v[j+1];
        int Larger=0;
        int Smaller=0;
        if(el1>el2){
            Larger=el1;
            Smaller=el2;
        }
        else {
            Larger=el2;
            Smaller=el1;

        }
        int i =j-1;
        while (i>=0 && v[i]> Larger){
            v[i+2]= v[i];
            i--;
        }
        v[i+2]=Larger;
        //wstawilismy wiekszy elemnt , teraz bierzemy mniejszy i od miejsca wiekszego indeksujemy
        while (i>=0 && v[i] > Smaller){
            v[i+1]=v[i];
            i--;
        }
        v[i+1]=Smaller;
    }
    //sprawdzamy tlyko  czy przypadkiem nasza tablica nie byla parzysta, bo wtedy nam umyka ostatnia liczba bo sie przesuwamy o dwa
    if (v.size()%2==0){
        int key= v.back();
        int i = v.size() -  2 ;
        while ( i>= 0 && v[i]> key){
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;

    }
}