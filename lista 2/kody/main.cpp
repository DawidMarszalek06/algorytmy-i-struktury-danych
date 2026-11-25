#include<iostream>
#include<random>
#include<vector>
#include<algorithm>
#include<string>
#include"quick_sort.hpp"


void testuj(const std::vector<int>& vector,const std::string& nazwa){
    std::cout<<" ------------------------\n";
    std::cout<<"Test dla:" << nazwa <<"\n";
    std::cout<<" ------------------------\n";
    long long porównanie=0,przypisanie=0;
    
    {
        std::vector<int>v = vector;
        porównanie=0;
        przypisanie=0;
        QUICK_SORT(v,0,v.size()-1,porównanie,przypisanie);
        std::cout<<" Quick_sort: porównania = "<< porównanie<< "\n";
        std::cout<< "przypisania= "<< przypisanie<< " \n";
        std::cout<< "czy posortowane : " << is_sorted(v.begin(), v.end())<<" \n";
    }
}
int main(){
    std::mt19937 gen(42);
    std::uniform_int_distribution<int> dist(1, 100000);

    std::vector<int> v100(100);
    std::vector<int> v1000(1000);
    std::vector<int> v10000(10000);
    for (int i = 0; i < v100.size(); i++) {
        v100[i] = dist(gen);
    }

    for (int i = 0; i < v1000.size(); i++) {
        v1000[i] = dist(gen);
    }
    for (int i = 0; i < v10000.size(); i++) {
        v10000[i] = dist(gen);
    }

    testuj(v100, "wektor 100 el");
    testuj(v1000, "wektor 1000 el");
    testuj(v10000, "wektor 10000 el");


}