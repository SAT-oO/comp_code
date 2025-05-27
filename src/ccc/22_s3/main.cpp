//
//  main.cpp
//  CCC'22S3
//
//  Created by Tina Liu on 2024-02-17.
//

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;



ll min1(ll a, ll b){
    if (a > b){
        return b;
    }else{
        return a;
    }
}

int main(int argc, const char * argv[]) {
    
    ll n, m, k;
    ll rem = 0;
    ll cur = 0; //current contribution
    vector<ll> ans;
    cin>>n>>m>>k;
    
    for(ll i = 0; i < n; i++){
        rem = n - i-1;
        cur = min1(k - rem, m);
        
        if(cur <= 0){
            break;
        }
        
        ll val = 0;
        if(cur > i){ //distinctive
            val = min1(m, i+1);
            cur = val;
        }else{ //non-distinctive
            
            val = ans[i - cur];
        }
        
        ans.push_back(val);
        //cout<<val;
        k = k - cur;
        
        
    }
    
    
    if(k ==0 and (ll) ans.size() == n)
    {
        for(ll x : ans){
            cout<<x<<" ";
            
        }
        cout<<endl;
    }else{
        cout<<-1<< endl;
    }
    
    

    
    
    return 0;
}
