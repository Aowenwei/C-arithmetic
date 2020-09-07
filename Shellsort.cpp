/*
 * @Author: 敖文伟
 * @Date: 2020-05-01 21:54:18
 * @LastEditTime: 2020-05-02 13:35:40
 * @LastEditors: Please set LastEditors
 * @Description: 希尔排序，不稳定排序
 * @FilePath: /StringMatching/Shellsort/Shellsort.cpp
 */
#include <iostream>
#include <vector>
void ShellSort(std::vector<int> &val);
int main(int argc, char *argv[])
{
  std::vector<int> val;
  for (int x = 0; x < 10; x++)
  {
    val.push_back(rand() % 20);
    std::cout << val[x] << ' ';
  }
  std::cout << '\n';
  ShellSort(val);
  for (int i : val)
  {
    std::cout << i << ' ';
  }
  return 0;
}
void ShellSort(std::vector<int> &val)
{
  int j = 0, temp = 0;
  int len = val.size();
  //增量每次都/2
  for (int setp = len / 2; setp > 0; setp /= 2)
  {
    //从增量那组开始进行插入排序，直到完毕
    for (int i = setp; i < len; i++)
    {
      j = i;
      temp = val[j];
      //j - setp 就是代表与他相同组隔壁的元素
      while (j - setp >= 0 && val[j - setp] > temp)
      {
        val[j] = val[j - setp];
        j -= setp;
      }
      val[j] = temp;
    }
  }
}