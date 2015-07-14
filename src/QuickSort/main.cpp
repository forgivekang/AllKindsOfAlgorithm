/************************快速排序*********************************
auther:zengrui.kang
概念：
	通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另
外一部分所有数据都要小，然后按此方法对这两部分数据分别进行快速排序，整个排序过
程可以递归进行，以此达到整个数据变成有序序列。

原理：
1、先从数列中取出一个数作为基准数。
2、分区过程中，将比这个数大的数全放到他的右边，小于或等于它的数全放到它的左边。
3、再对左右区间重复第二步，直到各区间只有一个数。
*******************************************************************/

#include <iostream>
using namespace std;

//代码一
//template<typename T>
//void quick_sort(T value[],int low,int high)
//{
//	if (low >= high)
//		return;
//
//	int i = low,j = high;
//	T temp = value[low];
//
//	while(i<j)
//	{
//		while(i<j&&value[j]>temp)
//			j--;
//		value[i] = value[j];
//
//		while(i<j&&value[i]<=temp)
//			i++;
//		value[j]=value[i];
//	}
//
//	value[i] = temp;	
//
//	quick_sort(value,low,i-1);
//	quick_sort(value,i+1,high);
//}

//代码二
template<typename T>
void quick_sort(T a[],int low,int high)
{
	if (low>high)
		return;

	int i=low,j=high;
	T temp = a[low];

	while(i<j)
	{
		while(i<j&&a[j]>temp)
			j--;
		while(i<j && a[i]<=temp)\
			i++;
		if (i<j)
		{
			T value = a[i];
			a[i] = a[j];
			a[j] = value;
		}
	}

	a[low] = a[i];
	a[i] = temp;
	quick_sort(a,low,i-1);
	quick_sort(a,i+1,high);
}

int main()
{
	int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	quick_sort(arr, 0,len-1);
	for (int i = 0; i < len; i++) 
		cout << arr[i] << ' ';
	cout << endl;
	double arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
	len = (int) sizeof(arrf) / sizeof(*arrf);
	quick_sort(arrf, 0,len-1);
	for (int i = 0; i < len; i++)
		cout << arrf[i] << ' ';	
	cout<<endl;

	system("pause");
	return 0;
}