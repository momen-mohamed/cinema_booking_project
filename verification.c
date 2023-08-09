#include "cinema_brain.h"
#include <string.h>


char verify_user_pass(char pass[])
{
    if (0 == strcmp(pass, "user"))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char verify_admin_pass(char pass[])
{
    if (0 == strcmp(pass, "admin"))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

ERROR_type phone_check(char number[])
{
    ERROR_type status = OK, i;
    for (i = 0; number[i] != '\0'; i++)
    {
        if (number[i] < '0' || number[i] > '9')
        {
            status = NOT_OK;
        }
    }
    if ((i - 1) != 10)
    {
        status = NOT_OK;
    }

    return status;
}