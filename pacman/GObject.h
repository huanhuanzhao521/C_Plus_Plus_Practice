#pragma once
#include<time.h>
#include"GMap.h"
#define PLAYERSPEED 6 //����ٶ�
#define ENERMYSPEED 4 //�����ٶ�
#define LEGCOUNTS 5 //�����ȵ�����
#define DISTANCE 10 //ͼ�η�Χ
#define BLUE_ALERT 8 //��ɫ���䷶Χ
#define D_OFFSET 2 //��ͼ���
#define RD (DISTANCE+D_OFFSET) //��ͼ��Χ 12

//����ö��
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
//������
class GObject
{
public:
    void SetPosition(int Row,int Array);
    void DrawBlank(HDC &hdc);
    virtual void Draw(HDC &hdc)=0; //���Ƶ�ͼ
    static GMap* pStage; //ָ���ͼ���ָ�룬����Ϊ��̬��ʹ������������ܹ�ʹ����ͬ�ĺ���
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
    void virtual action() = 0; //���ݱ���ı���
    int GetRow();
    int GetArray();
protected:
    int mX;
    int mY;
    TWARDS twCommand; //ָ���
    POINT point; //��������
    int dRow; //�߼�������
    int dArray; //�߼�������
    int speed; //�ٶ�
    TWARDS tw; //����
    int frame; //֡��

    //�ӳ���
    bool Achive();
    bool Collision();
    int PtTransform(int k);
    virtual void AchiveCtrl();
private:
};

//���죬��ҿ��ƵĶ���
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
    virtual void AchiveCtrl(); //��д�麯��
private:
};
//׷������ĵ���
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
    void Catch(); //�Ƿ�ץס����
    void virtual MakeDecision(bool b) = 0; //AI ʵ��
    COLORREF color;
private:
};

//����ƶ�s
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
//������
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
//������
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
