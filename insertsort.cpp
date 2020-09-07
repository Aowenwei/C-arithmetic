/*
 * @Author: 敖文伟
 * @Date: 2020-05-01 21:06:27
 * @LastEditTime: 2020-05-02 13:34:42
 * @LastEditors: Please set LastEditors
 * @Description:插入排序，稳定排序
 * @FilePath: /StringMatching/insertsort/insertsort.cpp
 * 算法思想: 每次选择一个元素，并且将这个元素和整个数组中的所有元素进行比较、然后插入到合适的位置
 * 时间复杂度为 O(n^2)
 */
#include <iostream>
#include <vector>
void insertiom_sort(std::vector<int> &val);
int main(int argc, char *argv[])
{
  std::vector<int> val;
  for (int x = 0; x < 7; x++)
  {
    val.push_back(rand() % 20);
    std::cout << val[x] << ' ';
  }
  std::cout << '\n';
  insertiom_sort(val);
  for (int x : val)
    std::cout << x << ' ';
  return 0;
}

void insertiom_sort(std::vector<int> &val)
{
  int len = val.size();
  if (len == 0)
    return;
  for (int i = 1; i < len; i++) //从第二位开始排序，一直到最后一个元素
  {
    int j, temp;
    if (val[i] < val[i - 1])
    {
      temp = val[i]; //储存val[i]的值
      //从当前位置处理
      j = i;                             //记录比较位置
      while (j > 0 && temp < val[j - 1]) //将比temp大的数往后挪一个位置，为temp腾出合适的位置
      {
        val[j] = val[j - 1];
        j--; //填充完毕继续向前比较
      }
      //将temp放在属于他的位置上
      val[j] = temp;
    }
  }
}