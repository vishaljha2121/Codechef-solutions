#include <bits/stdc++.h>
using namespace std;

int countTrue(bool vals[], int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (vals[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    bool vals[] = {true,
                   false,
                   true,
                   true,
                   false,
                   false};
    int length = sizeof(vals) / sizeof(vals[0]);
    cout << countTrue(vals, length) << endl;
}