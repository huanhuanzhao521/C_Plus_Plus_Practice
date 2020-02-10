#pragma once
#ifndef Graph_H
#define Graph_H
#include<string>
using namespace std;

//景点结构
typedef struct
{
	string name;//景点名称
	int code;//景点编号
	string introduce;//景点信息介绍
}vertex_class;

const int MaxSize = 20;//图的最大顶点数
class MGraph
{
public:
	MGraph();
	~MGraph() {};
	void paint_map();//绘图函数
	void look_scene();//查看景点信息函数
	void increase_scene();//增加景点函数
	void delete_scene();//删除景点函数
	void increase_road();//增加道路函数
	void delete_road();//删除道路函数
	void change_scene();//修改景点信息函数
	void plan_shortestroad();//规划最短路径
	void return_main();//返回主界面函数
	void increase_road(int from,int to);//增加道路重载函数（新建景点与原景点之间增加道路）
	void delete_road(int from);//删除道路重载函数（删除景点后删除所有以其相关的道路）

protected:
private:
	vertex_class v[MaxSize];//表示图中的顶点
	int arc[MaxSize][MaxSize];//存放图中边的数组
	int vertexNum, arcNum;//图的景点数和边数
};
#endif