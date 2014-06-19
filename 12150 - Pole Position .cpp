//
//  12150 - Pole Position .cpp
//  ACM-ICPC
//
//  Created by Giuseppe Marotta Portal on 6/19/14.
//  Copyright (c) 2014 Giuseppe. All rights reserved.
//



#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>
#include <map>

#define MAXN 100010
using namespace std;
int n;

int main()
{
        while( (cin>>n ) && n!=0){
            int a,b;
            //n vectors of -1
            vector<int> res;
            res.clear();
            res.resize(n);
            fill(res.begin(),res.end(),-10);
            
            bool entro=false;
            for(int i=0;i<n;i++){
                  cin>>a>>b;
            
                if(!entro){
                if ( (i+b<0 || i+b>=n) ){
                    entro=true;
                    cout<<"-1"<<endl;
                }
                else if(res[i+b]>0)
                {
                    entro=true;
                    cout<<"-1"<<endl;
                }
                else
                res[i+b]=a;
                
            }
                
            }
          
            if(!entro)
            {
                cout<<res[0];
                for(int i=1;i<n;i++){
                    cout<<" "<<res[i];
                }
                cout<<endl;
            }
    
        }
    
    return 0;
}

