//#include <WINGDI.h>
#include"framework.h"
#include"GObject.h"
//#include"pacman.h"

//#include<WinUser.h>
//GObject成员定义
GMap* GObject::pStage = NULL;
int GObject::GetRow()
{
    return dRow;
}
int GObject::GetArray()
{
    return dArray;
}
int GObject::PtTransform(int k)
{
    return (k - (pStage->LD) / 2) / pStage->LD;
}
bool GObject::Achive()
{
    int n = (point.x - pStage->LD / 2) % pStage->LD;
    int k = (point.y - pStage->LD / 2) % pStage->LD;
    bool l = (n == 0 && k == 0);
    return l;
}
void GObject::AchiveCtrl()
{
    if (Achive())
    {
        dArray = PtTransform(point.x);
        dRow = PtTransform(point.y);
    }
}
void GObject::DrawBlank(HDC& hdc)
{
    RECT rect;
    rect.top = mY - RD;
    rect.left = mX - RD;
    rect.right = mX + RD;
    rect.bottom = mY + RD;
    FillRect(hdc, &rect, ::CreateSolidBrush(RGB(255, 255, 255)));
}
void GObject::SetPosition(int Row,int Array)
{
    dRow = Row;
    dArray = Array;
    this->point.y = dRow * pStage->LD + pStage->LD / 2;
    this->point.x = dArray * pStage->LD + pStage->LD / 2;
}
bool GObject::Collision()
{
    bool b = false;
    AchiveCtrl(); //更新行列的数据，若是大嘴,则会执行PacMan重写的AchiveCtrl函数消除豆子
    //判断指令的有效性
    if (dArray<0 || dRow<0 || dArray>MAPLENTH - 1 || dRow>MAPLENTH - 1)
    {
        b = true;
    }
    else if (Achive())
    {
        switch (twCommand) //判断行进的方向
        {
        case LEFT:
            if (dArray > 0 && !pStage->mapData[dRow][dArray - 1]) //判断下一个格子能否能够通行
            {
                b = true; //指令无效
            }
            break;
        case RIGHT:
            if (dArray < MAPLENTH-1 && !pStage->mapData[dRow][dArray + 1]) //判断下一个格子能否能够通行
            {
                b = true; //指令无效
            }
            break;
        case UP:
            if (dRow > 0 && !pStage->mapData[dRow - 1][dArray]) //判断下一个格子能否能够通行
            {
                b = true; //指令无效
            }
            break;
        case DOWN:
            if (dRow < MAPLENTH-1 && !pStage->mapData[dRow + 1][dArray]) //判断下一个格子能否能够通行
            {
                b = true; //指令无效
            }
            break;
        }
        if (!b)
        {
            tw = twCommand; //没有撞墙，指令成功
        }
    }
    //依照真实的方向位移
    mX = point.x;
    mY = point.y;
    int MAX = pStage->LD * MAPLENTH + pStage->LD / 2;
    int MIN = pStage->LD / 2;
    switch (tw) //判断行进的方向
    {
    case LEFT:
        if (dArray > 0 && !pStage->mapData[dRow][dArray - 1])
        {
            b = true;
            break; //"撞墙了"
        }
        point.x -= speed;
        if (point.x < MIN)
        {
            point.x = MAX;
        }
        break;
    case RIGHT:
        if (dArray < MAPLENTH - 1 && !pStage->mapData[dRow][dArray + 1])
        {
            b = true;
            break; //"撞墙了"
        }
        point.x += speed;
        if (point.x > MAX)
        {
            point.x = MIN;
        }
        break;
    case UP:
        if (dRow > 0 && !pStage->mapData[dRow - 1][dArray])
        {
            b = true;
            break; //"撞墙了"
        }
        point.y -= speed;
        if (point.y < MIN)
        {
            point.y = MAX;
        }
        break;
    case DOWN:
        if (dRow < MAPLENTH - 1 && !pStage->mapData[dRow + 1][dArray])
        {
            b = true;
            break; //"撞墙了"
        }
        point.y += speed;
        if (point.y > MAX)
        {
            point.y = MIN;
        }
        break;
    }
    return b;
}
//PacMan成员定义
void PacMan::AchiveCtrl()
{
    GObject:: AchiveCtrl();
    if (Achive())
    {
        if (dRow >= 0 && dRow < MAPLENTH && dArray >= 0 && dArray < MAPLENTH) //防止数组越界
        {
            if (pStage->peaMapData[dRow][dArray])
            {
                pStage->peaMapData[dRow][dArray] = false;
            }
        }
    }
}
void PacMan::action()
{
    Collision();
}
void PacMan::SetTwCommand(TWARDS command)
{
    twCommand = command;
}
bool PacMan::Win()
{
    for (int i = 0; i <= MAPLENTH; i++)
    {
        for (int j = 0; j <= MAPLENTH; j++)
        {
            if (pStage->peaMapData[i][j] == true)
            {
                return false; //存在任意一个豆子,没有取得胜利
            }
        }
    }
    return true; //没有豆子，胜利
}
POINT PacMan::GetPos()
{
    return point;
}
void PacMan::Over()
{
    tw = OVER;
}
TWARDS PacMan::GetTw()
{
    return tw;
}
void PacMan::Draw(HDC & memDC)
{
    if (tw == OVER)
    {

    }
    else if (frame % 2 == 0) //第4帧动画与第2帧动画
    {
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        int offsetX = DISTANCE / 2 + D_OFFSET; //弧弦交点
        int offsetY = DISTANCE / 2 + D_OFFSET; //弧弦交点
        switch (tw)
        {
        case UP:
            x1 = point.x - offsetX;
            x2 = point.x + offsetX;
            y2 = y1 = point.y - offsetY;
            break;
        case DOWN:
            x1 = point.x + offsetX;
            x2 = point.x - offsetX;
            y1 = y2 = point.y + offsetY;
            break;
        case LEFT:
            x2 = x1 = point.x - offsetX;
            y1 = point.y + offsetY;
            y2 = point.y - offsetY;
            break;
        case RIGHT:
            x2 = x1 = point.x + offsetX;
            y1 = point.y - offsetY;
            y2 = point.y + offsetY;
            break;
        }
        Arc(memDC, point.x - DISTANCE, point.y - DISTANCE,
            point.x + DISTANCE, point.y + DISTANCE,
            x1, y1, x2, y2);
        MoveToEx(memDC, x1, y1, NULL);
        LineTo(memDC, point.x, point.y);
        LineTo(memDC, x2, y2);
    }
    else if (frame % 3 == 0)
    {
        Ellipse(memDC, point.x - DISTANCE, point.y - DISTANCE,
            point.x + DISTANCE, point.y + DISTANCE);
    }
    else {
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        switch (tw)
        {
        case UP:
            x1 = point.x - DISTANCE;
            x2 = point.x + DISTANCE;
            y1 = y2 = point.y;
            break;
        case DOWN:
            x1 = point.x + DISTANCE;
            x2 = point.x - DISTANCE;
            y1 = y2 = point.y;
            break;
        case LEFT:
            x1 = x2 = point.x;
            y1 = point.y + DISTANCE;
            y2 = point.y - DISTANCE;
            break;
        case RIGHT:
            x1 = x2 = point.x;
            y1 = point.y - DISTANCE;
            y2 = point.y + DISTANCE;
            break;
        }
        Arc(memDC, point.x - DISTANCE, point.y - DISTANCE,
            point.x + DISTANCE, point.y + DISTANCE,
            x1, y1, x2, y2);
        MoveToEx(memDC, x1, y1, NULL);
        LineTo(memDC, point.x, point.y);
        LineTo(memDC, x2, y2);
    }
    frame++; //绘制下一帧
}
//Enermy成员定义
PacMan* Enermy::player = NULL;
void Enermy::Catch()
{
    int DX = point.x - player->GetPos().x;
    int DY = point.y - player->GetPos().y;
    if ((-RD < DX && DX < RD) && (-RD < DY && DY < RD))
    {
        player->Over();
    }
}
void Enermy::Draw(HDC& hdc)
{
    HPEN pen = ::CreatePen(0, 0, color);
    HPEN oldPen = (HPEN)SelectObject(hdc, pen);
    Arc(hdc, point.x - DISTANCE, point.y - DISTANCE,
        point.x + DISTANCE, point.y + DISTANCE,
        point.x + DISTANCE, point.y,
        point.x - DISTANCE, point.y); //半圆形的头
    int const LEGLENTH = (DISTANCE) / (LEGCOUNTS);
    if (frame % 2 == 0)
    {
        MoveToEx(hdc, point.x - DISTANCE, point.y, NULL); //矩形的身子
        LineTo(hdc, point.x - DISTANCE, point.y + DISTANCE - LEGLENTH);
        MoveToEx(hdc, point.x + DISTANCE, point.y, NULL);
        LineTo(hdc, point.x + DISTANCE, point.y + DISTANCE - LEGLENTH);
        //从左往右绘制腿部
        for (int i = 0; i < LEGCOUNTS; i++)
        {
            Arc(hdc, point.x - DISTANCE + i * 2 * LEGLENTH, point.y + DISTANCE - 2 * LEGLENTH,
                point.x - DISTANCE + (i + 1) * 2 * LEGLENTH, point.y + DISTANCE,
                point.x - DISTANCE + i * 2 * LEGLENTH, point.y + DISTANCE - LEGLENTH,
                point.x - DISTANCE + (i + 1) * 2 * LEGLENTH, point.y + DISTANCE - LEGLENTH);
        }
    }
    else {
        MoveToEx(hdc, point.x - DISTANCE, point.y, NULL); //绘制身体
        LineTo(hdc, point.x - DISTANCE, point.y + DISTANCE);
        MoveToEx(hdc, point.x + DISTANCE, point.y, NULL);
        LineTo(hdc, point.x + DISTANCE, point.y + DISTANCE);

        //从左往右绘制腿部
        MoveToEx(hdc, point.x - DISTANCE, point.y + DISTANCE, NULL);
        LineTo(hdc, point.x - DISTANCE + LEGLENTH, point.y + DISTANCE - LEGLENTH);

        for (int i = 0; i < LEGCOUNTS - 1; i++)
        {
            Arc(hdc, point.x - DISTANCE + (1 + i * 2) * LEGLENTH, point.y + DISTANCE - 2 * LEGLENTH,
                point.x - DISTANCE + (3 + i * 2) * LEGLENTH, point.y + DISTANCE,
                point.x - DISTANCE + (1 + i * 2) * LEGLENTH, point.y + DISTANCE - LEGLENTH,
                point.x - DISTANCE + (3 + i * 2) * LEGLENTH, point.y + DISTANCE - LEGLENTH
            );
        }
        MoveToEx(hdc, point.x + DISTANCE, point.y + DISTANCE, NULL);
        LineTo(hdc, point.x + DISTANCE - LEGLENTH, point.y + DISTANCE - LEGLENTH);
    }
    //根据方向绘制眼睛
    int R = DISTANCE / 5; //眼睛的半径
    switch (tw)
    {
    case UP:
        Ellipse(hdc, point.x - 2 * R, point.y - 2 * R,
            point.x, point.y);
        Ellipse(hdc, point.x, point.y - 2 * R,
            point.x + 2 * R, point.y);
        break;
    case DOWN:
        Ellipse(hdc, point.x - 2 * R, point.y, point.x, point.y + 2 * R);
        Ellipse(hdc, point.x, point.y, point.x + 2 * R, point.y + 2 * R);
        break;
    case LEFT:
        Ellipse(hdc, point.x - 3 * R, point.y - R,
            point.x - R, point.y + R);
        Ellipse(hdc, point.x - R, point.y - R,
            point.x + R, point.y + R);
        break;
    case RIGHT:
        Ellipse(hdc, point.x - R, point.y - R,
            point.x + R, point.y + R);
        Ellipse(hdc, point.x + R, point.y - R,
            point.x + 3 * R, point.y + R);
        break;
    }
    frame++; //准备绘制下一帧
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
    return;
}
void Enermy::action()
{
    bool b = Collision();
    MakeDecision(b);
    Catch();
}

//RedOne成员
void RedOne::Draw(HDC& hdc)
{
    Enermy::Draw(hdc);
}
void RedOne::MakeDecision(bool b)
{
    int i = rand();
    //撞到墙壁改变方向
    if (b)
    {
        //逆时针方向
        if (i % 4 == 0)
        {
            tw == UP ? twCommand = LEFT : twCommand = UP;
        }
        else if (i % 3 == 0)
        {
            tw == DOWN ? twCommand = RIGHT : twCommand = DOWN;
        }
        else if (i % 2 == 0)
        {
            tw == RIGHT ? twCommand = UP : twCommand = RIGHT;
        }
        else {
            tw == LEFT ? twCommand = DOWN : twCommand = LEFT;
        }
        return;
    }

    if (i % 4 == 0)
    {
        twCommand != UP ? tw == DOWN : twCommand == UP;
    }
    else if (i % 3 == 0)
    {
        tw != DOWN ? twCommand = UP : twCommand = DOWN;
    }
    else if (i % 2 == 0)
    {
        tw != RIGHT ? twCommand = LEFT : twCommand = RIGHT;
    }
    else {
        tw != LEFT ? twCommand = RIGHT : twCommand = LEFT;
    }
}
//BlueOne成员定义
void BlueOne::Draw(HDC& hdc)
{
    Enermy::Draw(hdc);
}
void BlueOne::MakeDecision(bool b)
{
    const int DR = this->dRow - player->GetRow();
    const int DA = this->dArray - player -> GetArray();
    if (!b && DR == 0)
    {
        //玩家在左侧边警戒范围s
        if (DA <= BLUE_ALERT && DA > 0)
        {
            twCommand = LEFT; //向左移动
            return;
        }
        //玩家在右侧边警戒范围s
        if (DA < 0 && DA >= -BLUE_ALERT)
        {
            twCommand = RIGHT; //向右移动
            return;
        }
    }
    if(!b && DA == 0)
    {
        //玩家在下方边警戒范围s
        if (DR <= BLUE_ALERT && DR > 0)
        {
            twCommand = UP; //向左移动
            return;
        }
        //玩家在上方边警戒范围s
        if (DR < 0 && DR >= -BLUE_ALERT)
        {
            twCommand = DOWN; //向左移动
            return;
        }
    }
    RedOne::MakeDecision(b); //不在追踪模式时RED行为相同
}
//YellowOne成员定义
void YellowOne::MakeDecision(bool b)
{
    const int DR = this->dRow - player->GetRow();
    const int DA = this->dArray - player->GetArray();
    if (!b )
    {
        //玩家在左侧边警戒范围s
        if (DR * DR > DA * DA)
        {
            if (DA > 0)
            {
                twCommand = LEFT; //向左移动
                return;
            }
            //玩家在右侧边警戒范围s
            else if (DA < 0)
            {
                twCommand = RIGHT; //向右移动
                return;
            }
        }
        else {
            if (DR > 0)
            {
                //玩家在下方边警戒范围s
                twCommand = UP; //向左移动
                return;
            }
            //玩家在上方边警戒范围s
            if (DR < 0 )
            {
               twCommand = DOWN; //向左移动
               return;
            }
        }
    }
    RedOne::MakeDecision(b); //不在追踪模式时RED行为相同
}
void YellowOne::Draw(HDC& hdc)
{
    Enermy::Draw(hdc);
}