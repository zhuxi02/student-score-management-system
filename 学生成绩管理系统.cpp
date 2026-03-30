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
	int class;//班级
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
void menuC();//查询菜单
void menuD();//统计菜单
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
void menuA(){
    printf("==================================================
                    基本资料数据的维护管理
            ==================================================
        (1)添加:（批量、单个）添加学生基本资料数据。
        (2)修改：根据学号来修改任意学生的除学号外的其他基本资料数据。
        (3)删除：根据学号删除一个学生。
        (4)查询：根据学号查询一个学生的基本资料数据。");
}

void menuB() {
    printf("==================================================
                      成绩数据的维护管理
            ==================================================
        (1)输入:（批量、单个）输入学生成绩数据。成绩数据根据学生类型的不同而有区别，输入的相关数据也应不同。注意：总成绩、班级排名是计算项，不能输入。
        (2)修改：根据学号来修改任意学生的相关成绩数据（注意：不同类别学生相关数据不同）。
        (3)删除：根据学号删除一个学生（不能删除，只需将相关数据项设置成 - 1）。
        (4)查询：根据学号查询一个学生的成绩数据。
        (5)计算：批量计算所有学生的总成绩、班级排名。注意，只有各项数据都为有效数据时（ - 1为无效数据），才能计算。"
                );
}
