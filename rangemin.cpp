//Segetree example to query miv value in a given range

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>  // 
#include <string>
#include <utility> // pari<int,int> a; 
using namespace std;


#define MAX 10000

//macros for minimum of two numbers
 #define min(a,b) ( (a) < (b) ? (a) : (b) ) 

void buildsegmnttree(int* segtr,int input[],int left, int right, int pos);

int rangeminqury(int* segtr,int qleft,int qright,int left, int right, int pos);

//int min(int a,int b);



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

	//     int arr[N+1];  // didn't work for large N
    //long int *arr=new long int[N+1]();
	int N;
	cin >> N;
    int input[N];


    for (int i = 0; i < N; ++i)
    {
    	cin >> input[i];
    }

        //Height of segment tree
    int x = (int)(ceil(log2(N))); 
 
    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;

    // Allocate memory
    int *st = new int[max_size];

    for (int i = 0; i < max_size; ++i)
    {
    	st[i] = MAX;
    }


    int qleft,qright;
    cin >> qleft >> qright;

    //segtree before 
    for (int i = 0; i < max_size; ++i)
    {
        cout << st[i] << " ";
    }
    cout << endl;

    buildsegmnttree(st,input,0,N-1,0);

    //segtree after buiult
    for (int i = 0; i < max_size; ++i)
    {
        cout << st[i] << " ";
    }
    cout << endl;

    int mi = rangeminqury(st,qleft,qright,0,N-1,0); 

    cout << "minval: " << mi << endl;

    return 0;
}

//This fucntion bulids the segment tree for finding min value in a given range

// we start from the root (thats why position is zero intitilly)
// If there are more than one elements, then recur for left and right subtrees and store the 
//min values (of right and left subtree) in this node

void buildsegmnttree(int segtr[],int input[],int left, int right, int pos){

	if(left == right){
		segtr[pos] = input[left];
		return;
	}	
	int mid = (left + right)/2;

	buildsegmnttree(segtr,input,left,mid,2*pos+1);
	buildsegmnttree(segtr,input,mid+1,right,2*pos+2);

	segtr[pos] = min(segtr[2*pos+1],segtr[2*pos+2]);
	
    return ;
}



// function to return min value in a given range

//partial overlap
//total overlap
// no overlap

int rangeminqury(int segtr[],int qleft,int qright,int left, int right, int pos){

	// total overlap
	if (qleft <= left && qright >= right)
		return segtr[pos];

	if(qleft > right || qright < left)
		return MAX; 

	int mid = (left+right)/2;

	return min( rangeminqury(segtr,qleft,qright,left,mid,2*pos+1), rangeminqury(segtr,qleft,qright,mid+1,right,2*pos+2) ) ;

}
/*
int min(int a,int b){
    if(a<b) return a;
    else return b;
}*/