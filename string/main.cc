#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "qh_string.h"


int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
    qh::string str1;
    assert(str1.data() == NULL && str1.size() == 0);

    const char *s = "Hello world!";
    qh::string str2(s);
    assert(str2.size() == strlen(s));

    char *bracket = str2[3];
    assert(*bracket == 'l');

    bracket = str2[20];
    assert(bracket == NULL);

    qh::string str3(s, 5);
    assert(strlen(str3.c_str()) == 5);


#ifdef WIN32
    system("pause");
#endif

	return 0;
}

