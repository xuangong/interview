#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "qh_string.h"


int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
    // 靠�
    qh::string str1;
    assert(str1.data() == NULL && str1.size() == 0);

    // 靠靠�
    qh::string str12 = str1;
    assert(str12.data() == NULL && str12.size() == 0);

    // 靠靠靠
    const char *s = "Hello world!";
    qh::string str2(s);
    assert(str2.size() == strlen(s));

    // 靠靠靠
    qh::string str21 = str2;
    assert(str21.size() == strlen(s));

    // 靠靠靠�
    const char *s1 = "";
    qh::string str22(s1);
    assert(str22.size() == strlen(s1));

    // 靠靠靠
    char *bracket = str2[3];
    assert(*bracket == 'l');

    // 靠靠靠靠靠靠�
    bracket = str2[20];
    assert(bracket == NULL);

    // 靠靠靠靠�
    qh::string str3(s, 5);
    assert(strlen(str3.c_str()) == 5);

    // 靠靠靠靠靠�
    qh::string str31(s, 20);
    assert(strlen(str31.c_str()) == strlen(s));

    // 靠� 靠靠
    str31 = str3;
    assert(str31.size() == 5);

    // 靠� 靠�
    str31 = str1;
    assert(str31.size() == 0);

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

