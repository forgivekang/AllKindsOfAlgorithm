/************************直接插入排序*********************************
auther:zengrui.kang
概念：每次从无序表中取出第一个元素，把它插入到有序表的合适位置，使有序表仍然有序。
原理：
1、将原序列分成有序区和无序区。a[0...i-1]为有序区，a[i...n]为无序区。（i从1开始）
2、从无序区中取出第一个元素，即a[i]，在有序区序列中从后向前扫描。
3、如果有序元素大于a[i]，将有序元素后移到下一位置。
4、重复步骤3，直到找到小于或者等于a[i]的有序元素，将a[i]插入到该有序元素的下一个位置中。
5、重复2~4，直到无序区最后。
*******************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

template<typename T>
void straight_insert_sort(T a[],int n)
{
	int j;
	for (int i=1;i<n;i++)
	{
		T tmp = a[i];
		for (j=i-1;j>=0 && a[j]>tmp;j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] = tmp;
	}
}

int main()
{
	double a[] = {98.5,76.6,109,34,67,190,80,12,14,89,1};
	int n = (int)sizeof(a)/sizeof(a[0]);
	straight_insert_sort(a,n);

	for(int f=0;f<n;f++)
		cout<<a[f]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}