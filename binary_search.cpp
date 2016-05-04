#include <iostream>

int binary_search1(int array[], int n, int key)
{
	int mid, l = 0, r = n; //此时数组区间表示为[0,n) 等价于 [0,n - 1]。
	while (l < r){				/*合法的区间是二分查找的前提，极限情况下左右边界最后汇聚于一点，
									所以在左闭右开的情况下，合法区间的左边界<右边界。不存在[a,a)这种区间*/
		mid = l + (r - l) / 2;
		if (array[mid] > key) {	//查找的值小于arrary[mid]，即在中点左侧。[l,r) = [l,mid - 1] + [mid,r)。
			r = mid;					//区间更新为[l,mid) 等价于 [l,mid - 1]。
		}
		else if (array[mid] < key) {	//查找的值大于arrary[mid]，即在中点右侧。[l,r) = [l,mid] + [mid + 1,r)。
			l = mid + 1;						//区间更新为[mid + 1,r)
		}
		else {
			return mid;		//array[mid] == key，即找到key值，返回对应的数组下标
		}
	}
	return -1;					//没有找到key值，返回-1
}

//[a,b]
int binary_search2(int array[], int n, int key)
{
	int mid, l = 0, r = n - 1;//此时数组区间表示为[0,n - 1] 等价于 [0,n)。
	while (l <= r) {				/*合法的区间是二分查找的前提，极限情况下左右边界最后汇聚于一点，
										所以在左闭右闭的情况下，合法区间的左边界<=右边界。存在[a,a]这种区间*/
		mid = l + (r - l) / 2;
		if (array[mid] > key) {	//查找的值小于arrary[mid]，即在中点左侧。[l,r] = [l,mid - 1] + [mid,r]。
			r = mid - 1;				//区间更新为[l,mid - 1] 等价于 [l,mid)。
		}
		else if (array[mid] < key) {	//查找的值大于arrary[mid]，即在中点右侧。[l,r] = [l,mid] + [mid + 1,r]。
			l = mid + 1;						//区间更新为[mid + 1,r]
		}
		else {
			return mid;		//array[mid] == key，即找到key值，返回对应的数组下标
		}	
	}
	return -1;					//没有找到key值，返回-1
}
int main()
{
	return 0;
}