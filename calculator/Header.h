#pragma once

#include <iostream>
#include <string>
using namespace std;

int itc_min(int a, int b);
int itc_max(int a, int b);
long long itc_abs(int a);
int itc_stoi(string str);
int itc_stoi(char symbol);
int itc_stoi(string str);
void help();
void calculator();
long long itc_len(string str);
bool itc_isDigit(unsigned char c);
string itc_itos(int number);
int itc_find_str(string str1, string str2);
bool itc_isFirstInSecond(string s1, string s2);
string first_second(string str);
string biggestNum(string first, string second);
int len_strNum(string num);
string absBiggestNum(string first, string second);
string absSmallestNum(string a, string b);
string delete_null(string str);
string nulls(long long amount);
string firstnum(string str);
string secondnum(string str);


string plus_plus(string big, string small);
string plus_minus(string first, string second);
string plus_minus_big(string absbig, string abssmall);
string plus_minus_small(string absbig, string abssmall);
string multiplyhelp(string newbig, string newsmall);


string summator(string str);
string subtractor(string str);
string multiply(string str);