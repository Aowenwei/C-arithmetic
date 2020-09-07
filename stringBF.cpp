/*
 * @Author:  敖文伟
 * @Date: 2020-04-29 14:52:12
 * @LastEditTime: 2020-04-30 12:11:18
 * @LastEditors: Please set LastEditors
 * @Description: BF (BruteForce)暴力法
 * @FilePath: /StringMatching/BF/stringBF.cpp
 */
/* 算法思想：
 * 将目标串S的第一个二字符与模式串P的第一个字符进行匹配，相等，继续匹配两串的第二个字符，
 * 若不相等: 则比较S的第二个字符和P的第一个字符，直到匹配出结果，所以为暴力算法
 * 算法复杂度为： O(n(n-m));
 */
#include <iostream>
#include <string>
int BF(const char *s1, const char *s2);
int BruteForce(const std::string &s1, const std::string &s2);
int main(int argc, char *argv[])
{
  std::string s1{"HelloWorld"};
  std::string s2("rld");
  std::cout << "主串：" << s1 << "\n模式串: " << s2 << std::endl;
  std::cout << "匹配开始位置： " << BruteForce(s1, s2) << std::endl;
  return 0;
}

int BruteForce(const std::string &s1, const std::string &s2)
{
  int index = 0;
  int i = 0, j = 0;
  while (s1[i] != '\0' && s2[j] != '\0')
  {
    if (s1[i] == s2[j])
    {
      // 匹配成功，继续往下比较
      i++;
      j++;
    }
    else
    {
      // 匹配不成功，主串和子串回溯坐标， index记录每次匹配的开始位置
      index++;
      i = index; //回溯至主串的 index + 1 处位置开始
      j = 0;     //回到字串开始位置
    }
  }
  if (s2[j] == '\0')
    return index + 1;
  return -1;
}

int BF(const char *s1, const char *s2)
{
  int index = 0;
  int i = 0, j = 0;
  while (*(s1 + i) != '\0' && *(s2 + j) != '\0')
  {
    if (*(s1 + i) == *(s2 + j))
    {
      i++;
      j++;
    }
    else
    {
      index++;
      i = index;
      j = 0;
    }
  }
  if (*(s2 + j) == '\0')
    return index;
  return -1;
}
