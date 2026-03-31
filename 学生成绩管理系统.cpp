#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{male,female}gender;
typedef struct student {
	int id;//学号
	char name[20];//姓名
	gender gender;//性别
	char major[30];//专业
	int cls;//班级
	char reserch[100];//研究方向
	char tutor[20];//导师
	int course;//课程综合成绩
	int paper;//论文成绩
	int total;//总成绩
	int rank;//班级排名
	struct student* next;
}student;
student* head = NULL;
void mainmenu();
void menuA();
void menuB();
void menuC();//排序菜单
void menuD();//查询菜单
void menuE();//统计菜单
void read();//读取文件信息至链表函数
void load();//保存链表信息至文件函数
void add();//添加基本资料函数
void change1();//修改基本资料函数
void delet1();//删除基本资料函数
void search1();//查询基本资料函数
void input();//输入成绩数据函数
void change2();//修改成绩数据函数
void delet2();//删除成绩数据函数
void search2();//查询成绩数据函数
void count();//计算总成绩 班级排名函数
void sortall();//所有学生总成绩排序显示函数
void sortclass();//某班学生总成绩排序显示函数
void showall();//分页显示全部学生信息函数
void showclass();//显示某班全部学生信息函数
void showone();//查询显示学生个人信息
void countaverage();//统计显示每个班论文成绩的平均成绩函数
void countunqualified();//统计显示所有论文成绩不合格学生函数
void mainmenu() {
	while (1) {
		system("cls");
		printf(
			"=============================="
			"研究生学生成绩管理系统"
			"==============================\n"
			"1.基本资料数据的维护管理\n"
			"2.成绩数据的维护管理\n"
			"3.排序功能\n"
			"4.查询功能\n"
			"5.统计功能\n"
			"请输入要进行的操作(输入0关闭系统):\n"
		);
		int n;
		scanf("%d", &n);
		switch (n) {
		case 1:menuA(); break;
		case 2:menuB(); break;
		case 3:menuC(); break;
		case 4:menuD(); break;
		case 5:menuE(); break;
		case 0:
			printf("感谢使用学生成绩管理系统\n");
			return;
		default:printf("输入错误!"); break;
		}
	}
}
void menuA() {
	while (1) {
		system("cls");
		printf(
			"=============================="
			"基本资料数据的维护管理"
			"==============================\n"
			"1.添加:（批量、单个）添加学生基本资料数据。\n"
			"2.修改：根据学号来修改任意学生的除学号外的其他基本资料数据。\n"
			"3.删除：根据学号删除一个学生。\n"
			"4.查询：根据学号查询一个学生的基本资料数据。\n"
			"请输入要进行的操作(输入0返回主菜单):\n"
		);
		int n;
		scanf("%d", &n);
		switch (n) {
		case 1:add(); break;
		case 2:change1(); break;
		case 3:delet1(); break;
		case 4:search1(); break;
		case 0:return;
		default:
			printf("输入错误!"); break;
		}
	}
}
void menuB() {
	while (1) {
		system("cls");
		printf(
			"=============================="
			"成绩数据的维护管理"
			"==============================\n"
			"1.输入:（批量、单个）输入学生成绩数据。\n"
			"2.修改：根据学号来修改任意学生的相关成绩数据。\n"
			"3.删除：根据学号删除一个学生。\n"
			"4.查询：根据学号查询一个学生的成绩数据。\n"
			"5.计算：批量计算所有学生的总成绩、班级排名。\n"
			"请输入要进行的操作(输入0返回主菜单):\n"
		);
		int n;
		scanf("%d", &n);
		switch (n) {
		case 1:input(); break;
		case 2:change2(); break;
		case 3:delet2(); break;
		case 4:search2(); break;
		case 5:count(); break;
		case 0:return;
		default:
			printf("输入错误!");
		}
	}
}
void menuC() {
	while (1) {
		system("cls");
		printf(
			"=============================="
			"           排序功能           "
			"==============================\n"
			"1.所有学生信息按总成绩从高到低排序并显示\n"
			"2.某个班学生信息（即按班号）按总成绩从高到低排序并显示\n"
			"请输入要进行的操作(输入0返回主菜单):\n"
		);
		int n;
		scanf("%d", &n);
		switch (n) {
		case 1:sortall(); break;
		case 2:sortclass(); break;
		case 0:return;
		default:
			printf("输入错误!");
		}
	}
}
void menuD() {
	while (1) {
		system("cls");
		printf(
			"=============================="
			"           查询功能           "
			"==============================\n"
			"1.分页显示全部学生的信息。分页功能：每页显示10条学生的信息，有上一页、下一页、首页和最后一页的功能\n"
			"2.能够按班级显示本班全部学生个人信息。注意：无需分页显示\n"
			"3.能够根据学号或者姓名查询学生信息\n"
			"请输入要进行的操作(输入0返回主菜单):\n"
		);
			int n;
			scanf("%d", &n);
			switch (n) {
			case 1:showall(); break;
			case 2:showclass(); break;
			case 3:showone(); break;
			case 0:return;
			default:
				printf("输入错误!");
		}
	}
}
void menuE() {
	while (1) {
		system("cls");
		printf(
			"=============================="
			"           统计功能           "
			"==============================\n"
			"1.统计并显示每个班论文成绩的平均成绩\n"
			"2.统计并显示所有论文成绩不合格的学生，并最后显示统计的总人数\n"
			"请输入要进行的操作(输入0返回主菜单):\n"
		);
		int n;
		scanf("%d", &n);
		switch (n) {
		case 1:countaverage(); break;
		case 2:countunqualified(); break;
		case 0:return;
		default:
			printf("输入错误!");
		}
	}
}
void read() {
	printf("功能待开发\n");
	system("pause");
}
void load() {
	printf("功能待开发\n");
	system("pause");
}
void add() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void change1() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void delet1() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void search1() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void input() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void change2() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void delet2() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void search2() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void count() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void sortall() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void sortclass() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void showall() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void showclass() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void showone() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void countaverage() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
void countunqualified() {
	system("cls");
	printf("功能待开发\n");
	system("pause");
}
int main() {
	read();
	mainmenu();
	load();
	printf("信息已保存");
	return 0;
}