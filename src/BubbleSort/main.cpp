/************************冒泡排序*********************************
auther:zengrui.kang
概念：依次对相邻的两个数进行比较，每一轮下来最大的（最小的）数会自动浮现到最后一位。
原理：冒泡排序算法的运作如下：
1、比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2、对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
3、针对所有的元素重复以上的步骤，除了最后一个。
4、持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
*******************************************************************/
#include <iostream>
using namespace std;

template<typename T>
void change_value(T *a,T *b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


/*
//原始代码
template<typename T>
void bubble_sort(T param[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for (j=1;j<n-i;j++)
			if (param[j-1]>param[j])
				change_value(&param[j-1],&param[j]);
}
*/
/*
//优化一：设置一个标识符，如果这一趟发生了交换，则为true，否则为false。如果这一趟没有发生交换，说明排序已经完成。
template<typename T>
void bubble_sort(T param[],int n)
{
	int i;
	bool flag=true;

	while (flag)
	{
		flag = false;
		for (i=1;i<n;i++)
		{
			if (param[i-1]>param[i])
			{
				change_value(&param[i-1],&param[i]);
				flag = true;
			}
		}
		n--;
	}
}
*/

//优化二：再做进一步的优化。如果有100个数的数组，仅前面10个无序，后面90个都已排好序且都大于前面10个数字，
//那么在第一趟遍历后，最后发生交换的位置必定小于10，且这个位置之后的数据必定已经有序了，记录下这位置，
//第二次只要从数组头部遍历到这个位置就可以了。
template<typename T>
void bubble_sort(T param[],int n)
{
	int i,j;
	int flag = n;

	while(flag>0)
	{
		j=flag;
		flag=0;
		for (i=1;i<j;i++)
		{
			if (param[i-1]>param[i])
			{
				change_value(&param[i-1],&param[i]);
				flag=i;
			}
		}
	}
}

int main()
{
	int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
	int len = (int) sizeof(arr) / sizeof(*arr);
	bubble_sort(arr, len);
	for (int i = 0; i < len; i++) 
		cout << arr[i] << ' ';
	cout << endl;
	double arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
	len = (int) sizeof(arrf) / sizeof(*arrf);
	bubble_sort(arrf, len);
	for (int i = 0; i < len; i++)
		cout << arrf[i] << ' ';	
	cout<<endl;
	system("pause");
	return 0;
}
