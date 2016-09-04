#include <iostream>
//#include "BigInt.h"
#include <random>
#include <functional>
#include <climits>
#include <string>
//#include "StrVec.h"

using namespace std;

template<typename T>
void insertion_sort(T arr[], int len)
{
	int i, j;
	T temp;
	for (i = 1; i < len; ++i) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; --j) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

template<typename T>
void shell_sort(T arr[], int len)
{
	int i, j, gap;
	T temp;
	for (gap = len >> 1; gap > 0; gap >>= 1) {
		for (i = gap; i < len; ++i) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = temp;
		}
	}
}

template<typename T>
void selection_sort(T arr[], int len)
{
	int i, j, min;
	for (i = 0; i < len - 1; ++i) {
		min = i;
		for (j = i + 1; j < len; ++j) {
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

void max_heapify(int arr[], int start, int end) {//以start为父节点，在[start, end]范围进行筛选
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {
		if (son + 1 < end && arr[son] < arr[son + 1]) {//找到最大的孩子
			++son;
		}
		if (arr[dad] > arr[son])//如果父节点大于最大的孩子直接返回
			return;
		else {//否则交换父子节点，再对子节点和孙子节点进行筛选(自上而下)
			swap(arr[dad], arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) {
	//初始化i为最后一个节点的父节点
	for (int i = len / 2 - 1; i >= 0; --i) {
		max_heapify(arr, i, len - 1);//建堆
	}
	for (int i = len - 1; i > 0; --i) {
		swap(arr[0], arr[i]);//选一个关键字为最大的记录并与序列中最后一个记实录交换
		max_heapify(arr, 0, i - 1);//然后对序列中前n-1个记录进行筛选，重新调整为最大堆
	}
}

int AdjustArray(int s[], int l, int r) {
	int i = l, j = r;
	int x = s[l];
	while (i < j) {
		while (i < j && s[j] >= x)
			--j;
		if (i < j) {
			s[i] = s[j];
			++i;
		}

		while (i < j && s[i] < x)
			++i;
		if (i < j) {
			s[j] = s[i];
			--j;
		}
	}
	s[i] = x;
	return i;
}

void quick_sort1(int s[], int l, int r) {
	if (l < r) {
		int i = AdjustArray(s, l, r);
		quick_sort1(s, l, i - 1);
		quick_sort1(s, i + 1, r);
	}
}

void quick_sort(int arr[], int left, int right) {
	if (left< right) {

		int i = left, j = right;
		int x = arr[i];
		while (i < j) {
			while (i < j  && arr[j] >= x)
				--j;
			if (i < j)
				arr[i++] = arr[j];

			while (i < j && arr[i] < x)
				++i;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = x;
		quick_sort(arr, left, i - 1);
		quick_sort(arr, i + 1, right);
	}
}

template<typename T>
void merge_sort_recursive(T arr[], T temp[], int start, int end)
{
	if (start >= end)
		return;
	int len = end - start;
	int mid = start + len / 2;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;

	merge_sort_recursive(arr, temp, start1, end1);
	merge_sort_recursive(arr, temp, start2, end2);

	int k = start;
	while (start1 <= end1 && start2 <= end2) {
		if (arr[start1] < arr[start2]) {
			temp[k++] = arr[start1++];
		}
		else {
			temp[k++] = arr[start2++];
		}
	}
	while (start1 <= end1) {
		temp[k++] = arr[start1++];
	}
	while (start2 <= end2) {
		temp[k++] = arr[start2++];
	}

	for (int i = start; i <= end; ++i) {
		arr[i] = temp[i];
	}
}
template<typename T>
void merge_sort(T arr[], int len) {
	T *temp = new T[len];
	merge_sort_recursive(arr, temp,0, len - 1);
	delete []temp;
}

//[0, max]
void counting_sort(int arr[], int len, int max)
{
	if (len <= 1 || max <= 0)
		return;
	int *cnt = new int[max + 1];
	for (int i = 0; i <= max; ++i)
		cnt[i] = 0;
	for (int i = 0; i < len; ++i)
		cnt[arr[i]] += 1;

	for (int i = 1; i <= max; ++i) {
		cnt[i] += cnt[i - 1];
	}

	int *res = new int[len];
	for (int i = 0; i < len; ++i) {
		res[i] = arr[i];
	}

	for (int i = len - 1; i >= 0; --i)
	{
		arr[--cnt[res[i]]] = res[i];
	}

	delete[] cnt;
	delete[] res;
}

int maxbit(int arr[], int len) {
	int maxData = -1;
	for (int i = 0; i < len; ++i) {
		if (arr[i] > maxData) {
			maxData = arr[i];
		}
	}

	int res = 0;
	while (maxData) {
		++res;
		maxData /= 10;
	}
	return res;
}

void radix_sort(int arr[], int len) {
	int r = maxbit(arr, len);
	int i, k;
	int *temp = new int[len];
	int cnt[10];
	int radix = 1;
	while (r--) {
		for (i = 0; i < 10; ++i)
			cnt[i] = 0;
		for (i = 0; i < len; ++i) {
			k = (arr[i] / radix) % 10;
			cnt[k] += 1;
		}
		for (i = 1; i < 10; ++i) {
			cnt[i] += cnt[i - 1];
		}
		for (i = len - 1; i >= 0; --i) {
			k = (arr[i] / radix) % 10;
			temp[--cnt[k]] = arr[i];
		}
		for (i = 0; i < len; ++i)
			arr[i] = temp[i];
		radix *= 10;
	}
}

struct ListNode {

	explicit ListNode(int i) :data(i) ,next(NULL){}
	int data;
	ListNode *next;
};

ListNode* insert(ListNode *head, int val) {
	ListNode dummyNode(0);
	ListNode *newNode = new ListNode(val);
	ListNode *pre, *curr;
	dummyNode.next = head;
	pre = &dummyNode;
	curr = head;
	while (curr && curr->data <= val) {
		pre = curr;
		curr = curr->next;
	}
	newNode->next = curr;
	pre->next = newNode;
	return dummyNode.next;
}

ListNode *Merge(ListNode *head1, ListNode *head2)
{
	ListNode dummyNode(0);
	ListNode *dummy = &dummyNode;
	while (head1 && head2) {
		if (head1->data <= head2->data) {
			dummy->next = head1;
			head1 = head1->next;
		}
		else {
			dummy->next = head2;
			head2 = head2->next;
		}
		dummy = dummy->next;
	}
	if (head1)
		dummy->next = head1;
	if (head2)
		dummy->next = head2;

	return dummyNode.next;

}
void BucketSort(int arr[], int n) {
	const int BUCKET_NUM = 10;
	vector<ListNode *> buckets(BUCKET_NUM, NULL);
	for (int i = 0; i < n; ++i) {
		int index = arr[i] / BUCKET_NUM;
		ListNode *head = buckets.at(index);
		buckets.at(index) = insert(head, arr[i]);
	}

	ListNode *head = buckets.at(0);
	for (int i = 1; i < BUCKET_NUM; ++i) {
		head = Merge(head, buckets.at(i));
	}
	for (int i = 0; i < n; ++i) {
		arr[i] = head->data;
		head = head->next;
	}
}

int main()
{
		return 0;
}
