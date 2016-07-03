
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

//int result[100] = {0}; // initialization with zero
using namespace std;

int main() {
   

	//     int arr[N+1];  // didn't work for large N
    //long int *arr=new long int[N+1]();
    int t;
    cin >> t;
    int a[10][10];
    int n;
    while(t--){
    	cin >> n;
    	forloop(i,n)
    		forloop(j,n)
    			cin >> a[i][j];


    	int d_u=n-1;
   		int l_r=0;
   		int u_d=0;
   		int r_l=n-1;
   		bool flag = true;
   		int cas = 2;
   		int count = 0;
   		while(flag){	

   			//down to up
   			if(cas == 1 && u_d<=d_u){
   			for(int i=d_u;i>=u_d;i--){
   				cout << a[i][l_r] << " " ;
   			}
   				l_r +=1;
   				cas = 2;
 
   			}
   			else if(cas == 2 && l_r<=r_l){ //left to right
   			for(int i=l_r;i<=r_l;i++){
   				cout << a[u_d][i] << " ";
   			
   			}
   				u_d +=1;
   				cas = 3;
   			}
   			else if(cas == 3 && u_d<=d_u) {// up to down
   			for(int i=u_d;i<=d_u;i++){
   				cout << a[i][r_l] << " ";
   			
   			}
   				r_l = r_l-1;
   				cas = 4;
   			}
   			else if(cas == 4 && l_r<=r_l) {//right to left
   			for(int i=r_l;i>=l_r;i--){
   				cout << a[d_u][i] << " ";
   			
   			}
   				d_u = d_u-1;
   				cas = 1;
   			}
   			else flag = false;


   		}

    }


    return 0;
}

