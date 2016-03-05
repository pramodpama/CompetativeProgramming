// Tie It Up

/*You are given a bag full of rope segments and asked to build the longest loop of rope while alternating colors.
 The bag contains S segments and each segment will either be blue (B) or red (R). You are required to alternate 
 between colors. Each segment length is provided in centimeters and each knot in the loop consumes one centimeter 
 of length from the loop. In other words, a knot consumes one-half of a centimeter from each of the two 
 segment it connects.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	int s;
	string ab,l;
	char c;
	int R[1000];
	int B[1000];
	cin >> s;
	int m=0;
	int n=0;
	getchar();

	for (int i = 0; i < s; ++i)
	{
		
		cin >> ab;


		l = ab.substr(0, ab.size()-1);	

		int val = atoi(l.c_str());

		//cout << val << " " ;
		c = ab[(ab.size()-1)];

		if (c == 'R'){
			R[m++] = val;
		}
		else
			B[n++] = val;
		
	}

	 std::sort(R, R+m, std::greater<int>());
	 std::sort(B, B+n, std::greater<int>());

	 int sum = 0;
	 if(m==n){
	 	for (int i = 0; i < m; ++i)
	 	{
	 		sum = sum + R[i]+B[i];
	 	}

	 	sum = sum - m -n;
	 }
	 else if (m>n)
	 {
	 	for (int i = 0; i < n; ++i)
	 	{
	 		sum = sum + R[i]+B[i];
	 	}

	 	sum = sum - n -n;	
	 }
	 else{
	 	for (int i = 0; i < m; ++i)
	 	{
	 		sum = sum + R[i]+B[i];
	 	}

	 	sum = sum - m -m;
	 }


cout << sum;

    return 0;
}
