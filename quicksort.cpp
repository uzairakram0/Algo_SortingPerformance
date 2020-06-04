#include <iostream>
#include <cstdlib>
#include <list>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <set>
#include <climits>

#define N 1000000

using namespace std;

//prototype
void generateSet1(unsigned long long a[]);
void generateSet2(unsigned long long b[]);
void generateSet3(unsigned long long c[]);
double QuickSortSet(unsigned long long a[]);
int compare(const void* a_, const void* b_);


int main(){
    unsigned long long set[N];
    
    /*QUICKSORT*/
    cout << "Quick Sort" << endl;
    // EXPERIMENT # 1
    /*QuickSort Set1 Experiment*/
    cout << "Set 1: where no number repeats" << endl;
    /*Generate sets of data for sorting*/
    generateSet1(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set, set+(N-1));
        /*calculate execution time and display*/
        double Time = QuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // EXPERIMENT # 2
    /*QuickSort Set2 Experiment*/
    cout << "Set 2: where range of numbers is 1% of array size" << endl;
    /*Generate sets of data for sorting*/
    generateSet2(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set, set+(N-1));
        /*calculate execution time and display*/
        double Time = QuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // EXPERIMENT # 3
    /*QuickSort Set3 Experiment*/
    cout << "Set 3: where each number is a unique 20 digit number" << endl;
    /*Generate sets of data for sorting*/
    generateSet3(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set, set+(N-1));
        /*calculate execution time and display*/
        double Time = QuickSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    return 0;
}
/*Function for generating set 1*/
void generateSet1(unsigned long long a[]){
    /*Set 1 generating unique numbers*/
    for (unsigned long long i = 0; i < N; i++){
        a[i] = i;
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
    unsigned long long max = ULLONG_MAX;
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
