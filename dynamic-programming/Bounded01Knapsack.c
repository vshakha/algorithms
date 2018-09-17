/*
    Problem Name : Bounded 0-1 Knapsack Problem
    Description  : Given weights and values of n items, put these items in a 
    			   knapsack of capacity W to get the maximum total value in the knapsack.
    Complexity	 : O(nW) where W = Capacity of Knapsack
    Source		 : https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
*/

#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b) {
	return (a > b ? a : b);
}

void bounded01Knapsack(int values[], int weights[], int items, int knapsack) {
	int **table = (int **) malloc(sizeof(int) * (items+1));
	for(int i = 0; i <= items; i++)
		table[i] = (int *) malloc(sizeof(int) * (knapsack+1));
		
	for(int i = 0; i <= items; i++) {
		for(int j = 0; j <= knapsack; j++) {
			if((i == 0) || (j == 0))
				table[i][j] = 0;
			else {
				if(j < weights[i-1])
					table[i][j] = table[i-1][j];
				else 
					table[i][j] = maximum((values[i-1]+table[i-1][j-weights[i-1]]), table[i-1][j]); 
			}
		}
	}
	
	// Printing the knapsack
	int i = items, j = knapsack;
	printf("\n\n The maximum value of the Knapsack is : %d", table[items][knapsack]);
	printf("\n And the weights included are : ");
	while(table[i][j] != 0) {
		if(table[i][j] != table[i-1][j]) {
			printf("\t %d", weights[i-1]);
			j = j - weights[i-1];
			i--;
		}
		else {
			i--;
		}
	}
}

int main (void) {
	int values[] = { 60, 100, 120 };
	int weights[] = { 10, 20, 30 };
	int knapsack = 50;
	
	int items = sizeof(values) / sizeof(int);
	
	bounded01Knapsack(values, weights, items, knapsack);

	printf("\n\n");
	return 0;
}
