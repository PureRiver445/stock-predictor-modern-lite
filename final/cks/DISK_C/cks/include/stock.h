#ifndef STOCK_H
#define STOCK_H

#define CODE_LEN 8 
#define FORECAST_DAYS 3
#define STOCK_NUM 10

#include "global.h"

enum line_type { KDAY, KWEEK, MA, EXPMA, XUECHI, KDJ, MACD, NA, PRED, DAY, WEEK , STOCK, GENE , CHOICE, NEWSFILE , STOCKTXT, DEBUGLOG ,WILLIAMS};
enum maline_type{ MA5=5, MA10=10, MA20=20};
enum expmaline_type{ EXPMA12=12, EXPMA50=50 };
enum xuechi_type{ XUECHI20=20, XUECHI60=60 };

typedef struct
{
    char code[CODE_LEN+1];
    char name[ 20 ];
    int days;/* valid market days*/
    int weeks;/* valid weeks*/
    int period_length;/* for most value saving*/
    int period_num;
}stock_data;

typedef struct
{
    char code[CODE_LEN+1];
    char name[ 20 ];
    char region[ 20 ];
    char industry[ 20 ];
    float open;
    float high;
    float low;
    float close;
    char rate[10];
    char fu[10];

}stock_data2;

typedef struct
{
    char code[CODE_LEN+1];
    char name[ 12 ];
}stock_data3;

typedef struct
{
    float max;
    float min;
}most_value;

typedef struct
{
    unsigned long int date;
    float open;
    float high;
    float low;
    float close;
}day_price;
typedef day_price week_data;

typedef struct 
{
    float k;
    float d;
    float j;
}kdj_data;

typedef struct 
{
    float dif;
    float dea;
    float macd_value;
    float ema_12;
    float ema_26;

}macd_data;


#endif