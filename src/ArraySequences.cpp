/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int fend_of_series(int *arr, int start, int len, int type);
int type_of_series(int *arr, int start, int len);

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	int walker = 0;
	int writer = 0;
	int *result_array = (int*)calloc(6, sizeof(int));

	if ((len == 0) || (arr == NULL)){
		return NULL;
	}
	result_array[writer] = 0;
	result_array[++writer] = walker = fend_of_series(arr, walker, len, type_of_series(arr, walker, len));
	if (type_of_series(arr, walker, len)){
		//
	}
	else
		++walker;
	result_array[++writer] = walker;
	result_array[++writer] = walker = fend_of_series(arr, walker, len, type_of_series(arr, walker, len));
	if (type_of_series(arr, walker, len)){
		//
	}
	else{
		 ++walker;
	}
	result_array[++writer] = walker;
	result_array[++writer] = walker = fend_of_series(arr, walker, len, type_of_series(arr, walker, len));
	return result_array;
}

int fend_of_series(int *arr, int start, int len, int type){
	int end = start + 1;
	if (type == 1){
		//Arithmettic prog
		int diff = arr[start] - arr[start + 1];
		int p_diff = diff;
		printf("diff = %d, p_diff = %d\n", diff, p_diff);
		while (diff == p_diff){
			printf("end = %d, +1 = %d", arr[end], arr[end + 1]);
			p_diff = arr[end] - arr[end+1];
			printf("%d and %d are in %s, %s = %d", arr[end], arr[end + 1], "ap", "diff", p_diff);
			end++;
			if (end == len){
				break;
			}
			
		}
		printf("\nReturnint %d, start = %d", end - 1, start);
		return end - 1;
	}
	if (type == 2){
		//GP
		float r = arr[start + 1] / arr[start];

		float p_r = r;

		while (p_r == r){
			p_r = arr[end + 1] / arr[end++];
			printf("%d and %d are in %s, %s = %d", arr[end], arr[end + 1], "gp", "r", p_r);
			if (end == len){
				break;
			}
		}
		printf("\n GP Returnint %d, start = %d", end - 1, start);
		return end - 1;
	}
}

int type_of_series(int *arr, int start, int len){
	int walker = start;
	int diff = arr[start + 1] - arr[start];
	float r = arr[start + 1] / arr[start];

	if ((arr[start + 2] - arr[start + 1]) == diff){
		printf("\nSeries from %d is in ap", arr[start]);
		return 1;
	}
	else if((arr[start+2] / arr[start+1]) == r){
		printf("\nSeries from %d is in GP", arr[start]);
		return 2;
	}
	else{
		return 0;
	}

}


