#define _CRT_SECURE_NO_WARNINGS 1


#include<string>
#include<fstream>
#include<iostream>

struct job
{
	char name[40];
	double salary;
	int floor;
	int(*spp)(void* ps, double t);
};

//explicit specialization  显式具体化
template<typename T>
void Swap(T &a, T &b);
template<>void Swap<job>(job &j1, job &j2);//此处声明的含义是使用Swap()模板生成job 类型的函数定义
void Show(job &j);

int main(char argc, char** argv)
{
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i,j=" << i << "," << j << endl;
	cout << "using compiler-generated int swapper: \n";
	Swap(i, j);     //generates void Swap(int &a,int &b)
	cout << "now i,j=" << i << ',' << j << endl;

	job sue = { "susan yaffee",73000.6,7 };
	job kong = { "fanyin kong",80000.0,66 };
	cout << "before job swaping: \n";
	Show(sue);
	Show(kong);

	Swap(sue, kong);        //uses void Swap(job &,job &)
	cout << "after job swapped:\n";
	Show(sue);
	Show(kong);
	return 0;
}
template<typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
void Show(job &j)
{
	using namespace std;
	cout <<"姓名："<< j.name << endl;
	cout <<"薪资："<< j.salary <<"$"<< endl;
	cout <<"办公楼层："<< j.floor << endl;
}
template<>void Swap<job>(job &j1, job &j2)  //specialization 
{
	int t1;
	double t2;
	t2 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t2;
	t1 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t1;
}