#ifndef PAGE_H
#define PAGE_H

#include "global.h"

enum page { WELCOME, REGISTER, INDICATOR, STATUS, MARKET, PREDICT, EXIT, SEARCH, NEWS, NOBUT, NEWINFO };

typedef struct 
{
    enum line_type main_line;
    enum line_type sub_line;
    enum gear_type gear;
}indicator_info;

int new_position( day_price* kday_buffer, const rectangle_info* rectangle, const axis_data* axis, int mousex, int last_num );
enum page home_button(void);
void new_time( int* lastSecond );
int page_welcome(const user_data* user);
int page_register( user_data* user);
int page_status(const user_data* user, stock_data* stock);
void draw_choosed_stock(int* choice, int* total);
int page_indicator(const stock_data* stock, indicator_info* indicator);
int page_market(const user_data* user);
int page_search( stock_data* stock);
int page_predict(const stock_data* stock);

int page_news( int* new_num );
int page_newinfo( int new_num);


#endif