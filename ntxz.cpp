#include"txz.h"

IMAGE imgbk, img01, img02, img03, img04, img05, img06;
IMAGE img0, img1, img2, img3, img4, img5;
IMAGE img15, img16, img40, img50;
IMAGE img20, img21, img22, img23, img24;
IMAGE imgmes1,imgmes2;

//墙为1 空地为0 人为5 箱子为4 目的地为3  彩蛋为10  空白50
int map00[7][10] =
{ {50,50,50,1,1,1,1,1,10,50},
{50,1,1,1,0,0,0,0,10,50},
{1,1,3,0,4,1,1,0,10,1},
{1,3,3,4,0,4,0,0,5,10},
{1,3,3,0,4,0,4,0,10,1},
{1,1,1,1,1,1,0,0,10,50},
{50,50,50,50,50,1,1,1,10,50}, };

//空地为0 人为5 箱子为4 目的地为3  可推动墙为15和16
//红色墙20，紫色墙21，浅蓝墙22，蓝色墙23 空白墙50
int map01[7][7] =
{ {50,50,40,50,50,50,50},
{40,40,40,40,40,40,40},
{21,20,15,23,20,16,21},
{20,3,0,5,4,0,23},
{23,3,0,0,4,0,20},
{22,21,23,22,21,0,22},
{50,50,50,50,20,23,20}, };

//墙为1 空地为0 人为5 箱子为4 目的地为3  
//红色墙20，紫色墙21，浅蓝墙22，蓝色墙23，绿色24，空白墙50
int map02[9][8] =
{ {20,24,23,20,22,24,20,21},
{22,0,0,0,0,0,0,23},
{24,0,0,20,0,4,0,22},
{20,0,21,23,0,0,0,20},
{23,0,0,20,5,0,0,23},
{24,0,3,22,21,0,0,21},
{20,0,0,0,0,0,4,20},
{22,20,23,21,20,22,3,22},
{50,50,50,50,50,23,20,21}, };

//主函数
int main()
{
    char k;//用于接受主菜单下键盘输入
    int a1, a2, a3;//函数playgame返回值
    char choose1, choose2;//用于存储选择是否直接跳到下一关
    int flag = 0;
    int map1[7][10];
    int map2[7][7];
    int map3[9][8];

    InitGame();//位于initgame.h

	//初始化界面
    HWND txz = initgraph(560, 600);
    SetWindowTextA(txz, "推箱子");
    setbkcolor(RGB(245,245,245));
    cleardevice();

    mciSendString("open sf.mp3 alias BGM", 0, 0, 0);//播放音乐
    mciSendString("play BGM repeat", 0, 0, 0);//循环播放

    do {
        k = menu();//位于initgame.h
        switch (k)
        {     
        gate1:
        case '1':
            Create1(map1);//位于game1.h
            while (1)
            {
                cleardevice();
                DrawMap1(map1);//位于game1.h
                a1 = PlayGame1(map1);//位于game1.h
                if (a1 == 1)
                    break;
                else if (a1 == 2)
                {
                    settextstyle(25, 0, "宋体");
                    outtextxy(30, 440, "是否要进入第二关?");
                    settextstyle(25, 0, "宋体");
                    outtextxy(30, 475, "请选择:(y/n)");
                    choose1=_getch();
                    if (choose1 == 'y')
                        goto gate2;
                    else
                        break;
                }
                else if (a1 == 3)
                {
                    goto gate1;
                }
            }
            settextcolor(RGB(0, 0, 0));
            settextstyle(25, 0, "宋体");
            outtextxy(30, 520, "按任意键继续...");
            system("pause");
            cleardevice();
            break;
        gate2:
        case '2':
            Create2(map2);//位于game2.h
            while (1)
            {
                cleardevice();
                DrawMap2(map2);//位于game2.h
                a2 = PlayGame2(map2);//位于game2.h
                if (a2 == 1)
                    break;
                else if (a2 == 2)
                {
                    settextstyle(25, 0, "宋体");
                    outtextxy(30, 490, "是否要进入第三关?");
                    settextstyle(25, 0, "宋体");
                    outtextxy(30, 520, "请选择:(y/n)");
                    choose2=_getch();               
                    if (choose2 == 'y')
                        goto gate3;
                    else
                        break;
                }
                else if (a2 == 3)
                {
                    goto gate2;
                }
            }
            settextcolor(RGB(0, 0, 0));
            settextstyle(25, 0, "宋体");
            outtextxy(30, 520, "按任意键继续...");
            system("pause");
            cleardevice();
            break;
        gate3:
        case '3':
            Create3(map3);//位于game3.h
            while (1)
            {
                cleardevice();
                DrawMap3(map3);//位于game3.h
                a3 = PlayGame3(map3);//位于game3.h
                if (a3 == 1)
                    break;
                else if (a3 == 3)
                {
                    goto gate3;
                }
            }
            settextcolor(RGB(0, 0, 0));
            settextstyle(25, 0, "宋体");
            outtextxy(30, 520, "按任意键继续...");
            system("pause");
            cleardevice();
            break;
        case '4':
            system("cls");
            ShowMessage1();
            break;
        case '5':
            system("cls");
            ShowMessage2();
            break;      
        }
    } while (k);
    return 0;
}
