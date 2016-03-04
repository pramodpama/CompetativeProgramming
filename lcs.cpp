// Program to find the longest common substring of strings A and B
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	char a[100];
	char b[100];

	cin >> a;
	cin >> b;
	
	int m,n;
	int x,y;
	m = strlen(a);
	n = strlen(b);
	int max = 0;

	int table[m+1][n+1];
	
	for(int i = 0;i<=m;i++)
		for(int j = 0;j<=n;j++)
			table[i][j] = 0;
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			
			if(a[i-1] == b[j-1] ){
				table[i][j] = table[i-1][j-1]+1;
				
				if(table[i][j] > max){
					max = table[i][j];
					x=i;
					y=j;				
				}							
			}
			else table[i][j] = 0;			
		}
	cout << "suffix table \n";
	for(int i = 0;i<=m;i++){
		for(int j = 0;j<=n;j++){
			cout << table[i][j] << " ";
		}
	cout << endl;	
	}
	cout << "longest common substring: ";
	for(int i=x-max;i<x;i++){
		cout << a[i];	
	}
	cout << "\nlength of longest common substring: " << max << endl;

    return 0;
}

