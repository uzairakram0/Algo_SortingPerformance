#include <iostream>
#include <cstdlib>
#include <list>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <vector>
#include <set>
#include <climits>

#define N 1000000

using namespace std;

//prototype
void generateSet1(vector<unsigned long long>& a);
void generateSet2(vector<unsigned long long>& b);
void generateSet3(vector<unsigned long long>& c);
double InsertionQuickSortSet(vector<unsigned long long>& set);
void hybridSort(vector<unsigned long long> &vec, int start,  int end);

int main(){
    vector<unsigned long long> set;

    /*INSERTIONQUICKSORT*/
    cout << "Insertion/Quick Sort" << endl;
    // EXPERIMENT # 1
    /*InsertionQuickSort Set1 Experiment*/
    cout << "Set 1: where no number repeats" << endl;
    /*Generate sets of data for sorting*/
    generateSet1(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set.begin(), set.end());
        /*calculate execution time and display*/
        double Time = InsertionQuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // EXPERIMENT # 2
    /*InsertionQuickSort Set2 Experiment*/
    cout << "Set 2: where range of numbers is 1% of array size" << endl;
    /*Generate sets of data for sorting*/
    generateSet2(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set.begin(), set.end());
        /*calculate execution time and display*/
        double Time = InsertionQuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // EXPERIMENT # 3
    /*InsertionQuickSort Set3 Experiment*/
    cout << "Set 3: where each number is a unique 20 digit number" << endl;
    /*Generate sets of data for sorting*/
    generateSet3(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set.begin(), set.end());
        /*calculate execution time and display*/
        double Time = InsertionQuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    return 0;
}
/*Function for generating set 1*/
void generateSet1(vector<unsigned long long>& a){
    /*Set 1 generating unique numbers*/
    for (unsigned long long i = 0; i < N; i++){
        a.push_back(i);
    }
}

/*Function for generating set 2*/
void generateSet2(vector<unsigned long long>& b){
    /*Set 2 generating numbers less than 1% the size of set*/
    int range = N/100;
    for (int i = 0; i > N; i++){
        b.push_back(rand() % range);
    }
}

/*Function for generating set 3*/
void generateSet3(vector<unsigned long long>& c){
    /*Set 3 generating unique 20 digit numbers*/
    set<unsigned long long> s;
    unsigned long long min = 10000000000000000000u;
    unsigned long long max = ULLONG_MAX;
    int range = max - min + 1;
    while(s.size() < N){
        unsigned long long element = rand() % range + min;
        s.insert(element);
    }
    for(set<unsigned long long>::iterator it = s.begin(); it!=s.end();it++){
        c.push_back(*it);
    }
    
}

/*InsertionQuickSort timing subroutine*/
double InsertionQuickSortSet(vector<unsigned long long>& set){
    clock_t startTime = clock();
    // CODE
    hybridSort(set, 0,  N);
    // to compute its execution duration in runtime
    return double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
}

/*Insertion Quick Sort*/
/*Citation:
    www.stackoverflow.com
 */
// partition for quicksort algorithm
int partition(vector<unsigned long long>& A, int first,int last){
    int i= first;        // first pivot
    int j;
    for(j= first+1; j <= last; j++){
        if(A[first] > A[j]){       // use first value as the pivot
            i=i+1;
            swap(A[i],A[j]);    // swap value next to the current pivot
        }
    }
    swap(A[i], A[first]);    // swap current value to first value
    return i;
}



//insertion sort
void insertionSort(vector<unsigned long long>& vec, int start, int end) {
    for(int i = start; i <= end; i++) {
        int j = i;
        while(j > start && vec[j-1] > vec[j]) {     // swap value when value of the left greater than value on the right
            swap(vec[j-1], vec[j]);
            j--;
        }
    }
}
// hybrid sort of quicksort and insertion sort
void hybridSort(vector<unsigned long long> &vec, int start,  int end){
    if(start < end){
        if (end-start < 10){                // insertion sort when differene of first and last pivot is 10
            insertionSort(vec, start, end);
        } else {
            unsigned long long pivotIndex = partition(vec, start, end);     // get middle pivot
            hybridSort(vec, start, pivotIndex-1);       // recursively sort first half of partition
            hybridSort(vec, pivotIndex+1, end);         // recursively sort second half of partition
        }
    }
}
//swapping function
void swap(vector<unsigned long long>& v, int x,  int y) {
   unsigned long long temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}
