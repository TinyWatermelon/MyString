#include<stdio.h>

class string
{
public:
	string(const char *str=NULL);
	string(string&);
	~string();
	void operator =(const string &);
	string operator >> (const string &);
	string operator <<(const string &);
	string &assign(const char *s);
	string &assign(const char *s, int n);
	string &assign(int n, char c);
	void operator+=(const string &s);
	string &append(const char *s);
	static int Compare(string strA, string strB);
	static int Compare(string strA, string strB, bool ignoreCase);
	static int Indexof(string value);
	static int Indexof(string value, int startIndex);
	static int Indexof(string value, int startIndex, int count);
	static string replace(string oldValue, string newValue);
	static string trim(string value);
	static string trim(string value, string trimString);
	static string trimStart(string value, string trimString);
	static string trimEnd(string value, string trimString);
	static string getLength(string value);
	static string getLength(string value, string insertString);
	static string getLength(string value, string insertString, string trimString);
private:
	char* str;
};
