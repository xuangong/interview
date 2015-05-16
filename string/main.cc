#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "qh_string.h"


int main(int argc, char* argv[])
{
    //TODO ��������ӵ�Ԫ���ԣ�Խ��Խ�ã�����·��������ԽȫԽ��
    //TODO ��Ԫ����д����ο�INIParser�Ǹ���Ŀ����Ҫдһ��printf��Ҫ��assert���ж����жϡ�
    qh::string str1;
    assert(str1.data() == NULL && str1.size() == 0);

    const char *s = "Hello world!";
    qh::string str2(s);
    assert(str2.size() == strlen(s));

    const char *s1 = "";
    qh::string str21(s1);
    assert(str21.size() == strlen(s1));

    char *bracket = str2[3];
    assert(*bracket == 'l');

    bracket = str2[20];
    assert(bracket == NULL);

    qh::string str3(s, 5);
    assert(strlen(str3.c_str()) == 5);

    qh::string str31(s, 20);
    assert(strlen(str31.c_str()) == strlen(s));

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

