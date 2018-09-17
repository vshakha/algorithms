/*
    Problem Name : Longest Increasing Subsequence
    Description  : Find the length of the longest subsequence of a given sequence 
				   such that all elements of the subsequence are sorted in increasing order.
    Complexity	 : O(n2)
    Source		 : https://www.geeksforgeeks.org/reverse-an-array-in-groups-of-given-size/
*/

#include <stdio.h>
#include <stdlib.h>

// Optimal Subproblems - Bottom Up - Tabulation
int longestIncreasingSubSequenceIterative(int arr[], int arrSize) {
	int *subArray;
	int i, j, maxSeq = -1;
	
	subArray = (int *) malloc(sizeof(int)*arrSize);
	for(i = 0; i < arrSize; i++)
		subArray[i] = 1;
		
	for(i = 1; i < arrSize; i++) {
		for( j = 0; j < i; j++) {
			if((arr[j] < arr[i]) && (subArray[i] < subArray[j]+1))
				subArray[i] = subArray[j] + 1;
		}
	}
	
	for(i = 0; i < arrSize; i++) {
		if(maxSeq < subArray[i])
			maxSeq = subArray[i]; 
	}
	
	return maxSeq;
}

// Optimal Substructure - Top Down Approach - Memoization
int longestIncreasingSubSequenceRecursive(int arr[], int arrSize, int *maxSeq) {
	int maxEndingHere, maxSoFar = 1;
	
	if(arrSize == 1)
		return 1;
		
	for(int i = 1; i < arrSize; i++) {
		maxEndingHere = longestIncreasingSubSequenceRecursive(arr, i, maxSeq);
		
		if((arr[i-1] < arr[arrSize-1]) && (maxEndingHere+1 > maxSoFar))
			maxSoFar = maxEndingHere + 1;
	}
	
	if(*maxSeq < maxSoFar)
		*maxSeq = maxSoFar;
		
	return maxSoFar;
}

void longestIncreasingSubSequence(int arr[], int arrSize) {
	int maxSeq = 1;
	
	longestIncreasingSubSequenceRecursive(arr, arrSize, &maxSeq);

	printf("\n\n Length of the longest increasing subsequence is %d ", maxSeq);
}

int main(void) {
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int arrSize = sizeof(arr)/sizeof(int);

	longestIncreasingSubSequence(arr, arrSize);
	
	printf("\n");
	return 0;
}
