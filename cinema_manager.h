
#ifndef CINMEA_MANAGER_H_
#define CINMEA_MANAGER_H_
#include "MyP_Types.h"

void start_app();
void select_user();
void manage_user_selection();
void manage_ticket_reserve();
void manage_showing_ticket();
void manage_ticket_cancel();
void manage_admin_selection();
void manage_change_price();
void get_pass(Int8_t *pass);
void manage_cancelBySeat(Int32_t selected_movie);
void manage_cancelByPhoneNumber(Int32_t selected_movie);


#endif
