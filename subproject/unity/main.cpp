#include <unity.h>
#include <estd/string.h>
#include <dragonbox/dragonbox_to_chars.h>

void test_to_chars();


int main()
{
    UNITY_BEGIN();

    test_to_chars();

    UNITY_END();

    return 0;
}