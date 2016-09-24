#include"header.h"
String::String(const char* Str)
{
	str = new char[String::getLength(Str) + 1];
	int i = 0;
	while (Str != NULL&&Str[i] != '\0')
		str[i++] = Str[i];
	str[i] = '\0';
}
String::String(const int size)
{
	str = new char[size];
	str[0] = '\0';
}
String::String(String& s)
{
	str = new char[String::getLength(s) + 1];
	int i = 0;
	while (s.str[i] != '\0')
	{
		str[i++] = s.str[i];
	}
	str[i] = '\0';
}
String::~String()
{
	delete[] str;
}
void String::operator = (const String & os)
{
	int i = 0;
	delete[] str;
	str = new char[String::getLength(os.str) + 1];
	while (os.str[i] != '\0')
		str[i++] = os.str[i];
	str[i] = '\0';
}
ostream& operator << (ostream& output, String& s)
{
	output << s.str;
	return output;
}
istream& operator >> (istream& input, String& s)
{
	input >> s.str;
	return input;
}
void String::assign(const char *s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		str[i++] = s[i];
	}
	str[i] = '\0';
}
void String::assign(const char *s, int n)
{
	for (int i = 0; i<n; i++)
	{
		str[i] = s[i];
	}
}
void String::assign(int n, char c)
{
	int i = 0;
	for (; i<n; i++)
	{
		str[i] = c;
	}
	str[i] = '\0';
}
void String::operator+=(const String &s)
{
	char* temp = new char[String::getLength(*this) + String::getLength(s.str) + 1];
	int i = 0, n = 0;
	while (str[i] != '\0')
	{
		temp[i++] = str[i];
	}
	delete[] str;
	str = temp;
	while (s.str[n] != '\0')
	{
		str[i++] = s.str[n++];
	}
	str[i] = '\0';
}
void String::append(const char *s)
{
	int i = 0, n = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (s[n] != '\0')
	{
		str[i++] = s[n++];
	}
	str[i] = '\0';
}
int String::Compare(String& strA, String& strB)
{
	int i = 0;
	while (strA.str[i++] == strB.str[i])
		if (strA.str[i] == '\0')
			return 0;
	return (int)strA.str[i] - (int)strB.str[i];
}
int String::Compare(String& strA, String& strB, bool ignoreCase)
{
	if (ignoreCase)
	{
		String NstrA = strA, NstrB = strB;
		String::upperCase(NstrA);
		String::upperCase(NstrB);
		return String::Compare(NstrA, NstrB);
	}
	else
	{
		return String::Compare(strA, strB);
	}
}
int* String::Indexof(String& value)
{
	int* index = new int[this->getTimes(value) + 1];
	int i = 0, n = 0, l = 0;
	while (str[i] != '\0')
	{
		while (str[i++] == value.str[n])
			if (value.str[++n] == '\0')
			{
				index[l++] = i - n;
				n = 0;
				if (str[i] == '\0')
					break;
			}
		n = 0;
	}
	index[l] = -1;
	return index;
}
int* String::Indexof(String& value, int startIndex)
{
	int* index = new int[this->getTimes(value) + 1];
	int i = startIndex, n = 0, l = 0;
	while (str[i] != '\0')
	{
		while (str[i++] == value.str[n])
			if (value.str[++n] == '\0')
			{
				index[l++] = i - n;
				n = 0;
				if (str[i] == '\0')
					break;
			}
		n = 0;
	}
	index[l] = -1;
	return index;
}
int* String::Indexof(String& value, int startIndex, int count)//
{
	int* index = new int[this->getTimes(value) + 1];
	int i = startIndex, n = 0, l = 0;
	while (str[i] != '\0')
	{
		while (str[i++] == value.str[n])
			if (value.str[++n] == '\0')
			{
				index[l++] = i - n;
				n = 0;
				if (str[i] == '\0')
					break;
			}
		n = 0;
		if (i == count)
			break;
	}
	index[l] = -1;
	return index;
}
String String::replace(String oldValue, String newValue)
{

	int* index = Indexof(oldValue);
	int ovLength = String::getLength(newValue);
	int nvLength = String::getLength(oldValue);
	int times = getTimes(oldValue);
	String Nstr(String::getLength(*this) - times*ovLength + times*nvLength + 1);
	int i = 0, n = 0, l = 0;
	while (str[i] != '\0')
	{
		if (i == index[l])
		{
			for (int a = 0; a < nvLength; a++)
			{
				Nstr.str[n++] = newValue[a];
			}
			i += ovLength;
			l++;
		}
		Nstr.str[n++] = str[i++];
	}
	Nstr.str[n] = '\0';
	delete[] index;
	return Nstr;
}
String String::trim(String& value)
{
	int* index = value.Indexof((String)" ");
	int i = 0, n = 0, l = 0, times = value.getTimes((String)" ");
	String Nstr(String::getLength(value) - times + 1);
	while (value.str[i] != '\0')
	{
		while (i == index[l])
		{
			i++;
			l++;
		}
		Nstr.str[n++] = value.str[i++];
	}
	Nstr.str[n] = '\0';
	delete[] index;
	return Nstr;
}
String String::trim(String& value, String trimString)
{
	int* index = value.Indexof(trimString);
	int i = 0, n = 0, l = 0, times = value.getTimes(trimString), trimStringLength = String::getLength(trimString);
	String Nstr(String::getLength(value) - times*trimStringLength + 1);
	while (value.str[i] != '\0')
	{
		while (i == index[l])
		{
			i += trimStringLength;
			l++;
		}
		Nstr.str[n++] = value.str[i++];
	}
	Nstr.str[n] = '\0';
	delete[] index;
	return Nstr;
}
String String::trimStart(String& value, String trimString)
{
	int* index = value.Indexof(trimString);
	int i = 0, n = 0, l = 0, times = value.getTimes(trimString), trimStringLength = String::getLength(trimString);
	String Nstr(String::getLength(value) - times * 2 + 1);
	while (value.str[i] != '\0')
	{
		while (i == index[l])
		{
			i += 2;
			l++;
		}
		Nstr.str[n++] = value.str[i++];
	}
	Nstr.str[n] = '\0';
	delete[] index;
	return Nstr;
}
String String::trimEnd(String& value, String trimString)
{
	int* index = value.Indexof(trimString);
	int i = 0, n = 0, l = 0, times = value.getTimes(trimString), trimStringLength = String::getLength(trimString);
	String Nstr(String::getLength(value) - times * 2 + 1);
	while (value.str[i] != '\0')
	{
		while (i == index[l])
		{
			for (int a = 0; a<trimStringLength - 2; a++)
				Nstr.str[n++] = value.str[i++];
			i += 2;
			l++;
			if (value.str[i] == '\0')
			{
				i--;
				n--;
			}
		}
			Nstr.str[n++] = value.str[i++];
	}
	Nstr.str[n] = '\0';
	delete[] index;
	return Nstr;
}
int String::getLength(const char* Str)
{
	if (Str == NULL)
		return 0;
	int i = 0;
	while (Str[i++] != '\0');
	return i - 1;
}
int String::getLength(String& value)
{
	int i = 0;
	while (value.str[i++] != '\0');
	return i - 1;
}
int String::getLength(String& value, String insertString)
{
	int i = 0;
	while (value.str[i++] != '\0');
	while (insertString.str[i++] != '\0');
	return i - 2;
}
int String::getLength(String& value, String insertString, String trimString)
{
	int i = 0;
	while (value.str[i++] != '\0');
	while (insertString.str[i++] != '\0');
	while (trimString.str[i++] != '\0');
	return i - 3;
}
void String::upperCase(String& value)
{
	int i = 0;
	while (value.str[i] != '\0')
	{
		if (value.str[i] > 96 && value.str[i] < 123)
			value.str[i] -= 32;
		i++;
	}
	//while (*str1++ = *dtr++);
}
char String::operator [](const int index)
{
	return str[index];
}
int String::getTimes(String& value)
{
	int i = -1, n = 0, l = 0;
	while (str[i] != '\0')
	{
		while (str[i++] == value.str[n])
			if (value.str[++n] == '\0')
			{
				n = 0;
				l++;
				if (str[i] == '\0')
					break;
			}
	}
	return l;
}
