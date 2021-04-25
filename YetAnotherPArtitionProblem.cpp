//
//  main.cpp
//  Yet another partition problem
//
//  Created by Vishal Jha on 04/11/20.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<ll>s;
    vector<ll>v;
    set<ll>::iterator it;
    ll n,q,a,i,x;
    cin>>n>>q;
    v.push_back(-1);
    for(i=1;i<=n;i++){
        cin>>a;
        v.push_back(a);
    }
    s.insert(1);
    for(i=1;i<n;i++){
        if(v[i+1]%v[i] != 0){
            s.insert(i+1);
        }
    }
    int type;
    for(i=0;i<q;i++){
        cin>>type;
        if(type == 1){
            cin>>x>>a;
            v[x] = a;
            if(x<n && v[x+1]%v[x] != 0 && s.find(x+1) == s.end()){
                s.insert(x+1);
            }else if(x<n && v[x+1]%v[x] == 0 && s.find(x+1) != s.end()){
                s.erase(x+1);
            }
            
            if(x>1 && v[x]%v[x-1] != 0){
                s.insert(x);
            }else if(x>1 && v[x]%v[x-1]==0 && s.find(x) != s.end()){
                s.erase(x);
            }
        }
        else{
            cin>>x;
            it = s.lower_bound(x);
            if((*it) != x){
                it--;
            }
            cout<<(*it)<<"\n";
        }
    }
    return 0;
    
}
