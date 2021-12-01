#include "Header.h"

long long itc_abs(int a)
{
	if (a < 0) return (a * -1);
	return a;
}

int itc_max(int a, int b)
{
	if (a >= b) return a;
	return b;
}

int itc_min(int a, int b)
{
	if (a <= b) return a;
	return b;
}

string plus_plus(string big, string small)
{
	string presumm = "", summ = "", newbig = "", newsmall = "", summ1 = "";
	long long difference, one = 0, lenbig = itc_len(big), lensmall = itc_len(small);
	if (big[0] == '-' && small[0] == '-') {
		summ +=  '-';
		for (int i = 1; i < lenbig; i++) newbig += big[i];
		for (int i = 1; i < lensmall; i++) newsmall += small[i];}
	else {
		newbig = big;
		newsmall = small; }
	difference = itc_len(newbig) - itc_len(newsmall);
	for (int i = itc_len(newsmall) - 1; i >= 0; i--) {
		if (itc_stoi(newsmall[i]) + itc_stoi(newbig[i + difference]) + one >= 10) {
			presumm += itc_itos((itc_stoi(newsmall[i]) + itc_stoi(newbig[i + difference]) + one) % 10);
			one = 1;}
		else {
			presumm += itc_itos(itc_stoi(newsmall[i]) + itc_stoi(newbig[i + difference]) + one);
			one = 0; } }
	for (int i = difference - 1; i >= 0; i--) {
		presumm += itc_itos(itc_stoi(newbig[i]) + one);
		one = 0; }
	for (int i = itc_len(presumm) - 1; i >= 0; i--) summ1 += presumm[i];
	if (delete_null(summ1) != "") return summ + summ1;
	return "0";
}

string plus_minus(string first, string second)
{
	string absbig = "", abssmall = "", presumm = "", summ = "", newabs = "", summ1 = "";
	absbig = absBiggestNum(first, second);
	abssmall = absSmallestNum(first, second);
	if (absbig[0] == '-') {
		summ += '-';
		presumm = plus_minus_big(absbig, abssmall);
		for (int i = itc_len(presumm) - 1; i >= 0; i--) summ1 += presumm[i];
	}
	else {
		presumm = plus_minus_small(absbig, abssmall);
		for (int i = itc_len(presumm) - 1; i >= 0; i--) summ1 += presumm[i];
	}
	if (delete_null(summ1) != "") return summ + delete_null(summ1);
	return "0";
}