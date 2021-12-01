#include "Header.h"

string plus_minus_big(string absbig, string abssmall)
{
	if (absbig == '-' + abssmall) return "0";
	string newabs = "", presumm = "", postsumm = "";
	long long difference, one = 0;
	for (int i = 1; i < itc_len(absbig); i++) newabs += absbig[i];
	difference = itc_len(newabs) - itc_len(abssmall);
	for (int i = itc_len(abssmall) - 1; i >= 0; i--) {
		if (itc_stoi(newabs[i + difference]) - one < itc_stoi(abssmall[i])) {
			presumm += itc_itos(10 + itc_stoi(newabs[i + difference]) - one - itc_stoi(abssmall[i]));
			one = 1; }
		else {
			presumm += itc_itos(itc_stoi(newabs[i + difference]) - one - itc_stoi(abssmall[i]));
			one = 0; }
	}if (difference > 0) {
		for (int i = difference - 1; i >= 0; i--) {
			postsumm += itc_itos(itc_stoi(newabs[i]) - one);
			one = 0; } }
	if (postsumm != "0") return presumm + postsumm;
	return presumm;
}


string plus_minus_small(string absbig, string abssmall)
{
	if ('-' + absbig == abssmall) return "0";
	string newabs = "", presumm = "", postsumm = "";
	long long difference, one = 0;
	for (int i = 1; i < itc_len(abssmall); i++) newabs += abssmall[i];
	difference = itc_len(absbig) - itc_len(newabs);
	for (int i = itc_len(newabs) - 1; i >= 0; i--) {
		if (itc_stoi(absbig[i + difference]) - one < itc_stoi(newabs[i])) {
			presumm += itc_itos(10 + itc_stoi(absbig[i + difference]) - one - itc_stoi(newabs[i]));
			one = 1; }
		else {
			presumm += itc_itos(itc_stoi(absbig[i + difference]) - one - itc_stoi(newabs[i]));
			one = 0;} }
	if (difference > 0) {
		for (int i = difference - 1; i >= 0; i--) {
			postsumm += itc_itos(itc_stoi(absbig[i]) - one);
			one = 0; } }
	if (postsumm != "0") return presumm + postsumm;
	return presumm;
}

string nulls(long long amount)
{
	if (amount <= 0) return "";
	string nulls = "";
	for (int i = 0; i < amount; i++) nulls += '0';
	return nulls;
}

string multiplyhelp(string newbig, string newsmall)
{
	long long add = 0, counter = 0;
	string presumm = "", newpresumm = "", newsumm = "";
	for (int i = itc_len(newsmall) - 1; i >= 0; i--) {
		for (int j = itc_len(newbig) - 1; j >= 0; j--) {
			presumm += itc_itos((itc_stoi(newsmall[i]) * itc_stoi(newbig[j]) + add) % 10);
			add = (itc_stoi(newsmall[i]) * itc_stoi(newbig[j]) + add) / 10;
		}
		presumm += itc_itos(add);
		add = 0;
		for (int j = itc_len(presumm) - 1; j >= 0; j--) newpresumm += presumm[j];
		newsumm = summator(newsumm + " + " + newpresumm + nulls(counter));
		newpresumm = "";
		presumm = "";
		counter++;
	}
	return delete_null(newsumm);
}