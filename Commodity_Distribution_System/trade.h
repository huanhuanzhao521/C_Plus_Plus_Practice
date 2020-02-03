#pragma once
#include<iostream>
#include<list>
#include<string.h>
#include"commodity.h"

class trade
{
    struct record
    {
        char name[30];
        int count; //��������
        char sTime[70];
        record(char* name, int count, char* time)
        {
            strcpy_s(this->name, sizeof(name), name);
            this->count = count;
            strcpy_s(this->sTime, sizeof(sTime), time);
        }
    };
private:
    //��Ա����
    std::list<commodity> datalist;
    std::list<record> sellrecordlist;
    std::list<record> buyrecordlist;

    //��Ա����
public:
    bool getinformation(int index);
    void getindex();
    bool init();
    void save();
    bool buy(int id, int count);
    bool sell(int count, int id);
    void addnew(char name[], float buyvalue, float sellvalue);
    void getsellrecord();
    void getbuyrecord();

};