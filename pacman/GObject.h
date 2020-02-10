#pragma once
#include<time.h>
#include"GMap.h"
#define PLAYERSPEED 6 //玩家速度
#define ENERMYSPEED 4 //敌人速度
#define LEGCOUNTS 5 //敌人腿的数量
#define DISTANCE 10 //图形范围
#define BLUE_ALERT 8 //蓝色警戒范围
#define D_OFFSET 2 //绘图误差
#define RD (DISTANCE+D_OFFSET) //绘图范围 12

//方向枚举
enum TWARDS { UP, DOWN, LEFT, RIGHT, OVER };
/*
struct RECT
{
    int left;
    int top;
    int right;
    int bottom;
};
struct POINT
{
    int x;
    int y;
};*/
//物体类
class GObject
{
public:
    void SetPosition(int Row,int Array);
    void DrawBlank(HDC &hdc);
    virtual void Draw(HDC &hdc)=0; //绘制地图
    static GMap* pStage; //指向地图类的指针，设置为静态，使所有自类对象都能够使用相同的函数
    GObject(int Row, int Array)
    {
        frame = 1;
        pStage = NULL;
        this->dRow = Row;
        this->dArray = Array;
        this->point.y = dRow * pStage->LD + pStage->LD / 2;
        this->point.x = dArray * pStage->LD + pStage->LD / 2;
        this->mX = point.x;
        this->mY = point.y;
    }
    void virtual action() = 0; //数据变更的表现
    int GetRow();
    int GetArray();
protected:
    int mX;
    int mY;
    TWARDS twCommand; //指令缓存
    POINT point; //中心坐标
    int dRow; //逻辑横坐标
    int dArray; //逻辑纵坐标
    int speed; //速度
    TWARDS tw; //朝向
    int frame; //帧数

    //子程序
    bool Achive();
    bool Collision();
    int PtTransform(int k);
    virtual void AchiveCtrl();
private:
};

//大嘴，玩家控制的对象
class PacMan:public GObject
{
public:
    POINT GetPos();
    TWARDS GetTw();
    bool Win();
    void Draw(HDC& hdc);
    void SetTwCommand(TWARDS command);
    void Over();
    PacMan(int x, int y) :GObject(x, y)
    {
        this->speed = PLAYERSPEED;
        twCommand = tw = LEFT;
    }
    void action();
protected:
    virtual void AchiveCtrl(); //重写虚函数
private:
};
//追捕大嘴的敌人
class Enermy :public GObject
{
public:
    static PacMan* player;
    void virtual Draw(HDC& hdc);
    Enermy(int x, int y) :GObject(x, y)
    {
        this->speed = ENERMYSPEED;
        tw = LEFT;
        twCommand = UP;
    }
    void virtual action();
protected:
    void Catch(); //是否抓住大嘴
    void virtual MakeDecision(bool b) = 0; //AI 实现
    COLORREF color;
private:
};

//随机移动s
class RedOne :public Enermy
{
public:
    void Draw(HDC& hdc);
    RedOne(int x, int y) :Enermy(x, y)
    {
        color = RGB(255, 0, 0);
    }
protected:
    void virtual MakeDecision(bool b);
};
//守卫者
class BlueOne :public RedOne
{
public:
    void Draw(HDC& hdc);
    BlueOne(int x, int y) :RedOne(x, y)
    {
        color = RGB(0, 0, 255);
    }
protected:
    void virtual MakeDecision(bool b);
};
//扰乱者
class YellowOne :public RedOne
{
public:
    void Draw(HDC& hdc);
    YellowOne(int x, int y) :RedOne(x, y)
    {
        color = RGB(200, 200, 100);
    }
protected:
    void virtual MakeDecision(bool b);
};
