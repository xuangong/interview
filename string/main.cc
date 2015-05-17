#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "qh_string.h"


int main(int argc, char* argv[])
{
    //TODO ÔÚÕâÀïÌí¼Óµ¥Ôª²âÊÔ£¬Ô½¶àÔ½ºÃ£¬´úÂëÂ·¾¶¸²¸ÇÂÊÔ½È«Ô½ºÃ
    //TODO µ¥Ôª²âÊÔĞ´·¨Çë²Î¿¼INIParserÄÇ¸öÏîÄ¿£¬²»ÒªĞ´Ò»¶Ñprintf£¬ÒªÓÃassert½øĞĞ¶ÏÑÔÅĞ¶Ï¡£
    // ¿¿¿¿¿¿¿¿
    qh::string str1;
    assert(str1.data() == NULL && str1.size() == 0);

    // ¿¿¿¿¿¿¿¿¿¿
    qh::string str12 = str1;
    assert(str12.data() == NULL && str12.size() == 0);

    // ¿¿¿¿¿¿¿¿¿¿
    const char *s = "Hello world!";
    qh::string str2(s);
    assert(str2.size() == strlen(s));

    // ¿¿¿¿¿¿¿¿¿¿
    qh::string str21 = str2;
    assert(str21.size() == strlen(s));

    // ¿¿¿¿¿¿¿¿¿
    const char *s1 = "";
    qh::string str22(s1);
    assert(str22.size() == strlen(s1));

    // ¿¿¿¿¿¿
    char *bracket = str2[3];
    assert(*bracket == 'l');

    // ¿¿¿¿¿¿
    bracket = str2[20];
    assert(bracket == NULL);

    // ¿¿¿¿¿¿¿¿¿¿¿¿¿
    qh::string str3(s, 5);
    assert(strlen(str3.c_str()) == 5);

    // ¿¿¿¿¿¿¿¿¿¿¿¿¿
    qh::string str31(s, 20);
    assert(strlen(str31.c_str()) == strlen(s));

    // ¿¿¿¿¿¿¿¿
    str31 = str3;
    assert(str31.size() == 5);

    // ¿¿¿¿¿¿¿
    str31 = str1;
    assert(str31.size() == 0);

#ifdef WIN32
    system("pause");
#endif

	return 0;
}

