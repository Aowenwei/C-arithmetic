/*
 * @Author: 敖文伟
 * @Date: 2020-04-30 13:29:27
 * @LastEditTime: 2020-05-02 13:35:05
 * @LastEditors: Please set LastEditors
 * @Description: 快速排序，不稳定排序
 * @FilePath: /StringMatching/quicksort/quicksort.cpp
 *
快速排序的思想： 有一个待排序的数字 S = {1,2,4,5,3};从中找出元素 V， 我们称之为划界元素，
将剩下的元素中小于等于 V 的元素移动到 V 前面，将大于或等于 V 的元素移动到 V 后面，
这样 V 就找到了他最终的排序位置。
注意：快速排序是一个不稳定的排序算法，
主要是因为在进行最后一步划界元素与 S[i+1]交换的时候有可能打破前后元素的稳定性。
排序方法: 递归实现, 时间复杂度为 O(nlong^2n);
*/
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

template <typename T>
void quickSort(T *data, int p, int r); //排序
template <typename T>
void Swap(T &a, T &b); //交换数据
template <typename T>
int partition(T *data, int p, int r); //分割数据
int main()
{
  int data[10];
  cout << "排序前: ";
  for (int x = 0; x < 10; x++)
  {
    data[x] = rand() % 20;
    cout << data[x] << ' ';
  }
  quickSort(data, 0, 10 - 1);
  cout << "\n排序后: ";
  for (int x = 0; x < 10; x++)
    cout << data[x] << ' ';
  getchar();
  return 0;
}

//快速排序
template <typename T>
void quickSort(T *data, int p, int r)
{
  int position = 0;
  if (p < r)
  {
    position = partition(data, p, r); //返回划界元素的最终位置
    quickSort(data, p, position - 1); //对划分的子序列进行递归操作
    quickSort(data, p + 1, r);
  }
}

//交换值
template <typename T>
void Swap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}
//序列划分函数
template <typename T>
int partition(T *data, int p, int r)
{
  T temp = data[r];
  int i = p - 1;
  for (int j = p; j < r; j++)
  {
    if (data[j] <= temp)
    {         //发现小于划界元素的值
      i += 1; //交换元素 i+1 和元素 j 的值
      Swap(data[i], data[j]);
    }
  }
  Swap(data[i + 1], data[r]);
  return i + 1;
}
