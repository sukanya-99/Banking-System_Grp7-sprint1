#include <string.h>
#include<stdio.h>
#include <stdlib.h>
#include "../header/valid.h"
#include "../header/valid_suite.h"

int validation(char s[]){

    int l=strlen(s);
    if(l<3 || l>20)
    return 0;
    else
    return 1;


}
