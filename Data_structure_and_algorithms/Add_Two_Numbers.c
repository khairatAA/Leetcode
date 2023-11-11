#include <stdio.h>
#include <stdlib.h>

/**
* You are given two non-empty linked lists representing two non-negative
* integers. The digits are stored in reverse order,
* and each of their nodes contains a single digit.
* Add the two numbers and return the sum as a linked list.
* You may assume the two numbers do not contain any leading zero,
* except the number 0 itself.
* Example:
* Input: l1 = [2,4,3], l2 = [5,6,4]
* Output: [7,0,8]
* Explanation: 342 + 465 = 807.
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *temp = NULL;
	struct ListNode *current = NULL;
	int sum = 0;
	int carry = 0;
	int x, y, current_value;

	temp = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (temp == NULL)
	{
		return (NULL);
	}

	current = temp;

	while (l1 || l2 || carry)
	{
		if (l1)
			x = l1->val;
		else
			x = 0;

		if (l2)
			y = l2->val;
		else
			y = 0;

		sum = x + y + carry;
		carry = sum / 10;
		current_value = sum % 10;

		current->next = malloc(sizeof(struct ListNode));
		if (!current->next)
		{
			return (NULL);
		}
		current->next->val = current_value;
		current->next->next = NULL;
		current = current->next;

		if (l1)
			l1 = l1->next;

		if (l2)
			l2 = l2->next;
	}
	return (temp->next);
}
