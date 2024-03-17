#include <unity.h>
#include <estd/string.h>
#include <dragonbox/dragonbox_to_chars.h>

int main()
{
    char buffer[128];
    jkj::dragonbox::to_chars(0.3, buffer);

    UNITY_BEGIN();

    UNITY_END();

    return 0;
}