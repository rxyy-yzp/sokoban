#pragma once

extern IMAGE imgbk, img01, img02, img03, img04, img05, img06;
extern IMAGE img0, img1, img2, img3, img4, img5;
extern IMAGE img15, img16, img40, img50;
extern IMAGE img20, img21, img22, img23, img24;
extern IMAGE imgmes1,imgmes2;

extern int map00[7][10];

//创建数组以便传值
void Create1(int map1[7][10])
{
    int i, j;
    for (i = 0;i < 7;i++)
    {
        for (j = 0;j < 10;j++)
        {
            map1[i][j] = map00[i][j];
        }
    }
}

//绘制第一关界面及地图
void DrawMap1(int map1[7][10])
{   
    /*用for循环遍历数组*/
    BeginBatchDraw();
    putimage(0, 0, &img01);   

    for (int i = 0;i < 7;i++)
    {
        for (int j = 0;j < 10;j++)
        {
            switch (map1[i][j])
            {
            case 0:
                putimage((j + 2) * 40, (i + 2) * 40, &img0);
                break;
            case 1:
                putimage((j + 2) * 40, (i + 2) * 40, &img1);
                break;
            case 3:
                putimage((j + 2) * 40, (i + 2) * 40, &img4);
                break;
            case 4:
                putimage((j + 2) * 40, (i + 2) * 40, &img2);
                break;
            case 5:
                putimage((j + 2) * 40, (i + 2) * 40, &img3);
                break;
            case 7:
				//箱子到达目的地 4+3=7
                putimage((j + 2) * 40, (i + 2) * 40, &img5);
                break;
            case 8:
				//人到达目的地 5+3=8
                putimage((j + 2) * 40, (i + 2) * 40, &img3);
                break;
            case 50:
                putimage((j + 3) * 40, (i + 2) * 40, &img50);
                break;
            case 10:
				//彩蛋
                putimage((j + 2) * 40, (i + 2) * 40, &img1);
                break;
            }
        }
    }
    settextcolor(RGB(0, 0, 0));
    settextstyle(25, 0, "宋体");
    outtextxy(30, 360, "试着上下左右推动吧!"); 
    putimage(0, 545, &img04);
    EndBatchDraw();
}

//进行游戏
int PlayGame1(int map1[7][10])
{
    //获取到当前的人的下标
    int row, col;//人的 行 和 列
    char x;//退出时y/n
    for (int i = 0;i < 7;i++)//控制变量 0-6
    {
        for (int j = 0;j < 10;j++)//控制变量0-9
        {
            if (map1[i][j] == 5 || map1[i][j] == 8)
            {
                row = i;//i 0-6
                col = j;//j 0-9
            }
        }
    }

	//判断胜利
    if (map1[2][2] == 7 && map1[3][1] == 7 && map1[3][2] == 7 && map1[4][1] == 7 && map1[4][2] == 7)
    {
        settextstyle(30, 0, "宋体");
        outtextxy(30, 405, "恭喜你!成功通过了第一关!");
        return 2;
    }

    //键盘来控制图形所对应的数据
    char input;//定义一个字符变量
    input = _getch();/*接受键盘输入所对应的值*/
    //getch() 不显示回文，按下键盘马上接受
    switch (input)
    {
        /************************************
        人能走有哪些情况
        1.人的前面是空地
        2.人的前面是目的地
        3.人的前面是箱子且箱子地前面是空地
        4.人的前面是箱子且箱子的前面是目的地
        *************************************/
    case 'w'://上
        if (map1[row - 1][col] == 0 || map1[row - 1][col] == 3)//如果人的前面是空地/目的地
        {

            map1[row][col] -= 5;//人的ID 5/8
            map1[row - 1][col] += 5;
        }
        else if (map1[row - 1][col] == 4 || map1[row - 1][col] == 7)//人的前面是箱子
        {
            if (map1[row - 2][col] == 0 || map1[row - 2][col] == 3)//箱子前面是空地/目的地
            {
                map1[row - 2][col] += 4;
                map1[row - 1][col] += 1;
                map1[row][col] -= 5;
            }

        }
        break;
    case 'a'://左
        if (map1[row][col - 1] == 0 || map1[row][col - 1] == 3)//如果人的前面是空地/目的地
        {

            map1[row][col] -= 5;//人的ID 5/8
            map1[row][col - 1] += 5;
        }
        else if (map1[row][col - 1] == 4 || map1[row][col - 1] == 7)//人的前面是箱子
        {
            if (map1[row][col - 2] == 0 || map1[row][col - 2] == 3)//箱子前面是空地/目的地
            {
                map1[row][col - 2] += 4;
                map1[row][col - 1] += 1;
                map1[row][col] -= 5;
            }

        }
        break;
    case 's'://下
        if (map1[row + 1][col] == 0 || map1[row + 1][col] == 3)//如果人的前面是空地/目的地
        {

            map1[row][col] -= 5;//人的ID 5/8
            map1[row + 1][col] += 5;
        }
        else if (map1[row + 1][col] == 4 || map1[row + 1][col] == 7)//人的前面是箱子
        {
            if (map1[row + 2][col] == 0 || map1[row + 2][col] == 3)//箱子前面是空地/目的地
            {
                map1[row + 2][col] += 4;
                map1[row + 1][col] += 1;
                map1[row][col] -= 5;
            }

        }
        break;
    case 'd'://右
        if (map1[row][col + 1] == 0 || map1[row][col + 1] == 3)//如果人的前面是空地/目的地
        {

            map1[row][col] -= 5;//人的ID 5/8
            map1[row][col + 1] += 5;
        }
        else if (map1[row][col + 1] == 4 || map1[row][col + 1] == 7)//人的前面是箱子
        {
            if (map1[row][col + 2] == 0 || map1[row][col + 2] == 3)//箱子前面是空地/目的地
            {
                map1[row][col + 2] += 4;
                map1[row][col + 1] += 1;
                map1[row][col] -= 5;
            }

        }
        else if (map1[row][col + 1] == 10)//向右走为彩蛋格，可以推出墙壁
        {
            settextcolor(RGB(0, 0, 0));
            settextstyle(25, 0, "宋体");
            outtextxy(30, 390, "推墙壁干嘛?你想逃出去吗?"); 
            outtextxy(30, 420, "按任意键继续...");
            system("pause");
            outtextxy(30, 450, "这个游戏叫推箱子!");
            outtextxy(30, 480, "恭喜你!第一关失败了!");
            return 1;
        }
        break;
    case 'q'://退出
        settextstyle(25, 0, "宋体");
        outtextxy(30, 420, "请问您确定要退出难度为简单的第一关吗?");
        settextstyle(25, 0, "宋体");
        outtextxy(30, 455, "请选择:(y/n)");
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