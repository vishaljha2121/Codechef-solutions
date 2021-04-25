//
//  main.cpp
//  yet again a sub array problem
//
//  Created by Vishal Jha on 05/11/20.
//
#include<iostream>
using namespace std;

int calculateNewK(long long int size, long long int K)
{
    long long int val = (K + size - 1)/size;
    return (K + val -1)/val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int TC;
    cin>>TC;
    for(int t=0; t<TC; t++)
    {
        int N,K;
        cin>>N>>K;
        int arr[N];
        int kVal[N+1];
        for(long long int i=0;i<N;i++)
        {
            cin>>arr[i];
            kVal[i+1] = calculateNewK(i+1,K);
            //cout<<kVal[i+1]<<"\n";
        }
        
        int isBeautyCnt=0;
        for(int i=0;i<N;i++)
        {
            int freqCnt[2001]={0};
            
            int no_of_ele=0, curr_ele=0;
            for(int j=i; j<N; j++)
            {
                
                freqCnt[arr[j]]++;
                int newK = kVal[j-i+1];
                
                if(arr[j] <= curr_ele)
                {no_of_ele++;
                }
                
                while(curr_ele < 2001 && no_of_ele < newK)
                {
                    no_of_ele += freqCnt[++curr_ele];
                }
                
                while(curr_ele > 0 && no_of_ele - freqCnt[curr_ele] >= newK)
                {
                    no_of_ele -= freqCnt[curr_ele--];
                }
                
                
                if(freqCnt[freqCnt[curr_ele]]!=0)
                {
                    isBeautyCnt++;
                }
                
            
            }
        }
        cout<<isBeautyCnt<<"\n";
    }
    return 0;
}
