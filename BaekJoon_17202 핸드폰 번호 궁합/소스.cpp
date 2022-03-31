#include <iostream>
using namespace std;

int cnt[20][20];
int compatible(int j)
{
	if (j == 15)
		return cnt[j - 1][0] * 10 + cnt[j - 1][1];
	for (int i = 0; i < 16 - j; i++)
	{
		cnt[j][i] = (cnt[j - 1][i] + cnt[j - 1][i + 1]) % 10;
	}
	return compatible(j + 1);
}

int main()
{
	string num1;
	string num2;
	cin >> num1 >> num2;
	for (int i = 0, index = 0; i < num1.length() + num2.length(); i++)
	{
		if (i % 2 == 0)
			cnt[0][i] += num1[index] - '0';
		else
			cnt[0][i] += num2[index++] - '0';
	}
	printf("%02d", compatible(1));
	return 0;
}