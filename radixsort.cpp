#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <set>
#include <climits>
#include <vector>

#define N 1000000

using namespace std;

//prototype
void generateSet1(vector<unsigned long long>& a);
void generateSet2(vector<unsigned long long>& b);
void generateSet3(vector<unsigned long long>& c);
double RadixSortSet(vector<unsigned long long>& set);
void radixsort(vector<unsigned long long>& arr, int n);


int main(){
    vector<unsigned long long> set;
    
    /*RADIXSORT*/
    cout << "Radix Sort" << endl;
    // EXPERIMENT # 1
    /*RadixSort Set1 Experiment*/
    cout << "Set 1: where no number repeats" << endl;
    /*Generate sets of data for sorting*/
    generateSet1(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set.begin(), set.end());
        /*calculate execution time and display*/
        double Time = RadixSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // EXPERIMENT # 2
    /*RadixSort Set2 Experiment*/
    cout << "Set 2: where range of numbers is 1% of array size" << endl;
    /*Generate sets of data for sorting*/
    generateSet2(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set.begin(), set.end());
        /*calculate execution time and display*/
        double Time = RadixSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // EXPERIMENT # 3
    /*RadixSort Set3 Experiment*/
    cout << "Set 3: where each number is a unique 20 digit number" << endl;
    /*Generate sets of data for sorting*/
    generateSet3(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set.begin(), set.end());
        /*calculate execution time and display*/
        double Time = RadixSortSet(set);
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


/*RadixSort timing subroutine*/
double RadixSortSet(vector<unsigned long long>& set){
    clock_t startTime = clock();
    // Code
    radixsort(set, N);
    // to compute its execution duration in runtime
    return double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
}

/*Citation:
    https://www.geeksforgeeks.org/radix-sort/
 */
// A utility function to get maximum value in arr[]
unsigned long long getMax(vector<unsigned long long> arr, int n)
{
    unsigned long long mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
  
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(vector<unsigned long long>& arr, int n, int exp)
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
void radixsort(vector<unsigned long long>& arr, int n)
{
    // Find the maximum number to know number of digits
    unsigned long long m = getMax(arr, n);
  
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
