﻿========================================================================
    WIN32 应用程序：吃豆子游戏项目概述
========================================================================

应用程序向导已为您创建了此 pacman 应用程序。

本文件概要介绍组成 pacman 应用程序的每个文件的内容。


pacman.vcxproj
    这是使用应用程序向导生成的 VC++ 项目的主项目文件，
    其中包含生成该文件的 Visual C++ 
    的版本信息，以及有关使用应用程序向导选择的平台、配置和项目功能的信息。

pacman.vcxproj.filters
    这是使用“应用程序向导”生成的 VC++ 项目筛选器文件。 
    它包含有关项目文件与筛选器之间的关联信息。 在 IDE 
    中，通过这种关联，在特定节点下以分组形式显示具有相似扩展名的文件。
    例如，“.cpp”文件与“源文件”筛选器关联。

pacman.cpp
    这是主应用程序源文件。

/////////////////////////////////////////////////////////////////////////////
应用程序向导创建了下列资源：

包含文件：
framework.h
GMap.h
GObject.h
pacman.h
Resource.h
targetver.h
源文件：
pacman.cpp
GObject.cpp
GMap.cpp
framework.cpp

Resource.h
    这是标准头文件，可用于定义新的资源 ID。
    Microsoft Visual C++ 将读取并更新此文件。

pacman.ico
    这是用作应用程序图标 (32x32) 的图标文件。
    此图标包括在主资源文件 pacman.rc 中。

small.ico
    这是一个图标文件，其中包含应用程序的图标的较小版本 (16x16)。 
    此图标包括在主资源文件 pacman.rc 中。

/////////////////////////////////////////////////////////////////////////////
其他标准文件：

StdAfx.h，StdAfx.cpp
    这些文件用于生成名为 pacman.pch 的预编译头 (PCH) 文件和
    名为 StdAfx.obj 的预编译类型文件。

/////////////////////////////////////////////////////////////////////////////
注意：在编写的时候注意头文件，容易出现头文件依赖报错！

/////////////////////////////////////////////////////////////////////////////
