#include <iostream>
using namespace std;

char* compress(char* str, int len){
	int count = 0;
	char last = *str;
	for(int i = 1; i < len; i++){
		if(*(str + i) != last){
			count++;
			last = *(str + i);
		}
	}

	int realLen = 2 * (count + 1);

	if(realLen >= len) return str;
	else {
		char* newStr = (char*)malloc(sizeof(char) * realLen);
		int tmp = 1;
		int j = 0;
		char c[realLen];
		char last = *str;
		for(int i = 1; i < len; i++){
			if(*(str + i) == last){
				tmp++;
			}else{
				sprintf(c,"%d",tmp);


				*(newStr + j) = last;
				*(newStr + j + 1) = c[0];
				last = *(str + i);
				tmp = 1;
				j += 2;
			}
		}
		sprintf(c,"%d",tmp);

		*(newStr + j) = last;
		*(newStr + j + 1) = c[0];

		return newStr;		
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	char *t_string_1 = "aaaaabbccccddd";
	char *t_string_2 = "abcdefghijklmn";


	cout << compress(t_string_1, 14) << endl;


	return 0;
}