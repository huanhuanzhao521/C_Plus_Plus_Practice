// ConsoleApplication001.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//爱心
#include <iostream>
#include <math.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
//using namespace std;

/*
void SetColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
}


*/

/*getline的使用例子*/
/*
int main()
{
	
    const int ArrSize = 20;
    char name[ArrSize];
    char dessert[ArrSize];

    std::cout << "Enter your name:" << std::endl;
    std::cin.getline(name, ArrSize);
    std::cout << "Input your favorite dessert:" << std::endl;
    std::cin.getline(dessert, ArrSize);

    std::cout << "I have some delicious:" << dessert << "for you" << name << std::endl;
       
	std::cout << "hello......" << std::endl;
	system("pause");
}
*/

/*get的使用例子*/
/*
int main()
{

    const int ArrSize = 20;
    char name[ArrSize];
    char dessert[ArrSize];

    std::cout << "Enter your name:" << std::endl;
    std::cin.get(name, ArrSize).get();
    std::cout << "Input your favorite dessert:" << std::endl;
    std::cin.get(dessert, ArrSize).get();

    std::cout << "I have some delicious:" << dessert << "for you " << name << std::endl;

    std::cout << "hello......" << std::endl;
    system("pause");
}
*/

/*结构体的用法*/
struct inflatable
{
    //char name[20];
    std::string name;
    float volume;
    double price;
}mr_smith, ms_jones;
int main()
{
   inflatable mr_smith{ "Bambi",0.5,21.99 };
   inflatable ms_jones{ "Godzilla",2000,565.99 };
   std::cout << "The guest " << mr_smith.name << " and " << ms_jones.name << "\n have a combined volume of "
       << mr_smith.price + ms_jones.price << "cubic feet." <<std::endl;
   std::cout << "hellow world!......" << std::endl;
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
