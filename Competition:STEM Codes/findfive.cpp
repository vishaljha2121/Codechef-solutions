#include <bits/stdc++.h>
using namespace std;
#define MAX 100

bool findFive(int n[], int length)
{
    /* Create a function that takes an array of numbers and returns "Hello World!" if the digit 5 appears in the array.
       Otherwise, return "there is no 5 in the array". */
    bool condition = false;
    int arrayLength = length;
    for (int i = 0; i < arrayLength; i++)
    {
        //Checking for digit 5 in the current number
        //If present -> condition = true
        //int arr[MAX];
        int r, N = n[i];
        //int j = 0;
        while (N != 0)
        {
            r = N % 10;
            N = N / 10;
            if (r == 5)
            {
                condition = true;
                break;
            }
        }
    }
    //cout << condition << endl;
    //cout << true << false;
    return condition;
}

int main()
{
    int x[] = {12,
               65,
               4,
               67,
               987,
               234,
               87,
               89,
               6745,
               567,
               987,
               476,
               708,
               36,
               5587,
               798,
               884,
               671,
               7889};
    int length = sizeof(x) / sizeof(x[0]);

    if (!findFive(x, length))
    {
        cout << "there is no 5 in the array" << endl;
    }
    else
    {
        cout << "Hello World!" << endl;
    }
}