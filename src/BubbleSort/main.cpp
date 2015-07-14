/************************ð������*********************************
auther:zengrui.kang
������ζ����ڵ����������бȽϣ�ÿһ���������ģ���С�ģ������Զ����ֵ����һλ��
ԭ��ð�������㷨���������£�
1���Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
2����ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ�����һ�㣬����Ԫ��Ӧ�û�����������
3��������е�Ԫ���ظ����ϵĲ��裬�������һ����
4������ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�
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
//ԭʼ����
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
//�Ż�һ������һ����ʶ���������һ�˷����˽�������Ϊtrue������Ϊfalse�������һ��û�з���������˵�������Ѿ���ɡ�
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

//�Ż�����������һ�����Ż��������100���������飬��ǰ��10�����򣬺���90�������ź����Ҷ�����ǰ��10�����֣�
//��ô�ڵ�һ�˱����������������λ�ñض�С��10�������λ��֮������ݱض��Ѿ������ˣ���¼����λ�ã�
//�ڶ���ֻҪ������ͷ�����������λ�þͿ����ˡ�
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
