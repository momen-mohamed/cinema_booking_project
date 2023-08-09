#include "cinema_brain.h"
#include <string.h>
#include "MyP_Types.h"



Int8_t verify_user_pass(Int8_t pass[])
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
Int8_t verify_admin_pass(Int8_t pass[])
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

ERROR_type phone_check(Int8_t number[])
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
