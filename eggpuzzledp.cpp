//problem - http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/
#include <bits/stdc++.h>
// #include <utility> // pari<int,int> a; 
// #include <string.h> // for memset

#define abs(x) ((x)>0 ? (x) : -1*(x))    //absolute value of x
#define max(a,b) ( (a) > (b) ? (a) : (b) ) // max of a,b
#define min(a,b) ( (a) < (b) ? (a) : (b) ) // min of a,b

/// Array Start
#define set(a) memset( (a), -1, sizeof((a)) )             
#define clr(a) memset( (a), 0, sizeof((a)) )                            
#define mem(a,val) memset( (a), (val), sizeof((a)) )                        
/// Array End

#define forloop(i,n) for (int i = 0; i < (n); ++i)

const int INF = 0x3f3f3f3f;
typedef long long ll; 
int mintrial(int n,int k);
//int result[100] = {0}; // initialization with zero
using namespace std;
int st[11][51]={0};
int main() {
   

	//     int arr[N+1];  // didn't work for large N
    //long int *arr=new long int[N+1]();
int t;
cin >> t;
int n,k;
while(t--){
cin >> n >>k;

cout << mintrial(n,k) << endl;

// forloop(i,11){

// forloop(j,51)
// 	cout << st[i][j] << " ";

// cout << endl;
// }

}


    return 0;
}

int mintrial(int n,int k){

	if(st[n][k]!=0 || k==0)
		return st[n][k];

	else if(n==1)
		return st[n][k] = k;
	else {
		int a;
		int min = 1000000;
		for(int i=1;i<=k;i++){
			a = 1 + max(mintrial(n-1,i-1),mintrial(n,k-i));
			if(a<min)
				min = a;
		}
		st[n][k] = min;
		return st[n][k];
	}
}
