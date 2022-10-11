#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../header/result.h"
#include "../header/result_suite.h"


int result_Valid(char *key)
{
    int l=strlen(key);
    if(l==12)
    return 1;
    else
    return 0;
}
