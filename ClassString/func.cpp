#include"header.h"
string::string(const char* Str)
{
	str = new char;
	int i = 0;
	while (Str!=NULL&&Str[i]!='\0')
	{
		str[i++] = Str[i];
	}
	str[i] = '\0';
}
string::string(string& s)
{
	str = new char;
	int i = 0;
	while (s.str[i]!='\0')
	{
		str[i++]=s.str[i];
	}
	str[i] = '\0';
}
string::~string()
{
	delete str;
}
void string::operator = (const string & os)
{
	string s;
	int i = 0;
	while (os.str[i] != '\0')
	{
		str[i++] = os.str[i];
	}
	str[i] = '\0';
	
}
//string string::operator >>(const string & os)
//{
//
//}
//string string::operator <<(const string & os)
//{
//
//}
string & string::assign(const char *s)
{
	string ns;
	int i = 0;
	while (s[i]!='\0')
	{
		ns.str[i++] = s[i];
	}
	str[i] = '\0';
	return ns;
}
//string & string::assign(const char *s,int n)
//{
//	for(int i=0;i<n;i++)
//	{
//		str[i]=s[i];
//	}
//	return ;
//}
string & string::assign(int n,char c)
{
	string ns;
	for(int i=0;i<n;i++)
	{
		ns.str[i]=c;
	}
	return ns;
}
void string::operator+=(const string &s)
{
	int i = 0, n = 0;
	while (str[i]!='\0')
	{
		i++;
	}
	while (s.str[n] != '\0')
	{
		str[i++] = s.str[n++];
	}
	str[i] = '\0';
}
//string & string::append(const char *s)
//{
//
//}
//int string::Compare (string strA, string strB)
//{
//
//}
//int string::Compare(string strA, string strB, bool ignoreCase)
//{
//
//}
//int string::Indexof(string value)
//{}
//int string::Indexof(string value, int startIndex)
//{}
//int string::Indexof(string value, int startIndex, int count)
//{}
//string string::replace(string oldValue, string newValue)
//{}
//string string::trim(string value)
//{}
//string string::trim(string value, string trimString)
//{}
//string string::trimStart(string value, string trimString)
//{}
//string string::trimEnd(string value, string trimString)
//{}
//string string::getLength(string value)
//{}
//string string::getLength(string value, string insertString)
//{}
//string string::getLength(string value, string insertString, string trimString)
//{}