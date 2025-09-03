#include "global.h"

void get_input(int x, int y, char* str, int max, int min)
{
    unsigned int ch;
    unsigned char ascii, scancode;
    char temp[2] = { 0 };
    int index = 0;

    setfillstyle(SOLID_FILL, WHITE);
    bar( x, y, x + 10 * 10, y + 15);
    clrmous(MouseX, MouseY);
    setcolor(DARKGRAY);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    moveto(x, y);

    while (1)
    {
        // 显示竖线
        int cursor_x = x + index * CHAR_WIDTH;
        setcolor(8);  // 可以根据需要修改竖线颜色
        line(cursor_x, y-3, cursor_x, y + CHAR_HEIGHT-3);

        while (!bioskey(1))
            continue;

        // 清除竖线
        setfillstyle(SOLID_FILL, WHITE);
        bar(cursor_x, y-3, cursor_x + 1, y + CHAR_HEIGHT);

        ch = bioskey(0);
        ascii = (unsigned char)(ch & 0xFF);
        scancode = (unsigned char)(ch >> 8);

        if (scancode == BACKSPACE)
        {
            if (index == 0)
                continue;

            str[--index] = 0;
            erase_char(x, y, index);
        }
        else if (ascii == ENTER)
        {
            if (index > min)
                break;
        }
        else if (isalnum(ascii))
        {
            if (index == max - 1)
                continue;

            temp[0] = (char)ascii;
            str[index++] = (char)ascii;
            outtext(temp);
        }
    }
    str[index] = 0;
    // 最后清除竖线
    {
        int cursor_x = x + index * CHAR_WIDTH;
        setfillstyle(SOLID_FILL, WHITE);
        bar(cursor_x, y-3, cursor_x + 1, y + CHAR_HEIGHT);
    }
}

static void erase_char(int x, int y, int index)
{
    x += index * CHAR_WIDTH;

    setfillstyle(SOLID_FILL, WHITE);
    bar(x, y, x + CHAR_WIDTH, y + CHAR_HEIGHT);

    moveto(x, y);
}

enum bool check_info(const user_data* user)
{
    char filename[FILE_LEN];
    FILE* fp;
    user_data temp;
    enum bool flag = false;

    strcpy(filename, DIRECTORY);
    strcat(filename, user->name);
    strcat(filename, ".cho");

    fp = fopen( filename, "rb");
    if (fp != NULL)
    {
        SAFE_READ(&temp, sizeof(user_data), 1, fp);
        if (strcmp(user->password, temp.password) == 0)
            flag = true;
        close_file(fp, user->name, ".cho");
    }
    return flag;
}

enum bool save_account(const user_data* user)//
{
    FILE* fp;
    int* choice;

    {
        char filename[FILE_LEN];
        strcpy( filename, DIRECTORY);
        strcat( filename, user->name);
        strcat( filename, ".cho");

        fp = fopen( filename, "rb");
        if( fp != NULL )
        {
            fclose( fp );
            return false;     
        }
    }

    fp = open_file(user->name, CHOICE, "wb");
    choice = safe_calloc(STOCK_NUM, sizeof(int));
    SAFE_WRITE(user, sizeof(user_data), 1, fp);
    SAFE_WRITE(choice, sizeof(int), STOCK_NUM, fp);
    close_file(fp, user->name, ".cho");
    free( choice );

    return true;
}
