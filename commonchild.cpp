/*Given two strings aa and bb of equal length, what's the longest string (SS) that can be constructed such that it is a child of both? 
A string xx is said to be a child of a string yy if xx can be formed by deleting 0 or more characters from yy. 
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	char a[5000];
	char b[5000];

	cin >> a;
	cin >> b;
	
	int m,n;
	int x,y;
	m = strlen(a);
	n = strlen(b);
	int max = 0;
	int localmax = 0;

	int table[m+1][n+1];
	
	for(int i = 0;i<=m;i++)
		for(int j = 0;j<=n;j++)
			table[i][j] = 0;
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			
			if(a[i-1] == b[j-1] ){
				
				for(int k=0;k<i;k++)
					for (int l=0;l<j;l++){
					if(table[k][l] > localmax)
						localmax = table[k][l];
				}	

				table[i][j] = localmax+1;
				localmax = 0;
				if(table[i][j] > max){
					max = table[i][j];
									
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
/*	cout << "longest common substring: ";
	for(int i=x-max;i<x;i++){
		cout << a[i];	
	}*/
	cout <<  max ;

    return 0;
}

