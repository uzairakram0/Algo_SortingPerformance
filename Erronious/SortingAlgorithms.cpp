#include <iostream>
#include <cstdlib>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <time.h>
#include <set>
#include "timsort.hpp"

#define N 1000000

using namespace std;

//prototype
void generateSet1(unsigned long long a[]);
void generateSet2(unsigned long long b[]);
void generateSet3(unsigned long long c[]);
double QuickSortSet(unsigned long long a[]);
double InsertionQuickSortSet(unsigned long long a[]);
double RadixSortSet(unsigned long long a[]);
double TimSortSet(unsigned long long a[]);

//auxilary function prototypes
int compare(const void* a_, const void* b_);
//sorting algorithms prototypes
void hybridSort(unsigned long long a[], int start,  int end);
void radixsort(unsigned long long arr[], int n);


int main(){
    unsigned long long set[N];
    
    /*QUICKSORT*/
    cout << "Quick Sort" << endl;
    /*QuickSort Set1 Experiment*/
    cout << "Set 1: where no number repeats" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet1(set);
        /*calculate and display*/
        double Time = QuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    /*QuickSort Set2 Experiment*/
    cout << "Set 2: where range of numbers is 1% of array size" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet2(set);
        /*calculate and display*/
        double Time = QuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    /*QuickSort Set3 Experiment*/
    cout << "Set 3: where each number is a unique 20 digit number" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet3(set);
        /*calculate and display*/
        double Time = QuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << "========================================" << endl;
    cout << "========================================" << endl;

    /*INSERTIONQUICKSORT*/
    cout << "Insertion/Quick Sort" << endl;
    /*InsertionQuickSort Set1 Experiment*/
    cout << "Set 1: where no number repeats" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet1(set);
        /*calculate and display*/
        double Time = InsertionQuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    /*InsertionQuickSort Set2 Experiment*/
    cout << "Set 2: where range of numbers is 1% of array size" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet2(set);
        /*calculate and display*/
        double Time = InsertionQuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    /*InsertionQuickSort Set3 Experiment*/
    cout << "Set 3: where each number is a unique 20 digit number" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet3(set);
        /*calculate and display*/
        double Time = InsertionQuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    
    /*RADIXSORT*/
    cout << "Radix Sort" << endl;
    /*RadixSort Set1 Experiment*/
    cout << "Set 1: where no number repeats" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet1(set);
        /*calculate and display*/
        double Time = RadixSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    /*RadixSort Set2 Experiment*/
    cout << "Set 2: where range of numbers is 1% of array size" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet2(set);
        /*calculate and display*/
        double Time = RadixSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    /*RadixSort Set3 Experiment*/
    cout << "Set 3: where each number is a unique 20 digit number" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet3(set);
        /*calculate and display*/
        double Time = RadixSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    
    /*TIMSORT*/
    cout << "TimSort" << endl;
    /*TimSort Set1 Experiment*/
    cout << "Set 1: where no number repeats" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet1(set);
        /*calculate and display*/
        double Time = TimSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    /*TimSort Set2 Experiment*/
    cout << "Set 2: where range of numbers is 1% of array size" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet2(set);
        /*calculate and display*/
        double Time = TimSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    /*TimSort Set3 Experiment*/
    cout << "Set 3: where each number is a unique 20 digit number" << endl;
    for (int i = 0; i < 10; i++){
        /*Generate sets of data for sorting*/
        generateSet3(set);
        /*calculate and display*/
        double Time = TimSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    return 0;
}
/*Function for generating set 1*/
void generateSet1(unsigned long long a[]){
    /*Set 1 generating unique numbers*/
    set <int> s;
    int element;
    while(s.size() < N){
        element = rand();
        s.insert(element);
    }
    //generate array from set
    int i = 0;
    for(set<int>::iterator it = s.begin(); it!=s.end();it++){
        a[i++] = *it;
    }
}

/*Function for generating set 2*/
void generateSet2(unsigned long long b[]){
    /*Set 2 generating numbers less than 1% the size of set*/
    int range = N/100;
    for (int i = 0; i > N; i++){
        b[i] = rand() % range;
    }
}

/*Function for generating set 3*/
void generateSet3(unsigned long long c[]){
    /*Set 3 generating unique 20 digit numbers*/
    set<unsigned long long> s;
    unsigned long long min = 10000000000000000000u;
    unsigned long long max = 18446744073709551615u;
    int range = max - min + 1;
    while(s.size() < N){
        unsigned long long element = rand() % range + min;
        s.insert(element);
    }
    //generate array of set
    int i = 0;
    for(set<unsigned long long>::iterator it = s.begin(); it!=s.end();it++){
        c[i++] = *it;
    }
    
}
/*QuickSort timing subroutine*/
double QuickSortSet(unsigned long long a[]){
    clock_t startTime = clock();
    // CODE
        qsort(a, N, sizeof(unsigned long long), compare);
    // to compute its execution duration in runtime
    return double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
}

/*InsertionQuickSort timing subroutine*/
double InsertionQuickSortSet(unsigned long long a[]){
    clock_t startTime = clock();
    // CODE
        hybridSort(a, 0, N-1);
    // to compute its execution duration in runtime
    return double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
}

/*RadixSort timing subroutine*/
double RadixSortSet(unsigned long long a[]){
    clock_t startTime = clock();
    // Code
    radixsort(a, N);
    // to compute its execution duration in runtime
    return double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
}

/*TimeSort timing subroutine*/
double TimSortSet(unsigned long long a[]){
    clock_t startTime = clock();
    //CODE
    gfx::timsort(a, a+(N-1));
    // to compute its execution duration in runtime
    return double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
}
/*auxilary compare function for c++ qsort()*/
int compare(const void* a_, const void* b_)
{
    long long (*a)[2] = (long long (*)[2]) a_;
    long long (*b)[2] = (long long (*)[2]) b_;

    long long result;

    if ((*a)[0] - (*b)[0] != 0)
        result = (*a)[0] - (*b)[0];
    else
        result = (*a)[1] - (*b)[1];

    if (result < 0)
        return -1;
    else if (result > 0)
        return 1;
    else
        return 0;
}

/*Insertion Quick Sort*/
/*Citation:
    https://www.techiedelight.com/hybrid-quicksort/
 */
// perform insertion sort on arr[]
//swapping function
void swap(unsigned long long a[], int x,  int y) {
   unsigned long long temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

// perform insertion sort on arr[]
// partition for quicksort algorithm
int partition(unsigned long long A[], int first,int last)
    {
        int i= first;        // first pivot
        int j;
    
        for(j= first+1; j <= last; j++)
        {
            if(A[first] > A[j])        // use first value as the pivot
            {
                i=i+1;
                swap(A[i],A[j]);    // swap value next to the current pivot
            }
    
        }
    
        swap(A[i], A[first]);    // swap current value to first value
        return i;
    }



//insertion sort
void insertionSort(unsigned long long a[], int start, int end) {
    for(int i = start; i <= end; i++) {
        int j = i;
        while(j > start && a[j-1] > a[j]) {     // swap value when value of the left greater than value on the right
            swap(a[j-1], a[j]);
            j--;
        }
    }
}
// hybrid sort of quicksort and insertion sort
void hybridSort(unsigned long long a[], int start,  int end){
    if(start < end){
        if (end-start < 10){                // insertion sort when differene of first and last pivot is 10
            insertionSort(a, start, end);
        } else {
            unsigned long long pivotIndex = partition(a, start, end);     // get middle pivot
            hybridSort(a, start, pivotIndex-1);       // recursively sort first half of partition
            hybridSort(a, pivotIndex+1, end);         // recursively sort second half of partition
        }
    }
}

/*Citation:
    https://www.geeksforgeeks.org/radix-sort/
 */
// A utility function to get maximum value in arr[]
unsigned long long getMax(unsigned long long arr[], int n)
{
    unsigned long long mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
  
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(unsigned long long arr[], int n, int exp)
{
    unsigned long long output[n]; // output array
    int i, count[10] = {0};
  
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
  
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
  
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
  
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
  
// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(unsigned long long arr[], int n)
{
    // Find the maximum number to know number of digits
    unsigned long long m = getMax(arr, n);
  
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
