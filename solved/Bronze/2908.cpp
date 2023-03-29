#include <iostream>
#include <string>

using namespace std;

int main() {
  char a[4], b[4];
  scanf("%s%s", &a, &b);

  if(a[2] > b[2]) printf("%c%c%c\n", a[2], a[1], a[0]);
  else if(a[2] < b[2]) printf("%c%c%c\n", b[2], b[1], b[0]);
  else if(a[1] > b[1])printf("%c%c%c\n", a[2], a[1], a[0]);
  else if(a[1] < b[1]) printf("%c%c%c\n", b[2], b[1], b[0]);
  else if(a[0] > b[0])printf("%c%c%c\n", a[2], a[1], a[0]);
  else if(a[0] < b[0]) printf("%c%c%c\n", b[2], b[1], b[0]);
}