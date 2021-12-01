#include "Header.h"

int itc_stoi(string str)
{
	int number = 0, len = itc_len(str);
	for (int i = 0; i < len; i++) {
		if ((number == 0) && (str[i] > '0') && (str[i] <= '9')) number = str[i] - 48;
		else number = number * 10 + (str[i] - 48);
	}
	return number;
}

int itc_stoi(char symbol)
{
	return symbol - 48;
}

string itc_itos(int number)
{
	string str = "", num = "";
	if (number == 0) return "0";
	else if (number < 0) {
		number *= -1;
		str += '-';
	}
	while (number > 0) {
		num += 48 + (number % 10);
		number /= 10;
	}
	for (int i = itc_len(num) - 1; i >= 0; i--) str += num[i];
	return str;
}