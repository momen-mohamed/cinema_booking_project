
#ifndef CINMEA_BRAIN_H_
#define CINMEA_BRAIN_H_

#define NO_OF_SEATS 100
#define NO_OF_MOVIES 3

typedef struct {
    char phone_number[12];
    int isReserved;
    int price;
}Seat_t;


typedef enum{
    ADMIN,
    USER
}USER_type;


typedef enum{
    INITIAL,
    USER_SELECTION,
    ADMIN_SELECTION,
    RESERVE_TICKET,
    CANCEL_TICKET,
    DISPLAY_SEAT,
    SHOW_RESERVED_TICKET,
    CHANGE_PRICE
}STATE;


typedef enum{
    OK,
    NOT_OK,
}ERROR_type;

void view_reservedTicket(int movie_index);
void change_price(int new_price);
void set_credential(USER_type type_of_user);
void get_pass (char *pass);
char verify_user_pass (char pass[]);
char verify_admin_pass (char pass[]);
USER_type get_user_type();
int seats(int index);
ERROR_type reserve_seat(int movie_index, int seat_number,char* phone_number);
ERROR_type cancel_seat(int movie_index,int seat_number);
ERROR_type canceling_by_phone (int movie_index , char *phone_number);


#endif