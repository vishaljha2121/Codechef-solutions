//
//  main.cpp
//  Fencing
//
//  Created by Vishal Jha on 04/11/20.
//

#include <iostream>
#include <utility>
#include <algorithm>
#include <map>


using namespace std;

int main(){
    map<pair<int,int>, int>field;
    int i,j,n,m,k,t,x,y;
    
    cin>>t;
    for(i=0;i<t;i++){
        int c = 0;
        cin>>n>>m>>k;
        int ar[k][2];
        
        for(j=0;j<k;j++){
            cin>>x>>y;
            ar[j][0] = x;
            ar[j][1] = y;
            field[make_pair(x, y)] = 1;
        }
        
        for(j=0;j<k;j++){
            if(field.find({ar[j][0]+1, ar[j][1]}) == field.end())
                c++;
            if(field.find({ar[j][0]-1, ar[j][1]}) == field.end())
                c++;
            if(field.find({ar[j][0], ar[j][1]+1}) == field.end())
                c++;
            if(field.find({ar[j][0], ar[j][1]-1}) == field.end())
                c++;
        }
        cout<<c<<endl;
        field.clear();
    }
}
