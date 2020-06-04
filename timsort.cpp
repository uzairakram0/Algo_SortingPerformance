#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <set>
#include <climits>
#include "timsort.hpp"

#define N 1000000

using namespace std;

//prototype
void generateSet1(unsigned long long a[]);
void generateSet2(unsigned long long b[]);
void generateSet3(unsigned long long c[]);
double TimSortSet(unsigned long long a[]);


int main(){
    unsigned long long set[N];
    
    /*TIMSORT*/
    cout << "TimSort" << endl;
    // EXPERIMENT # 1
    /*TimSort Set1 Experiment*/
    cout << "Set 1: where no number repeats" << endl;
    /*Generate sets of data for sorting*/
    generateSet1(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set, set+(N-1));
        /*calculate execution time and display*/
        double Time = TimSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // EXPERIMENT # 2
    /*TimSort Set2 Experiment*/
    cout << "Set 2: where range of numbers is 1% of array size" << endl;
    /*Generate sets of data for sorting*/
    generateSet2(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set, set+(N-1));
        /*calculate execution time and display*/
        double Time = TimSortSet(set);
        cout << "Experiment" << "[" << i << "]" << "time: " << Time << " seconds." << endl;
    }
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // EXPERIMENT # 3
    /*TimkSort Set3 Experiment*/
    cout << "Set 3: where each number is a unique 20 digit number" << endl;
    /*Generate sets of data for sorting*/
    generateSet3(set);
    for (int i = 0; i < 10; i++){
        //shuffle set
        random_shuffle(set, set+(N-1));
        /*calculate execution time and display*/
        double Time = TimSortSet(set);
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

/*TimeSort timing subroutine*/
double TimSortSet(unsigned long long a[]){
    clock_t startTime = clock();
    //CODE
    gfx::timsort(a, a+(N-1));
    // to compute its execution duration in runtime
    return double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
}
