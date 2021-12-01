#include "Header.h"

string biggestNum(string first, string second)
{
	string convertedSumm;
	if (itc_len(first) > itc_len(second) && ((first[0] != '-' && second[0] != '-') || (first[0] == '-' && second[0] == '-'))) return first;
	if (itc_len(first) < itc_len(second) && ((first[0] != '-' && second[0] != '-') || (first[0] == '-' && second[0] == '-'))) return second;
	if (first[0] == '-' && second[0] != '-') return second;
	if (second[0] == '-' && first[0] != '-') return first;
	int i = 0;
	if (first[0] == '-') int i = 1;
	for (i; i < itc_len(first); i++) {
		if (itc_stoi(first[i]) > itc_stoi(second[i])) return first;
		else if (itc_stoi(second[i]) > itc_stoi(first[i])) return second;
	}
	return first;
}

string absBiggestNum(string first, string second)
{
	if (first == second) return first;
	string first1 = "", second2 = "";
	long long i = 0, len1 = itc_len(first), len2 = itc_len(second);
	while (!(itc_isDigit(first[i])) && i < len1) i++;
	while (i < len1 && itc_isDigit(first[i])) {
		first1 += first[i];
		i++;
	}
	i = 0;
	while (!(itc_isDigit(second[i])) && i < len2) i++;
	while (i < len2 && itc_isDigit(second[i])) {
		second2 += second[i];
		i++;
	}
	string bigNum = biggestNum(first1, second2);
	if (bigNum == first || bigNum == second) return bigNum;
	else return "-" + bigNum;
}

bool itc_isFirstInSecond(string s1, string s2)
{
	if (s1 == "") return true;
	if (s2 == "") return false;
	return (itc_find_str(s2, s1) != -1);
}

int itc_find_str(string str1, string str2)
{
	long long ind = 0, st1 = itc_len(str1), st2 = itc_len(str2), otv = -1;
	for (int i = 0; i < st1; i++) {
		if (str1[i] == str2[0]) {
			otv = i;
			for (int j = 0; j < st2; j++) {
				if (str1[j + i] == str2[ind]) {
					ind++;
				}
				else {
					ind = 0;
					break;
				}
			}
		}
		if (ind == st2) {
			break;
		}
	}
	return(otv);
}

int len_strNum(string num)
{
	if (num[0] == '-') return itc_len(num) - 1;
	return itc_len(num);
}