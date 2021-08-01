#pragma once

extern IMAGE imgmes2;

//显示开发人员及游戏信息
void ShowMessage2()
{
    putimage(0, 0, &imgmes2);
    system("pause");
}
