#pragma once

extern IMAGE imgbk, img01, img02, img03, img04, img05, img06;
extern IMAGE img0, img1, img2, img3, img4, img5;
extern IMAGE img15, img16, img40, img50;
extern IMAGE img20, img21, img22, img23, img24;
extern IMAGE imgmes1,imgmes2;

extern int map01[7][7];

//创建数组以便传值
void Create2(int map2[7][7])
{
    int i, j;
    for (i = 0;i < 7;i++)
    {
        for (j = 0;j < 7;j++)
        {
            map2[i][j] = map01[i][j];
        }
    }
}

//绘制第二关界面及地图
void DrawMap2(int map2[7][7])
{
    //用for循环遍历数组
    BeginBatchDraw();
    putimage(0, 0, &img02);
    
    for (int i = 0;i < 7;i++)
    {
        for (int j = 0;j < 7;j++)
        {
            switch (map2[i][j])
            {
            case 0:
                putimage((j + 3) * 40, (i + 2) * 40, &img0);
                break;
            case 40:
                putimage((j + 3) * 40, (i + 2) * 40, &img40);
                break;
            case 50:
				//空白墙50
                putimage((j + 3) * 40, (i + 2) * 40, &img50);
                break;
            case 20:
				//红色墙20
                putimage((j + 3) * 40, (i + 2) * 40, &img20);
                break;
            case 21:
				//紫色墙21
                putimage((j + 3) * 40, (i + 2) * 40, &img21);
                break;
            case 22:
				//浅蓝墙22
                putimage((j + 3) * 40, (i + 2) * 40, &img22);
                break;
            case 23:
				//蓝色墙23
                putimage((j + 3) * 40, (i + 2) * 40, &img23);
                break;
            case 3:
                putimage((j + 3) * 40, (i + 2) * 40, &img4);
                break;
            case 4:
                putimage((j + 3) * 40, (i + 2) * 40, &img2);
                break;
            case 5:
                putimage((j + 3) * 40, (i + 2) * 40, &img3);
                break;
            case 7:
				//箱子到达目的地 4+3=7
                putimage((j + 3) * 40, (i + 2) * 40, &img5);
                break;
            case 8:
				//人到达目的地 5+3=8
                putimage((j + 3) * 40, (i + 2) * 40, &img3);
                break;
            case 15:
				//可推动墙1
                putimage((j + 3) * 40, (i + 2) * 40, &img15);
                break;
            case 16:
				//可推动墙2
                putimage((j + 3) * 40, (i + 2) * 40, &img16);
                break;
            }
        }
    }
    settextcolor(RGB(0, 0, 0));
    settextstyle(25, 0, "宋体");
    outtextxy(30, 380, "墙被刷成");
    settextcolor(RGB(255, 0, 0));
    outtextxy(130, 380, "彩");
    settextcolor(RGB(0, 200, 255));
    outtextxy(155, 380, "色");
    settextcolor(RGB(0, 0, 0));
    outtextxy(180, 380, "了");
    outtextxy(30, 415, "难道只是变好看了?");
    putimage(0, 545, &img05);
    EndBatchDraw();
}

//进行游戏
int PlayGame2(int map2[7][7])
{
    //获取到当前的人的下标
    int row, col;//人的 行 和 列
    char x;//退出时y/n
    for (int i = 0;i < 7;i++)//控制变量 0-6
    {
        for (int j = 0;j < 7;j++)//控制变量0-9
        {
            if (map2[i][j] == 5 || map2[i][j] == 8)
            {
                row = i;//i 0-6
                col = j;//j 0-9
            }
        }
    }

    //胜利判定
    if (map2[3][1] == 7 && map2[4][1] == 7)
    {
        settextstyle(30, 0, "宋体");
        outtextxy(30, 450, "恭喜你!成功通过了第二关!");
        return 2;
    }

    //键盘来控制图形所对应的数据
    char input;//定义一个字符变量
    input = _getch();//接受键盘输入所对应的值
    //getch() 不显示回文，按下键盘马上接受
    switch (input)
    {
        /************************************
        人能走有哪些情况
        1.人的前面是空地
        2.人的前面是目的地
        3.人的前面是箱子且箱子地前面是空地
        4.人的前面是箱子且箱子的前面是目的地
		5.人的前面是绿色墙（该墙可推）且墙前面是空地
        *************************************/
    case 'w'://上
        if (map2[row - 1][col] == 0 || map2[row - 1][col] == 3)//如果人的前面是空地/目的地
        {

            map2[row][col] -= 5;//人的ID 5/8
            map2[row - 1][col] += 5;
        }
        else if (map2[row - 1][col] == 4 || map2[row - 1][col] == 7)//人的前面是箱子
        {
            if (map2[row - 2][col] == 0 || map2[row - 2][col] == 3)//箱子前面是空地/目的地
            {
                map2[row - 2][col] += 4;
                map2[row - 1][col] += 1;
                map2[row][col] -= 5;
            }

        }
        else if (map2[row - 1][col] == 15 && map2[row - 2][col] == 40)
        {
            map2[row][col] -= 5;
            map2[row - 1][col] = 5;
            map2[row - 2][col] = 15;
            if (map2[0][2] == 15)//增加新的围墙
            {
                map2[0][0] = 20;
                map2[0][1] = 21;
                map2[0][3] = 23;
                map2[0][4] = 20;
                map2[0][5] = 22;
                map2[0][6] = 21;
                map2[1][0] = 23;
                map2[1][6] = 20;
                map2[1][1] = 0;
                map2[1][3] = 0;
                map2[1][4] = 0;
                map2[1][5] = 0;
            }
        }
        break;
    case 'a'://左
        if (map2[row][col - 1] == 0 || map2[row][col - 1] == 3)//如果人的前面是空地/目的地
        {

            map2[row][col] -= 5;//人的ID 5/8
            map2[row][col - 1] += 5;
        }
        else if (map2[row][col - 1] == 4 || map2[row][col - 1] == 7)//人的前面是箱子
        {
            if (map2[row][col - 2] == 0 || map2[row][col - 2] == 3)//箱子前面是空地/目的地
            {
                map2[row][col - 2] += 4;
                map2[row][col - 1] += 1;
                map2[row][col] -= 5;
            }

        }
        break;
    case 's'://下
        if (map2[row + 1][col] == 0 || map2[row + 1][col] == 3)//如果人的前面是空地/目的地
        {

            map2[row][col] -= 5;//人的ID 5/8
            map2[row + 1][col] += 5;
        }
        else if (map2[row + 1][col] == 4 || map2[row + 1][col] == 7)//人的前面是箱子
        {
            if (map2[row + 2][col] == 0 || map2[row + 2][col] == 3)//箱子前面是空地/目的地
            {
                map2[row + 2][col] += 4;
                map2[row + 1][col] += 1;
                map2[row][col] -= 5;
            }

        }
        else if (map2[row + 1][col] == 16 && map2[row + 2][col] == 0)
        {
            map2[row][col] -= 5;
            map2[row + 1][col] = 5;
            map2[row + 2][col] = 16;
        }
        break;
    case 'd'://右
        if (map2[row][col + 1] == 0 || map2[row][col + 1] == 3)//如果人的前面是空地/目的地
        {

            map2[row][col] -= 5;//人的ID 5/8
            map2[row][col + 1] += 5;
        }
        else if (map2[row][col + 1] == 4 || map2[row][col + 1] == 7)//人的前面是箱子
        {
            if (map2[row][col + 2] == 0 || map2[row][col + 2] == 3)//箱子前面是空地/目的地
            {
                map2[row][col + 2] += 4;
                map2[row][col + 1] += 1;
                map2[row][col] -= 5;
            }

        }
        break;
    case 'q'://退出
        settextstyle(25, 0, "宋体");
        outtextxy(30, 450, "请问您确定要退出难度为非常简单的第二关吗?");
        settextstyle(25, 0, "宋体");
        outtextxy(30, 485, "请选择:(y/n)");
        x=_getch();
        if (x == 'y')
            return 1;
        break;
    case 'r'://重新开始本关
        return 3;
        break;
    }
    return 0;
}