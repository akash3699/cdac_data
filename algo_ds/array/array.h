/*
 * array.h
 *
 *  Created on: 26-Sep-2019
 *      Author: sunbeam
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#define SIZE 5

extern int comparisons;

void accept_array_elements(int arr[]);
void display_array_elements(int arr[]);
int array_sum(int arr[]);
int rec_array_sum(int arr[], int index);
bool linear_search(int arr[], int key);


#endif /* ARRAY_H_ */
