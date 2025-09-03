#include "global.h"

void move_search( void )
{
	int i;
	clrmous( MouseX, MouseY);
	cleardevice();
	setbkcolor(WHITE);

	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(230, 160, 410, 260);
	puthz(248, 190, "分析预测中，请稍后", 16, 16, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar(280, 230, 360, 240);
	setfillstyle(SOLID_FILL, 8);
	puthz(185, 120, "财富的列车正在启动，用智慧开启财富大门！", 16, 16, 8);

	for (i = 0; i < 21; i++) {
		setcolor(BLUE);
		circle(70 + i * 25, 60, 20);
		line(80 + i * 25, 76, 90 + i * 25, 92);

		setcolor(LIGHTRED);
		circle(570 - i * 25, 360, 20);
		line(580 - i * 25, 376, 590 - i * 25, 392);

		setcolor(LIGHTMAGENTA);
		circle(70 , 360-14*i, 20);
		line(80 , 376-14*i, 90 , 392-14*i);

		setcolor(LIGHTCYAN);
		circle(570, 60 + 14 * i, 20);
		line(580, 76+14*i, 590, 92+14*i);
		bar(280, 230, 280 + i * 4, 240);
		
		delay(450);

		setcolor(WHITE);
		circle(70 + i * 25, 60, 20);
		line(80 + i * 25, 76, 90 + i * 25, 92);
		circle(570 - i * 25, 360, 20);
		line(580 - i * 25, 376, 590 - i * 25, 392);
		circle(70, 360 - 14 * i, 20);
		line(80, 376 - 14 * i, 90, 392 - 14 * i);
		circle(570, 60 + 14 * i, 20);
		line(580, 76 + 14 * i, 590, 92 + 14 * i);
	}		
}

// 更新时间显示
void updateTime( void ) {
	struct time t;
	char str[sizeof("00:00:00") + 1] = "";  // 初始化为空字符串

	gettime(&t);

	// 格式化小时
	if (t.ti_hour < 10) {
		str[0] = '0';
		str[1] = t.ti_hour + '0';
	}
	else {
		str[0] = t.ti_hour / 10 + '0';
		str[1] = t.ti_hour % 10 + '0';
	}
	str[2] = ':';

	// 格式化分钟
	if (t.ti_min < 10) {
		str[3] = '0';
		str[4] = t.ti_min + '0';
	}
	else {
		str[3] = t.ti_min / 10 + '0';
		str[4] = t.ti_min % 10 + '0';
	}
	str[5] = ':';

	// 格式化秒
	if (t.ti_sec < 10) {
		str[6] = '0';
		str[7] = t.ti_sec + '0';
	}
	else {
		str[6] = t.ti_sec / 10 + '0';
		str[7] = t.ti_sec % 10 + '0';
	}
	str[8] = '\0';

	//输出
	setfillstyle(SOLID_FILL, WHITE);
	bar(460, 0, 535, 20);
	setcolor(8);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(470, 2, str);
}