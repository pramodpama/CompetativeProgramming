// Codechef//
/*
In Byteland they have a very strange monetary system.
Each Bytelandian gold coin has an integer number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. But these numbers are all rounded down (the banks have to make a profit).
You can also sell Bytelandian coins for American dollars. The exchange rate is 1:1. But you can not buy Bytelandian coins.
You have one gold coin. What is the maximum amount of American dollars you can get for it?*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
using namespace std;

int max(int N);
map<int, int> m;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	int T;
	int N;
	int a;

//	cin >> T;
	//map<int, int> m;
	m[0] = 0;
	m[1] = 1;

	 while(scanf("%d",&N)!=EOF)
	{
//		cin >> N;
		a = max(N);

		cout << a << endl;
	}

    return 0;
}

int max(int N){

	if(N < 12) return N;
	else
	if(m.count(N) > 0)
		return m[N];

	int a =  max(N/4)+max(N/3)+max(N/2);

	if(a>N){
		m[N] = a;
		return a;
	}
	else {
		m[N] = N;
		return N;
	}

}