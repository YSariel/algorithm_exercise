#include <iostream>
using namespace std;

bool permutation(char* str1, int len1, char* str2, int len2){
	if(len1 != len2){
		return false;
	}

	int index[256];

	for(int i = 0; i < len1; i++){
		index[int(*(str1 + i))]++;
	}

	for(int i = 0; i < len2; i++){
		if(--index[int(*(str2 + i))] < 0){
			return false;
		}
	}
	return true;
}


int main(int argc, char const *argv[])
{
	/* code */
	char *t_string_1 = "qwertyuiop";
	char *t_string_2 = "qwerttrewq";
	char *t_string_3 = "poiuytrewq";


	cout << permutation(t_string_1 ,10 ,t_string_3 ,10) << endl;

	return 0;
}