#include <unity.h>
#include <estd/string.h>
#include <dragonbox/dragonbox_to_chars.h>

static void test1()
{
    estd::layer1::string<32> s;
    jkj::dragonbox::to_chars(1.35, s.data());

    TEST_ASSERT_EQUAL_STRING("1.35E0", s.c_str());
}

void test_to_chars()
{
    RUN_TEST(test1);
}