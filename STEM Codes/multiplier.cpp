#include <bits/stdc++.h>
using namespace std;
int main()
{
    int array[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int array_length = sizeof(array) / sizeof(array[0]);
    int product_of_array_elements = 1;
    for (int i = 0; i < array_length; i++)
    {
        product_of_array_elements = product_of_array_elements * array[i];
    }
    cout << product_of_array_elements << endl;
}