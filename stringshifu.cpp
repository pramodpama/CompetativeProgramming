// Probelm statement - https://www.codechef.com/DMNT2016/problems/SHISTR

//#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>  // 
#include <string>
#include <string.h>
#include <utility> // pari<int,int> a; 
using namespace std;

char inp[5001];
int stor[5001] = {0};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   


	int T;
	cin >> T;
	int N,Q;
	int L,R,K;

	for (int i = 0; i < T; ++i)
	{
		cin >> N >> Q;
		cin >>inp ;

		for (int j = 0; j < Q; ++j)
		{
			cin >> L >> R >> K;

			stor[L-1] = stor[L-1] + K;
			stor[R] = stor[R] - K;

			//K = K%26;
		}
		
		stor[0] = stor[0]%26;
		for (int l = 1; l < N; ++l)
		{
				stor[l] = stor[l]+stor[l-1];
				stor[l] = stor[l]%26;
		}	


		for (int k = 0; k < N; ++k)
		{
			int a = inp[k];

			if(stor[k] >= 0){
				int x = stor[k] + a;

				if(x>122)
					inp[k] = 97 + (x - 122)-1;
				else
					inp[k] = x;
			}
			else{
				int y = stor[k] + a ;

				if(y < 97)
					inp[k] = 122 - (97 - y - 1);
				else
					inp[k] = y;
			}

		}


		cout << inp<<endl;

		memset(inp, '\0', sizeof(inp));
		for (int j = 0; j < 5001; ++j)
		{
			stor[j] = 0;
		}

	}


    return 0;
}

