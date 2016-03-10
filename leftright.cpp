/*Watson gives Sherlock an array AA of length NN. Then he asks him to determine if there exists an element in the array such 
that the sum of the elements on its left is equal to the sum of the elements on its right. If there are no elements to the 
left/right, then the sum is considered to be zero. 
Formally, find an ii, such that, AA1+A+A2...A...Ai-1 =A=Ai+1+A+Ai+2...A...AN.*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int sum[100000];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	int T;
	cin >> T;

	int N;

	int sum1 = 0;
	int flag = 0;

	for (int i = 0; i < T; ++i)
	{
		cin >> N ;

		for (int i = 0; i < N; ++i)
		cin >> arr[i];

		for (int i = 0; i < N; ++i)
		{
			sum1 = sum1 + arr[i];
			sum[i] = sum1;
		}

		sum1= 0;

		for (int i = 0; i < N; ++i)
		{
			if(i == 0 && N == 1){
				flag = 1;
				break;
			}	
			else if (sum[i-1] == (sum[N-1] - sum[i]))
			{
				flag = 1;
				break;
			}

		}

		if(flag == 1)
			cout << "YES\n";
		else cout << "NO\n";

		flag = 0;	

	}

    return 0;
}
