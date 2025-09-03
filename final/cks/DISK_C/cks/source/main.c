#include "global.h"
//#pragma pack(1) 
//#define DEVELOPER

int main(void)
{
    {
        float dummy = sin(0.0);
       // load();
    }
    {
        int i;
        FILE* stockfp;
        stock_data2 stock;
        stockfp = open_file("main", STOCK, "rb");
        fseek( stockfp, sizeof(stock_data)*STOCK_NUM , SEEK_SET );
        for ( i = 0; i < STOCK_NUM; i++)
        {
            SAFE_READ(&stock, sizeof(stock_data2), 1, stockfp);
            printf( "%s\n", stock.code );
            printf( "%d read\n", i+1 );
        }
        close_file(stockfp, "main", ".stock");
        printf( "data prepared\n");
        printf( "press any key to continue\n");
        getchar();
    }
    {
        #if defined (DEBUG)
        {
            int i;
            FILE* stockfp;
            FILE* log;
            stock_data stock;
            stockfp = open_file("main", STOCK, "rb");
            log = open_file( "debug", DEBUGLOG, "a" );
            fprintf( log, "main function: \n");
            for ( i = 0; i < STOCK_NUM; i++)
            {
                SAFE_READ(&stock, sizeof(stock_data), 1, stockfp);
                fprintf( log,"%s:\n ", stock.code );
                fprintf(log, "name:%s\n", stock.name);
                fprintf( log,"days:%d\n", stock.days );
                fprintf( log,"weeks:%d\n", stock.weeks );
                fprintf( log,"period_length:%d\n", stock.period_length );
                fprintf( log,"period_num:%d\n", stock.period_num );
            }
            close_file(stockfp, "main", ".stock");
            close_file(log, "debug", ".log");
        }
        #endif
    }
    {
        int gd = VGA;
        int gm = VGAHI;
        initgraph(&gd, &gm, "C:\\borlandc\\BGI");
        mouseinit();
    }
    {
        int new_num = 0;
        user_data user;
        stock_data stock;
        enum page pattern = WELCOME;
        indicator_info indicator = { KDAY, KDJ, MEDIUM };

        memset(user.name, 0, sizeof(user.name));
        memset(user.password, 0, sizeof(user.password));
        #if defined( DEVELOPER )
        {
            strcpy( user.name, "123456" );
            strcpy( user.password, "123456" );
            pattern = STATUS;
        }
        #endif

        while (1)
        {

            switch (pattern)
            {
            case WELCOME:
                pattern = page_welcome(&user);
                break;
            case REGISTER:
                pattern = page_register(&user);
                break;
            case INDICATOR:
                pattern = page_indicator(&stock,&indicator);
                break;
            case STATUS:
                pattern = page_status(&user, &stock);
                break;
            case MARKET:
                pattern = page_market(&user);
                break;
            case SEARCH:
                pattern = page_search(&stock);
                break;
            case PREDICT:
                pattern = page_predict(&stock);
                break;
            case NEWS:
                pattern = page_news( &new_num );
                break;
            case NEWINFO:
                pattern = page_newinfo( new_num );
                break;
            case EXIT:
                cleardevice();
                puthz(220, 225, "感谢您使用通达信，再见", 16, 16, LIGHTRED);
                delay(1500);
                closegraph();
                exit(EXIT_SUCCESS);
                return 0;
            }
        }
    }
}