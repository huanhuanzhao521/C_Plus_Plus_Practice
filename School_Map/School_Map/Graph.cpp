#include<iostream>
#include<string>
#include<iomanip>
#include<Windows.h>
#include"Graph.h"
using namespace std;
const int maxinum = 1000000;//假定无穷大为一百万
//

//构造函数
MGraph::MGraph()
{
	vertexNum = 12; //设置景点数为12
	arcNum = 18;//设置边数为18

	//初始化景点信息
	for (int i = 0; i < MaxSize; i++)
	{
		v[i].code = -1;
		v[i].name = "";
		v[i].introduce = "";
	}

	/*学校12个景点信息录入*/
	v[0].code = 0;
	v[0].name = "成都工业学院";
	v[0].introduce = "成都工业学院创办于1913年，是四川省人民政府举办的本科院校，是辛亥革命后中国最早设立的工科学校之一，也是陈毅元帅的母校";

	v[1].code = 1;
	v[1].name = "学校正门";
	v[1].introduce = "学校正门进出校园的通道，也是区分每个大学的标志";


	v[2].code = 2;
	v[2].name = "长虹会堂";
	v[2].introduce = "长虹会堂是学校最大的会议室和学生各种大型活动以及晚会举办场地";

	v[3].code = 3;
	v[3].name = "德五楼";
	v[3].introduce = "德五楼是学校大三大四上课的地方和学校学生会组织开会集中所在地";

	v[4].code = 4;
	v[4].name = "允明楼";
	v[4].introduce = "允明楼是全校最大的教学楼，学校教务处以及办公室的所在地";

	v[5].code = 5;
	v[5].name = "图书馆";
	v[5].introduce = "图书馆是全校最高最大的建筑物，是莘莘学子学习考研的圣地";

	v[6].code = 6;
	v[6].name = "文澄楼";
	v[6].introduce = "文澄楼是学校师生实验室，学校各学院或者系部的办公室";

	v[7].code = 7;
	v[7].name = "陈毅纪念馆";
	v[7].introduce = "陈毅纪念馆是纪念陈毅元帅的地方，这里记录了陈毅元帅从懵懂少年到建国元帅的伟大革命历程";

	v[8].code = 8;
	v[8].name = "学生6宿舍";
	v[8].introduce = "学生6宿舍又叫致远居6号楼，是学校最大的男生宿舍";

	v[9].code = 9;
	v[9].name = "体育馆";
	v[9].introduce = "体育馆是学校最大的学生军训或者锻炼的地方，也是学校有关音乐协会演奏歌唱的地方";

	v[10].code = 10;
	v[10].name = "学校工厂";
	v[10].introduce = "学校工厂是一家军工生产厂，也是学校学生实习，特别是机械电子专业实训的地方";

	v[11].code = 11;
	v[11].name = "学生4宿舍";
	v[11].introduce = "学生4宿舍与学生6宿舍毗邻，是一个男生宿舍，旁边为学校篮球场";

	v[12].code = 12;
	v[12].name = "足球场";
	v[12].introduce = "学校足球场，是学校学生团组织生活，宿营娱乐的地方";

	//初始化邻接矩阵
	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; i < MaxSize; j++)
		{
			arc[i][j] = 0;
		}
	}

	//录入边与权重
	arc[1][2] = 116;
	arc[1][3] = 187;
	arc[2][4] = 87;

	arc[1][5] = 254;
	arc[3][5] = 98;
	arc[4][6] = 117;

	arc[5][6] = 100;
	arc[5][7] = 90;
	arc[3][7] = 82;

	arc[1][3] = 187;
	arc[1][2] = 116;
	arc[1][3] = 187;

	arc[6][8] = 147;
	arc[5][9] = 220;
	arc[7][10] = 162;

	arc[8][9] = 274;
	arc[9][10] = 161;
	arc[8][11] = 103;

	arc[9][12] = 180;
	arc[10][12] = 158;
	arc[11][12] = 327;

	//邻接矩阵对称赋值
	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; i < MaxSize; j++)
		{
			arc[j][i] = arc[i][j];
		}
	}
}

//查看景点信息函数
void MGraph::look_scene()
{
	cout << endl << v[0].name << endl;
	cout << endl << v[0].introduce << endl << endl;
	for (int i = 1; i < MaxSize; i++)
	{
		if (v[i].code > 0)
		{
			cout << setiosflags(ios::left) << setw(2) << v[i].code << setw(15) << v[i].name;
			if (i % 4 == 0)
				cout << endl;
		}
	}
	while (true)
	{
		cout << endl<<"请输入您要查询景点的编号（1-"<<vertexNum<<"):"<<endl;
		int index = 0;
		cin >> index;
		if (index >= 1 && index << vertexNum)
		{
			cout << endl << "景点编号为：" << v[index].code << "\t" << v[index].name << endl;
			cout << endl << "景点介绍为：" << v[index].introduce;
			break;
		}
		else
		{
			cout << "景点编号输入有误，请重新输入！" << endl;
		}
	}
	
}

//增加景点函数
void MGraph::increase_scene()
{
	vertexNum++;
	v[vertexNum].code = vertexNum;
	getchar();
	cout << endl << "请输入您要增加的景点的信息：" << endl;
	cout << endl << "输入增加景点名称为：" << endl;
	string name;
	getline(cin, name);
	v[vertexNum].name = name;
	cout << "请输入增加景点的介绍：" << endl;
	string introduce;
	getline(cin, introduce);
	v[vertexNum].introduce = introduce;
	cout << endl << "增加景点成功！" << endl;
	for (int i = 1; i < MaxSize; i++)
	{
		if (v[i].code > 0)
		{
			cout << setiosflags(ios::left) << setw(2) << v[i].code << setw(15) << v[i].name ;
			if (i % 4 == 0)//4个景点占据一行
				cout << endl;
		}
	}
	cout << "请输入" << v[vertexNum].name << "与其他景点之间的道路关联" << endl;
	while (true)
	{
		int to;
		cout << endl << "道路的起点为默认值为:" << v[vertexNum].code << v[vertexNum].name <<
			"现在请按照景点编号的方式输入您要增加道路的终点:" << endl;
		cin >> to;
		if (to<1 || to>vertexNum)//?
		{
			cout << "您输入的起点或者终点不存在,请重新输入" << endl;
			continue;
		}
		cout << "增加新建景点与原景点之间的道路成功！" << endl;
		increase_road(v[vertexNum].code, to);//增加新建景点与原景点之间的道路成功,则调用增加道路重载函数
	}

}

//删除景点函数
void MGraph::delete_scene()
{
	for (int i = 0; i < MaxSize; i++)
	{
		if (v[i].code > 0)
		{
			cout << setiosflags(ios::left) << setw(2) << v[i].code << setw(15) << v[i].name << endl;
			if(i%4==0)
				cout<<endl;
		}
	}
	int get_delete_scene_index;
	while (true)
	{
		cout << "1. 按照景点编号删除景点         2. 按照景点名称删除景点" << endl;
		cout << "请输入删除景点的方式（1 or 2）" << endl;
		int way;
		cin >> way;
		if (way == 1)
		{
			while (true)
			{
				cout << endl << "请输入您要删除的景点编号（1-" << vertexNum << "):";
				int index1;
				cin >> index1;
				get_delete_scene_index = index1;
				if (index1<1 || index1>vertexNum)
				{
					cout << endl << "您输入的景点编号无效，请重新输入" << endl;
					continue;
				}
				for (int i = index1; i <= vertexNum; i++)
				{
					v[i] = v[i + 1];
					v[i].code--;
				}
				break;
			}
			vertexNum--;
			cout << "删除成功，请继续！！！" << endl;
			delete_road(get_delete_scene_index);
			return;
		}
		else if (way == 2)
		{
		while (true)
		{
			cout << endl << "请输入您要删除景点的名称:";
			int index2 = -1;
			string de_name;
			cin >> de_name;
			for (int j = 1; j <= vertexNum; j++)
			{
				if (v[j].name == de_name)
				{
					index2 = j;
					get_delete_scene_index = index2;
				}
			}
			if (index2 = -1)
			{
				cout << endl << "您输入的景点名称格式错误，请重新输入" << endl;
				continue;
			}
			for (int i = index2; i <= vertexNum; i++)
			{
				v[i] = v[i + 1];
				v[i].code--;
			}
			break;
		}
		vertexNum--;
		cout << "删除成功！请继续" << endl;
		delete_road(get_delete_scene_index);
		return;
		}
		else
		{
		cout << endl << "您选择的删除景点的方式错误！请重新输入" << endl;         //输入方式错误，继续执行循环
		 }
	}
}

//增加道路函数
void MGraph::increase_road()
{
	for (int i = 1; i < MaxSize; i++)
	{
		if (v[i].code > 0)
		{
			cout << setiosflags(ios::left) << setw(2) << v[i].code << setw(15) << v[i].name;
			if (i % 4 == 0)
				cout << endl;
		}
	}
	while (true)
	{
		int from;
		int to;
		cout << endl << "请按照景点编号的方式输入您要增加道路的起点和终点（数字之间用空格分隔）:" << endl;
		cin >> from;
		cin >> to;
		if ((from<1 || from>vertexNum) || (to<1 || to>vertexNum))
		{
			cout << endl << "您输入的起点或者终点不存在,请重新输入" << endl;
			continue;
		}
		cout << endl << "您输入的景点编号正确！" << endl;
		cout << endl << "您输入的增加道路的起点是" << v[from].name << "    输入的增加道路的终点是:" << v[to].name << endl;
		cout << endl << "请输入" << v[from].name << "到" << v[to].name << "之间的路径长度" << endl;
		int distance;
		cin >> distance;
		arc[from][to] = distance;
		arc[to][from] = distance;
		cout << "增加道路成功！" << endl;
		cout << "从" << v[from].name << "到" << v[to].name << "之间的路径长度为：" << arc[from][to] << endl;
		break;
	}
	cout << "原校园平面图如下" << endl;
	paint_map();
	cout << endl << "更改后图对应的邻接矩阵如下：" << endl << endl;
	for (int i = 1; i <= vertexNum; i++)
	{
		for (int j = 1; j <= vertexNum; j++)
		{
			if (arc[i][j] != maxinum)
			{
				cout << setiosflags(ios::left) << setw(5) << arc[i][j];
			}
			else if (i == j)
			{
				cout << setiosflags(ios::left) << setw(5) << "0";
			}
			else
			{
				cout << setiosflags(ios::left) << setw(5) << "∞";
			}
			if (j % vertexNum == 0)//vertexNum为景点数
			{
				cout << endl;
			}
		}
	}
}

//删除道路函数
void MGraph::delete_road()
{
	for (int i = 1; i < MaxSize; i++)
	{
		if (v[i].code > 0)
		{
			cout << setiosflags(ios::left) << setw(2) << v[i].code << setw(15) << v[i].name;
			if (i % 4 == 0)
			{
				cout << endl;
			}
		}
	}
	while (true)
	{
		int from;
		int to;
		cout << endl << "请按照景点编号的方式输入您要删除道路的起点和终点（数字之间用空格分隔）:" << endl;
		cin >> from;
		cin >> to;
		if ((from<1 || from>vertexNum) || (to<1 || to>vertexNum))
		{
			cout << endl << "您输入的起点或者终点不存在,请重新输入" << endl;
			continue;
		}
		cout << endl << "您输入的景点编号正确！" << endl;
		cout << endl << "您输入删除道路的起点是:" << v[from].name << "   输入的删除道路的终点是:" << v[to].name << endl;
		arc[from][to] = maxinum;
		arc[to][from] = maxinum;
		cout << "删除道路成功！" << endl;
		cout << "原校园平面图如下：" << endl;
		paint_map();
		cout << endl << "更改后图对应的邻接矩阵如下：" << endl << endl;
		for (int i = 1; i <= vertexNum; i++)
		{
			for (int j = 1; j <= vertexNum; j++)
			{
				if (arc[i][j] != maxinum)
				{
					cout << setiosflags(ios::left) << setw(5) << arc[i][j];
				}
				else if (i == j)
				{
					cout << setiosflags(ios::left) << setw(5) << "0";
				}
				else
				{
					cout << setiosflags(ios::left) << setw(5) << "∞";

				}
				if (j % vertexNum == 0)
					cout << endl;
			}
		}
		break;
	}
}

//修改景点信息函数
void MGraph::change_scene()
{
	for (int i = 1; i < MaxSize; i++)
	{
		if (v[i].code > 0)
		{
			cout << setiosflags(ios::left) << setw(2) << v[i].code << setw(15) << v[i].name;
			if (i % 4 == 0)
				cout << endl;
		}
	}
	while (true)
	{
		cout << endl << "请输入您要更改景点的编号：" << endl;
		int index;
		cin >> index;
		getchar();
		if (index<1 || index>vertexNum)
		{
			cout << endl << "您输入的景点编号有误！请重新输入" << endl;
			continue;
		}
		string name;
		string introduce;
		v[index].name = "";
		v[index].introduce = "";
		cout << endl << "请输入你要更改景点后的名字" << endl;
		getline(cin, name);
		v[index].name = name;
		cout << endl << "请输入你要更改景点后的景点介绍" << endl;
		getline(cin, introduce);
		v[index].introduce = introduce;
		break;
	}
	cout << "更改成功，请继续！" << endl;
}

//规划最短路径
void MGraph::plan_shortestroad()
{
	for (int i = 1; i < MaxSize; i++)
	{
		if (v[i].code > 0)
		{
			cout << setiosflags(ios::left) << setw(2) << v[i].code << setw(15) << v[i].name;
			if (i % 4 == 0)
			{
			    cout << endl;
			}
			
		}
	}
	while (true)
	{
		cout << endl << "请输入出发点编号和终点的编号（数字之间用空格隔开）：" << endl;
		int from;
		int to;
		cin >> from;
		cin >> to;
		cout << "您选择的出发点是" << v[from].name << " 终点是" << v[to].name;
		if ((from<1 || from>vertexNum) || (to<1 || to>vertexNum))
		{
			cout << "您输入的出发点或者终点编号有误！请重新输入" << endl;
			continue;
		}
		//弗洛伊德算法规划最短路径
		string path[MaxSize][MaxSize];//声明路径方案字符串
		int dist[MaxSize][MaxSize];//声明图中权值数组
		for (int i = 1; i <= vertexNum; i++)
		{
			for (int j = 1; i <= vertexNum; j++)
			{
				dist[i][j] = arc[i][j];
				if (dist[i][j] != maxinum)
				{
					path[i][j] = v[i].name + "——>" + v[j].name + ",";
				}
				else
				{
					path[i][j] = "";
				}
			}
			for (int k = 1; k <= vertexNum; k++)
			{
				for (int i = 1; i <= vertexNum; i++)
				{
					for (int j = 1; j <= vertexNum; j++)
					{
						if (dist[i][k] + dist[k][j] < dist[i][j])
						{
							dist[i][j] = dist[i][k] + dist[k][j];
							path[i][j] = path[i][k] + path[k][j];
						}
					}
				}
			}
			cout << endl << "规划最短路径成功！" << endl;
			for (int i = 2; i > 0; i--)
			{
				system("cls");
				cout << endl << "程序将在第" << i << "秒后展示出规划方案" << endl;
				Sleep(1000);
			}

		}
		cout << endl << "从" << v[from].name << " 到 " << v[to].name << "的最短路径为" << dist[from][to] << "米" << endl;
		cout << "最短路径方案为：" << endl << endl << path[from][to] << endl;
		break;
	}
}



//增加道路重载函数（新建景点与原景点之间增加道路）
void MGraph::increase_road(int from, int to)
{
	cout << "您要增加的道路是新建景点" << v[from].name << " 与原景点" << v[to].name << "之间的道路" << endl;
	cout << endl << "请输入" << v[from].name << "到" << v[to].name << "之间的路径长度" <<endl;
	int distance;
	cin >> distance;
	arc[from][to] = distance;
	arc[to][from] = distance;
	cout << "增加道路成功！" << endl;
	cout << "从" << v[from].name << "到" << v[to].name << "间的路径长度为：" << arc[from][to] << endl;
	cout << "原校园平面图如下：" << endl;
	paint_map();
	cout << endl << "更改后图对应的邻接矩阵如下：" << endl << endl;
	for(int i=1;i<=vertexNum;i++)
	{
		for (int j = 1; j <= vertexNum; j++)
		{
			if (arc[i][j] != maxinum)
			{
				cout << setiosflags(ios::left) << setw(5) << arc[i][j];
			}
			else if (i == j)
			{
				cout << setiosflags(ios::left) << setw(5) << "0";
			}
			else
			{
				cout << setiosflags(ios::left) << setw(5) << "∞";
			}
			if (j % vertexNum)
			{
				cout << endl;
			}
		}
	}
}

//删除道路重载函数（删除景点后删除所有以其相关的道路）
void MGraph::delete_road(int from) 
{
	for (int i = 0; i < vertexNum; i++)
	{
		arc[from][i] = maxinum;
		arc[i][from] = maxinum;
	}
	cout << endl << "删除道路成功！" << endl;
	cout << endl << "原校园平面图如下：" << endl;
	paint_map();
	cout << endl << "更改后图对应的邻接矩阵如下：" << endl << endl;
	for (int i = 1; i <= vertexNum; i++)
	{
		for (int j = 1; j <= vertexNum; j++)
		{
			if (arc[i][j] != maxinum)
			{
				cout << setiosflags(ios::left) << setw(5) << arc[i][j];
			}
			else if (i == j)
			{
				cout << setiosflags(ios::left) << setw(5) << "0";
			}
			else
			{
				cout << setiosflags(ios::left) << setw(5) << "∞";
			}
			if (j % vertexNum == 0)
				cout << endl;
			
		}
	}
}

//绘图函数
void MGraph::paint_map()
{
	cout << "                   116                             187                     " << endl;
	cout << "长虹会堂2-------------------- - 学校正门1--------------------------德五楼3" << endl;
	cout << "    |                             |                          /       |    " << endl;
	cout << "    |87                           |254               /98             |    " << endl;
	cout << "    |                             |          /                       |    " << endl;
	cout << " 允明楼4                        图书馆5                            82|    " << endl;
	cout << "    |                    /        |         \\                        |    " << endl;
	cout << "    |117          /100            |                 \\90              |    " << endl;
	cout << "    |       /                     |                          \\       |    " << endl;
	cout << "  文澄楼6                     220 |                            陈毅纪念馆7" << endl;
	cout << "    |                             |                                  |    " << endl;
	cout << "    |147                          |                              162 |    " << endl;
	cout << "    |            274              |               161                |    " << endl;
	cout << "  6舍8--------------------------体育馆9-------------------------学校工厂10" << endl;
	cout << "    |                             |                             /         " << endl;
	cout << "    |103                       180|                   /158                " << endl;
	cout << "    |           327               |         /                             " << endl;
	cout << "  4舍11-------------------------足球场12                                  " << endl;
}

//返回主界面函数
void return_main();