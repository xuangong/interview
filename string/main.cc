#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "qh_string.h"


int main(int argc, char* argv[])
{
    // construct an empty object
    qh::string str1;
    assert(str1.data() == NULL && str1.size() == 0);

    // copy construct an object with an empty one
    qh::string str12 = str1;
    assert(str12.data() == NULL && str12.size() == 0);

    // construct an object with an array of chars
    const char *s = "Hello world!";
    qh::string str2(s);
    assert(str2.size() == strlen(s));

    // copy construct an object with an nonEmpty object
    qh::string str21 = str2;
    assert(str21.size() == strlen(s));

    // construct an object with an empty array of chars
    const char *s1 = "";
    qh::string str22(s1);
    assert(str22.size() == strlen(s1));

    // get an element in a object with a legal index
    char *bracket = str2[3];
    assert(*bracket == 'l');

    // get an element in a object with an illegal index
    bracket = str2[20];
    assert(bracket == NULL);

    // constuct an object with params of a legal length
    qh::string str3(s, 5);
    assert(strlen(str3.c_str()) == 5);

    // constuct an object with params of an illegal length
    qh::string str31(s, 20);
    assert(strlen(str31.c_str()) == strlen(s));

    // assign an object with an nonEmpty object
    str31 = str3;
    assert(str31.size() == 5);

    // assign an object with an empty object
    str31 = str1;
    assert(str31.size() == 0);

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

