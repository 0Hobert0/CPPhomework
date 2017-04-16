### 题目描述
有一个学生类student，包括学生姓名、成绩，一个教师类teacher，包括教师姓名、职称。两个类共用一个友员函数print（……），输出相关信息：学生姓名、成绩、教师姓名、职称。
print（……）函数中的输出语句如下，请复制使用
> cout<<"student's name:"<<S.name<<"   "<<S.score<<endl;
>cout<<"Teacher's name:"<<T.name<<"   "<<T.pro<<endl;

main（）函数如下，请复制使用
> int main()
> {
>	char stuname[20],teaname[20],teapro[20]; 
>	cout<<"请输入学生姓名："<<endl; 
>	cin>>stuname; 
>	cout<<"请输入教师姓名："<<endl;
>	cin>>teaname;
>	cout<<"请输入教师职称："<<endl;  
>	cin>>teapro;
>	Stu student(stuname,88);
>	Tea teacher(teaname,teapro);
>	print(student,teacher);
>	return 0;
> }

###输入
>wangcheng
zhaokai
professor

###输出
>请输入学生姓名：
wangcheng    //此行为键盘输入内容
请输入教师姓名：
zhaokai    //此行为键盘输入内容
请输入教师职称：
professor    //此行为键盘输入内容
student's name:wangcheng   88
Teacher's name:zhaokai   professor

