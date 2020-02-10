#include<iostream>
#include<string>
#include<iomanip>
#include<Windows.h>
#include"Graph.h"
using namespace std;
const int maxinum = 1000000;//�ٶ������Ϊһ����
//

//���캯��
MGraph::MGraph()
{
	vertexNum = 12; //���þ�����Ϊ12
	arcNum = 18;//���ñ���Ϊ18

	//��ʼ��������Ϣ
	for (int i = 0; i < MaxSize; i++)
	{
		v[i].code = -1;
		v[i].name = "";
		v[i].introduce = "";
	}

	/*ѧУ12��������Ϣ¼��*/
	v[0].code = 0;
	v[0].name = "�ɶ���ҵѧԺ";
	v[0].introduce = "�ɶ���ҵѧԺ������1913�꣬���Ĵ�ʡ���������ٰ�ı���ԺУ���������������й����������Ĺ���ѧУ֮һ��Ҳ�ǳ���Ԫ˧��ĸУ";

	v[1].code = 1;
	v[1].name = "ѧУ����";
	v[1].introduce = "ѧУ���Ž���У԰��ͨ����Ҳ������ÿ����ѧ�ı�־";


	v[2].code = 2;
	v[2].name = "�������";
	v[2].introduce = "���������ѧУ���Ļ����Һ�ѧ�����ִ��ͻ�Լ����ٰ쳡��";

	v[3].code = 3;
	v[3].name = "����¥";
	v[3].introduce = "����¥��ѧУ���������Ͽεĵط���ѧУѧ������֯���Ἧ�����ڵ�";

	v[4].code = 4;
	v[4].name = "����¥";
	v[4].introduce = "����¥��ȫУ���Ľ�ѧ¥��ѧУ�����Լ��칫�ҵ����ڵ�";

	v[5].code = 5;
	v[5].name = "ͼ���";
	v[5].introduce = "ͼ�����ȫУ������Ľ������ݷݷѧ��ѧϰ���е�ʥ��";

	v[6].code = 6;
	v[6].name = "�ĳ�¥";
	v[6].introduce = "�ĳ�¥��ѧУʦ��ʵ���ң�ѧУ��ѧԺ����ϵ���İ칫��";

	v[7].code = 7;
	v[7].name = "��������";
	v[7].introduce = "���������Ǽ������Ԫ˧�ĵط��������¼�˳���Ԫ˧���¶����굽����Ԫ˧��ΰ���������";

	v[8].code = 8;
	v[8].name = "ѧ��6����";
	v[8].introduce = "ѧ��6�����ֽ���Զ��6��¥����ѧУ������������";

	v[9].code = 9;
	v[9].name = "������";
	v[9].introduce = "��������ѧУ����ѧ����ѵ���߶����ĵط���Ҳ��ѧУ�й�����Э������質�ĵط�";

	v[10].code = 10;
	v[10].name = "ѧУ����";
	v[10].introduce = "ѧУ������һ�Ҿ�����������Ҳ��ѧУѧ��ʵϰ���ر��ǻ�е����רҵʵѵ�ĵط�";

	v[11].code = 11;
	v[11].name = "ѧ��4����";
	v[11].introduce = "ѧ��4������ѧ��6�������ڣ���һ���������ᣬ�Ա�ΪѧУ����";

	v[12].code = 12;
	v[12].name = "����";
	v[12].introduce = "ѧУ���򳡣���ѧУѧ������֯�����Ӫ���ֵĵط�";

	//��ʼ���ڽӾ���
	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; i < MaxSize; j++)
		{
			arc[i][j] = 0;
		}
	}

	//¼�����Ȩ��
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

	//�ڽӾ���ԳƸ�ֵ
	for (int i = 0; i < MaxSize; i++)
	{
		for (int j = 0; i < MaxSize; j++)
		{
			arc[j][i] = arc[i][j];
		}
	}
}

//�鿴������Ϣ����
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
		cout << endl<<"��������Ҫ��ѯ����ı�ţ�1-"<<vertexNum<<"):"<<endl;
		int index = 0;
		cin >> index;
		if (index >= 1 && index << vertexNum)
		{
			cout << endl << "������Ϊ��" << v[index].code << "\t" << v[index].name << endl;
			cout << endl << "�������Ϊ��" << v[index].introduce;
			break;
		}
		else
		{
			cout << "�����������������������룡" << endl;
		}
	}
	
}

//���Ӿ��㺯��
void MGraph::increase_scene()
{
	vertexNum++;
	v[vertexNum].code = vertexNum;
	getchar();
	cout << endl << "��������Ҫ���ӵľ������Ϣ��" << endl;
	cout << endl << "�������Ӿ�������Ϊ��" << endl;
	string name;
	getline(cin, name);
	v[vertexNum].name = name;
	cout << "���������Ӿ���Ľ��ܣ�" << endl;
	string introduce;
	getline(cin, introduce);
	v[vertexNum].introduce = introduce;
	cout << endl << "���Ӿ���ɹ���" << endl;
	for (int i = 1; i < MaxSize; i++)
	{
		if (v[i].code > 0)
		{
			cout << setiosflags(ios::left) << setw(2) << v[i].code << setw(15) << v[i].name ;
			if (i % 4 == 0)//4������ռ��һ��
				cout << endl;
		}
	}
	cout << "������" << v[vertexNum].name << "����������֮��ĵ�·����" << endl;
	while (true)
	{
		int to;
		cout << endl << "��·�����ΪĬ��ֵΪ:" << v[vertexNum].code << v[vertexNum].name <<
			"�����밴�վ����ŵķ�ʽ������Ҫ���ӵ�·���յ�:" << endl;
		cin >> to;
		if (to<1 || to>vertexNum)//?
		{
			cout << "��������������յ㲻����,����������" << endl;
			continue;
		}
		cout << "�����½�������ԭ����֮��ĵ�·�ɹ���" << endl;
		increase_road(v[vertexNum].code, to);//�����½�������ԭ����֮��ĵ�·�ɹ�,��������ӵ�·���غ���
	}

}

//ɾ�����㺯��
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
		cout << "1. ���վ�����ɾ������         2. ���վ�������ɾ������" << endl;
		cout << "������ɾ������ķ�ʽ��1 or 2��" << endl;
		int way;
		cin >> way;
		if (way == 1)
		{
			while (true)
			{
				cout << endl << "��������Ҫɾ���ľ����ţ�1-" << vertexNum << "):";
				int index1;
				cin >> index1;
				get_delete_scene_index = index1;
				if (index1<1 || index1>vertexNum)
				{
					cout << endl << "������ľ�������Ч������������" << endl;
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
			cout << "ɾ���ɹ��������������" << endl;
			delete_road(get_delete_scene_index);
			return;
		}
		else if (way == 2)
		{
		while (true)
		{
			cout << endl << "��������Ҫɾ�����������:";
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
				cout << endl << "������ľ������Ƹ�ʽ��������������" << endl;
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
		cout << "ɾ���ɹ��������" << endl;
		delete_road(get_delete_scene_index);
		return;
		}
		else
		{
		cout << endl << "��ѡ���ɾ������ķ�ʽ��������������" << endl;         //���뷽ʽ���󣬼���ִ��ѭ��
		 }
	}
}

//���ӵ�·����
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
		cout << endl << "�밴�վ����ŵķ�ʽ������Ҫ���ӵ�·�������յ㣨����֮���ÿո�ָ���:" << endl;
		cin >> from;
		cin >> to;
		if ((from<1 || from>vertexNum) || (to<1 || to>vertexNum))
		{
			cout << endl << "��������������յ㲻����,����������" << endl;
			continue;
		}
		cout << endl << "������ľ�������ȷ��" << endl;
		cout << endl << "����������ӵ�·�������" << v[from].name << "    ��������ӵ�·���յ���:" << v[to].name << endl;
		cout << endl << "������" << v[from].name << "��" << v[to].name << "֮���·������" << endl;
		int distance;
		cin >> distance;
		arc[from][to] = distance;
		arc[to][from] = distance;
		cout << "���ӵ�·�ɹ���" << endl;
		cout << "��" << v[from].name << "��" << v[to].name << "֮���·������Ϊ��" << arc[from][to] << endl;
		break;
	}
	cout << "ԭУ԰ƽ��ͼ����" << endl;
	paint_map();
	cout << endl << "���ĺ�ͼ��Ӧ���ڽӾ������£�" << endl << endl;
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
				cout << setiosflags(ios::left) << setw(5) << "��";
			}
			if (j % vertexNum == 0)//vertexNumΪ������
			{
				cout << endl;
			}
		}
	}
}

//ɾ����·����
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
		cout << endl << "�밴�վ����ŵķ�ʽ������Ҫɾ����·�������յ㣨����֮���ÿո�ָ���:" << endl;
		cin >> from;
		cin >> to;
		if ((from<1 || from>vertexNum) || (to<1 || to>vertexNum))
		{
			cout << endl << "��������������յ㲻����,����������" << endl;
			continue;
		}
		cout << endl << "������ľ�������ȷ��" << endl;
		cout << endl << "������ɾ����·�������:" << v[from].name << "   �����ɾ����·���յ���:" << v[to].name << endl;
		arc[from][to] = maxinum;
		arc[to][from] = maxinum;
		cout << "ɾ����·�ɹ���" << endl;
		cout << "ԭУ԰ƽ��ͼ���£�" << endl;
		paint_map();
		cout << endl << "���ĺ�ͼ��Ӧ���ڽӾ������£�" << endl << endl;
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
					cout << setiosflags(ios::left) << setw(5) << "��";

				}
				if (j % vertexNum == 0)
					cout << endl;
			}
		}
		break;
	}
}

//�޸ľ�����Ϣ����
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
		cout << endl << "��������Ҫ���ľ���ı�ţ�" << endl;
		int index;
		cin >> index;
		getchar();
		if (index<1 || index>vertexNum)
		{
			cout << endl << "������ľ�������������������" << endl;
			continue;
		}
		string name;
		string introduce;
		v[index].name = "";
		v[index].introduce = "";
		cout << endl << "��������Ҫ���ľ���������" << endl;
		getline(cin, name);
		v[index].name = name;
		cout << endl << "��������Ҫ���ľ����ľ������" << endl;
		getline(cin, introduce);
		v[index].introduce = introduce;
		break;
	}
	cout << "���ĳɹ����������" << endl;
}

//�滮���·��
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
		cout << endl << "������������ź��յ�ı�ţ�����֮���ÿո��������" << endl;
		int from;
		int to;
		cin >> from;
		cin >> to;
		cout << "��ѡ��ĳ�������" << v[from].name << " �յ���" << v[to].name;
		if ((from<1 || from>vertexNum) || (to<1 || to>vertexNum))
		{
			cout << "������ĳ���������յ�����������������" << endl;
			continue;
		}
		//���������㷨�滮���·��
		string path[MaxSize][MaxSize];//����·�������ַ���
		int dist[MaxSize][MaxSize];//����ͼ��Ȩֵ����
		for (int i = 1; i <= vertexNum; i++)
		{
			for (int j = 1; i <= vertexNum; j++)
			{
				dist[i][j] = arc[i][j];
				if (dist[i][j] != maxinum)
				{
					path[i][j] = v[i].name + "����>" + v[j].name + ",";
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
			cout << endl << "�滮���·���ɹ���" << endl;
			for (int i = 2; i > 0; i--)
			{
				system("cls");
				cout << endl << "�����ڵ�" << i << "���չʾ���滮����" << endl;
				Sleep(1000);
			}

		}
		cout << endl << "��" << v[from].name << " �� " << v[to].name << "�����·��Ϊ" << dist[from][to] << "��" << endl;
		cout << "���·������Ϊ��" << endl << endl << path[from][to] << endl;
		break;
	}
}



//���ӵ�·���غ������½�������ԭ����֮�����ӵ�·��
void MGraph::increase_road(int from, int to)
{
	cout << "��Ҫ���ӵĵ�·���½�����" << v[from].name << " ��ԭ����" << v[to].name << "֮��ĵ�·" << endl;
	cout << endl << "������" << v[from].name << "��" << v[to].name << "֮���·������" <<endl;
	int distance;
	cin >> distance;
	arc[from][to] = distance;
	arc[to][from] = distance;
	cout << "���ӵ�·�ɹ���" << endl;
	cout << "��" << v[from].name << "��" << v[to].name << "���·������Ϊ��" << arc[from][to] << endl;
	cout << "ԭУ԰ƽ��ͼ���£�" << endl;
	paint_map();
	cout << endl << "���ĺ�ͼ��Ӧ���ڽӾ������£�" << endl << endl;
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
				cout << setiosflags(ios::left) << setw(5) << "��";
			}
			if (j % vertexNum)
			{
				cout << endl;
			}
		}
	}
}

//ɾ����·���غ�����ɾ�������ɾ������������صĵ�·��
void MGraph::delete_road(int from) 
{
	for (int i = 0; i < vertexNum; i++)
	{
		arc[from][i] = maxinum;
		arc[i][from] = maxinum;
	}
	cout << endl << "ɾ����·�ɹ���" << endl;
	cout << endl << "ԭУ԰ƽ��ͼ���£�" << endl;
	paint_map();
	cout << endl << "���ĺ�ͼ��Ӧ���ڽӾ������£�" << endl << endl;
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
				cout << setiosflags(ios::left) << setw(5) << "��";
			}
			if (j % vertexNum == 0)
				cout << endl;
			
		}
	}
}

//��ͼ����
void MGraph::paint_map()
{
	cout << "                   116                             187                     " << endl;
	cout << "�������2-------------------- - ѧУ����1--------------------------����¥3" << endl;
	cout << "    |                             |                          /       |    " << endl;
	cout << "    |87                           |254               /98             |    " << endl;
	cout << "    |                             |          /                       |    " << endl;
	cout << " ����¥4                        ͼ���5                            82|    " << endl;
	cout << "    |                    /        |         \\                        |    " << endl;
	cout << "    |117          /100            |                 \\90              |    " << endl;
	cout << "    |       /                     |                          \\       |    " << endl;
	cout << "  �ĳ�¥6                     220 |                            ��������7" << endl;
	cout << "    |                             |                                  |    " << endl;
	cout << "    |147                          |                              162 |    " << endl;
	cout << "    |            274              |               161                |    " << endl;
	cout << "  6��8--------------------------������9-------------------------ѧУ����10" << endl;
	cout << "    |                             |                             /         " << endl;
	cout << "    |103                       180|                   /158                " << endl;
	cout << "    |           327               |         /                             " << endl;
	cout << "  4��11-------------------------����12                                  " << endl;
}

//���������溯��
void return_main();