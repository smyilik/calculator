#include "Header.h"

string summator(string str)
{
	string first = "", second = "", big, small;
	long long i = 0, len = itc_len(str);
	while (i < len && !(itc_isDigit(str[i])) && str[i] != '-') i++;
	while (i < len && (itc_isDigit(str[i]) || (str[i] == '-' && itc_isDigit(str[i + 1])))) {
		first += str[i];
		i++; }
	while (i < len && !(itc_isDigit(str[i])) && str[i] != '-') i++;
	while (i < len && (itc_isDigit(str[i]) || (str[i] == '-' && itc_isDigit(str[i + 1])))) {
		second += str[i];
		i++; }
	big = absBiggestNum(first, second);
	small = absSmallestNum(first, second);
	if ((big[0] == '-' && small[0] == '-') || (big[0] != '-' && small[0] != '-')) return plus_plus(big, small);
	return plus_minus(big, small);
}

string subtractor(string str)
{
	string first = "", second = "", big, small, newsecond = "";
	long long i = 0, len = itc_len(str);
	while (i < len && !(itc_isDigit(str[i])) && str[i] != '-') i++;
	while (i < len && (i == 0 || itc_isDigit(str[i]) || (str[i] == '-' && itc_isDigit(str[i + 1] && !itc_isDigit(str[i - 1]))))) {
		first += str[i];
		i++;
	}
	while (i < len && (!itc_isDigit(str[i]) && !(str[i] == '-' && itc_isDigit(str[i + 1])))) i++;
	while (i < len && (itc_isDigit(str[i]) || ((str[i] == '-' && itc_isDigit(str[i + 1])) && itc_isDigit(str[i + 1])))) {
		second += str[i];
		i++;
	}
	if (second[0] == '-') for (int i = 1; i < itc_len(second); i++) newsecond += second[i];
	else newsecond = '-' + second;
	big = absBiggestNum(first, newsecond);
	small = absSmallestNum(first, newsecond);
	if ((big[0] == '-' && small[0] == '-') || (big[0] != '-' && small[0] != '-')) return plus_plus(big, small);
	return plus_minus(big, small);
}

string multiply(string str)
{
	string first, second, big, small, newbig = "", newsmall = "", summ;
	long long i = 0, len = itc_len(str), add = 0, counter = 0;
	first = firstnum(str);
	second = secondnum(str);
	if (delete_null(first) == "" || delete_null(second) == "") return "0";
	big = absBiggestNum(first, second);
	small = absSmallestNum(first, second);
	if (big[0] == '-') {
		summ = "-";
		for (int i = 1; i < itc_len(big); i++) newbig += big[i]; }
	else newbig = big;
	if (small[0] == '-' && summ == "-") {
		summ = "";
		for (int i = 1; i < itc_len(small); i++) newsmall += small[i]; }
	else if (small[0] == '-' && summ == "") {
		summ = "-";
		for (int i = 1; i < itc_len(small); i++) newsmall += small[i]; }
	else newsmall = small;
	return summ + multiplyhelp(newbig, newsmall);
}

string firstnum(string str)
{
	string first = "";
	long long i = 0, len = itc_len(str);
	while (i < len && !(itc_isDigit(str[i])) && str[i] != '-') i++;
	while (i < len && (itc_isDigit(str[i]) || (str[i] == '-' && itc_isDigit(str[i + 1])))) {
		first += str[i];
		i++;
	}
	return first;
}

string secondnum(string str)
{
	string second = "";
	long long i = 0, len = itc_len(str);
	while (i < len && !(itc_isDigit(str[i])) && str[i] != '-') i++;
	while (i < len && (itc_isDigit(str[i]) || (str[i] == '-' && itc_isDigit(str[i + 1])))) i++;
	while (i < len && !(itc_isDigit(str[i])) && str[i] != '-') i++;
	while (i < len && (itc_isDigit(str[i]) || (str[i] == '-' && itc_isDigit(str[i + 1])))) {
		second += str[i];
		i++;
	}
	return second;
}