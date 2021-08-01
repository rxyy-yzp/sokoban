#pragma once

extern IMAGE imgbk, img01, img02, img03, img04, img05, img06;
extern IMAGE img0, img1, img2, img3, img4, img5;
extern IMAGE img15, img16, img40, img50;
extern IMAGE img20, img21, img22, img23, img24;
extern IMAGE imgmes1,imgmes2;

extern int map02[9][8];

//创建数组以便传值
void Create3(int map3[9][8])
{
    int i, j;
    for (i = 0;i < 9;i++)
    {
        for (j = 0;j < 8;j++)
        {
            map3[i][j] = map02[i][j];
        }
    }
}

//绘制第三关界面及地图
void DrawMap3(int map3[9][8])
{
    BeginBatchDraw();
    putimage(0, 0, &img03);
    //用for循环遍历数组
    for (int i = 0;i < 9;i++)
    {
        for (int j = 0;j < 8;j++)
        {
            switch (map3[i][j])
            {
            case 0:
                putimage((j + 3) * 40, (i + 2) * 40, &img0);
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
            case 24:
				//绿色24
                putimage((j + 3) * 40, (i + 2) * 40, &img24);
                break;
            case 50:
				//空白墙50
                putimage((j + 3) * 40, (i + 2) * 40, &img50);
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
            }
        }
    }
    settextcolor(RGB(0, 0, 0));
    settextstyle(25, 0, "宋体");
    outtextxy(30, 420, "一闪一闪亮晶晶");
    putimage(0, 545, &img06);
    EndBatchDraw();
}

int PlayGame3(int map3[9][8])
{
    //获取到当前的人的下标
    int row, col;//人的 行 和 列
    char x;//退出时y/n
    for (int i = 0;i < 9;i++)//控制变量 0-6
    {
        for (int j = 0;j < 8;j++)//控制变量0-9
        {
            if (map3[i][j] == 5)
            {
                row = i;//i 0-6
                col = j;//j 0-9
            }
        }
    }

	//判断胜利
    if ((map3[6][1] == 7 || map3[6][2] == 7 || map3[6][3] == 7 || map3[6][4] == 7 || map3[6][5] == 7 || map3[6][6] == 7) && (map3[7][6] == 7))
    {
        settextstyle(30, 0, "宋体");
        outtextxy(30, 450, "恭喜你!成功通过了第三关!");
        return 1;
    }

    //键盘来控制图形所对应的数
    char input;//定义一个字符变量
    input = _getch();//接受键盘输入所对应的值
    //getch() 不显示回文，按下键盘马上接受*/
    switch (input)
    {
        /************************************
        人能走有哪些情况
        1.人的前面是空地
        2.人的前面是目的地:推动目的地
        3.人的前面是箱子且箱子地前面是空地
        4.人的前面是箱子且箱子的前面是目的地
        5.人的前面是目的地且目的地前面是空地
        6.人的前面是目的地且目的地前面是墙
        7.人的前面是目的地且目的地前面是箱子
        *************************************/
        //墙为1 空地为0 人为5 箱子为4 目的地为3  箱子到达目的地7
    case 'w'://上
        if (map3[row - 1][col] == 0)//如果人的前面是空地/目的地
        {

            map3[row][col] -= 5;//人的ID 5/8
            map3[row - 1][col] += 5;
        }
        else if (map3[row - 1][col] == 4 || map3[row - 1][col] == 7)//人的前面是箱子
        {
            if (map3[row - 2][col] == 0 || map3[row - 2][col] == 3)//箱子前面是空地/目的地
            {
                map3[row - 2][col] += 4;
                map3[row - 1][col] += 1;
                map3[row][col] -= 5;
            }
        }
        else if (map3[row - 1][col] == 3 && map3[row - 2][col] == 0)//如果人的前面是目的地
        {
            map3[row][col] = 0;
            map3[row - 1][col] = 5;
            map3[row - 2][col] = 3;
        }

        break;
    case 'a'://左
        if (map3[row][col - 1] == 0)//如果人的前面是空地/目的地
        {

            map3[row][col] -= 5;//人的ID 5/8
            map3[row][col - 1] += 5;
        }
        else if (map3[row][col - 1] == 4 || map3[row][col - 1] == 7)//人的前面是箱子
        {
            if (map3[row][col - 2] == 0 || map3[row][col - 2] == 3)//箱子前面是空地/目的地
            {
                map3[row][col - 2] += 4;
                map3[row][col - 1] += 1;
                map3[row][col] -= 5;
            }

        }
        else if (map3[row][col - 1] == 3 && map3[row][col - 2] == 0)//如果人的前面是目的地
        {
            map3[row][col] = 0;
            map3[row][col - 1] = 5;
            map3[row][col - 2] = 3;
        }
		else if (map3[row][col - 1] == 3 && map3[row][col - 2] == 4)
		{
			map3[row][col] = 0;
			map3[row][col - 1] = 5;
			map3[row][col - 2] += 3;
		}
		break;
    case 's'://下
        if (map3[row + 1][col] == 0)//如果人的前面是空地/目的地
        {

            map3[row][col] -= 5;//人的ID 5/8
            map3[row + 1][col] += 5;
        }
        else if (map3[row + 1][col] == 4 || map3[row + 1][col] == 7)//人的前面是箱子
        {
            if (map3[row + 2][col] == 0 || map3[row + 2][col] == 3)//箱子前面是空地/目的地
            {
                map3[row + 2][col] += 4;
                map3[row + 1][col] += 1;
                map3[row][col] -= 5;
            }

        }
        else if (map3[row + 1][col] == 3 && map3[row + 2][col] == 0)//如果人的前面是目的地
        {
            map3[row][col] = 0;
            map3[row + 1][col] = 5;
            map3[row + 2][col] = 3;
        }
		else if (map3[row + 1][col] == 3 && map3[row+2][col] == 4)
		{
			map3[row][col] = 0;
			map3[row + 1][col] = 5;
			map3[row + 2][col] += 3;
		}
        break;
    case 'd'://右
        if (map3[row][col + 1] == 0)//如果人的前面是空地/目的地
        {

            map3[row][col] -= 5;//人的ID 5/8
            map3[row][col + 1] += 5;
        }
        else if (map3[row][col + 1] == 4 || map3[row][col + 1] == 7)//人的前面是箱子
        {
            if (map3[row][col + 2] == 0 || map3[row][col + 2] == 3)//箱子前面是空地/目的地
            {
                map3[row][col + 2] += 4;
                map3[row][col + 1] += 1;
                map3[row][col] -= 5;
            }

        }
        else if (map3[row][col + 1] == 3 && map3[row][col + 2] == 0)//如果人的前面是目的地
        {
            map3[row][col] = 0;
            map3[row][col + 1] = 5;
            map3[row][col + 2] = 3;
        }
		else if (map3[row][col + 1] == 3 && map3[row][col + 2] == 4)
		{
			map3[row][col] = 0;
			map3[row][col + 1] = 5;
			map3[row][col + 2] += 3;
		}
		
        break;
    case 'q'://退出
        settextstyle(25, 0, "宋体");
        outtextxy(30, 450, "请问您确定要退出难度为超级简单的第三关吗?");
        settextstyle(25, 0, "宋体");
        outtextxy(30, 485, "请选择:(y/n)");
        x = _getch();
        if (x == 'y')
            return 1;
        break;
    case 'r'://重新开始本关
        return 3;
        break;
    }
    return 0;
}