#include <iostream>
using namespace std;

bool isAllDiffStr(char *str){
	bool index[256];
	while(*str){
		int tmp = int(*str);
		if (index[tmp]) return false;
		else index[tmp] = true;
		++str;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	/* code */
	char *t_string_1 = "qwertyuiop";
	char *t_string_2 = "qwerttrewq";
	cout << isAllDiffStr(t_string_1) << endl;
	return 0;
}
