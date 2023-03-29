#include <iostream>

using namespace std;

int num(char c) {
  if(c < 'S') {
    return (c - 'A') / 3 + 3;
  }
  else if(c < 'T') return 8;
  else if(c < 'W') return 9;
  else return 10;
}

int main() {
  char str[16];
  int cnt = 0;

  scanf("%s", str);

  for(int i = 0; str[i] != '\0'; i++) {
    cnt += num(str[i]);
  }

  printf("%d\n", cnt);
}