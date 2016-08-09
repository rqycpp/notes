//鸡尾酒排序
//鸡尾酒排序最糟或是平均所花费的次数都是 O(n^2)，但如果序列在一开始已经大部分排序过的话，会接近O(n)
//link：https://zh.wikipedia.org/wiki/%E9%B8%A1%E5%B0%BE%E9%85%92%E6%8E%92%E5%BA%8F
//该排序也叫涟漪排序，从左到右从右到左，来来回回的排
template<typename T>//整型或浮点型皆可使用，若要使用class，必须定义<运算符
void cocktail_sort(T arr[], int len)
{
	int j, left = 0, right = len - 1;
	while (left < right) {//由左至右
		for (j = left; j < right; ++j) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
		--right;//缩小区间

		for (j = right; j > left; --j) {//由左至右
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		}
		++left;//缩小区间
	}
}
