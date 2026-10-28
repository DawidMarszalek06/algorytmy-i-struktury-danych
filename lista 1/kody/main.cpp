#include <iostream> // Include the iostream library for input and output operations
#include <vector> 
#include <algorithm> // narzedzia operujace 
#include <fstream> // bedizemy uzywac ofstream zeby zapisac tam wyniki w  wyniki.csv
#include <random> //  generator liczb losowych , zazwuczaj uzwyalem cstdlib i ctime ale wyprobuje tą
#include "mergesort.hpp"
#include "insertionsort.hpp"
#include "bubblesort.hpp"


int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    std::vector<int> v(20);

    /*for( int i=0; i<= v.size()-1; i++){
        v[i] = dist(gen);
    }
    std::cout <<"przed sortowaniem:\n";
    for(int x: v){
        std::cout<< x <<" ";
    }  to sobie do testow uzywalem */
   // MERGE_SORT(v,0,v.size()-1); zad 1
   // MERGE_S0RT3(v,0,v.size()-1); zad 1.2
    //INSERTION_SORT(v);
    //INSERTION_SORT2(v);
    //BUBBLE_SORT(v);

    std::cout<<"\n";
    std::cout<< " Po sortowaniu ";
    for (int x : v) {
        std::cout << x << " ";

    }


    return 0;
}