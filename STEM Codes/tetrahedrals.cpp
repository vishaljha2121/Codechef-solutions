#include <bits/stdc++.h>
using namespace std;

void tetrahedralNumber(int n)
{
    int num = n * (n + 1) * (n + 2) / 6;
    cout << num << endl;
}
int main()
{
    /* A tetrahedron is a pyramid with a triangular base and three sides.
       A tetrahedral number is a number of items within a tetrahedron. */
    int n = 6;
    tetrahedralNumber(n);
}