//计数排序
//时间复杂度：O(n + k)
//空间复杂度：O(n + k)
//步骤：
// 找出待排序的数组中最大和最小的元素
// 统计数组中每个值为i的元素出现的次数，存入数组 C 的第 i 项
// 对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
// 反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
//https://zh.wikipedia.org/wiki/%E8%AE%A1%E6%95%B0%E6%8E%92%E5%BA%8F
void counting_sort(int ini_arr[], int sorted_arr[], int n)
{
	int *count_arr = new int[100];
	int i, j, k;

	for (k = 0; k < 100; ++k)//清零
		count_arr[k] = 0;

	for (i = 0; i < n; ++i)
		count_arr[ini_arr[i]] += 1;//统计次数

	for (k = 1; k < 100; ++k)
		count_arr[k] += count_arr[k - 1];//求小于等于k的元素个数

	for (j = n- 1; j >= 0; --j)
		sorted_arr[--count_arr[ini_arr[j]]] = ini_arr[j];

	delete count_arr;
}
