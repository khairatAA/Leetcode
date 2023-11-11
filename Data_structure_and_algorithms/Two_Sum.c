#include <stdio.h>
#include <stdlib.h>

/**
* Given an array of integers nums and an integer target, return indices
* of the two numbers such that they add up to target.
* You may assume that each input would have exactly one solution,
* and you may not use the same element twice.
* You can return the answer in any order.
* Example 1:
* Input: nums = [2,7,11,15], target = 9
* Output: [0,1]
* Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i = 0;
	int j = 0;
	int *result = NULL;

	result = malloc(sizeof(int) * 2);
	if (result == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < numsSize; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				result[0] = i;
				result[1] = j;
				*returnSize = 2;
				return (result);
			}	
		}
	}
	free(result);
	return (NULL);
}
