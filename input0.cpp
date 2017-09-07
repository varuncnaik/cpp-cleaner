#include <iostream>

int main() {
	int a;
	/**/a = 0;
	/*/ */a = 0;
	/* */a = 0;
	/***/a = 0;
	/** */a = 0;
	/****/a = 0;
	/*
	 * a  
	 * b
	 */a = 0;
	/* /* */a = 0;
	/* //a */a = 0;
	/* R"a(pq)a" */a = 0;
	/* "a" */a = 0;
	/* " */a = 0;
	/* 'a' */a = 0;
	/* ' */a = 0;
	/* a\
	 * b
	 */a = 0;
	/* a\  
	 * b
	 */a = 0;
	/* a *\
\  
/a = 0;
	/\
\  
* a */a = 0;

	int b;
	b = 0;//
	b = 0;//a
	b = 0;///
	b = 0;///a
	b = 0;////
	b = 0;// //
	b = 0;// /*
	b = 0;// */
	b = 0;// R"a(pq)a"
	b = 0;// "a"
	b = 0;// "
	b = 0;// 'a'
	b = 0;// '
	b = 0;// a\
	b
	b = 0;// a\  
	b
	b = 0;/\
\  
/ a

	std::string r;
	r = R"()";
	r = R"a()a";
	r = R"(pq)";
	r = R"a(pq)a";
	r = R"a()")a";
	r = R"(/*)";
	r = R"(*/)";
	r = R"/*()/*";
	r = R"*/()*/";
	r = R"(//a)";
	r = R"//a()//a";
	r = R"a(R"()")a";
	r = R"("a")";
	r = R"(")";
	r = R""()"";
	r = R"('a')";
	r = R"(')";
	r = R"'()'";
	r = R"a(p
	q)a";
	r = R"a(p\
	q)a";
	r = R"a(p\  
	q)a";
	r = R\
\  
"a(pq)a";

	std::string s;
	s = "";
	s = "a";
	s = " a";
	s = " /*";
	s = " */";
	s = " //a";
	s = " \"a\"";
	s = " \"";
	s = " 'a'";
	s = " '";
	s = " a\
	b";
	s = " a\  
	b";

	char c;
	c = 'a';
	c = '"';
	c = '\'';

	return 0;
}
