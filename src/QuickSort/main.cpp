/************************��������*********************************
auther:zengrui.kang
���
	ͨ��һ������Ҫ��������ݷָ�ɶ����������֣�����һ���ֵ��������ݶ�����
��һ�����������ݶ�ҪС��Ȼ�󰴴˷����������������ݷֱ���п����������������
�̿��Եݹ���У��Դ˴ﵽ�������ݱ���������С�

ԭ��
1���ȴ�������ȡ��һ������Ϊ��׼����
2�����������У���������������ȫ�ŵ������ұߣ�С�ڻ����������ȫ�ŵ�������ߡ�
3���ٶ����������ظ��ڶ�����ֱ��������ֻ��һ������
*******************************************************************/

#include <iostream>
using namespace std;

//����һ
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

//�����
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