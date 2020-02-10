#pragma once
#ifndef Graph_H
#define Graph_H
#include<string>
using namespace std;

//����ṹ
typedef struct
{
	string name;//��������
	int code;//������
	string introduce;//������Ϣ����
}vertex_class;

const int MaxSize = 20;//ͼ����󶥵���
class MGraph
{
public:
	MGraph();
	~MGraph() {};
	void paint_map();//��ͼ����
	void look_scene();//�鿴������Ϣ����
	void increase_scene();//���Ӿ��㺯��
	void delete_scene();//ɾ�����㺯��
	void increase_road();//���ӵ�·����
	void delete_road();//ɾ����·����
	void change_scene();//�޸ľ�����Ϣ����
	void plan_shortestroad();//�滮���·��
	void return_main();//���������溯��
	void increase_road(int from,int to);//���ӵ�·���غ������½�������ԭ����֮�����ӵ�·��
	void delete_road(int from);//ɾ����·���غ�����ɾ�������ɾ������������صĵ�·��

protected:
private:
	vertex_class v[MaxSize];//��ʾͼ�еĶ���
	int arc[MaxSize][MaxSize];//���ͼ�бߵ�����
	int vertexNum, arcNum;//ͼ�ľ������ͱ���
};
#endif