/*
    Problem Name : Longest Common Subsequence
    Description  : Given two sequences, find the length of longest subsequence present in both of them. 
    			   A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
    Complexity	 : O(n2)
    Source		 : https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximum(int a, int b) {
	return (a > b ? a : b);
}

void longestCommonSubSequence(char str1[], char str2[], int size1, int size2) {
	int **table = (int **) malloc(sizeof(int) * (size1+1));
	for(int i = 0; i <= size1; i++)
		table[i] = (int *) malloc(sizeof(int)*(size2+1));

	for(int i  = 0; i <= size1; i++)
		table[i][0] = 0;
		
	for(int i = 1; i <= size2; i++)
		table[0][i] = 0;
		
	for(int i = 1; i <= size1; i++) {
		for(int j = 1; j <= size2; j++) {
			if(str1[i-1] == str2[j-1])
				table[i][j] = table[i-1][j-1]+1;
			else
				table[i][j] = maximum(table[i-1][j], table[i][j-1]);
		}
	}
	
	char *subSeq = (char *) malloc(sizeof(char) * (table[size1][size2]+1));
	int i = size1, j = size2, k = table[size1][size2];
	subSeq[k--] = '\0';
	
	while( i > 0 && j > 0) {
		if(str1[i-1] == str2[j-1]) {
			subSeq[k--] = str1[i-1];
			i--;
			j--;
		} else {
			if(table[i][j-1] == table[i][j])
				j--;
			else
				i--;
		}
	}
	
	printf("\n\n The length of Longest Common SubSequence is %d", table[size1][size2]);
	printf("\n The subsequence is : \t %s", subSeq);
}

int main(void) {
	char str1[] = "AGGTAB";
	char str2[] = "GXTXAYB";
	
	int str1Size = strlen(str1);
	int str2Size = strlen(str2);
	
	longestCommonSubSequence(str1, str2, str1Size, str2Size);

	printf("\n");
	getchar();
	return 0;
}
