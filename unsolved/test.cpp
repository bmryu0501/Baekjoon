#include <iostream>
#include <algorithm>

#include <vector> // https://blockdmask.tistory.com/70
#include <list>
#include <map> // https://blockdmask.tistory.com/87
#include <set>
#include <stack>
#include <queue>

#define _USE_MATH_DEFINES // need this to use math defines
#include <math.h>

#include <cstring>
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dx8[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy8[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

using namespace std;

/* condition */

/* variables */

/* functions */
void swap(string &a, string &b){
    string tmp = a;
    a = b;
    b = tmp;
}

int binaryToDecimal(string bin) {
	int sum = 0;
	int len = bin.length();
	for(int i=0;i<len;i++) {
		if(bin[len-i-1] == '1') sum += pow(2, i);
	}
	return sum;
}

string decimalToBinary(int num) {
	string tmp = "";
	while (num > 0) {
		char ch = num % 2 + '0';
		tmp += ch;
		num /= 2;
	};

    string bin = "";
	for(int i=0;i<4-tmp.length();i++) bin += '0';
    for(int i=0;i<tmp.length();i++) {
        bin += tmp[tmp.length()-i-1];
    }

	return bin;
}

int main() {
    //ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char c = '*';

	if(c == '*') printf("Good\n");
}