#include "CUnit/Basic.h"
#include "../header/result_suite.h"
#include "../header/result.h"

int init_suite_result(void)
{
return 0;
}

int clean_suite_result(void)
{
return 0;
}

void testSunnyCases2(void)
{
CU_ASSERT_EQUAL(result_Valid("123456789101"),1);
CU_ASSERT_EQUAL(result_Valid("123456789102"),1);
CU_ASSERT_EQUAL(result_Valid("123456789103"),1);
}
void testRainyCases2(void)
{
 CU_ASSERT_EQUAL(result_Valid("123jjj8888"),0);
CU_ASSERT_EQUAL(result_Valid("abciiiii"),0);
CU_ASSERT_EQUAL(result_Valid("888oooo"),0);
}
