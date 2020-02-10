#pragma once
#include<list>
#include"framework.h"
//#include<wingdi.h>
#define MAPLENTH 19 //�߼���ͼ��С
#define P_ROW 10
#define P_ARRAY 9
#define E_ROW 8
#define E_ARRAY 9
using std::list;
//������GMap
class GMap
{
public:
    void DrawMap(HDC& hdc); //���Ƶ�ͼ
    void DrawPeas(HDC& hdc); //���ƶ���
    virtual ~GMap();
    GMap()
    {

    }
    friend class GObject; //����������ʹ��ֱ�ߵ������յ����Ϣ����ײ���
    friend class PacMan; //�������족���ʶ��ӵ�ͼ
protected:
    static int LD; //�ϰ���ߴ�
    static int PD; //���ӵİ뾶
    void InitOP(); //����˫������λ�ã�����û�г���
    bool mapData[MAPLENTH][MAPLENTH]; //�ϰ����߼���ͼ����
    bool peaMapData[MAPLENTH][MAPLENTH];
    COLORREF color;
private:
};
//��һ��
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