#include "global.h"

void new_time( int* lastSecond )
{
    struct time currentTime;
    gettime(&currentTime);
    if (currentTime.ti_sec != *lastSecond)
    {
        updateTime();
        *lastSecond = currentTime.ti_sec;
    }
}

int page_welcome( const user_data* user)
{
    int but;
    enum bool name_check = false, password_check = false;

    clrmous(MouseX, MouseY);
    cleardevice();
    draw_welcome();

    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);

        if( button_simple( 160, 230, 160 + 320, 230 + 32 ) )
        {
            delay(200);
            get_input( 160 + 75, 230 + 11, user->name, 8, 3);
            name_check = true;
        }
        if( button_simple( 160, 278, 160 + 320, 278 + 32 ) )
        {
            delay(200);
            get_input(160 + 75, 278 + 11, user->password, 8, 3);
            password_check = true;
        }
        if( button_simple(  160, 342, 480, 374 ) )
        {
            delay(200);
            if (name_check && password_check)
            {
                if (check_info(user))
                {
                    puthz( 250, 432, "登录成功", 32, 32, LIGHTGREEN);
                    #if defined (DEBUG)
                    {
                        FILE* log;
                        log = open_file( "debug", DEBUGLOG, "a" );
                        fprintf( log, "page_welcome function: \n");
                        fprintf( log,"user %s log in\n", user->name );
                        fprintf( log,"password %s\n", user->password );
                        close_file(log, "debug", ".log");
                    }
                    #endif
                    delay( 1000 );
                    return STATUS;
                }
                else
                {
                    puthz( 150-8, 432, "密码错误或用户名不存在", 32, 32, RED);
                    memset(user->name, 0, sizeof(user->name));
                    memset(user->password, 0, sizeof(user->password));
                    delay( 1000 );
                    return WELCOME;
                }
            }
        }
        if (button_simple(250, 380, 370, 415)) 
        {
            delay( 1000 );
            return REGISTER;
        }
        if (button_simple(576, 432, 636, 462)) 
        {
            delay( 1000 );
            return EXIT;
        }
        
        delay(20);
     }
}

int page_register(user_data* user)
{
    enum bool name_check = false, password_check = false;

    cleardevice();
    mouseinit();
    draw_register();

    while (1) 
    {
        newmouse(&MouseX, &MouseY, &press);

        if( button_simple( 160, 230, 160 + 320, 230 + 32 ))
        {
            delay(200);
            get_input(160 + 75, 230 + 11, user->name, 8, 3);
            name_check = true;
        }
        if( button_simple( 160, 278, 160 + 320, 278 + 32 ))
        {
            delay(200);
            get_input(160 + 75, 278 + 11, user->password, 8, 3);
            password_check = true;
        }
        if( button_simple( 160, 278 + 64, 160 + 320, 278 + 64 + 32 ))
        {
            delay(200);
            if (name_check && password_check) 
            {
                if (save_account(user)) 
                {
                    puthz(253, 400, "注册成功", 32, 32, LIGHTGREEN);
                    #if defined (DEBUG)
                    {
                        FILE* log;
                        log = open_file( "debug", DEBUGLOG, "a" );
                        fprintf( log, "page_register function: \n");
                        fprintf( log,"user %s register\n", user->name );
                        fprintf( log,"password %s\n", user->password );
                        close_file(log, "debug", ".log");
                    }
                    #endif
                    memset(user->name, 0, sizeof(user->name));
                    memset(user->password, 0, sizeof(user->password));
                    delay( 1000 );
                    return WELCOME;
                }
                else 
                {
                    puthz(253, 400, "用户名已存在", 32, 32, RED);
                    memset(user->name, 0, sizeof(user->name));
                    memset(user->password, 0, sizeof(user->password));
                    delay( 1000 );
                    return REGISTER;
                }
            }
        }
        if( button_simple( 640 - 16 - 48, 480 - 16 - 32, 640 - 16, 480 - 16 ))
        {
            delay(1000);
            return WELCOME;
        }

        delay(20);
    }
}

enum page home_button( void )
{

    if (button_home(180, 1, 210, 20)) 
        return MARKET;
    else if (button_home(230, 1, 270, 20)) 
        return SEARCH;
    else if (button_home(600, 1, 630, 20)) 
        return EXIT;
    else if (button_home(130, 1, 160, 20)) 
        return STATUS;
    else if (button_home(295, 1, 325, 20)) 
        return NEWS;
    else 
        return NOBUT;

}

int page_status(const user_data* user, stock_data* stock) 
{

    int total;
    int i, j, k;
    enum page pattern = NOBUT;

    int* choice;
    {
        FILE* fp = open_file(user->name, CHOICE, "rb");;
        choice = safe_calloc(STOCK_NUM, sizeof(int));
        fseek(fp, sizeof(user_data), SEEK_SET);
        SAFE_READ(choice, sizeof(int), STOCK_NUM, fp);
        close_file(fp, user->name, ".cho");
    }

    clrmous(MouseX, MouseY);
    cleardevice();
    draw_status();

    total = 0;
    draw_choosed_stock(choice, &total);

    #if defined (DEBUG)
    {
        FILE* log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, "page_status funtion: \n");
        fprintf( log, "choice: \n");
        for( i=0; i<STOCK_NUM; i++ )
            fprintf( log, "%d ", choice[i]);
        fprintf( log ,"\ntotal:%d\n",total);
        close_file( log, "debug", ".log" );
    }
    #endif


    while (1)
    {
        int lastSecond = -1;  
        struct time currentTime;
        gettime(&currentTime);
        if (currentTime.ti_sec != lastSecond) 
        {
            updateTime();
            lastSecond = currentTime.ti_sec;
        }

        newmouse(&MouseX, &MouseY, &press);

        pattern = home_button();
        if( pattern != NOBUT )
        {
            delay( 1000 );
            free(choice);
            return pattern;
        }

        for( k=0; k<total; k++ )
        {
            if( button_simple( 10, 40 + k * 20, 160,  40 + (k+1) * 20 ) )
            {
                FILE* stockfp = open_file("main", STOCK, "rb");
                for (i = 0, j = 0; i < STOCK_NUM; i++)
                    if (choice[i] == 1 && ++j == k + 1)
                        break;
                fseek(stockfp, sizeof(stock_data) * i, SEEK_SET);
                SAFE_READ(stock, sizeof(stock_data), 1, stockfp);
                close_file(stockfp, "main", ".stock");

                #if defined (DEBUG)
                {
                    FILE* log = open_file( "debug", DEBUGLOG, "a" );
                    fprintf( log, "page_status funtion: \n");
                    fprintf( log, "%s choosed\n", stock->code);
                    fprintf(log, "name:%s", stock->name);
                    fprintf( log,"days:%d\n", stock->days );
                    fprintf( log,"weeks:%d\n", stock->weeks );
                    fprintf( log,"period_length:%d\n", stock->period_length );
                    fprintf( log,"period_num:%d\n", stock->period_num );
                    close_file( log, "debug", ".log" );
                }
                #endif

                free(choice);
                delay( 1000 );
                return INDICATOR;
            }
        }
        delay(20);
    }
}

void draw_choosed_stock(int* choice, int* total)
{

    int i,j;
    int num = 0;
    stock_data2 stock;
    FILE* stockfp = open_file("main", STOCK, "rb");
    fseek( stockfp, sizeof(stock_data)*STOCK_NUM , SEEK_SET );

    for (i = 0; i < STOCK_NUM; i++)
    {
        SAFE_READ(&stock, sizeof(stock_data2), 1, stockfp);

        if (choice[i] == 1)
        {
            enum COLORS color;
            char str[4][6] = { 0 };

            sprintf(str[0], "%.2f", stock.open);
            sprintf(str[1], "%.2f", stock.close);
            sprintf(str[2], "%.2f", stock.high);
            sprintf(str[3], "%.2f", stock.low);

            settextstyle(SMALL_FONT, HORIZ_DIR, 6);
            setcolor(YELLOW);
            outtextxy(10, 42 + num * 20, stock.code); 
            puthz(90, 44 + num * 20, stock.name, 16, 16, YELLOW);
            puthz(430, 44 + num * 20, stock.industry, 16, 16, YELLOW); 
            puthz(520, 44 + num * 20, stock.region, 16, 16, YELLOW); 
            outtextxy(235, 43 + num * 20, str[2]); 
            outtextxy(302, 43 + num * 20, str[3]); 

            if (stock.open >= stock.close) 
                color = RED;
            else 
                color = GREEN;
            
            setcolor(color);
            outtextxy(176, 43 + num * 20, str[0]); 
            outtextxy(368, 43 + num * 20, str[1]); 

            num++;

            #if defined (DEBUG)
            {
                FILE* log = open_file( "debug", DEBUGLOG, "a" );
                fprintf( log, "draw_choosed stock funtion: \n");
                fprintf( log, "%s choosed\n", stock.code);
                close_file( log, "debug", ".log" );
            }
            #endif

        }
    }
    *total = num;
    close_file(stockfp, "main", ".stock");
}
int new_position( day_price* kday_buffer, const rectangle_info* rectangle, const axis_data* axis, int mousex, int last_num )
{
	day_price info;
    int num = ROUND( (axis->x - mousex) / rectangle->gap );
    if( mousex > axis->x || num == 0 )
        num = 1;
    
    if( last_num == num )
        return num;
    setfillstyle(SOLID_FILL, 8);
    bar(298+95, 41, 500+95, 60);
    bar(298+95, 259, 500+95,278);//覆盖
	settextstyle(SMALL_FONT, HORIZ_DIR, 6);
	{
		char str[6];
        setcolor(WHITE);
		info = kday_buffer[rectangle->num-num];
        sprintf(str, "%.2f", info.close);
        outtextxy(450+95,40 ,str);

        sprintf(str, "%.2f", info.high);
        outtextxy(350+95,258 ,str);

        sprintf(str, "%.2f", info.low);
        outtextxy(450+95,258 ,str);

        sprintf(str, "%.2f", info.open);
        outtextxy(350+95,40 ,str);
    }

    puthz(300+95, 42, "开盘：", 16, 16, WHITE);
    puthz(300+95, 260, "最高：", 16, 16, WHITE);
    puthz(400+95, 260, "最低：", 16, 16, WHITE);
    puthz(400+95, 42, "收盘：", 16, 16, WHITE);
#if defined (DEBUG)
    {
        FILE* log = open_file("debug", DEBUGLOG, "a");
        fprintf(log, "new_position funtion: \n");
        fprintf(log, "%.2f %.2f %.2f %.2f : \n",info.open,info.high,info.low,info.close);
        close_file(log, "debug", ".log");
    }
#endif
    return num;
    
}
int page_indicator(const stock_data* stock, indicator_info* indicator)
{
    int lastSecond = -1;  
    int last_num;
    enum page pattern;
    enum bool notchange;
    rectangle_info rectangle;
    axis_data main_axis = { 600, 50, 220, 0, 0, 6 };
    axis_data sub_axis  = { 600, 290,180, 0, 0, 4 }; 
    day_price* kday_buffer;

    #if defined (DEBUG)
    {
        FILE* log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, "\npage_indicator funtion: \n");
        fprintf( log, "code:%s\n", stock->code);
        fprintf(log, "name:%s", stock->name);
        fprintf( log,"days:%d\n", stock->days );
        fprintf( log,"weeks:%d\n", stock->weeks );
        fprintf( log,"period_length:%d\n", stock->period_length );
        fprintf( log,"period_num:%d\n", stock->period_num );

        fprintf( log, "rectangle: \n");
        fprintf( log , "gap:%d num:%d width%d\n", rectangle.gap, rectangle.num, rectangle.width);

        fprintf( log, "main_line:%d\n", indicator->main_line);
        fprintf( log, "sub_line:%d\n", indicator->sub_line);
        fprintf( log, "gear:%d \n", indicator->gear);

        close_file( log, "debug", ".log" );
    }
    #endif

    {
        cleardevice();
        clrmous(MouseX, MouseY);
        draw_indicator( stock->code );
        choose_rectangle(&rectangle, indicator->gear);
        draw_line(stock, &rectangle, indicator->main_line, &main_axis);
        draw_line(stock, &rectangle, indicator->sub_line, &sub_axis);
        draw_mark(indicator->main_line);
        draw_mark(indicator->sub_line);
        #if defined (DEBUG)
        {
            FILE* log = open_file("debug", DEBUGLOG, "a");
            fprintf(log, "\npage_indicator funtion before puthz: \n");
            fprintf(log, "code:%s\n", stock->code);
            fprintf(log, "name:%s\n", stock->name);
            close_file(log, "debug", ".log");
        }
        #endif
        puthz(11, 41, stock->name, 16, 16, WHITE);
    }

    {
        long position = (stock->days - rectangle.num) * sizeof(day_price);
        FILE* fp = open_file( stock->code, KDAY, "rb" );
        fseek(fp, position, SEEK_SET);
        SAFE_READ( kday_buffer, sizeof(day_price), rectangle.num, fp );
        close_file( fp, stock->code, ".kday" );
    }

    while (1)
    {
        notchange = false;
        new_time( &lastSecond );
        newmouse(&MouseX, &MouseY, &press);
        last_num = new_position( kday_buffer, &rectangle, &main_axis, MouseX, last_num );

        pattern = home_button();
        if( pattern != NOBUT )
        {
            indicator->main_line = KDAY;
            indicator->sub_line = KDJ;
            indicator->gear = MEDIUM;
            delay( 1000 );
            return pattern;
        }

        if ( button_simple( 10,21,45,40 ) )
            indicator->main_line = KDAY;
        else if ( button_simple( 51,21,85,40 ) )
            indicator->main_line =  KWEEK;
        else if ( button_simple(95,21,145,40) )
            indicator->main_line = (indicator->main_line == MA)? KDAY : MA;
        else if ( button_simple( 155,21,230,40 ) )
            indicator->main_line = (indicator->main_line == EXPMA)? KDAY : EXPMA;   
        else if ( button_simple( 238,21,305,40 ) )
            indicator->main_line = (indicator->main_line == XUECHI)? KDAY : XUECHI;
        else if ( button_simple( 360,21,415,40 ) )
            indicator->sub_line = MACD;
        else if ( button_simple( 315,21,355,40 ) )
            indicator->sub_line = KDJ;
        else if( button_simple( 415,21,468,40 ) )
            indicator->sub_line = WILLIAMS;
        else
            notchange = true;

        if ( button_simple( 488,21,524,40 ) && indicator->gear < LARGE)
        {
            indicator->gear++;
            notchange = false;
        }
        else if ( button_simple( 527,21,564,40 ) && indicator->gear > SMALL)
        {
            indicator->gear--;
            notchange = false;
        } 

        if ( !notchange )
        {
           delay( 200 );
           return INDICATOR;
        }

        delay( 20 );
    }
}

int page_market(const user_data* user)
{
    int i, k;
    int lastSecond = -1;
    enum page pattern = NOBUT;
    enum bool breakloop = false;

    int* choice = safe_malloc( STOCK_NUM * sizeof(int) );
    {
        FILE* fp = open_file(user->name, CHOICE, "rb");
        fseek(fp, sizeof(user_data), SEEK_SET);
        SAFE_READ(choice, sizeof(int), STOCK_NUM, fp);
        close_file( fp, user->name, ".cho" );
    }

    #if defined (DEBUG)
    {
        int i;
        FILE* log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, "page_market function: \n");
        fprintf( log, "choice: \n");
        for( i=0; i<STOCK_NUM; i++ )
            fprintf( log, "%d ", choice[i]);
        close_file( log, "debug", ".log" );
    }
    #endif

    {
        cleardevice();
        clrmous(MouseX, MouseY);
        draw_market();
        setcolor(BLUE);
        for( i=0; i<STOCK_NUM; i++ )
        {
            if( choice[ i ] )
            {
                line(125, 51 + i * 20 , 130, 55 + i * 20 );
                line(130, 55 + i * 20 , 134, 47 + i * 20 );
            }
        }
    }
    
    while (!breakloop)
    {

        new_time( &lastSecond );
        newmouse(&MouseX, &MouseY, &press);

        pattern = home_button();
        if( pattern != NOBUT )
            break;

        for( k=0; k<STOCK_NUM; k++ )
        {
            if( button_simple( 125, 46 + k * 20, 135,  56 + k * 20 ) )
            {
                delay( 200 );
                choice[k] = (choice[k] == 0)? 1 : 0;
                breakloop = true;
                pattern = MARKET;
                break;
            } 
        }

        delay(20);
    }

    #if defined (DEBUG)
    {
        FILE* log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, "page_market function: \n");
        fprintf( log, "last choice: \n");
        for( i=0; i<STOCK_NUM; i++ )
            fprintf( log, "%d ", choice[i]);
        close_file( log, "debug", ".log" );
    }
    #endif

    {
        FILE* fp = open_file(user->name, CHOICE, "rb+");
        fseek(fp, sizeof(user_data), SEEK_SET);
        SAFE_WRITE(choice, sizeof(int), STOCK_NUM, fp);
        close_file(fp, user->name, ".choice");
    }

    free(choice);

    return pattern;
}

int page_predict( const stock_data* stock )
{
    int lastSecond = -1;
    enum page pattern = NOBUT;
    axis_data pred_axis = { 630, 210, 160, 0, 0, 5 }; 
    rectangle_info rectangle = { 5, 0, 35 };

    #if defined (DEBUG)
    {
        FILE* log;
        log = open_file( "debug", DEBUGLOG, "a" );
        fprintf( log, "page_predict function: \n");
        fprintf( log,"predict stock:%s\n", stock->code );
        fprintf( log,"days:%d\n", stock->days );
        fprintf( log,"weeks:%d\n", stock->weeks );
        fprintf( log,"period_length:%d\n", stock->period_length );
        fprintf( log,"period_num:%d\n", stock->period_num );
        close_file(log, "debug", ".log");
    }
    #endif
    
    {
        clrmous(MouseX, MouseY);
        cleardevice();
        draw_predict();
        draw_ar_pred( stock, &rectangle, &pred_axis);
        draw_gene_pred( stock->code);
        setcolor(LIGHTGREEN);
        settextstyle(SMALL_FONT, HORIZ_DIR, 6);
        outtextxy(87, 32, stock->code);
        puthz(85, 60, stock->name, 16, 16, LIGHTGREEN);
    }

    while (1)
    {
        new_time( &lastSecond );
        newmouse(&MouseX, &MouseY, &press);

        pattern = home_button();
        if (pattern != NOBUT) 
        {
            delay( 1000 );
            return pattern;
        }
        if (button_back(570, 30, 630, 60)) {
            return SEARCH;
        }
        delay(20);
    }
}


int page_search( stock_data* stock )
{
    char code[7];
    int lastSecond = -1;
    enum page pattern = NOBUT;
    enum bool check = false;

    {
        clrmous(MouseX, MouseY);
        cleardevice();
        draw_search();
    }

    while (1)
    {
        new_time( &lastSecond );
        newmouse(&MouseX, &MouseY, &press);

        pattern = home_button();
        if( pattern != NOBUT )
            return pattern;

        if( button_simple( 180, 190, 430, 270 ) )
        {
            memset(code, 0, 7);
            get_input( 190, 222, code, 7, 5 );
            check = true;
            #if defined (DEBUG)
            {
                FILE* log;
                log = open_file( "debug", DEBUGLOG, "a" );
                fprintf( log, "page_search function: \n");
                fprintf( log, " get input %s \n", code);
                close_file(log, "debug", ".log");
            }
            #endif
            {
                int i;
                FILE* stockfp = open_file("main", STOCK, "rb");
                for( i=0; i<STOCK_NUM; i++ )
                {
                    SAFE_READ( stock, sizeof(stock_data), 1, stockfp);
                    if( strcmp( stock->code, code ) == 0 )
                        break;
                }
                close_file(stockfp, "main", ".stock");
                if( i == STOCK_NUM )
                {
                    puthz( 200, 300, "抱歉，我们无此股票信息！", 16, 16, RED );
                    delay(1000);
                    return SEARCH;
                }
            }
        }
        if( button_simple( 431, 190, 480, 270 ) && check )
        {
            move_search();
            return PREDICT;
        }

        delay(20);
    }
}

int page_news( int* new_num )
{
    int i;
    int lastSecond = -1;
    enum page pattern = NOBUT;

    {
        clrmous(MouseX, MouseY);
        cleardevice();
        draw_news();
    }

    while (1)
    {
        new_time( &lastSecond );
        newmouse(&MouseX, &MouseY, &press);

        pattern = home_button();
        if (pattern != NOBUT) 
        {
            delay( 1000 );
            return pattern;
        }

        for (i = 0; i < 19; i++) 
        {
            if (button_back(16, 67 + 23 * i, 280, 87 + 23 * i))
            {
                delay( 200 );
                *new_num = i + 1;
                return NEWINFO;
            }
        }
        for (i = 19; i < 37; i++) 
        {
            if (button_back(336, 67 + 23 * (i - 19), 600, 87 + 23 * (i - 19))) 
            {
                delay( 200 );
                *new_num = i;
                return NEWINFO;
            }
        }

        delay(20);
    }
}

int page_newinfo( int new_num )
{
    int lastSecond = -1;
    enum page pattern = NOBUT;

    {
        cleardevice();
        clrmous(MouseX, MouseY);
        draw_newinfo( new_num);
    }

    while (1) 
    {
        new_time( &lastSecond );
        newmouse(&MouseX, &MouseY, &press);

        pattern = home_button();
        if (pattern != NOBUT) 
        {
            delay( 1000 );
            return pattern;
        }

        if (button_back(0, 23, 60, 53))
        {
            delay(200);
            return NEWS;
        }

        delay(20);
    }
}
