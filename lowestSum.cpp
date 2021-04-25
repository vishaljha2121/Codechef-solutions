#include <bits/stdc++.h>
using namespace std;
#define K 20000;
#define Q 500;

int lowestSum(int A[], int B[], int k, int q)
{
    /* The Head Chef is studying the motivation and satisfaction level of his chefs .
    The motivation and satisfaction of a Chef can be represented as an integer .
    The Head Chef wants to know the N th smallest sum of one satisfaction value and one motivation value for various values of N .
    The satisfaction and motivation values may correspond to the same chef or different chefs .
    Given two arrays, the first array denoting the motivation value and the second array denoting the satisfaction value of the chefs .
    We can get a set of sums(add one element from the first array and one from the second).
    For each query ( denoted by an integer qi ( i = 1 to Q ) , Q denotes number of queries ) ,
    find the qi th element in the set of sums ( in non-decreasing order ) . */

    int sum_of_elements_a_b[20000];
    int idx = 0;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= q; j++)
        {
            sum_of_elements_a_b[idx] = A[i] + B[j];
            idx++;
        }
    }

    int allLength = sizeof(sum_of_elements_a_b) / sizeof(sum_of_elements_a_b[0]);
    for (int j = 0; j < allLength; j++)
    {
        cout << sum_of_elements_a_b[j] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A[] = {1, 2, 3};
    int B[] = {4, 5, 6};
    int k = 3, q = 1;
    lowestSum(A, B, k, q);
}