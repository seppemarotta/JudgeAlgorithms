
// Uva Online Judge
//

//Author : Seppemarotta

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

void reflexion(vector<string> &v){
    // rota 90 grados
    int tam=v.size();
    vector<string> temp=v;
    for (int r=0;r<tam;r++)
        for (int c=0;c<tam;c++)
            temp[r][c] = v[n-r-1][c];
    v=temp;
}


void rotar(vector<string> &v){
    // rota 90 grados
    int tam=v.size();
    vector<string> temp=v;
    for (int r=0;r<tam;r++)
        for (int c=0;c<tam;c++)
            temp[c][n-r-1] = v[r][c];
    v=temp;
    
}


bool compara(vector<string> &org,vector<string> &obj)
{

    for(int i=0;i<n;i++)
    {
        if ( org[i].compare(obj[i]) != 0)
        {
    	    return false;
        }
    }
    return true;
}

int main()
{
   
    
    int cont=0;
    while( scanf("%d\n",&n)!=EOF){
        cont++;
        cout<<"Pattern "<<cont;
        vector<string>org,obj;
        org.resize(n);
        obj.resize(n);
        // lectura de la original
        for(int i=0;i<n;i++)
        {
            cin>>org[i]>>obj[i];
        }
        bool entro=false;
        // hallar todas las posibilidades
        if(compara (org,obj))
            cout<<" was preserved."<<endl;
        else{
            //90*
            rotar(org);
            if(compara (org,obj) && !entro )
            {
                cout<<" was rotated 90 degrees."<<endl;
              entro=true;
            }
            rotar(org);
            if(compara (org,obj)&& !entro)
            {
                cout<<" was rotated 180 degrees."<<endl;
              entro=true;
            }
            rotar(org);
            if(compara (org,obj)&& !entro)
            {
                cout<<" was rotated 270 degrees."<<endl;
                entro=true;
            }
            rotar(org);
            //pulleo el estado original
            //todos reflectados a partir de aqui
            reflexion(org);
            if(compara (org,obj)&& !entro)
            {
                cout<<" was reflected vertically."<<endl;
                entro=true;
            }
            
            rotar(org);
            if(compara (org,obj)&& !entro)
            {
                cout<<" was reflected vertically and rotated 90 degrees."<<endl;
                entro=true;
            }
            rotar(org);
            if(compara (org,obj)&& !entro)
            {
                cout<<" was reflected vertically and rotated 180 degrees."<<endl;
                entro=true;
            }
            rotar(org);
            if(compara (org,obj)&& !entro)
            {
                cout<<" was reflected vertically and rotated 270 degrees."<<endl;
                entro=true;
            }
            if(!entro)
            {
                cout<<" was improperly transformed."<<endl;
            }
            
        }
        
       
        
        
        
        
    }
    
    
    
    return 0;
}

