#include "Header.h"

bool itc_isDigit(unsigned char c)
{
	return((c >= 48) && (c <= 57));
}

string first_second(string str)
{
	string first, second, str2;
	long long i = 0, len = itc_len(str);
	while (!(itc_isDigit(str[i])) && i < len) i++;
	while (itc_isDigit(str[i]) && i < len) {
		str2 += str[i];
		i++;
	}
	str2 += ' ';
	while (!itc_isDigit(str[i]) && i < len) i++;
	while (itc_isDigit(str[i]) && i < len) {
		str2 += str[i];
		i++;
	}
	return str2;
}

string absSmallestNum(string a, string b)
{
	string biggest = absBiggestNum(a, b);
	if (biggest == a) return b;
	else return a;
}

string delete_null(string str)
{
	long long i = -1, len = itc_len(str);
	bool b = true;
	string ret = "";
	while (i < len && b) {
		i++;
		if (str[i] != '0') b = false;
	}
	for (i; i < len; i++) ret += str[i];
	return ret;
}