/*Mr. Swegwan likes to play around with arrays. Recently while sitting in his room he invented a new game to play with arrays. In this game, firstly you are given an array A of size N by Mr. Swegwan and each element of the array lies in the range [L,R](inclusive). You have to choose exactly one integer from the array and replace it with another integer that also lies in the range [L,R] inclusive. You necessarily have to change a number and you can't change a number with itself.


After the replacement you are required to sort the array. Now Mr. Swegwan wants to know what would be the minimum integer that could occur at each position after the replacement and sorting.
 
Input

First line of input contains T, the number of test cases.

In the description of each test case, the first line contains three space seperated integers N,L,R.

The second line for each test case contains N space separated integers, the array elements.
 
Output

For each test case output in a new line, N integers each showing the minimum element at the index on which it is being printed, if the answer exists and -1 otherwise.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
using namespace std;

int arr[10000];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	int T;
	cin >> T;
	
	int N,L,R;
	int flag = 1;

	for (int i = 0; i < T; ++i)
	{
		cin >> N >> L >> R;

		for (int j = 0; j < N; ++j)
		{
			cin >> arr[j] ; 
		}

		sort(arr,arr+N);	


		int a;

		if (L < arr[0])
		{
			arr[N-1] = L;
		} 
		else if (L == arr[0])
		{	
			if(arr[N-1] > arr[0]){
				arr[N-1] = arr[0];
			}
			else if (arr[0] == arr[N-1])
			{
				if (R > arr[N-1])
				{
					arr[N-1] = arr[N-1] + 1;
				}
				else{
					cout << "-1" << endl;
					continue;
				}
			}
		}

		sort(arr,arr+N);

//		cout << a << " ";
		for (int l = 0; l < N; ++l)
		{
			cout << arr[l] << " ";
		}
		cout << endl ;

	}

    return 0;
}

	