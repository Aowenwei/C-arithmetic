#include <iostream>

template <typename Type> Type catStr(Type str1, Type str2) {
  int i = 0, j = 0, k = 0, m = 0;
  while (str1[i] != '\0') {
    i++;
    k++;
  }
  while (str2[j] != '\0') {
    j++;
    m++;
  }
  for (i = 0; i <= k + m; i++) {
    //注意：在把str2复制过来时连着最后一个'\0'也要复制过来
    // str1[i + k] = str2[i];
    *(str1 + i + k) = *(str2 + i);
  }
  return str1;
}
void swa(char *str1, char &str2) {
  char *p = catStr(str1, &str2);
  std::cout << p << std::endl;
}
int main() {
  int i = 0, j = 0, k = 0, m = 0;
  char str1[20]{"Hello "};
  char str2[7]{"World"};
  char &s = *str2;
  swa(str1, s);
  return 0;
}