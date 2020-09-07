/*
 * @Author: your name
 * @Date: 2020-04-30 09:32:08
 * @LastEditTime: 2020-05-02 13:34:23
 * @LastEditors: Please set LastEditors
 * @Description: 冒泡排序，文档排序
 * @FilePath: /StringMatching/bubbleSort/bubbleSort.cpp
 */

#include <iostream>
#include <vector>
template <typename Type> void swap(Type &a, Type &b);
template <typename Type> void bubbleSort(Type &data, int n);
template <typename Type> void bubble_sort(Type &data, int size);
int main(int argc, char *argv[]) {
  std::vector<int> val;
  for (int x = 0; x < 10; x++) {
    //随机生成
    val.push_back(rand() % 20);
    std::cout << val[x] << ' ';
  }
  //  bubbleSort(val, val.size());
  bubble_sort(val, val.size());
  std::cout << "排序后的数据: ";
  for (int x = 0; x < val.size(); x++)
    std::cout << val[x] << ' ';
  std::cout << "\a\n";
  return 0;
}
template <typename Type> void swap(Type &a, Type &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
template <typename Type> void bubbleSort(Type &data, int n) {
  bool flag = 0; //设置一个flag， flag == 1时有位置交换， 否则没有位置交换。
  int i = 1; //判断是否大于 n
  int j = 0; //依次遍历
  do {
    flag = 0; //未发生交换
    for (j = 0; j + 1 < n; j++) {
      if (data[j] > data[j + 1]) //前一个比后一个大
        swap(data[j], data[j + 1]);
      flag = 1;
    }
    i++;
  } while (i < n && flag == 1);
}
/* 最好情况： T = O(N),   有序
 * 最坏情况： T = O(N^2)  逆序
 */
template <typename Type> void bubble_sort(Type &data, int size) {
  int flag;
  for (int i = 0; i < size - 1; i++) //进行size-1论排序
  {
    flag = 0; //未发生交换
    for (int j = 0; j < size - i - 1; j++) {
      if (data[j] > data[j + 1]) {
        swap(data[j], data[j + 1]);
        flag = 1;
      }
    }
    if (flag == 0) //如果当次循环没有发生交换，则数组已经排序好
      break;
  }
}