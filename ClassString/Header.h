#include<iostream>
using namespace std;
class String
{
public:
	String(const char *str=NULL);
	String(String&);
	String(const int size);
	~String();
	void operator =(const String &);
	char operator [](const int index);//
	friend ostream& operator << (ostream& output,String& s); //ostream& output
	friend istream& operator >> (istream& input, String& s);
	void assign(const char *s);
	void assign(const char *s, int n);
	void assign(int n, char c);
	void operator+=(const String &s);
	void append(const char *s);
	static int Compare(String& strA, String& strB);
	static int Compare(String& strA, String& strB, bool ignoreCase);
	int * Indexof(String& value);
	int * Indexof(String& value, int startIndex);
	int * Indexof(String& value, int startIndex, int count);
	String replace(String oldValue, String newValue);
	static String trim(String& value);
	static String trim(String& value, String trimString);
	static String trimStart(String& value, String trimString);
	static String trimEnd(String& value, String trimString);
	static int getLength(const char* value);
	static int getLength(String& value);
	static int getLength(String& value, String insertString);
	static int getLength(String& value, String insertString, String trimString);
	static void upperCase(String& value);//
	int getTimes(String& value);//
	int getTimes(String& value, int);
	int getTimes(String& value, int, int);
private:
	char* str;
};
