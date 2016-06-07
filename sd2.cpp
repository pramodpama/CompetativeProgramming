
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

//#define MIN -1000000000

//int result[100] = {0}; // initialization with zero
using namespace std;

int N;
//int A[10000];

int main() {
   

	//     int arr[N+1];  // didn't work for large N
    //long int *arr=new long int[N+1]();
    //printf("%lld\n",result[N] ); // for printing long long type (instead of cout)

	int T;
	cin >> T;
	long long *A;
	long long *E;
	long long *S;
	for (int i = 0; i < T; ++i)
	{
		
		cin >> N;
		A = new long long[N];
		E = new long long[N];
		S = new long long[N];
		//int A[N];
		for (int ii = 0; ii < N; ++ii)
		{
			cin >> A[ii];
		}
		

		long long msum = A[0];
		long long sum = 0;
		long long negative = 0;
		
		for (int j = 0; j < N; ++j)
		{
			sum = sum + A[j];

			if(sum>msum){
				msum = sum;
			}	

			if(sum < 0){
				sum = 0;
			}

			E[j] = msum;

			if(A[j]<0) negative++;	
		}
		if(negative == N){
			//cout << msum << endl;
			printf("%lld\n",msum );
			continue;			
		}

		sum = 0;
		msum = A[N-1];
		for (int k = N-1; k>=0; k--)
		{
			sum = sum + A[k];

			if(sum > msum)
				msum = sum;

			if(sum < 0)
				sum = 0;

			S[k]= msum;
		}

		long long msum2=msum;
		sum = 0;
		for (int l = 1; l < N-1; ++l)
		{
			sum = E[l-1]+S[l+1];

			if(sum>msum2)
				msum2 = sum;
		}

		printf("%lld\n",msum2 );
		

	}


    return 0;
}


