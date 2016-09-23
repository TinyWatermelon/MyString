#include"header.h"

void main()
{
	//////////////////////////        3.1.1        //////////////////////////////
	String str3_1_1a = "Hello World";
	String str3_1_1b = "HELLO WORLD";
	cout << String::Compare(str3_1_1a, str3_1_1b) << endl;
	//////////////////////////        3.1.2        //////////////////////////////
	cout << String::Compare(str3_1_1a, str3_1_1b, true) << endl;
	//////////////////////////        3.1.3        //////////////////////////////
	String str3_1_3 = "China stocks extend rally on positive policy outlook";
	cout << String::getLength(str3_1_3) << endl;
	//////////////////////////        3.1.4        //////////////////////////////
	str3_1_3 += "Chinese shares remained in positive territory for the second-consecutive day on Wednesday following the government's fresh fiscal stimulus measures";
	cout << String::getLength(str3_1_3) << endl;
	//////////////////////////        3.1.5        //////////////////////////////
	cout << String::getLength(String::trim(str3_1_3, "o")) << endl;
	//////////////////////////        3.1.6        //////////////////////////////
	int* temp = str3_1_3.Indexof((String)"China");
	cout << temp[0] << endl;
	temp = str3_1_3.Indexof((String)"Chinese");
	cout << temp[0] << endl;
	//////////////////////////        3.1.7        //////////////////////////////
	temp = str3_1_3.Indexof((String)"China", 40);
	cout << temp[0] << endl;
	temp = str3_1_3.Indexof((String)"Chinese", 40);
	cout << temp[0] << endl;
	////////////////////////////        3.1.8        //////////////////////////////
	temp = str3_1_3.Indexof((String)"day", 35, 60);
	cout << temp[0] << endl;
	//////////////////////////        3.1.9        //////////////////////////////
	String str3_1_9 = str3_1_3.replace("positive", "negative");
	cout << str3_1_9 << endl;
	cout << String::getLength(str3_1_9) << endl;
	//////////////////////////        3.1.10        //////////////////////////////
	String str3_1_10 = "  CCCentral bank defends measures taken to regulate forex markettt  ";
	str3_1_10 = String::trim(str3_1_10);
	cout << String::getLength(str3_1_10) << endl;
	//////////////////////////        3.1.11        //////////////////////////////
	str3_1_10 = String::trimStart(str3_1_10, "CCCentral");
	str3_1_10 = String::trimEnd(str3_1_10, "markettt");//
	cout << str3_1_10 << endl;
	cout << String::getLength(str3_1_10) << endl;
}
