#include<iostream>
#include"trade.h"

void tobuy(int &id,int &count)
{
    std::cout << "�����빺����Ʒ�ı��" << std::endl;
    std::cin >> id;
    std::cout << "�����빺����Ʒ������" << std::endl;
    std::cin >> count;
    getchar();
}
void tosell(int& id, int& count)
{
    std::cout << "������������Ʒ�ı��" << std::endl;
    std::cin >> id;
    std::cout << "������������Ʒ������" << std::endl;
    std::cin >> count;
    getchar();
}
void operate()
{
    std::cout << "�����������";
    getchar();
    system("cls");
}
void drawindex()
{
    system("cls");
    std::cout << "\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T " << std::endl;
    std::cout << "\t                ***** ��ƷĿ¼ *****                        " << std::endl;
    std::cout << "\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T " << std::endl;
}
void drawline()
{
    std::cout << "\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T " << std::endl;
}
/*������ģ��*/
void drawmainMenu()
{
    std::cout << "\t==================================================== " << std::endl;
    std::cout << "\t                    ��ӭʹ������ϵͳ                 " << std::endl;
    std::cout << "\t                    1- ������Ʒ                      " << std::endl;
    std::cout << "\t                    2- ������Ʒ                      " << std::endl;
    std::cout << "\t                    3- �����Ʒ                      " << std::endl;
    std::cout << "\t                    4- �鿴��Ʒ��Ϣ                  " << std::endl;
    std::cout << "\t                    5- �鿴�ɹ���¼                  " << std::endl;
    std::cout << "\t                    6- �鿴���ۼ�¼                  " << std::endl;
    std::cout << "\t                    7- �˳�                          " << std::endl;
    std::cout << "\t==================================================== " << std::endl;
}
void drawbuyrecord()
{

    system("cls");
    std::cout << "\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T " << std::endl;
    std::cout << "\t                ***** �ɹ���¼ *****                        " << std::endl;
    std::cout << "\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T " << std::endl;
}
void drawsellrecord()
{

    system("cls");
    std::cout << "\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T " << std::endl;
    std::cout << "\t                ***** ���ۼ�¼ *****                        " << std::endl;
    std::cout << "\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T " << std::endl;
}
int main()
{
    trade MyTrade;
    if (!MyTrade.init())
    {
        MyTrade = trade();
    }
    bool quitFlag = false;
    while (!quitFlag)
    {
        drawmainMenu();
        std::cout << "���������ѡ��:" << std::endl;
        int selection;
        std::cin >> selection;
        getchar();
        int id;
        int count;
        switch (selection)
        {
        case 1:
            drawindex();
            MyTrade.getindex();
            //drawline();
            tobuy(id, count);
            if (MyTrade.buy(id, count))
            {
                system("cls");
                std::cout << "�����ɹ�" << std::endl;
            }
            else {
                system("cls");
                std::cout << "������������" << std::endl;
            }
            operate();
            break;
        case 2:
            drawindex();
            MyTrade.getindex();
            //drawline();
            tosell(id, count);
            if (MyTrade.sell(id, count))
            {
                system("cls");
                std::cout << "�����ɹ�" << std::endl;
            }
            else {
                system("cls");
                std::cout << "������������" << std::endl;
            }
            operate();
            break;
        case 3:
            char name[30];
            float value;
            float cost;
            system("cls");
            std::cout << "��������Ʒ����" << std::endl;
            std::cin >> name;
            getchar();
            std::cout << "�����빺��۸�" << std::endl;
            std::cin >> cost;
            getchar();
            std::cout << "�������۳��۸�" << std::endl;
            std::cin >> value;
            getchar();
            MyTrade.addnew(name, cost, value);
            system("cls");
            std::cout << "�����ɹ�" << std::endl;
            operate();
            break;
        case 4:
            drawindex();
            MyTrade.getindex();
            drawline();
            std::cout << "��������Ʒ���" << std::endl;
            int index;
            std::cin >> index;
            getchar();
            system("cls");
            if (!MyTrade.getinformation(index))
            {
                std::cout << "��Ч����Ʒ��" << std::endl;
                operate();
            }
            else {
                operate();
            }
            break;
        case 5:
            drawbuyrecord();
            MyTrade.getbuyrecord();
            operate();
            break;
        case 6:
            drawsellrecord();
            MyTrade.getsellrecord();
            operate();
            break;
        case 7:
            quitFlag = true;
            break;
        default:
            system("cls");
            std::cout << "��Ч��ѡ��" << std::endl;
            operate();
        }
    }
    MyTrade.save();
    return 0;
}