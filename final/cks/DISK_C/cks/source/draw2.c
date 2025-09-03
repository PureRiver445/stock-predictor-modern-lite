#include "global.h"

#include "hzo.h"
#include "mouse.h"
#include "stock.h"
#include "draw2.h"


//锟斤拷印锟斤拷锟斤拷锟斤拷锟斤拷通锟斤拷锟斤拷
void draw_tongdaxin() {
    puthz(200, 40, "通", 48, 48, BLUE);

    setlinestyle(0, 0, 3);
    setcolor(BLUE);
    circle(300, 50, 2);
    floodfill(300, 50, BLUE);
    line(299, 50, 301, 50);
    line(373 - 80, 60, 379 - 80, 60);
    line(373 - 80, 61, 379 - 80, 61);
    circle(373 - 80, 60, 1);
    line(379 - 80, 59, 379 - 80, 82);
    line(380 - 80, 59, 380 - 80, 82);
    line(380 - 80, 82, 418 - 80, 82);
    line(380 - 80, 83, 418 - 80, 83);
    circle(418 - 80, 82, 1);
    line(389 - 80, 55, 415 - 80, 55);
    line(405 - 80, 60, 410 - 80, 75);
    line(410 - 80, 75, 420 - 80, 75);
    setcolor(RED);
    line(376 - 80, 86, 388 - 80, 76);
    line(375 - 80, 85, 387 - 80, 75);
    line(388 - 80, 76, 394 - 80, 76);
    line(387 - 80, 75, 394 - 80, 75);
    line(394 - 80, 76, 405 - 80, 42);
    line(403 - 80, 45, 399 - 80, 45);
    line(399 - 80, 45, 405 - 80, 42);
    line(400 - 80, 46, 398 - 80, 46);
    //锟斤拷锟斤拷

    puthz(400, 40, "信", 48, 48, BLUE);
}


//锟斤拷锟狡碉拷录锟斤拷锟斤拷
void draw_welcome()
{
    setbkcolor(WHITE);
    draw_tongdaxin();

    setcolor(LIGHTRED);
    rectangle(160, 230, 160 + 320, 230 + 32);
    rectangle(160, 278, 160 + 320, 278 + 32);

    setcolor(LIGHTGRAY);
    settextstyle(SMALL_FONT, HORIZ_DIR, 0);
    puthz(164, 160, "模拟股票行情预测系统", 32, 32, LIGHTCYAN);
    puthz(165, 240, "账户", 16, 16, LIGHTGRAY);
    outtextxy(200, 242, ":");
    puthz(165, 288, "密码", 16, 16, LIGHTGRAY);
    outtextxy(200, 290, ":");

    setfillstyle(SOLID_FILL, 8);
    bar(576, 432, 636, 462);
    puthz(584, 438, "退出", 24, 24, WHITE);

    bar(160, 342, 480, 374);
    puthz(294, 348, "登录", 16, 16, WHITE);


    bar(250, 380, 370, 415);
    puthz(278, 390, "注册账号", 16, 16, WHITE);
}

//锟斤拷锟斤拷注锟斤拷锟斤拷锟?
void draw_register()
{
    setbkcolor(WHITE);
    draw_tongdaxin();
    setcolor(LIGHTRED);

    rectangle(160, 230, 160 + 320, 230 + 32);
    rectangle(160, 278, 160 + 320, 278 + 32);

    setcolor(LIGHTGRAY);
    settextstyle(SMALL_FONT, HORIZ_DIR, 0);
    puthz(165, 240, "账户", 16, 16, LIGHTGRAY);
    outtextxy(200, 240, ":");
    puthz(165, 275 + 14, "密码", 16, 16, LIGHTGRAY);
    outtextxy(200, 289, ":");

    puthz(210, 140, "股市如战场", 16, 16, LIGHTGRAY);
    puthz(310, 140, "智者勇攀财富高峰", 16, 16, LIGHTGRAY);
    puthz(240, 188, "请注册账户", 32, 32, LIGHTCYAN);

    setfillstyle(SOLID_FILL, 8);
    bar(576, 432, 636, 462);
    puthz(585, 440, "返回", 24, 24, WHITE);

    bar(160, 278 + 64, 160 + 320, 278 + 64 + 32);
    puthz(295, 278 + 71, "注册", 16, 16, WHITE);
}



//锟斤拷锟斤拷锟斤拷锟剿碉拷锟斤拷
void draw_home()
{
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(0, 0, 640, 20);
    floodfill(2, 2, 1);
    puthz(10, 2, "通达信金融端", 16, 16, 8);
    puthz(130, 2, "行情", 16, 16, 8);
    puthz(180, 2, "市场", 16, 16, 8);
    puthz(230, 2, "问小达", 16, 16, 8);
    puthz(295, 2, "资讯", 16, 16, 8);
    setcolor(8);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    puthz(550, 2, "周四", 16, 16, 8);
    puthz(600, 2, "退出", 16, 16, 8);
}



//锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟?
void draw_status() {
    draw_home();
    setcolor(8);
    setfillstyle(SOLID_FILL, 8);
    rectangle(0, 22, 640, 480);
    floodfill(50, 50, 8);
    setcolor(RED);
    rectangle(0, 22, 640, 40);
    puthz(585, 22, "添加", 16, 16, LIGHTCYAN);
    setcolor(LIGHTCYAN);
    settextstyle(SMALL_FONT, HORIZ_DIR, 8);
    outtextxy(620, 14, "+");
    puthz(22, 22, "代码", 16, 16, LIGHTGRAY);
    puthz(104, 22, "名称", 16, 16, LIGHTGRAY);
    puthz(183, 22, "今开", 16, 16, LIGHTGRAY);
    puthz(242, 22, "最高", 16, 16, LIGHTGRAY);
    puthz(305, 22, "最低", 16, 16, LIGHTGRAY);
    puthz(372, 22, "昨收", 16, 16, LIGHTGRAY);
    puthz(430, 22, "细分行业", 16, 16, LIGHTGRAY);
    puthz(520, 22, "地区", 16, 16, LIGHTGRAY);
}


//锟斤拷锟斤拷锟叫筹拷锟斤拷锟斤拷
void draw_market() {

    int i,j,k;
    char temp[7];
    stock_data2 stock;
    FILE* fp = open_file("main", STOCK, "rb");
    fseek( fp, sizeof(stock_data)*STOCK_NUM, SEEK_SET);
    draw_home();

    //画框架
    setcolor(8);
    setfillstyle(SOLID_FILL, 8);
    rectangle(0, 22, 640, 480);
    floodfill(50, 70, 8);
    setcolor(RED);
    rectangle(0, 22, 320, 479);
    rectangle(0, 22, 639, 40);
    line(0, 242, 639, 242);
    line(0, 262, 639, 262);
    setcolor(8);
    line(0, 22, 640, 22);
    setcolor(RED);
    for( i=0 ; i<STOCK_NUM ; i++ )
    {
        SAFE_READ( &stock, sizeof(stock_data2), 1, fp);
        #if defined( DEBUG )
        {
            FILE* log = open_file( "debug", DEBUGLOG, "a" );
            fprintf( log, "%s read\n", stock.code);
            fprintf( log, "name:%s\n", stock.name);
            close_file( log, "debug", ".log" );
        }
        #endif
        puthz(10, 40+i*20, stock.name, 16, 16, YELLOW);
        /*sprintf(temp, "%.2f", stock.rate);
        puthz(180, 40+i*20, temp, 16, 16, YELLOW);
        sprintf(temp, "%.2f", stock.fu);
        puthz(240, 40+i*20, temp, 16, 16, YELLOW);*/
        setcolor(RED);
        settextstyle(SMALL_FONT, HORIZ_DIR, 6);
        outtextxy(190,40+i*20,stock.rate);
        outtextxy(265,40+i*20,stock.fu);        
    }
    close_file(fp, "main", "stock");

    puthz(10, 23, "精选股票", 16, 16, LIGHTGRAY);
    puthz(100, 23, "添加自选", 16, 16, LIGHTGRAY);
    puthz(190, 23, "涨跌速", 16, 16, LIGHTGRAY);
    puthz(265, 23, "涨跌幅", 16, 16, LIGHTGRAY);

    puthz(330, 23, "深证", 16, 16, LIGHTGRAY);
    settextstyle(SMALL_FONT, HORIZ_DIR, 6);
    setcolor(LIGHTGRAY);
    outtextxy(365, 21, "A");
    puthz(374, 23, "股", 16, 16, LIGHTGRAY);
    puthz(420, 23, "添加自选", 16, 16, LIGHTGRAY);
    puthz(420, 220 + 23, "添加自选", 16, 16, LIGHTGRAY);
    puthz(515, 23, "涨速", 16, 16, LIGHTGRAY);
    puthz(515, 220 + 23, "涨速", 16, 16, LIGHTGRAY);
    puthz(595, 23, "涨幅", 16, 16, LIGHTGRAY);
    puthz(595, 220 + 23, "涨幅", 16, 16, LIGHTGRAY);

    puthz(10, 243, "沪深", 16, 16, LIGHTGRAY);//220，320
    settextstyle(SMALL_FONT, HORIZ_DIR, 6);
    setcolor(LIGHTGRAY);
    outtextxy(45, 241, "A");
    puthz(54, 243, "股", 16, 16, LIGHTGRAY);
    puthz(100, 243, "添加自选", 16, 16, LIGHTGRAY);
    puthz(200, 243, "跌速", 16, 16, LIGHTGRAY);
    puthz(275, 243, "跌幅", 16, 16, LIGHTGRAY);

    //上证A股
    puthz(330, 243, "上证", 16, 16, LIGHTGRAY);//220，320
    settextstyle(SMALL_FONT, HORIZ_DIR, 6);
    setcolor(LIGHTGRAY);
    outtextxy(365, 241, "A");
    puthz(374, 243, "股", 16, 16, LIGHTGRAY);


    puthz(10, 263, "碧兴物联", 16, 16, YELLOW);
    puthz(10, 283, "华贸物流", 16, 16, YELLOW);
    puthz(10, 303, "中原家具", 16, 16, YELLOW);
    puthz(10, 323, "新赛股份", 16, 16, YELLOW);
    puthz(10, 343, "连云港", 16, 16, YELLOW);
    puthz(10, 363, "华纺股份", 16, 16, YELLOW);
    puthz(10, 383, "力源科技", 16, 16, YELLOW);
    puthz(10, 403, "智洋创新", 16, 16, YELLOW);
    puthz(10, 423, "世华科技", 16, 16, YELLOW);
    puthz(10, 443, "灿勤科技", 16, 16, YELLOW);
    puthz(10, 463, "铭科精技", 16, 16, YELLOW);

    //深证A股
    puthz(330, 43, "达利凯普", 16, 16, YELLOW);
    puthz(330, 63, "硕贝德", 16, 16, YELLOW);
    puthz(330, 83, "新城市", 16, 16, YELLOW);
    puthz(330, 103, "慧瀚股份", 16, 16, YELLOW);
    puthz(330, 123, "金凯生科", 16, 16, YELLOW);
    puthz(330, 143, "兴源环境", 16, 16, YELLOW);
    puthz(330, 163, "矽电股份", 16, 16, YELLOW);
    puthz(330, 183, "澄天伟业", 16, 16, YELLOW);
    puthz(330, 203, "拓维信息", 16, 16, YELLOW);
    puthz(330, 223, "凯莱英", 16, 16, YELLOW);

    puthz(330, 263, "飞力达", 16, 16, YELLOW);
    puthz(330, 283, "三态股份", 16, 16, YELLOW);
    puthz(330, 303, "华融化学", 16, 16, YELLOW);
    puthz(330, 323, "飞沃科技", 16, 16, YELLOW);
    puthz(330, 343, "安居宝", 16, 16, YELLOW);
    puthz(330, 363, "怡达股份", 16, 16, YELLOW);
    puthz(330, 383, "南京港", 16, 16, YELLOW);
    puthz(330, 403, "吉峰科技", 16, 16, YELLOW);
    puthz(330, 423, "南方精工", 16, 16, YELLOW);
    puthz(330, 443, "名雕股份", 16, 16, YELLOW);
    puthz(330, 463, "中南传媒", 16, 16, YELLOW);

    setfillstyle(SOLID_FILL, WHITE);
    for (i = 0; i < 10; i++) {
        bar(125, 46 + 20 * i, 135, 56 + 20 * i);
    }
    for (i = 11; i < 22; i++) {
        bar(125, 46 + 20 * i, 135, 56 + 20 * i);
    }
    for (i = 0; i < 10; i++) {
        bar(445, 46 + 20 * i, 455, 56 + 20 * i);
    }
    for (i = 11; i < 22; i++) {
        bar(445, 46 + 20 * i, 455, 56 + 20 * i);
    }

    setcolor(RED);
    settextstyle(SMALL_FONT, HORIZ_DIR, 6);

    //锟斤拷证指锟斤拷锟斤拷锟斤拷
    outtextxy(512, 41, "1.86%");
    outtextxy(512, 61, "1.65%");
    outtextxy(512, 81, "1.60%");
    outtextxy(512, 101, "1.52%");
    outtextxy(512, 121, "1.49%");
    outtextxy(512, 141, "1.43%");
    outtextxy(512, 161, "1.40%");
    outtextxy(512, 181, "1.38%");
    outtextxy(512, 201, "1.35%");
    outtextxy(512, 221, "1.30%");

    //锟斤拷证指锟斤拷锟角凤拷
    outtextxy(583, 41, "20.02%");
    outtextxy(583, 61, "20.02%");
    outtextxy(583, 81, "12.68%");
    outtextxy(583, 101, "10.10%");
    outtextxy(583, 121, "10.05%");
    outtextxy(589, 141, "8.79%");
    outtextxy(589, 161, "8.65%");
    outtextxy(589, 181, "8.34%");
    outtextxy(589, 201, "8.01%");
    outtextxy(589, 221, "7.56%");


    setcolor(GREEN);
    outtextxy(188, 261, "-8.76%");
    outtextxy(188, 281, "-1.77%");
    outtextxy(188, 301, "-1.22%");
    outtextxy(188, 321, "-1.08%");
    outtextxy(188, 341, "-1.07%");
    outtextxy(188, 361, "-1.05%");
    outtextxy(188, 381, "-1.01%");
    outtextxy(188, 401, "-0.95%");
    outtextxy(188, 421, "-0.92%");
    outtextxy(188, 441, "-0.91%");
    outtextxy(188, 461, "-0.85%");

    //锟斤拷证指锟斤拷锟斤拷锟斤拷
    outtextxy(255, 261, "-10.88%");
    outtextxy(255, 281, "-10.05%");
    outtextxy(255, 301, "-10.03%");
    outtextxy(255, 321, "-10.03%");
    outtextxy(255, 341, "-10.02%");
    outtextxy(255, 361, "-10.00%");
    outtextxy(260, 381, "-9.85%");
    outtextxy(260, 401, "-9.82%");
    outtextxy(260, 421, "-9.76%");
    outtextxy(260, 441, "-9.72%");
    outtextxy(260, 461, "-9.67%");

    //锟斤拷证指锟斤拷锟斤拷锟斤拷
    setcolor(RED);
    outtextxy(512, 261, "1.99%");
    outtextxy(512, 281, "1.90%");
    outtextxy(512, 301, "1.60%");
    outtextxy(512, 321, "1.42%");
    outtextxy(512, 341, "1.26%");
    outtextxy(512, 361, "1.21%");
    outtextxy(512, 381, "1.13%");
    outtextxy(512, 401, "1.10%");
    outtextxy(512, 421, "0.95%");
    outtextxy(512, 441, "0.94%");
    outtextxy(512, 461, "0.89%");

    //锟斤拷证指锟斤拷锟斤拷锟斤拷
    outtextxy(583, 261, "19.57%");
    outtextxy(583, 281, "13.42%");
    outtextxy(583, 301, "12.38%");
    outtextxy(583, 321, "11.90%");
    outtextxy(583, 341, "11.81%");
    outtextxy(583, 361, "11.15%");
    outtextxy(583, 381, "10.93%");
    outtextxy(583, 401, "10.87%");
    outtextxy(583, 421, "10.26%");
    outtextxy(589, 441, "9.98%");
    outtextxy(589, 461, "9.95%");

}

void draw_indicator(char* code) {

    int i;
    draw_home();
    setcolor(8);
    rectangle(0, 21, 639, 479);
    setfillstyle(SOLID_FILL, 8);
    floodfill(50, 50, 8);
    setcolor(LIGHTRED);
    rectangle(0, 21, 639, 40);
    rectangle(0, 40, 600, 280);
    rectangle(0, 280, 600, 479);
    rectangle(600, 40, 639, 280);
    rectangle(600, 280, 639, 479);
    setcolor(8);
    line(0, 21, 639, 21);
    setcolor(LIGHTRED);

    puthz(10, 21, "日线", 16, 16, WHITE);
    puthz(50, 21, "周线", 16, 16, WHITE);
    setcolor(LIGHTCYAN);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(95, 21, "MA");
    puthz(110, 21, "均线", 16, 16, LIGHTCYAN);
    outtextxy(155, 21, "EXPMA");
    puthz(195, 21, "均线", 16, 16, LIGHTCYAN);
    puthz(238, 21, "薛斯通道", 16, 16, LIGHTCYAN);
    setcolor(YELLOW);
    settextstyle(SMALL_FONT, HORIZ_DIR, 7);
    outtextxy(315, 18, "KDJ");
    outtextxy(360, 18, "MACD");
    puthz(417, 21, "威廉指标", 16, 16, YELLOW);

    puthz(490, 21, "放大", 16, 16, LIGHTGREEN);
    puthz(529, 21, "缩小", 16, 16, LIGHTGREEN);

    settextstyle(SMALL_FONT, HORIZ_DIR, 7);
    setcolor(LIGHTMAGENTA);
    outtextxy(566, 19, code);
}


//锟斤拷锟斤拷锟斤拷锟斤拷锟街★拷锟斤拷小锟斤”
void draw_wenxiaoda() {

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(LIGHTGRAY);
    rectangle(0, 22, 640, 480);
    floodfill(50, 50, LIGHTGRAY);//锟斤拷锟矫憋拷锟斤拷锟斤拷色

    setcolor(BLUE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    circle(250, 64, 20);
    setcolor(LIGHTGRAY);
    rectangle(237, 74, 263, 89);
    floodfill(250, 84, LIGHTGRAY);
    rectangle(246, 40, 249, 46);
    floodfill(248, 43, LIGHTGRAY);
    rectangle(233, 52, 237, 47);
    floodfill(235, 49, LIGHTGRAY);
    setcolor(BLUE);
    circle(250, 64, 9);
    setlinestyle(0, 0, 3);
    line(257, 70, 263, 79);
    line(263, 79, 264, 78);
    //锟斤拷锟斤拷锟绞★拷

    puthz(300, 40, "小", 48, 48, BLUE);

    circle(380, 50, 1);
    floodfill(380, 50, BLUE);
    line(379, 50, 381, 50);
    line(373, 60, 379, 60);
    line(373, 61, 379, 61);
    circle(373, 60, 1);
    line(379, 59, 379, 82);
    line(380, 59, 380, 82);
    line(380, 82, 418, 82);
    line(380, 83, 418, 83);
    circle(418, 82, 1);
    line(389, 55, 415, 55);
    line(405, 60, 410, 75);
    line(410, 75, 420, 75);
    setcolor(RED);
    line(376, 86, 388, 76);
    line(375, 85, 387, 75);
    line(388, 76, 394, 76);
    line(387, 75, 394, 75);
    line(394, 76, 405, 42);
    line(403, 45, 399, 45);
    line(399, 45, 405, 42);
    line(400, 46, 398, 46);
    //锟斤拷锟斤拷锟斤”

    puthz(210, 110, "智能投资顾问", 16, 16, 14);
    puthz(320, 110, "开启财富新航线", 16, 16, 14);

}


//锟斤拷锟斤拷锟斤拷小锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷
void draw_search() {
    draw_home();
    draw_wenxiaoda();

    setcolor(RED);
    circle(180, 230, 40);
    setcolor(LIGHTGRAY);
    bar(180, 190, 450, 270);
    setcolor(RED);
    rectangle(180, 190, 430, 270);
    setcolor(LIGHTGRAY);
    line(180, 192, 180, 268);
    setcolor(BLUE);
    rectangle(431, 190, 480, 270);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(450, 200, BLUE);
    circle(480, 230, 40);
    floodfill(483, 230, BLUE);
    setcolor(WHITE);
    circle(465, 225, 18);
    line(478, 238, 488, 248);
    puthz(181, 220, "请输入股票代码", 16, 16, 8);
    setfillstyle(SOLID_FILL, 15);
    floodfill(181, 220, RED);
}





void draw_predict() {

    int i;
    draw_home();
    draw_wenxiaoda();

    puthz(10, 35, "股票代码", 16, 16, LIGHTGREEN);//代码坐标：（87，32）字体6号
    setcolor(LIGHTGREEN);
    settextstyle(SMALL_FONT, HORIZ_DIR, 6);
    outtextxy(78, 32, ":");
    outtextxy(78, 57, ":");
    puthz(10, 60, "股票名称", 16, 16, LIGHTGREEN);//名称坐标：（85，60）字体16号


    //画左侧指标表格
    puthz(52, 100, "由遗传算法", 16, 16, 8);
    puthz(29, 120, "确定的最佳权重表", 16, 16, 8);

    setcolor(8);
    setlinestyle(0, 0, 1);
    rectangle(10, 145, 180, 428);
    line(95, 145, 95, 428);
    line(10, 175, 180, 175);
    line(10, 215, 180, 215);
    line(10, 257, 180, 257);
    line(10, 283, 180, 283);
    line(10, 322, 180, 322);
    line(10, 362, 180, 362);
    line(10, 390, 180, 390);

    //画虚线
    setcolor(8);
    setlinestyle(1, 0, 1);
    line(195, 145, 195, 390);
    setlinestyle(0, 0, 1);

    setcolor(8);
    puthz(34, 153, "指标", 16, 16, 8);

    settextstyle(SMALL_FONT, HORIZ_DIR, 6);
    outtextxy(49, 191, "/");
    outtextxy(49, 233, "/");
    outtextxy(49, 298, "/");
    outtextxy(49, 410, "/");
    settextstyle(SMALL_FONT, HORIZ_DIR, 7);

    outtextxy(40, 175, "MA");
    puthz(17, 195, "金叉", 16, 16, 8);
    puthz(57, 195, "死叉", 16, 16, 8);
    settextstyle(SMALL_FONT, HORIZ_DIR, 7);

    outtextxy(25, 215, "EXPMA");
    puthz(17, 237, "金叉", 16, 16, 8);
    puthz(57, 237, "死叉", 16, 16, 8);

    puthz(21, 262, "薛氏突破", 16, 16, 8);
    outtextxy(35, 282, "KDJ");
    puthz(17, 302, "超买", 16, 16, 8);
    puthz(57, 302, "超卖", 16, 16, 8);

    outtextxy(30, 321, "MACD");
    puthz(21, 343, "极性变化", 16, 16, 8);

    puthz(14, 367, "收盘价惯性", 16, 16, 8);
    puthz(119, 153 , "权重", 16, 16, 8);

    puthz(34, 393, "威廉", 16, 16, 8);
    puthz(17, 410, "超买", 16, 16, 8);
    puthz(57, 410, "超卖", 16, 16, 8);

    /*
    setcolor(MAGENTA);
    settextstyle(3, 0, 1);
    MA:(121,183)
    EXPMA(112,225)
    薛氏(112,258)
    KDJ(112,290)
    MACD(112,330)
    惯性(112,364)
    settextstyle(SMALL_FONT, HORIZ_DIR, 8);
    puthz(5, 400+10, "上涨概率：", 24, 24, LIGHTCYAN);
    outtextxy(112, 364, "36.1%");
    */

    //画右侧坐标轴
    puthz(440 + 3, 300 - 60 - 83, "基于", 16, 16, 8);
    setcolor(8);
    settextstyle(SMALL_FONT, HORIZ_DIR, 7);
    outtextxy(472 + 3, 298 - 60 - 86, "AR");
    puthz(495 + 3, 300 - 60 - 83, "模型的价格预测图", 16, 16, 8);

    //横轴195,竖轴180,原点(630,390)
    line(630, 210, 630, 390);
    line(630, 390, 435, 390);
    line(630, 210, 625, 220);
    line(630, 210, 635, 220);
    line(435, 390, 445, 385);
    line(435, 390, 445, 395);


    //画右侧时间价格表格
    puthz(253, 153, "过去", 16, 16, 8);
    outtextxy(285, 148, "2");
    puthz(295, 153, "天与未来", 16, 16, 8);
    outtextxy(359, 148, "3");
    puthz(369, 153, "天", 16, 16, 8);
    puthz(271, 177, "日期", 16, 16, 8);
    outtextxy(303, 172, "--");
    puthz(323, 177, "股价表", 16, 16, 8);
    puthz(248, 215, "日期", 16, 16, 8);
    puthz(349, 215, "价格", 16, 16, 8);

    rectangle(215, 205, 413, 390);
    line(319, 205, 319, 390);
    for (i = 0; i < 5; i++) {
        line(215, 240 + 30 * i, 413, 240 + 30 * i);
    }
    //第一行：日期坐标（224，246），价格坐标（339，246），RMB坐标（389，248），每行y递增30，六号字体

    puthz(10 + 200, 400 + 24, "通达信提醒您", 16, 16, 8);
    setcolor(8);
    settextstyle(SMALL_FONT, HORIZ_DIR, 6);
    outtextxy(110 + 200, 398 + 24, ":");
    puthz(10 + 200, 425 + 24, "本系统预测结果仅供参考，股市有风险，投资需谨慎！", 16, 16, 8);

    setfillstyle(SOLID_FILL, 8);
    bar(570, 30, 630, 60);
    puthz(576, 33, "返回", 24, 24, WHITE);


}


//锟斤拷锟斤拷锟斤拷讯锟斤拷锟斤拷
void draw_news() 
{
    int i;
    char temp[3];

    draw_home();
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(0, 22, 640, 480);
    floodfill(50, 50, 8);
   
    setcolor(RED);
    line(0, 22, 640, 22);
    rectangle(3, 28, 6, 31);
    rectangle(9, 28, 12, 31);
    rectangle(3, 34, 6, 37);
    setfillstyle(SOLID_FILL, RED);
    bar(9, 34, 12, 37);
    puthz(16, 25, "财经新闻", 16, 16, RED);

    line(0, 44, 640, 44);
    puthz(16, 48, "国际财经", 16, 16, LIGHTGREEN);
    line(310, 44, 310, 480);
    puthz(336, 48, "国内财经", 16, 16, LIGHTGREEN);

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);

    for (i = 1; i < 19; i++) 
    {
        char str[50];
        FILE* fp = open_file( itoa(i, temp, 10), NEWSFILE,"r");
        fgets(str, 25, fp);
        close_file( fp, "whocares",".whocares");

        circle(8, 75 + 23 * (i - 1), 2);
        floodfill(8, 75 + 23 * (i - 1), BLUE);
        puthz(16, 67 + 23 * (i - 1), str, 16, 16, 8);
        outtextxy(215, 69 + 23 * (i - 1), "...");
    }

    for (i = 19; i < 37; i++) 
    {
        char str[50];
        FILE* fp = open_file( itoa(i, temp, 10), NEWSFILE,"r");
        fgets(str, 25, fp);
        close_file( fp, "whocares",".whocares");
        fgets(str, 25, fp);
        fclose(fp);

        circle(328, 75 + 23 * (i - 19), 2);
        floodfill(328, 75 + 23 * (i - 19), BLUE);
        puthz(336, 67 + 23 * (i - 19), str, 16, 16, 8);
        outtextxy(536, 69 + 23 * (i - 19), "...");
    }
}


void draw_newinfo(int num) 
{
    char temp[5];
    char str[800];

    draw_home();
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(0, 22, 640, 480);
    floodfill(50, 50, 8);

    setfillstyle(SOLID_FILL, BLUE); 
    bar(0, 23, 60, 53);
    puthz(13, 29, "返回", 16,16, LIGHTGREEN);
    {
        FILE* fp = open_file( itoa(num, temp, 10), NEWSFILE,"r");
        fgets(str, sizeof(str), fp);
        puthz(65, 30, str, 16, 16, 8);
        close_file( fp, ".whocares",".whocares");
    }
}