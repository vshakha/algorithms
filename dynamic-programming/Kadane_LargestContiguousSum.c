/*
    Problem Name : Kadane's Algorithm - Largest Sum in a Contiguous Sub-Array
    Description  : Find the largest sum of contiguous subarray in a 1-D array of numbers
    Complexity	 : O(n)
    Source		 : https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/

#include "stdio.h"

void largestContiguousSum(int arr[], int arrSize) {
	int maxSoFar = -100, maxEndingHere = 0;
	
	for(int i = 0; i < arrSize; i++) {
	
		maxEndingHere = maxEndingHere + arr[i];
		
		if(maxSoFar < maxEndingHere) {
			maxSoFar = maxEndingHere;
		}
		
		if(maxEndingHere < 0)
			maxEndingHere = 0;
	}
	
	printf("\n\n Maximum Contiguous Sum is : %d \n\n", maxSoFar);
}

int main (void) {
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int arrSize = sizeof(arr) /  sizeof(int);
	
	largestContiguousSum(arr, arrSize);
	
	return 0;
}
