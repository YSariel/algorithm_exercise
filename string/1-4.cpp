#include <iostream>
using namespace std;

char* replaceSpaces(char* str, int len){
	int spaceCount = 0, newLength, i;
	for(i = 0; i < len; i++){
		if(*(str + i) == ' '){
			spaceCount++;
		}
	}
	newLength = len + spaceCount * 2;
	char *newStr = (char*)malloc(sizeof(char) * newLength);
	*(newStr + newLength) = '\0';
	for(i = len - 1; i >= 0; i--){
		if(*(str + i) == ' '){
			*(newStr + newLength - 1) = '0';
			*(newStr + newLength - 2) = '2';
			*(newStr + newLength - 3) = '%';
			newLength -= 3;
		} else {
			*(newStr + newLength - 1) = *(str + i);
			newLength--;
		}
	}

	return newStr;

}

int main(int argc, char const *argv[])
{
	/* code */
	char *t_string_1 = "I am Sariel";

	cout << replaceSpaces(t_string_1, 10) << endl;

	return 0;
}