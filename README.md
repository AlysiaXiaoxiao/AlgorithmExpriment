# 代码文件说明

- dp.cpp：动态规划法
- trackBack：回溯法
- brachBound.cpp：分支限界法

输入参数和格式统一为：物品个数$n$、背包容量$m$、各个物品的重量$w_i$、各个物品的价值$v_i$。

代码的编译运行均在window系统上进行，编译器版本为gcc-11.2.0，输出文件均为同名.exe二进制文件。

# 数据文件说明

数据集名称为：

- knapsack-FSU-01.txt
- knapsack-FSU-02.txt
- knapsack-FSU-03.txt
- knapsack-FSU-04.txt
- knapsack-FSU-05.txt
- knapsack-FSU-06.txt

测试数据统一来源：[Florida State University(FSU): 前 6 个数据集](https://people.sc.fsu.edu/~jburkardt/datasets/knapsack_01/knapsack_01.html)。

格式统一为.txt文件。

文件主要参数为：物品数量、背包容量、物品重量、物品价值。

# 结果文件说明

包括输出的文件名称、使用的应用程序名称、调用的函数名称、参数设置及文件格式等。

输出的文件名称均为和.cpp文件同名的.exe可执行文件。

使用的应用程序为 *Visual Studio Code* 

参数设置为物品个数$n$，背包可承受重量$m$，物品的重量$w_i$，物品的价值$v_i$

输出结果文件名称：

- branchBound-knapsack-01.txt
- branchBound-knapsack-02.txt
- dp-knapsack-03.txt
- dp-knapsack-04.txt
- trackBack-knapsack-05.txt
- trackBack-knapsack-06.txt

文件命名格式为：`使用方法 + 问题名称 + 使用的数据文件编号`

文件格式均为.txt文件。
