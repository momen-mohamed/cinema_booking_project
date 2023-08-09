#include <stdio.h>
#include "terminal_manager.h"
#include "terminal_color.h"
#include "cinema_brain.h"
#include <string.h>


static int price = 100;
static Seat_t cinema[NO_OF_MOVIES][NO_OF_SEATS];
static USER_type user;

void view_reservedTicket(int movie_index)
{

    // printing reserved seats

    for (int i = 0; i < NO_OF_SEATS; i++)
    {

        if (cinema[movie_index][i].isReserved)
        {
            printf(RED "|%3d| " RESET, i + 1);
        }
        else
        {
            printf(GRN "|%3d| " RESET, i + 1);
        }
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }

    // printing tickets
    printf("-----------------------------------------------\n");
    for (int i = 0; i < NO_OF_SEATS; i++)
    {

        Seat_t current_seat = cinema[movie_index][i];
        if (current_seat.isReserved)
        {
            printf("-----------------------------------------------\n");

            switch (movie_index)
            {
            case 0:
                printf(CYN "OPPENHIEMER\n" RESET);
                break;
            case 1:
                printf(CYN "BARBIE\n" RESET);
                break;
            case 2:
                printf(CYN "MISSION IMPOSSIBLE\n" RESET);
                break;
            default:
                break;
            }
            printf(BLU "price:%d    seatNo:%d   phoneNumber:%s\n" RESET, current_seat.price, i + 1, current_seat.phone_number);

            printf("-----------------------------------------------\n");
        }
    }
}

void change_price(int new_price)
{
    price = new_price;
}

void set_credential(USER_type type_of_user)
{
    user = type_of_user;
}

USER_type get_user_type()
{
    return user;
}

ERROR_type reserve_seat(int movie_index, int seat_number, char *phone_number)
{
    ERROR_type status = OK;
    if (cinema[movie_index - 1][seat_number - 1].isReserved)
    {
        status = NOT_OK;
    }
    else
    {
        cinema[movie_index - 1][seat_number - 1].isReserved = 1;
        strcpy(cinema[movie_index - 1][seat_number - 1].phone_number, phone_number);
        cinema[movie_index - 1][seat_number - 1].price = price;
    }

    return status;
}

// canceling by phone
ERROR_type canceling_by_phone(int movie_index, char *phone_number)
{
    ERROR_type status = NOT_FOUND;
    for (int i = 0; i < NO_OF_SEATS; i++)
    {

        if (strcmp(cinema[movie_index - 1][i].phone_number, phone_number) == 0)
        {
            status = OK;
            if (cinema[movie_index - 1][i].isReserved == 1)
            {
                cinema[movie_index - 1][i].isReserved = 0;
                strcpy(cinema[movie_index - 1][i].phone_number, "");
            }
            else
            {
                status = NOT_OK;
            }
        }
    }
    return status;
}

ERROR_type cancel_seat(int movie_index, int seat_number)
{
    ERROR_type status = OK;

    if (cinema[movie_index - 1][seat_number - 1].isReserved == 0)
    {
        status = NOT_OK;
    }
    else
    {
        cinema[movie_index - 1][seat_number - 1].isReserved = 0;
        strcpy(cinema[movie_index - 1][seat_number - 1].phone_number, "");
    }
    return status;
}