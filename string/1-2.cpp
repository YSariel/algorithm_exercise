#include <iostream>
using namespace std;

void reverse(char* str){
	char* end = str;
	char* start = str;
	char tmp;

	while(*end) ++end;
	--end;

	while(start < end){
		if(*start != *end){
			tmp = *start;
			*start++ = *end;
			*end-- = tmp;
		}
	}
}

void reverse2(char *str){
	char* end = str;
	char tmp;
	if(str){
		while(*end){
			++end;
		}
		--end;

		while(str < end){
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	char *t_string_1 = "qwertyuiop";

	reverse2(t_string_1);

	cout << t_string_1 << endl;

	return 0;
}