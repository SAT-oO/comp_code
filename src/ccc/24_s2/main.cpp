//
//  main.cpp
//  CCC24S2
//
//  Created by Tina Liu on 2024-02-21.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int t, n;

string line;
int arr[200];

bool flag;



int main(int argc, const char * argv[]) {
    cin>>t>>n;
    for(int r = 1; r <= t; r++){ //processing queries
        
        cin>>line;
        line = " " + line;
        flag = true;
        
        for(int i = 0; i < 200; i++){
            arr[i] = 0;
            
        }
        
        
        for(int i = 1; i <= n; i++){
            arr[line[i] - 96]++;
            
        }
        
        /*
        for(int i = 1; i <= 5; i++){
            
            cout<<arr[i]<<endl;
        }
        */
        
        
        
        //scan + process
        
        if(arr[line[1] -96] > 1){//heavy light
            //check heavy
            for(int i = 1; i <= n; i += 2){
                if(arr[line[i] -96] <= 1){
                    flag = false;
                }
                
                
            }
            //check light
            for(int i = 2; i <= n; i += 2){
                if(arr[line[i] -96] > 1){
                    flag = false;
                }
                
                
            }
            
            
        }else if(arr[line[1] -96] == 1){ //light heavy
            //check heavy
            for(int i = 2; i <= n; i += 2){
                if(arr[line[i] -96] <= 1){
                    flag = false;
                }
                
                
            }
            //check light
            for(int i = 1; i <= n; i += 2){
                if(arr[line[i] -96] != arr[line[1] -96]){
                    flag = false;
                }
                
                
            }
            
            
            
            
            
        }
        
        
        
        
        
        
        
        
        if(flag){
            cout<<"T"<<endl;
        }else{
            cout<<"F"<<endl;
        }
        
        
        
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
