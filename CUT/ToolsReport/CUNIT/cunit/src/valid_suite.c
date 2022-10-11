#include "CUnit/Basic.h"
#include "../header/valid.h"

int init_suite_valid()
{
return 0;
}

int clean_suite_valid()
{
return 0;
}

void testSunnyCases1()
{
CU_ASSERT_EQUAL(validation("Anisha"),1);
CU_ASSERT_EQUAL(validation("Sukanya"),1);
CU_ASSERT_EQUAL(validation("Anshul"),1);
}
void testRainyCases1()
{
CU_ASSERT_EQUAL(validation("an"),0);
CU_ASSERT_EQUAL(validation("d"),0);
CU_ASSERT_EQUAL(validation("be"),0);
}
