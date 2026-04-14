#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum { male, female }gender;
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
int next_id=1001;
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
			"2.按班级显示本班全部学生个人信息。注意：无需分页显示\n"
			"3.根据学号或者姓名查询学生信息\n"
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
	FILE* fp;
	if ((fp = fopen("student.dat", "rb")) == NULL) {
		head = NULL;
		printf("无历史数据，已自动创建新文件\n");
		system("pause");
		return;
	}
	student* p, * q;
	p = head;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	head = NULL;
	student* tail = NULL;
	student temp;
	int max_id = 1000;
	while (fread(&temp, sizeof(student), 1, fp) == 1) {
		student* node = (student*)malloc(sizeof(student));
		*node = temp;
		node->next = NULL;
		if (head == NULL) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
		if (node->id > max_id)
			max_id = node->id;
	}
	fclose(fp);
	next_id = max_id + 1;
	printf("已读取上次保存的数据\n");
	system("pause");
}
void load() {
	FILE* fp = fopen("student.dat", "wb"); 
	if (fp == NULL) {
			printf("文件打开失败，数据保存失败！\n");
			system("pause");
			return;
	}
	student* p = head;
	while (p != NULL) {
			fwrite(p, sizeof(student), 1, fp);
			p = p->next;
	}
	fclose(fp);
	printf("所有学生数据已成功保存！\n");
	system("pause");
}
void add() {
	system("cls");
	int choice;
	printf("=============================="
		   "学生基本资料添加"
		   "==============================\n"
		   "1.单个添加学生\n"
		   "2.批量添加学生\n");
	scanf("%d", &choice);
	getchar();
	if (choice == 1) {
		student* new_node = (student*)malloc(sizeof(student));
		new_node->next = NULL;
		new_node->id = next_id++;
		printf("姓名：");
		scanf("%s",&new_node->name);
		printf("性别(0=男,1=女)：");
		scanf("%d", (int*)&new_node->gender);
		printf("专业：");
		scanf("%s",&new_node->major);
		printf("班级：");
		scanf("%d", &new_node->cls);
		printf("研究方向：");
		scanf("%s",&new_node->reserch);
		printf("导师：");
		scanf("%s",&new_node->tutor);
		new_node->course = -1;
		new_node->paper = -1;
		new_node->total = -1;
		new_node->rank = -1;
		if (head == NULL) {
			head = new_node;
		}
		else {
			student* p = head;
			while (p->next != NULL) {
				p = p->next; 
			}
			p->next = new_node; 
		}
		printf("\n单个学生添加成功\n");
	}
	else if (choice == 2) {
		int num;
		printf("\n请输入要添加的学生数量：");
		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			printf("\n===== 第 %d 个学生 =====\n", i + 1);
			student* new_node = (student*)malloc(sizeof(student));
			new_node->next = NULL;
			new_node->id = next_id++;
			printf("姓名：");
			scanf("%s",&new_node->name);
			printf("性别(0=男,1=女)：");
			scanf("%d", (int*)&new_node->gender);
			printf("专业：");
			scanf("%s",&new_node->major);
			printf("班级：");
			scanf("%d", &new_node->cls);
			printf("研究方向：");
			scanf("%s",&new_node->reserch);
			printf("导师：");
			scanf("%s",&new_node->tutor);
			new_node->course = -1;
			new_node->paper = -1;
			new_node->total = -1;
			new_node->rank = -1;
			if (head == NULL) {
				head = new_node;
			}
			else {
				student* p = head;
				while (p->next != NULL) {
					p = p->next;
				}
				p->next = new_node;
			}
		}
			printf("\n批量添加 %d 名学生成功\n", num);
	}
	else {
		printf("输入错误\n");
	}
	system("pause");
}
void change1() {
	system("cls");
	if (head == NULL) {
		printf("暂无学生数据，无法修改\n");
		system("pause");
		return;
	}
	int target_id;
	printf("=============================="
		   "修改学生基本资料"
		   "==============================\n"
		   "请输入要修改的学生学号：");
	scanf("%d", &target_id);
	student* p = head;
	while (p != NULL && p->id != target_id) {
		p = p->next;
	}
	if (p == NULL) {
		printf("未找到学号为%d的学生\n", target_id);
		system("pause");
		return;
	}
	int choice;
	while (1) {
		system("cls");
		printf("===== 当前修改学生：%s（学号：%d）=====\n", p->name, p->id);
		printf("1.修改姓名\n"
			"2.修改性别\n"
			"3.修改专业\n"
			"4.修改班级\n"
			"5.修改研究方向\n"
			"6.修改导师\n"
			"0.保存并退出修改\n");
		scanf("%d", &choice);
		switch (choice) {
		case 0:
			printf("修改已保存\n");
			system("pause");
			return;
		case 1:
			printf("新姓名：");
			scanf("%s", &p->name);
			printf("姓名修改成功\n");
			system("pause");
			break;
		case 2:
			printf("新性别(0=男,1=女)：");
			scanf("%d", (int*)&p->gender);
			printf("性别修改成功\n");
			system("pause");
			break;
		case 3:
			getchar();
			printf("新专业：");
			scanf("%s", &p->major);
			printf("专业修改成功\n");
			system("pause");
			break;
		case 4:
			printf("新班级：");
			scanf("%d", &p->cls);
			printf("班级修改成功\n");
			system("pause");
			break;
		case 5:
			printf("新研究方向：");
			scanf("%s", &p->reserch);
			printf("研究方向修改成功\n");
			system("pause");
			break;
		case 6:
			printf("新导师：");
			scanf("%s", &p->tutor);
			printf("导师修改成功\n");
			system("pause");
			break;
		default:
			printf("输入错误\n");
			system("pause");
			break;
		}
	}
	system("pause");
}
void delet1() {
	system("cls");
	if (head == NULL) {
		printf("暂无学生数据，无需删除\n");
		system("pause");
		return;
	}
	int target_id;
	printf("=============================="
	       "删除学生基本资料"
		   "==============================\n"
		   "请输入要删除的学生学号：");
	scanf("%d", &target_id);
	student* p = head, * prev = NULL;
	while (p != NULL && p->id != target_id) {
		prev = p;
		p = p->next;
	}
	if (p == NULL) {
		printf("未找到学号为%d的学生\n", target_id);
		system("pause");
		return;
	}
	if (prev == NULL) {
		head = head->next;
	}
	else {
		prev->next = p->next;
	}
	free(p);
	printf("学号%d的学生已成功删除\n", target_id);
	system("pause");
}
void search1() {
	system("cls");
	if (head == NULL) {
		printf("当前没有任何学生数据！\n");
		system("pause");
		return;
	}
	int target_id;
	printf("=============================="
		"查询学生基本资料"
		"==============================\n");
	printf("请输入要查询的学生学号：");
	scanf("%d", &target_id);
	student* p = head;
	while (p != NULL) {
		if (p->id == target_id) {
			system("cls");
			printf("======================================"
				"学生基本信息"
				"=======================================\n");
			printf("学号：%d\n", p->id);
			printf("姓名：%s\n", p->name);
			printf("性别：%s\n", (p->gender == 0) ? "男" : "女");
			printf("专业：%s\n", p->major);
			printf("班级：%d\n", p->cls);
			printf("研究方向：%s\n", p->reserch);
			printf("导师：%s\n", p->tutor);
			system("pause");
			return;
		}
		p = p->next;
	}
	printf("\n未找到学号为%d的学生\n", target_id);
	system("pause");
}
void input() {
	system("cls");
		int choice;
		printf("==============================成绩数据录入==============================\n");
		printf("1.单个录入学生成绩\n");
		printf("2.批量录入学生成绩\n");
		printf("请选择：");
		scanf("%d", &choice);
		int num = 1;
		switch (choice) {
		case 1:
			break;
		case 2:
			printf("请输入需要录入成绩的学生人数：");
			scanf("%d", &num);
			if (num <= 0) {
				printf("人数输入无效！\n");
				system("pause");
				return;
			}
			break;
		default:
			printf("输入错误！\n");
			system("pause");
			return;
		}
		for (int i = 0; i < num; i++) {
			int id;
			printf("\n===== 第 %d 个学生 =====\n", i + 1);
			printf("请输入学生学号：");
			scanf("%d", &id);
			student* p = head;
			while (p != NULL && p->id != id) {
				p = p->next;
			}
			if (p == NULL) {
				printf("未找到学号为 %d 的学生，跳过该学生！\n", id);
				continue;
			}
			printf("找到学生：%s\n", p->name);
			int c;
			while (1) {
				printf("请输入课程综合成绩（0-100，-1表示无成绩）：");
				scanf("%d", &c);
				if ((c >= 0 && c <= 100) || c == -1) {
					p->course = c;
					break;
				}
				else {
					printf("成绩无效！请重新输入！\n");
				}
			}
			int psc;
			while (1) {
				printf("请输入论文成绩（0-100，-1表示无成绩）：");
				scanf("%d", &psc);
				if ((psc >= 0 && psc <= 100) || psc == -1) {
					p->paper = psc;
					break;
				}
				else {
					printf("成绩无效！请重新输入！\n");
				}
			}
			p->total = -1;
			p->rank = -1;

			printf("=> 学号 %d 成绩录入成功！\n", id);
		}
		printf("\n所有成绩录入完成！\n");
		system("pause");
	}
void change2() {
	system("cls");
	if (head == NULL) {
		printf("暂无学生数据，无法修改\n");
		system("pause");
		return;
	}
	int target_id;
	printf("==============================修改学生成绩数据==============================\n");
	printf("请输入要修改的学生学号：");
	scanf("%d", &target_id);
	student* p = head;
	while (p != NULL && p->id != target_id) {
		p = p->next;
	}
	if (p == NULL) {
		printf("未找到学号为%d的学生\n", target_id);
		system("pause");
		return;
	}
	int choice;
	while (1) {
		system("cls");
		printf("===== 当前修改学生：%s（学号：%d）=====\n", p->name, p->id);
		printf("1.修改课程综合成绩\n");
		printf("2.修改论文成绩\n");
		printf("0.保存并退出修改\n");
		scanf("%d", &choice);
		if (choice == 0) {
			break;
		}
		switch (choice) {
		case 1:
			printf("输入新的课程综合成绩（0-100，-1表示无成绩）：");
			scanf("%d", &p->course);
			printf("课程综合成绩修改成功\n");
			break;
		case 2:
			printf("输入新的论文成绩（0-100，-1表示无成绩）：");
			scanf("%d", &p->paper);
			printf("论文成绩修改成功\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
		system("pause");
	}
	printf("修改已保存\n");
	system("pause");
}
void delet2() {
	system("cls");
	if (head == NULL) {
		printf("暂无学生数据，无法删除\n");
		system("pause");
		return;
	}
	int target_id;
	printf("==============================删除学生成绩数据==============================\n");
	printf("请输入要删除成绩的学生学号：");
	scanf("%d", &target_id);
	student* p = head;
	while (p != NULL && p->id != target_id) {
		p = p->next;
	}
	if (p == NULL) {
		printf("未找到学号为%d的学生\n", target_id);
		system("pause");
		return;
	}
	p->course = -1;
	p->paper = -1;
	p->total = -1;
	p->rank = -1;
	printf("学号%d的学生成绩已清空（置为-1）\n", target_id);
	system("pause");
}
void search2() {
	system("cls");
	if (head == NULL) {
		printf("当前没有任何学生数据！\n");
		system("pause");
		return;
	}
	int target_id;
	printf("=============================="
		"查询学生成绩数据"
		"==============================\n");
	printf("请输入要查询的学生学号：");
	scanf("%d", &target_id);
	student* p = head;
	while (p != NULL) {
		if (p->id == target_id) {
			printf("该学生课程综合成绩为：%d\n", p->course);
			printf("该学生论文成绩为：%d\n", p->paper);
			system("pause");
			return;
		}
		p = p->next;
	}
	printf("未找到学号为%d的学生\n",target_id);
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
	return 0;
}