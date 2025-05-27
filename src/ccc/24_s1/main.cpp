//
//  main.cpp
//  CCC24S1
//
//  Created by Tina Liu on 2024-02-21.
//

#include <iostream>
using namespace std;

int n;
int h[1000009];

int ans;

int main(int argc, const char * argv[]) {
    cin>>n;
    
    for(int i = 1; i <= n; i ++){
        cin>>h[i];
    }
    
    for(int i = 1; i <= n/2; i++){
        if(h[i] == h[i+n/2]){
            ans+=2;
        }
        
    }
    cout<<ans<<endl;
    
    
    
    
    return 0;
}
