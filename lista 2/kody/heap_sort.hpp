#include<vector>
#include<iostream>

void HEAPIFY(std::vector<int>& v, int heap_size, int i, long long& porównanie, long long& przypisanie){
    int largest=i;
    int left=i*2+1;
    int right=i*2+2;
    
    if(left<heap_size){
        porównanie++;
        if (v[left]>v[largest])
        {
            largest=left;
        }
        
    }

    if(right<heap_size){
        porównanie++;
        if (v[right]>v[largest])
        {
            largest=right;
        }
        
    }

    if(largest != i ){
       std::swap(v[i],v[largest]);
       przypisanie+=3;
        HEAPIFY(v,heap_size,largest,porównanie,przypisanie);
    }
}

void BUILD_MAX_HEAPIFY(std::vector<int>& v, long long& porównanie, long long& przypisanie ){
    int n=v.size();
    for(int i=n/2-1;i>=0;i--){
        HEAPIFY(v , n , i , porównanie , przypisanie );
    }

}
void HEAP_SORT(std::vector<int>& v, long long& porównanie, long long& przypisanie){
    BUILD_MAX_HEAPIFY( v , porównanie, przypisanie);
    int n=v.size();

    for(int i=n-1;i>=1;i--){
        std::swap(v[i],v[0]);
        przypisanie+=3;
        HEAPIFY( v , i , 0 , porównanie , przypisanie);


    }
}

void TERNARY_HEAPIFY(std::vector<int>& v, int heap_size, int i, long long& porównanie, long long& przypisanie ){
    int largest=i;
    int c1=3*i+1;
    int c2=3*i+2;
    int c3=3*i+3;

    if(c1<heap_size){
        porównanie++;
        if(v[c1]>v[largest]){
            largest=c1;
        }
    }

    if(c2<heap_size){
        porównanie++;
        if(v[c2]>v[largest]){
            largest=c2;
        }
    }

    if(c3<heap_size){
        porównanie++;
        if(v[c3]>v[largest]){
            largest=c3;
        }
    }

    if(largest !=i){
        std::swap(v[i],v[largest]);
        przypisanie+=3;
        TERNARY_HEAPIFY( v , heap_size , largest , porównanie , przypisanie);
    }

}

void TERENARY_BUILD_MAX_HEAP(std::vector<int>& v, long long& porównanie, long long& przypisanie ){
    int n=v.size();
    if (n<2){ return; 
    }
    for(int i=(n-2)/3;i>=0;i--){
            TERNARY_HEAPIFY( v , n , i , porównanie , przypisanie);
    }  
}
void TERNARY_HEAP_SORT(std::vector<int>& v, long long& porównanie, long long& przypisanie){
    TERENARY_BUILD_MAX_HEAP( v , porównanie , przypisanie);
    int n=v.size();

    for(int i=n-1;i>=1;i--){
        std::swap(v[0],v[i]);
        przypisanie+=3;
        TERNARY_HEAPIFY( v , i , 0 , porównanie , przypisanie);
    }
}