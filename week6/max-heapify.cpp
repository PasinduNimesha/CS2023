#include <iostream>
#include <vector>
using namespace std;

struct heap{
    vector<int> a;
    int size;
    int length;
};

heap max_heapify(heap A, int i){
    int l = i*2+1;
    int r = i*2+2;
    int largest, temp;
    if(l < A.size && A.a[l] > A.a[i]){
        largest = l;
    }
    else{
        largest = i;
    }
    if(r < A.size && A.a[r] > A.a[largest]){
        largest = r;
    }
    if(largest != i){
        temp = A.a[i];
        A.a[i] = A.a[largest];
        A.a[largest] = temp;
    }
    if(r >= A.size || l >= A.size || largest == i){
        return A;
    }
    else{
        return max_heapify(A, largest);
    }
}

heap buildMaxHeap(heap a){
    int i = (a.size/2) -1;
    for(i; i >= 0; i-- ){
        a = max_heapify(a, i);
        // for(int j = 0; j < a.a.size(); j++){
        //     cout<< a.a[j]<<" ";
        // }
        // cout<<endl;
    }
    return a;
}

heap heapSort(heap A){
    int size = A.size;
    int i = A.size;
    int temp;
    for(int i = size -1; i >= 1; i--){
        temp = A.a[i];
        A.a[i] = A.a[0];
        A.a[0] = temp;
        A.size--;
        A = max_heapify(A, 0);
    }
    return A;
}



int main(){

    heap heap1;
    heap1.a = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7, 0, 11};
    heap1.length = 15;
    heap1.size = heap1.a.size();

    heap heapified = buildMaxHeap(heap1);
    // heap heapified = max_heapify(heap1, 4);

    for(int i = 0; i < heap1.a.size(); i++){
        cout<< heapified.a[i]<<" ";
    }
    cout<<endl;
    heap sorted = heapSort(heapified);
    for(int i = 0; i < heap1.a.size(); i++){
        cout<< sorted.a[i]<<" ";
    }

    return 0;
}