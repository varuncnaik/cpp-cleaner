#include <iostream>

int main() {
	int a;
	/**/a = 0;
	/*xx*/a = 0;
	/*x*/a = 0;
	/*x*/a = 0;
	/*xx*/a = 0;
	/*xx*/a = 0;
	/*
	 xxxxx
	 xxx
	 */a = 0;
	/*xxxx*/a = 0;
	/*xxxxx*/a = 0;
	/*xxxxxxxxxxx*/a = 0;
	/*xxxxx*/a = 0;
	/*xxx*/a = 0;
	/*xxxxx*/a = 0;
	/*xxx*/a = 0;
	/*xx\
	 xxx
	 */a = 0;
	/*xx\  
	 xxx
	 */a = 0;
	/*xxx*\
\  
/a = 0;
	/\
\  
*xxx*/a = 0;

	int b;
	b = 0;//
	b = 0;//x
	b = 0;//x
	b = 0;//xx
	b = 0;//xx
	b = 0;//xxx
	b = 0;//xxx
	b = 0;//xxx
	b = 0;//xxxxxxxxxx
	b = 0;//xxxx
	b = 0;//xx
	b = 0;//xxxx
	b = 0;//xx
	b = 0;//xx\
	x
	b = 0;//xx\  
	x
	b = 0;/\
\  
/xx

	std::string r;
	r = R"()";
	r = R"x()x";
	r = R"(xx)";
	r = R"x(xx)x";
	r = R"x(xx)x";
	r = R"(xx)";
	r = R"(xx)";
	r = R"xx()xx";
	r = R"xx()xx";
	r = R"(xxx)";
	r = R"xxx()xxx";
	r = R"x(xxxxx)x";
	r = R"(xxx)";
	r = R"(x)";
	r = R"x()x";
	r = R"(xxx)";
	r = R"(x)";
	r = R"x()x";
	r = R"x(x
	x)x";
	r = R"x(xx
	x)x";
	r = R"x(xxxx
	x)x";
	r = R\
\  
"x(xx)x";

	std::string s;
	s = "";
	s = "x";
	s = "xx";
	s = "xxx";
	s = "xxx";
	s = "xxxx";
	s = "xxxxxx";
	s = "xxx";
	s = "xxxx";
	s = "xx";
	s = "xx\
	x";
	s = "xx\  
	x";

	char c;
	c = 'x';
	c = 'x';
	c = 'xx';

	return 0;
}
