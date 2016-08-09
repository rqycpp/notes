//选择排序
//平均时间复杂度：O(n^2)
//交换次数比冒泡排序较少，由于交换所需CPU时间比比较所需的CPU时间多， {\displaystyle n} n值较小时，选择排序比冒泡排序快。
/*它的工作原理如下。首先在未排序序列中找到最小（大）元素，
存放到排序序列的起始位置，然后，再从剩余未排序元素中
继续寻找最小（大）元素，然后放到已排序序列的末尾。
以此类推，直到所有元素均排序完毕。*/
https://zh.wikipedia.org/wiki/%E9%80%89%E6%8B%A9%E6%8E%92%E5%BA%8F
template<typename T>
void selection_sort(T arr[], int len)
{
	int i, j, min;
	for (i = 0; i < len - 1; ++i) {
		min = i;//记录下标
		for (j = i + 1; j < len; ++j) {
			if (arr[min] > arr[j])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}
