// How many times is a sorted array rotated.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int FindRotationCount(int A[], int n)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		if (A[low] <= A[high]) return low;
		int mid = (low + high) / 2;
		int next = (mid + 1) % n, prev = (mid + n - 1) % n;
		if (A[mid] <= A[next] && A[mid] <= A[prev])
			return mid;
		else if (A[mid] <= A[high]) high = mid - 1;
		else if (A[mid] >= A[low]) low = mid + 1;
	}
	return -1;
}


int main()
{
	int A[] = { 3,4,5,6,7,8,9,10,11,1,2 };
	int count = FindRotationCount(A, 11);
	printf("The array is rotated %d times", count);

    return 0;
}

