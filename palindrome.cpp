
#include <bits/stdc++.h>
// #include <utility> // pari<int,int> a; 
// #include <string.h> // for memset
#include <stdio.h>
#include <string.h>

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

int getcount(char* str,int l,int h);
int getcountlcs(char* str,int n);
//int result[100] = {0}; // initialization with zero
using namespace std;

int main() {
   

	//     int arr[N+1];  // didn't work for large N
    //long int *arr=new long int[N+1]();
    int t;
    cin >> t;
    char str[50];
    while(t--){

    	cin >> str;
    	//cout << getcount(str,0,strlen(str)-1) << endl;
    	cout << strlen(str)-getcountlcs(str,strlen(str))<<endl;
    	memset(str,'\0',sizeof str);

    }


    return 0;
}

int getcount(char* str,int l,int h){

	if(l>=h)
		return 0;
	else{

		return str[l] == str[h]?getcount(str,l+1,h-1):1+min(getcount(str,l,h-1),getcount(str,l+1,h));

	}


}

int getcountlcs(char* str,int n){

	char rev[50];
	int j=0;
	for(int i=n-1;i>=0;i--){
		rev[j++] = str[i];
	}
	rev[j] = '\0';
	//strcpy(rev,str);
	//strrev(rev);

	//int n = strlen(str);

	int a[n+1][n+1];
	forloop(i,n+1){
		forloop(j,n+1)
		a[i][j] = 0;
	}

	int max = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <=n; ++j)
		{
			if(str[i-1] == rev[j-1]){
				a[i][j] = 1+a[i-1][j-1];

				if(a[i][j]>max)
					max = a[i][j];
			}
			else a[i][j] = max(a[i-1][j],a[i][j-1]);
		}
	}

	return max;
}