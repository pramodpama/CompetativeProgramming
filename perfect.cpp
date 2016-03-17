//Codechef = Mr Perfectionist
/*Vicky (Mr. Perfect) goes for shopping in a shopping mall with N shops to buy an item X. The shops in the shopping malls are in a single row and numbered from 0 to N-1. Each shop has total stock of Ai of the item X. He already knows the available stocks of X in each shop. He can buy any number of X from a shop. Due to his habit for perfection in every task, he will shop according to the following conditions:

1. Vicky only buys either all the stock available in the shop or none of it.
2. Vicky will select the shops in a manner such that all the shops are consecutive.
3. Vicky will only shop if total number of X to be bought is multiple of N.
4. Number of shops to be visited by him should be minimum.

link : https://www.codechef.com/COBL2016/problems/PERFECT/

One such solution is always possible. Print the starting shop(l) and ending shop(r). If multiple solutions are possible, then consider the solution with leftmost starting shop.
*/

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
int mod[10000];

#define max 10001

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	int T;
	cin >> T;
	int N;
	int sum = 0;
	int l,r;
	int k;
	int gmin = max;
	int x;
	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[j];
		}

		for (int i = 0; i < N; ++i)
			mod[i] = -1;

		for (int i = 0; i < N; ++i)
		{
			sum = sum + arr[i];
			k = sum % N;

			if ( mod[k] == -1)
			{
				if(k == 0){
					x = i+1;
					if(x < gmin){
						l = 0;
						r = i;
					}
				}
				mod[k] = i;

			}

			else if(mod[k]!= -1){
				x = i - mod[k] ; 
				

				if(x < gmin ){
					gmin = x;

					l = mod[k]+1;
					r = i;
				}

				mod[k] = i;
			}

		}
		gmin = max;

		for (int i = 0; i < N; ++i)
			mod[i] = -1;

		cout << l << " " << r << endl;

		l = 0;
		r = 0;
		sum = 0;

	}

    return 0;
}

	