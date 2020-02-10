// School_Map.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<Windows.h>
#include"Graph.h"
using namespace std;

void Exit();
void Screen_main(MGraph &MG);

int main()
{
	MGraph G;
	cout << "校园导航图为：" << endl;
	G.paint_map();
	cout << endl;
	while (true)
	{
		cout << endl << "|-----------------------欢迎来到校园导游系统---------------------------------|" << endl << endl;
		cout << "|-----------------------------1.查看景点信息---------------------------------|" << endl << endl;
		cout << "|-----------------------------2.增加景点-------------------------------------|" << endl << endl;
		cout << "|-----------------------------3.删除景点-------------------------------------|" << endl << endl;
		cout << "|-----------------------------4.更改景点信息---------------------------------|" << endl << endl;
		cout << "|-----------------------------5.删除道路-------------------------------------|" << endl << endl;
		cout << "|-----------------------------6.增加道路-------------------------------------|" << endl << endl;
		cout << "|-----------------------------7.规划最短路径---------------------------------|" << endl << endl;
		cout << "|-----------------------------8.退出导游系统---------------------------------|" << endl << endl;
		Screen_main(G);   //调用主界面函数
	}
	system("pause");
	return 0;
}
void Screen_main(MGraph& MG)
{
	while (true)
	{
		int choose;
		cout << endl << "请输入您要选择的功能(1 - 8) :" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			MG.look_scene();
			break;
		case 2:
			MG.increase_scene();
			break; 
		case 3:
			MG.delete_scene();
				break; 
		case 4:
					
			MG.change_scene();
				break; 
		case 5:
			MG.delete_road();
				break; 
		case 6:
			MG.increase_road();
				break; 
		case 7:
			MG.plan_shortestroad();
			MG.paint_map();
				break;
		case 8:
			Exit();
		        break;
		default:
			cout << endl << "您输入错误!" << endl;
			continue;
		}
		getchar();
		while (true)
		{
			char input_again;
			cout << endl << "是否继续(y/n):" << endl;
			cin >> input_again;
			if (input_again == 'N' || input_again == 'n')
			{
				system("cls");
				break;
			}
			else if (input_again == 'Y' || input_again == 'y')
			{
				system("cls");
				break;
			}
			else
			{
				cout << endl << "输入错误!" << endl;
			}
		}
		break;
	}
}
void Exit()
{
	system("cls");
	for (int i = 3; i > 0; i++)
	{
		system("cls");
		cout << endl << "程序将在" << i << "秒后退出" << endl;
		Sleep(1000);
	}
	exit(0);
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
