#include <stdio.h>
#include "terminal_manager.h"
#include "terminal_color.h"
#include "cinema_brain.h"
#include "cinema_manager.h"

static STATE current_state = INITIAL;

void start_app()
{
    clrscr();
    print_cinema_entery();
    play_intro();
    clrscr(); // clear terminal
    print_cinema_entery();
    clrscr(); // clear terminal

    while (1)
    {

        switch (current_state)
        {
        case INITIAL:
            select_user();
            break;
        case USER_SELECTION:
            manage_user_selection();
            break;
        case ADMIN_SELECTION:
            manage_admin_selection();
            break;
        case SHOW_RESERVED_TICKET:
            manage_showing_ticket();
            break;
        case RESERVE_TICKET:
            manage_ticket_reserve();
            break;
        case CANCEL_TICKET:
            manage_ticket_cancel();
            break;
        case CHANGE_PRICE:
            manage_change_price();
            break;
        default:
            break;
        }
    }
}

void select_user()
{
    int selected_value;
    char pass[6] = {0};
    PRINT_MAIN_MENU;
    printf(BLU "TO MANAGE SYSTEM AS USER PRESS 1 AS ADMIN PRESS 2: " RESET);

    scanf("%d", &selected_value);

    if (selected_value == 1)
    {
        get_pass(pass);
        if (1 == verify_user_pass(pass))
        {
            set_credential(USER);
            current_state = USER_SELECTION;
        }
        else
        {
            show_error("WRONG PASSWORD\n");
        }
    }
    else if (selected_value == 2)
    {
        get_pass(pass);
        if (1 == verify_admin_pass(pass))
        {
            set_credential(ADMIN);
            current_state = ADMIN_SELECTION;
        }
        else
        {
            show_error("WRONG PASSWORD\n");
        }
    }
    else
    {
        printf(RED "WRONG ENTERY\n" RESET);
        play_errorBuzz();
    }
    clrscr();
}

void manage_user_selection()
{
    PRINT_USER_INSTRUCTIONS;
    int selection;
    printf("please enter your selection:");
    scanf("%d", &selection);
    switch (selection)
    {
    case 1:
        current_state = RESERVE_TICKET;
        break;
    case 2:
        current_state = CANCEL_TICKET;
        break;
    case 3:
        current_state = SHOW_RESERVED_TICKET;
        break;
    case 4:
        current_state = INITIAL;
        break;

    default:
        show_error("WRONG ENTERY\n");
        break;
    }
    clrscr();
}

void manage_ticket_reserve()
{

    PRINT_MOVIES;
    char phone_number[12];
    int selection;
    int seat_number;
    ERROR_type status;

    printf("please enter your selection: ");
    scanf("%d", &selection);
    if (selection < 4 && selection > 0)
    {
        printf("please enter seat number:");
        scanf("%d", &seat_number);
        printf("please enter your phone number: ");
        fflush(stdin);
        scanf("%s",phone_number);
        if (seat_number > 0 && seat_number <= 100)
        {
            status = reserve_seat(selection, seat_number, phone_number);
            if (status == NOT_OK)
            {
                show_error("SEAT IS ALREADY RESERVED\n");
            }
            else
            {
                play_correct();
            }
        }
        else
        {
            show_error("INCORRECT SEAT NUMBER\n");
        }
    }
    else if (selection == 4)
    {
        current_state = USER_SELECTION;
    }
    else
    {
        show_error("WRONG ENTERY");
    }
    clrscr();
}

void manage_showing_ticket()
{
    int movie_number;
    PRINT_MOVIES;
    printf("please enter number of movie:");
    scanf("%d", &movie_number);
    view_reservedTicket(movie_number - 1);
    current_state = USER_SELECTION;
}

void manage_ticket_cancel()
{
    int selection, selected_seat;
    ERROR_type status;

    PRINT_MOVIES;
    printf("please enter your selection:");
    scanf("%d", &selection);
    if (selection == 4)
    {
        current_state = USER_SELECTION;
    }
    else if (selection > 0 && selection < 4)
    {
        printf("please enter seat number:");
        scanf("%d", &selected_seat);
        status = cancel_seat(selection, selected_seat);
        if (status == NOT_OK)
        {
            show_error("SEAT IS ALREADY NOT RESERVED\n");
        }
        else
        {
            play_delete();
        }
    }
    else
    {
        show_error("WRONG ENTERY\n");
    }
    clrscr();
}

void manage_admin_selection()
{
    PRINT_ADMIN_INSTRUCTIONS;
    int selection;
    printf("please enter your selection:");
    scanf("%d", &selection);
    switch (selection)
    {
    case 1:
        current_state = SHOW_RESERVED_TICKET;
        break;
    case 2:
        current_state = CHANGE_PRICE;
        break;
    case 3:
        current_state = INITIAL;
        break;

    default:
        show_error("WRONG ENTERY");
        break;
    }
    clrscr();
}

void manage_change_price()
{
    int new_price;
    printf("please enter the new price:");
    scanf("%d", &new_price);
    change_price(new_price);
    current_state = ADMIN_SELECTION;
    clrscr();
}

void get_pass(char *pass)
{
    printf(YEL "Enter password : " RESET);
    scanf("%s", pass);
    pass[5] = '\0';
}