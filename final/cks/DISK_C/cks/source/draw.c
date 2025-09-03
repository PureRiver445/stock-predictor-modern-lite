#include "global.h"


void write_axis_number(const most_value* most, axis_data* axis)
{
    int max_unit_num = 5;
    float gap = most->max - most->min;
    float unit_gap; /* gap between two marks */
    float marks[] = { 0.1f, 0.2f, 0.5f, 1, 2, 3, 4, 5, 10, 20, 50, 100 };
    int mark_num = sizeof(marks) / sizeof(marks[0]);
    int i;
    int unit_length;
    char buffer[7]; /* contain 000.1-999.9 */
    int mark_y;
    float mark_value;

    for (i = 0; i < mark_num; i++)
    {
        if (gap > max_unit_num * marks[i])
            continue;

        unit_gap = marks[i];
        axis->max = (int)ceil(most->max / marks[i]) * marks[i];
        axis->min = (int)floor(most->min / marks[i]) * marks[i];
        axis->unit_num = (axis->max - axis->min) / unit_gap;
        break;
    }
    
    if( i!=0)
    {
        i--;
        unit_gap = marks[i];
        axis->max = (int)ceil(most->max / marks[i]) * marks[i];
        axis->min = (int)floor(most->min / marks[i]) * marks[i];
        axis->unit_num = (axis->max - axis->min) / unit_gap;
    }



#if defined (DEBUG)
    {
        FILE* log = open_file("debug", DEBUGLOG, "a");
        fprintf(log, "\nwrite_axis_number function :\n");
        fprintf(log, "most result :\n");
        fprintf(log, "max: %.2f, min: %.2f\n", most->max, most->min);
        fprintf(log, "axis result :\n", i);
        fprintf(log, "max: %.2f, min: %.2f, unit_gap: %.2f\n", axis->max, axis->min, unit_gap);
        fprintf(log, "unit_num: %d\n", axis->unit_num);
        close_file(log, "debug", ".log");
    }
#endif

    unit_length = axis->length / axis->unit_num;

    setcolor(LIGHTRED);
    settextstyle(SMALL_FONT, HORIZ_DIR, 4);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    for (i = 0; i < axis->unit_num + 1; i++)
    {
        mark_y = axis->y + unit_length * i;
        mark_value = axis->max - i * unit_gap;

        sprintf(buffer, "%.1f", mark_value);
        outtextxy(axis->x + 9, mark_y, buffer);
        setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
        line(0, mark_y+5, axis->x, mark_y+5);
        setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
        line(axis->x, mark_y+5, axis->x + 5, mark_y+5);
    }
}

void write_axis_number2(const most_value* most, axis_data* axis)
{
    int max_unit_num = 5;
    float gap = most->max - most->min;
    float unit_gap; /* gap between two marks */
    float marks[] = { 0.1f, 0.2f, 0.5f, 1, 2, 3, 4, 5, 10, 20, 50, 100 };
    int mark_num = sizeof(marks) / sizeof(marks[0]);
    int i;
    int unit_length;
    char buffer[7]; /* contain 000.1-999.9 */
    int mark_y;
    float mark_value;

    for (i = 0; i < mark_num; i++)
    {
        if (gap > max_unit_num * marks[i])
            continue;

        unit_gap = marks[i];
        axis->max = (int)ceil(most->max / marks[i]) * marks[i];
        axis->min = (int)floor(most->min / marks[i]) * marks[i];
        axis->unit_num = (axis->max - axis->min) / unit_gap;
        break;
    }

#if defined (DEBUG)
    {
        FILE* log = open_file("debug", DEBUGLOG, "a");
        fprintf(log, "\nwrite_axis_number function :\n");
        fprintf(log, "most result :\n");
        fprintf(log, "max: %.2f, min: %.2f\n", most->max, most->min);
        fprintf(log, "axis result :\n", i);
        fprintf(log, "max: %.2f, min: %.2f, unit_gap: %.2f\n", axis->max, axis->min, unit_gap);
        fprintf(log, "unit_num: %d\n", axis->unit_num);
        close_file(log, "debug", ".log");
    }
#endif

    unit_length = axis->length / axis->unit_num;

    setcolor(LIGHTRED);
    settextstyle(SMALL_FONT, HORIZ_DIR, 4);
    setlinestyle(DOTTED_LINE, 0, NORM_WIDTH);
    for (i = 0; i < axis->unit_num + 1; i++)
    {
        mark_y = axis->y + unit_length * i;
        mark_value = axis->max - i * unit_gap;

        sprintf(buffer, "%.1f", mark_value);
        outtextxy(axis->x +14, mark_y, buffer);
    }
}


void choose_rectangle(rectangle_info* rectangle, enum gear_type gear)
{
    switch (gear)
    {
        case SMALL:
        {
            rectangle->width = 3;
            rectangle->gap = 7;
            rectangle->num = 84;
            break;
        }
        case MEDIUM:
        {
            rectangle->width = 5;
            rectangle->gap = 14;
            rectangle->num = 42;
            break;
        }
        case LARGE:
        {
            rectangle->width = 10;
            rectangle->gap = 27;
            rectangle->num = 21;
            break;
        }
    }
}

void get_most(const stock_data* stock, enum line_type type, int num, most_value* most)
{
    int line_num;
    enum bool ismain;
    FILE* fp;
    most_value* buffer;
    int i;
    long start;

    assert(num * stock->period_length <= stock->days);

    ismain = tell_line(type, &line_num);
    fp = open_file(stock->code, type, "rb");

    most->max = -FLT_MAX;
    most->min = FLT_MAX;

    buffer = (most_value*)safe_malloc(num * sizeof(most_value));
    fseek( fp, 0, SEEK_END );
    start = ftell( fp ) - sizeof(most_value) * num;
    fseek( fp, start, SEEK_SET );
    SAFE_READ(buffer, sizeof(most_value), num, fp);
    close_file(fp, stock->code, ".who cares");

    for (i = 0; i < num; i++)
    {
        most->max = buffer[i].max > most->max ? buffer[i].max : most->max;
        most->min = buffer[i].min < most->min ? buffer[i].min : most->min;
    }
    free(buffer);

    if (ismain)
    {
        most_value most2;
        get_most(stock, KDAY, num, &most2);
        most->max = most2.max > most->max ? most2.max : most->max;
        most->min = most2.min < most->min ? most2.min : most->min;
    }

    #if defined (DEBUG)
    {
        FILE* log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, "\nget_most function: \n");
        fprintf( log, "max: %.2f, min: %.2f\n", most->max, most->min);
        close_file( log, "debug", ".log" );
    }
    #endif
}

void draw_line(const stock_data* stock, const rectangle_info* rectangle, enum line_type type, axis_data* axis)
{
    most_value most;
    int line_num;
    enum bool ismain;
    FILE* fp;

    get_most(stock, type, rectangle->num / stock->period_length, &most);
    write_axis_number(&most, axis);

    #if defined (DEBUG)
    {
        FILE* log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, "\ndraw_line function: \n");
        fprintf( log, "max: %.2f, min: %.2f\n", most.max, most.min);
        fprintf( log, "max: %.2f, min: %.2f, unit_num: %d\n", axis->max, axis->min, axis->unit_num);
        fprintf( log, "start to draw line\n");
        close_file( log, "debug", ".log" );
    }
    #endif

    ismain = tell_line(type, &line_num);
    fp = open_file(stock->code, type, "rb");
    if (type == KDAY || type == KWEEK)
        draw_kline(fp, type, stock, rectangle, axis);
    else if (type == MACD)
        draw_macd(fp, stock, rectangle, axis);
    else if (!ismain)
        draw_simple_line(fp, line_num, stock, rectangle, axis);
    else if (ismain)
    {
        FILE* kdayfp = open_file(stock->code, KDAY, "rb");
        draw_simple_line(fp, line_num, stock, rectangle, axis);
        draw_kline(kdayfp, KDAY, stock, rectangle, axis);
        close_file(kdayfp, stock->code, ".kday");
    }
    close_file(fp, stock->code, ".whatever");

}
void draw_mark( enum line_type type)
{
    int i;
    enum COLORS color[] = { WHITE, YELLOW, BLUE, GREEN };
    settextstyle(SMALL_FONT, HORIZ_DIR, 6);
    switch( type )
    {
        case KDAY:
            puthz( 92,42,"日线",16,16,BROWN);
            break;
        case KWEEK:
            setcolor(WHITE);
            puthz( 92,42,"周线",16,16,BROWN);
            break;
        case MA:
        {
            char str[4][5] = { "MA05", "MA10", "MA20" };
            for( i=0; i<3; i++)
            {
                setcolor(color[i]);
                outtextxy( 93+55*i,38, str[i]);
            }
            break;
        }
        case EXPMA:
        {
            char str[2][8] = { "EXPMA12", "EXPMA50" };
            for( i=0; i<2; i++)
            {
                setcolor(color[i]);
                outtextxy( 93+80*i,38 ,str[i]);
            }
            break;
        }
        case XUECHI:
        {
            char str[4][9] = { "XUECHI12", "XUECHI50" };
            for( i=0; i<2; i++)
            {
                setcolor(color[i]);
                outtextxy( 93+96*i,38 ,str[i]);
            }
            break;
        }
        case KDJ:
        {
            char str[3][2] = { "K", "D", "J" };
            for( i=0; i<3; i++)
            {
                setcolor(color[i]);
                outtextxy(15+15*i ,282, str[i]);
            }
            break;
        }
        case MACD:
        {
            char str[3][5] = { "DIF", "DEA", "MACD" };
            for( i=0; i<3; i++)
            {
                setcolor(color[i]);
                outtextxy( 15+45*i,282, str[i]);
            }
            break;
        } 
        case WILLIAMS:
        {
            char str[] = "Williams";
            setcolor(YELLOW);
            outtextxy(15, 282, str);
            break;
        }
    }
}

void draw_kline(FILE* fp, enum line_type type, const stock_data* stock, const rectangle_info* rectangle, const axis_data* axis)
{

    int high_y, low_y, open_y, close_y;
    int present_x;
    int half_width;
    int i;

    {
        long start;
        if (type == KDAY)
            start = sizeof(day_price) * stock->days - sizeof(day_price) * rectangle->num;
        else
            start = sizeof(week_data) * stock->weeks - sizeof(week_data) * rectangle->num;
        fseek(fp, start, SEEK_SET);
    }

    present_x = axis->x - rectangle->gap * rectangle->num;
    half_width = ROUND(rectangle->width / 2);

    assert(present_x >= 0);

    for (i = 0; i < rectangle->num; i++, present_x += rectangle->gap)
    {
        enum COLORS color;
        day_price info;
        SAFE_READ(&info, sizeof(day_price), 1, fp);

        if (info.close > info.open)
            color = RED;
        else
            color = GREEN;
        setcolor(color);
        setfillstyle(SOLID_FILL, color);

        high_y = CALCULATE_Y(axis, info.high);
        low_y = CALCULATE_Y(axis, info.low);
        open_y = CALCULATE_Y(axis, info.open);
        close_y = CALCULATE_Y(axis, info.close);

        line(present_x, high_y, present_x, low_y);
        bar(present_x - half_width, open_y, present_x + half_width, close_y);
    }

    #if defined (DEBUG)
    {
        FILE* log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, "\nkline %d has been drawn \n",type);
        close_file( log, "debug", ".log" );
    }
    #endif
}

void draw_simple_line(FILE* fp, int line_num, const stock_data* stock, const rectangle_info* rectangle, const axis_data* axis)
{
    int p;
    enum COLORS color[] = { WHITE, YELLOW, BLUE, GREEN };
    for (p = 0; p < line_num; p++)
    {
        int* xy_buffer;
        float* buffer = (float*)safe_calloc(rectangle->num, sizeof(float));
        {
            long start = sizeof(float) * stock->days * (p+1) - sizeof(float) * rectangle->num;
            fseek(fp, start, SEEK_SET);
            SAFE_READ(buffer, sizeof(float), rectangle->num, fp);
        }
        xy_buffer = (int*)safe_malloc(rectangle->num * 2 * sizeof(int));
        calculate_xy(buffer, xy_buffer, rectangle, axis);

        setcolor(color[p]);
        drawpoly(rectangle->num, xy_buffer);
        free(buffer);
        free(xy_buffer);

        #if defined (DEBUG)
        {
            FILE* log = open_file( "debug", DEBUGLOG, "a" );
            fprintf( log, "simple line %d has been drawn \n", p);
            close_file( log, "debug", ".log" );
        }
        #endif
    }
}

void calculate_xy(float* buffer, int* xy_buffer, const rectangle_info* rectangle, const axis_data* axis)
{
    int i;

    int present_x;
    present_x = axis->x - rectangle->gap * rectangle->num;
    assert(present_x >= 0);

    for (i = 0; i < rectangle->num; i++, present_x += rectangle->gap)
    {
        xy_buffer[i * 2] = present_x;
        xy_buffer[i * 2 + 1] = CALCULATE_Y(axis, buffer[i]);
    }
}

void draw_macd(FILE* fp, const stock_data* stock, const rectangle_info* rectangle, const axis_data* axis)
{
    int i;
    int zero_y;
    float* buffer;
    int* xy_buffer;

    draw_simple_line(fp, 2, stock, rectangle, axis);

    {
        long start;
        buffer = (float*)safe_calloc(rectangle->num, sizeof(float));
        start = sizeof(float) * stock->days * 3 - sizeof(float) * rectangle->num;
        fseek(fp, start, SEEK_SET);
        SAFE_READ(buffer, sizeof(float), rectangle->num, fp);
    }

    xy_buffer = (int*)safe_malloc(rectangle->num * 2 * sizeof(int));
    calculate_xy(buffer, xy_buffer, rectangle, axis);
    free(buffer);

    zero_y = CALCULATE_Y(axis, 0);
    for (i = 0; i < rectangle->num; i++)
    {
        if (xy_buffer[i * 2 + 1] > zero_y )
            setcolor(RED);
        else
            setcolor(GREEN);
        line(xy_buffer[i * 2], zero_y, xy_buffer[i * 2], xy_buffer[i * 2 + 1]);
    }
    free(xy_buffer);

    #if defined (DEBUG)
    {
        FILE* log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, "macd has been drawn \n", i);
        close_file( log, "debug", ".log" );
    }
    #endif
}


void draw_gene_pred(const char* code)
{
    char str[GENE_NUM+1][6];
    float probability;

    FILE* fp = open_file( code, GENE, "rb");
    individual_data best;
    feature_data last;
    SAFE_READ(&best, sizeof(individual_data), 1, fp);
    SAFE_READ(&last, sizeof(feature_data), 1, fp);
    SAFE_READ(&probability, sizeof(float), 1, fp);
    close_file(fp, code, ".gene");

    sprintf(str[0], "%.2f", best.weights[0]);
    sprintf(str[1], "%.2f", best.weights[1]);
    sprintf(str[2], "%.2f", best.weights[2]);
    sprintf(str[3], "%.2f", best.weights[3]);
    sprintf(str[4], "%.2f", best.weights[4]);
    sprintf(str[5], "%.2f", best.weights[5]);
    sprintf(str[6], "%.2f", best.weights[6]);
    sprintf(str[7], "%.2f%%", probability * 100);

    setcolor(MAGENTA);
    settextstyle(3, 0, 1);
    outtextxy( 117,183, str[0]);
    outtextxy( 117,225, str[1]);
    outtextxy( 117,258, str[2]);
    outtextxy( 117,290, str[3]);
    outtextxy( 117,330, str[4]);
    outtextxy( 117,364, str[5]);
    outtextxy( 117,394, str[6]);

    settextstyle(3, HORIZ_DIR, 2);
    setcolor(LIGHTCYAN);
    puthz(5, 400+40, "上涨概率：", 24, 24, LIGHTCYAN);
    outtextxy(114, 437, str[7]);

    #if defined (DEBUG)
    {
        FILE* log;
        log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, " %s gene prediction has been drawn : \n", code);
        close_file(log, "debug", ".log");
    }
    #endif
    
}
void draw_ar_pred(const stock_data* stock, rectangle_info* rectangle, axis_data* axis)
{

    int i;
    most_value most;
    float* pred_buffer;
    unsigned long int start_date;

    {
        long start;
        FILE* predfp = open_file(stock->code, PRED, "rb");
        fseek( predfp, 0, SEEK_END );
        start = ftell( predfp ) - sizeof(float) * rectangle->num ;
        fseek(predfp, start, SEEK_SET);
        pred_buffer = (float*)safe_calloc(rectangle->num, sizeof(float));
        SAFE_READ(pred_buffer, sizeof(float), rectangle->num, predfp);
        close_file(predfp, stock->code, ".pred");
    }
    {
        int i;
        day_price info;
        FILE* kdayfp = open_file(stock->code, KDAY, "rb");
        fseek(kdayfp, (stock->days - rectangle->num + FORECAST_DAYS) * sizeof(day_price) , SEEK_SET);
        SAFE_READ(&info, sizeof(day_price), 1, kdayfp);
        start_date = info.date;
        close_file(kdayfp, stock->code, ".kday");
    }
    {
        int i;
        most.max = -FLT_MAX;
        most.min = FLT_MAX;
        for (i = 0; i < rectangle->num; i++)
        {
            most.max = most.max > pred_buffer[i] ? most.max : pred_buffer[i];
            most.min = most.min < pred_buffer[i] ? most.min : pred_buffer[i];
        }
    }
    write_axis_number2(&most, axis);

    #if defined (DEBUG)
    {
        int i;
        FILE* log;
        log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, "ar read: \n");
        for (i = 0; i < rectangle->num; i++)
            fprintf( log,"%.2f ", pred_buffer[i] );
        fprintf( log, "\nmax: %.2f, min: %.2f\n", most.max, most.min);
        fprintf( log, "start_date:%lu \n", start_date);
        close_file(log, "debug", ".log");
    }
    #endif
    setcolor(RED);
    settextstyle(SMALL_FONT, HORIZ_DIR, 6);
    for (i = 0; i < rectangle->num; i++)
    {
        char str[9];
        sprintf(str, "%lu", start_date+i);
        outtextxy(227, 246+i*30, str);
        sprintf(str, "%.2f", pred_buffer[i]);
        outtextxy(339, 246+i*30, str);
        //puthz( 388,248+i*30, "?", 16, 16, RED);
    }

    {
        int* xy_buffer = (float*)safe_malloc(sizeof(int) * 2 * rectangle->num);
        calculate_xy(pred_buffer, xy_buffer, rectangle, axis);
        setlinestyle(SOLID_LINE, 0, 1);
        drawpoly(rectangle->num-FORECAST_DAYS, xy_buffer);
        setlinestyle(DOTTED_LINE, 0, 1);
        drawpoly(FORECAST_DAYS+1, xy_buffer + (rectangle->num-FORECAST_DAYS-1) * 2);
        free(xy_buffer);
    }

    free(pred_buffer);

    #if defined (DEBUG)
    {
        FILE* log;
        log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, " %s ar prediction has been drawn : \n", stock->code);
        close_file(log, "debug", ".log");
    }
    #endif
}

