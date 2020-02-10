#pragma once
#include<list>
#include"framework.h"
//#include<wingdi.h>
#define MAPLENTH 19 //逻辑地图大小
#define P_ROW 10
#define P_ARRAY 9
#define E_ROW 8
#define E_ARRAY 9
using std::list;
//抽象类GMap
class GMap
{
public:
    void DrawMap(HDC& hdc); //绘制地图
    void DrawPeas(HDC& hdc); //绘制豆子
    virtual ~GMap();
    GMap()
    {

    }
    friend class GObject; //允许物体类使用直线的起点和终点的信息做碰撞检测
    friend class PacMan; //允许“大嘴”访问豆子地图
protected:
    static int LD; //障碍物尺寸
    static int PD; //豆子的半径
    void InitOP(); //敌我双方出现位置，豆子没有出现
    bool mapData[MAPLENTH][MAPLENTH]; //障碍物逻辑地图点阵
    bool peaMapData[MAPLENTH][MAPLENTH];
    COLORREF color;
private:
};
//第一关
class Stage_1 :public GMap
{
public:
    Stage_1();
private:
    bool static initData[MAPLENTH][MAPLENTH];
};
class Stage_2 :public GMap
{
public:
    Stage_2();
private:
    bool static initData[MAPLENTH][MAPLENTH];
};
class Stage_3 :public GMap
{
public:
    Stage_3();
private:
    bool static initData[MAPLENTH][MAPLENTH];
};