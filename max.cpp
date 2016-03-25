//https://www.hackerrank.com/challenges/crush

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
     long int N,M;
    cin >> N >> M;
     long int a,b,k;

//     int arr[N+1];  // didn't work
    long int *arr=new long int[N+1]();
    
//    for(int i = 0;i<N+2;i++)
  //      arr[i] = 0;
    
    long int max=0,s=0;
    
    for(int i=0;i<M;i++){
        
        cin >> a >> b >> k;
        
        if(b+1 <= N)
        arr[b+1] = arr[b+1] - k;

        if(a <= N)
        arr[a] = arr[a] + k;
    }    
    
    for(int j=1;j<=N ; j++){
        s = s + arr[j];
        if(s > max) max = s;
    }
        
        cout<< max ;
        s=0;
        max=0;
    
    
    return 0;
}
