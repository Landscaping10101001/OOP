#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
	char str[10000]; //배열 선언
	int alphabet[26] = { 0 }; //알파벳 개수 저장 배열 선언 및 초기화
	int count = 0;

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 10000개 까지 가능합니다." << endl;

	cin.getline(str, 10000, ';');
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		str[i] = tolower(str[i]);
	}

	for (int i = 0; i < len; i++)
	{
		if (isalpha(str[i]) != 0)
		{
			for (int j = 0; j < 26; j++)
			{
				if (str[i] == (j + 'a'))
				{
					alphabet[j]++;
				}
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < 26; i++)
	{
		sum += alphabet[i];
	}

	cout << "총 알파벳 수 " << sum << endl;
	cout << endl;

	for (int i = 0; i < 26; i++)
	{
		cout << (char)(i + 97) << "(" << alphabet[i] << ")" << " : ";
		for (int j = 0; j < alphabet[i]; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}