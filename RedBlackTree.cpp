#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <set>

#define N 1000000
#define INDENT_STEP  4
#define MAX 1000000

using namespace std;
enum color { RED, BLACK };

/*
 Citation: https://www.sanfoundry.com/cpp-program-implement-red-black-tree/
 */

// A utility function to swap to integers
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Node RBTree Declaration
 */
typedef struct rbtree_node
{
    enum color color;
    void *key;
    void *value;
    rbtree_node *left, *right, *parent;
}*node;
 
typedef struct rbtree_t
{
    node root;
}*rbtree;
 
/*
 * Class RBTree Declaration
 */
class RBTree
{
    public:
        typedef int (*compare_func)(void* left, void* right);
        rbtree rbtree_create();
        void* rbtree_lookup(rbtree t, void* , compare_func compare);
        void rbtree_insert(rbtree t, void* , void* , compare_func compare);
        void rbtree_delete(rbtree t, void* , compare_func compare);
        node grandparent(node n);
        node sibling(node n);
        node uncle(node n);
        color node_color(node n);
        node new_node(void* key, void* , color , node , node);
        node lookup_node(rbtree t, void* , compare_func compare);
        void rotate_left(rbtree t, node n);
        void rotate_right(rbtree t, node n);
        void replace_node(rbtree t, node oldn, node newn);
        void insert_case1(rbtree t, node n);
        void insert_case2(rbtree t, node n);
        void insert_case3(rbtree t, node n);
        void insert_case4(rbtree t, node n);
        void insert_case5(rbtree t, node n);
        node maximum_node(node root);
        void delete_case1(rbtree t, node n);
        void delete_case2(rbtree t, node n);
        void delete_case3(rbtree t, node n);
        void delete_case4(rbtree t, node n);
        void delete_case5(rbtree t, node n);
        void delete_case6(rbtree t, node n);
};
/*
 * Return Grandparent of Node
 */
node RBTree::grandparent(node n)
{
    assert (n != NULL);
    assert (n->parent != NULL);
    assert (n->parent->parent != NULL);
    return n->parent->parent;
}
 
/*
 * Return Sibling of Node
 */
node RBTree::sibling(node n)
{
    assert (n != NULL);
    assert (n->parent != NULL);
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}
 
/*
 * Return Uncle of Node
 */
node RBTree::uncle(node n)
{
    assert (n != NULL);
    assert (n->parent != NULL);
    assert (n->parent->parent != NULL);
    return sibling(n->parent);
}
/*
 * Returns color of a node
 */
color RBTree::node_color(node n)
{
    return n == NULL ? BLACK : n->color;
}
 
/*
 * Create Red Black Tree
 */
rbtree RBTree::rbtree_create()
{
    rbtree t = new rbtree_t;
    t->root = NULL;
    return t;
}
 
/*
 * Creating New Node of Reb Black Tree
 */
node RBTree::new_node(void* k, void* v, color n_color, node left, node right)
{
    node result = new rbtree_node;
    result->key = k;
    result->value = v;
    result->color = n_color;
    result->left = left;
    result->right = right;
    if (left  != NULL)
        left->parent = result;
    if (right != NULL)
        right->parent = result;
    result->parent = NULL;
    return result;
}
/*
 * Look Up through Node
 */
node RBTree::lookup_node(rbtree t, void* key, compare_func compare)
{
    node n = t->root;
    while (n != NULL)
    {
        int comp_result = compare(key, n->key);
        if (comp_result == 0)
        {
            return n;
        }
        else if (comp_result < 0)
        {
            n = n->left;
        }
        else
        {
            assert(comp_result > 0);
            n = n->right;
        }
    }
    return n;
}
/*
 * RbTree Look Up
 */
void* RBTree::rbtree_lookup(rbtree t, void* key, compare_func compare)
{
    node n = lookup_node(t, key, compare);
    return n == NULL ? NULL : n->value;
}
 
/*
 * Rotate left
 */
void RBTree::rotate_left(rbtree t, node n)
{
    node r = n->right;
    replace_node(t, n, r);
    n->right = r->left;
    if (r->left != NULL)
    {
        r->left->parent = n;
    }
    r->left = n;
    n->parent = r;
}
/*
 * Rotate right
 */
void RBTree::rotate_right(rbtree t, node n)
{
    node L = n->left;
    replace_node(t, n, L);
    n->left = L->right;
    if (L->right != NULL)
    {
        L->right->parent = n;
    }
    L->right = n;
    n->parent = L;
}
/*
 * Replace a node
 */
void RBTree::replace_node(rbtree t, node oldn, node newn)
{
    if (oldn->parent == NULL)
    {
        t->root = newn;
    }
    else
    {
        if (oldn == oldn->parent->left)
            oldn->parent->left = newn;
        else
            oldn->parent->right = newn;
    }
    if (newn != NULL)
    {
        newn->parent = oldn->parent;
    }
}
/*
 * Insert node into RBTree
 */
void RBTree::rbtree_insert(rbtree t, void* key, void* value, compare_func compare)
{
    node inserted_node = new_node(key, value, RED, NULL, NULL);
    if (t->root == NULL)
    {
        t->root = inserted_node;
    }
    else
    {
        node n = t->root;
        while (1)
        {
            int comp_result = compare(key, n->key);
            if (comp_result == 0)
            {
                n->value = value;
                return;
            }
            else if (comp_result < 0)
            {
                if (n->left == NULL)
                {
                    n->left = inserted_node;
                    break;
                }
                else
                {
                    n = n->left;
                }
            }
            else
            {
                assert (comp_result > 0);
                if (n->right == NULL)
                {
                    n->right = inserted_node;
                    break;
                }
                else
                {
                    n = n->right;
                }
            }
        }
        inserted_node->parent = n;
    }
    insert_case1(t, inserted_node);
}
 
/*
 * Inserting Case 1
 */
void RBTree::insert_case1(rbtree t, node n)
{
    if (n->parent == NULL)
        n->color = BLACK;
    else
        insert_case2(t, n);
}
 
/*
 * Inserting Case 2
 */
void RBTree::insert_case2(rbtree t, node n)
{
    if (node_color(n->parent) == BLACK)
        return;
    else
        insert_case3(t, n);
}
 
/*
 * Inserting Case 3
 */
void RBTree::insert_case3(rbtree t, node n)
{
    if (node_color(uncle(n)) == RED)
    {
        n->parent->color = BLACK;
        uncle(n)->color = BLACK;
        grandparent(n)->color = RED;
        insert_case1(t, grandparent(n));
    }
    else
    {
        insert_case4(t, n);
    }
}
 
/*
 * Inserting Case 4
 */
void RBTree::insert_case4(rbtree t, node n)
{
    if (n == n->parent->right && n->parent == grandparent(n)->left)
    {
        rotate_left(t, n->parent);
        n = n->left;
    }
    else if (n == n->parent->left && n->parent == grandparent(n)->right)
    {
        rotate_right(t, n->parent);
        n = n->right;
    }
    insert_case5(t, n);
}
 
/*
 * Inserting Case 5
 */
void RBTree::insert_case5(rbtree t, node n)
{
    n->parent->color = BLACK;
    grandparent(n)->color = RED;
    if (n == n->parent->left && n->parent == grandparent(n)->left)
    {
        rotate_right(t, grandparent(n));
    }
    else
    {
        assert (n == n->parent->right && n->parent == grandparent(n)->right);
        rotate_left(t, grandparent(n));
    }
}
 
/*
 * Delete Node from RBTree
 */
void RBTree::rbtree_delete(rbtree t, void* key, compare_func compare)
{
    node child;
    node n = lookup_node(t, key, compare);
    if (n == NULL)
        return;
    if (n->left != NULL && n->right != NULL)
    {
        node pred = maximum_node(n->left);
        n->key   = pred->key;
        n->value = pred->value;
        n = pred;
    }
    assert(n->left == NULL || n->right == NULL);
    child = n->right == NULL ? n->left  : n->right;
    if (node_color(n) == BLACK)
    {
        n->color = node_color(child);
        delete_case1(t, n);
    }
    replace_node(t, n, child);
    free(n);
}
 
/*
 * Returns Maximum node
 */
node RBTree::maximum_node(node n)
{
    assert (n != NULL);
    while (n->right != NULL)
    {
        n = n->right;
    }
    return n;
}
 
/*
 * Deleting Case 1
 */
void RBTree::delete_case1(rbtree t, node n)
{
    if (n->parent == NULL)
        return;
    else
        delete_case2(t, n);
}
 
/*
 * Deleting Case 2
 */
void RBTree::delete_case2(rbtree t, node n)
{
    if (node_color(sibling(n)) == RED)
    {
        n->parent->color = RED;
        sibling(n)->color = BLACK;
        if (n == n->parent->left)
            rotate_left(t, n->parent);
        else
            rotate_right(t, n->parent);
    }
    delete_case3(t, n);
}
 
/*
 * Deleting Case 3
 */
void RBTree::delete_case3(rbtree t, node n)
{
    if (node_color(n->parent) == BLACK && node_color(sibling(n)) == BLACK &&
        node_color(sibling(n)->left) == BLACK && node_color(sibling(n)->right) == BLACK)
    {
        sibling(n)->color = RED;
        delete_case1(t, n->parent);
    }
    else
        delete_case4(t, n);
}
 
/*
 * Deleting Case 4
 */
void RBTree::delete_case4(rbtree t, node n)
{
    if (node_color(n->parent) == RED && node_color(sibling(n)) == BLACK &&
        node_color(sibling(n)->left) == BLACK && node_color(sibling(n)->right) == BLACK)
    {
        sibling(n)->color = RED;
        n->parent->color = BLACK;
    }
    else
        delete_case5(t, n);
}
 
/*
 * Deleting Case 5
 */
void RBTree::delete_case5(rbtree t, node n)
{
    if (n == n->parent->left && node_color(sibling(n)) == BLACK &&
        node_color(sibling(n)->left) == RED && node_color(sibling(n)->right) == BLACK)
    {
        sibling(n)->color = RED;
        sibling(n)->left->color = BLACK;
        rotate_right(t, sibling(n));
    }
    else if (n == n->parent->right && node_color(sibling(n)) == BLACK &&
             node_color(sibling(n)->right) == RED && node_color(sibling(n)->left) == BLACK)
    {
        sibling(n)->color = RED;
        sibling(n)->right->color = BLACK;
        rotate_left(t, sibling(n));
    }
    delete_case6(t, n);
}
 
/*
 * Deleting Case 6
 */
void RBTree::delete_case6(rbtree t, node n)
{
    sibling(n)->color = node_color(n->parent);
    n->parent->color = BLACK;
    if (n == n->parent->left)
    {
        assert (node_color(sibling(n)->right) == RED);
        sibling(n)->right->color = BLACK;
        rotate_left(t, n->parent);
    }
    else
    {
        assert (node_color(sibling(n)->left) == RED);
        sibling(n)->left->color = BLACK;
        rotate_right(t, n->parent);
    }
}
 
/*
 * Compare two nodes
 */
int compare_int(void* leftp, void* rightp)
{
    int left = (int)leftp;
    int right = (int)rightp;
    if (left < right)
        return -1;
    else if (left > right)
        return 1;
    else
    {
        assert (left == right);
        return 0;
    }
}
/*
 * Print RBTRee
 */
void print_tree_helper(node n, int indent)
{
    int i;
    if (n == NULL)
    {
        fputs("<empty tree>", stdout);
        return;
    }
    if (n->right != NULL)
    {
        print_tree_helper(n->right, indent + INDENT_STEP);
    }
    for(i = 0; i < indent; i++)
        fputs(" ", stdout);
    if (n->color == BLACK)
        cout<<(int)n->key<<endl;
    else
        cout<<"<"<<(int)n->key<<">"<<endl;
    if (n->left != NULL)
    {
        print_tree_helper(n->left, indent + INDENT_STEP);
    }
}
 
void print_tree(rbtree t)
{
    print_tree_helper(t->root, 0);
    puts("");
}
 
int height(node temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int black_height(node temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_b_height = black_height(temp->left);
        int r_b_height = black_height(temp->right);
        int max_b_height = max(l_b_height, r_b_height);
        if (temp->color == BLACK)
            h = max_b_height + 1;
        else
            h = max_b_height;
    }
    return h;
}


//prototype
void generateSet(int a[]);
void generateDel(int a[]);
double InsertionRB(int a[]);
double deletionRB(int a[]);


int main(){
    int *set = new int[N];
    int *del = new int[N/10];
    RBTree rbt;
    rbtree t = rbt.rbtree_create();
    
    /*Generate sets for experiment*/
    generateSet(set);
    generateDel(del);
    
    // EXPERIMENT INSERTION DELETION
    /*REDBLACK TREE*/
    cout << "Red Black Tree" << endl;
    /*Red Black Tree Insert Experiment*/
    for (int run = 0; run < 10; run++){
        //shuffle sets
        random_shuffle(set, set+(N-1));
        random_shuffle(del, del+(N-1));
        
        cout << "Experiment" << "[" << run << "]" << endl;
        /*calculate execution time and display*/
        //Insertion Experiment
        clock_t startTime = clock();
        for(int i = 0; i < N; i++){
            int x = set[i];
            int y = rand() % N;
            rbt.rbtree_insert(t, (void*)x, (void*)y, compare_int);
            assert(rbt.rbtree_lookup(t, (void*)x, compare_int) == (void*)y);
        }
        clock_t Time = clock();
        //Insertion experiment end
        /*Display Results*/
        cout << "Insertion Experiment" << "[" << run << "]" << " time: " << (double)( Time - startTime ) / CLOCKS_PER_SEC << " seconds." << endl;
        cout << "Tree Height: " << height(t->root) << endl;
        cout << "Tree Black Height: " << black_height(t->root) << endl;
        
        //Deletion Experiment
        startTime = clock();
        for(int i = 0; i < (N/10); i++){
            int x = del[i];
            rbt.rbtree_delete(t, (void*)x, compare_int);
        }
        Time = clock();
        //Deletion experiment end
        /*Display Results*/
        cout << "Deletion Experiment" << "[" << run << "]" << "time: " << (double)( Time - startTime ) / CLOCKS_PER_SEC << " seconds." << endl;
        cout << "Tree Height: " << height(t->root) << endl;
        cout << "Tree Black Height: " << black_height(t->root) << endl;
        cout << endl;
    }
    
    return 0;
}

/*Function for generating set*/
void generateSet(int a[]){
    for (int i = 0; i < N; i++){
        a[i] = i;
    }
}
/*Function for generating deletion set*/
void generateDel(int a[]){
    set <int> s;
    while(s.size() < (N/10)){
        int element = rand() % N;
        s.insert(element);
    }
    //generate array of set
    int i = 0;
    for(set<int>::iterator it = s.begin(); it!=s.end();it++){
        a[i++] = *it;
    }
}
///*REDBLACK tree insertion time Experiment Subroutine*/
//double InsertionRB(int a[], class RBTree *rbt)){
//    int i = 0;
//    clock_t startTime = clock();
//    // CODE
//    for(i = 0; i < N/10; i++){
//        int x = a[i];
//        int y = rand() % MAX;
//        *rbt.rbtree_insert(t, (void*)x, (void*)y, compare_int);
//        assert(*rbt.rbtree_lookup(t, (void*)x, compare_int) == (void*)y);
//    }
//    // to compute its execution duration in runtime
//    return double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
//}
//
///*REDBLACK tree deletion time Experiment Subroutine*/
//double deletionRB(int a[], class RBTree *rbt){
//    int i = 0;
//    clock_t startTime = clock();
//    // Delete 10% elements
//    for(i = 0; i < (N/10); i++){
//        int x = a[i];
//        *rbt.rbtree_delete(t, (void*)x, compare_int);
//    }
//    // to compute its execution duration in runtime
//    return double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
//}
