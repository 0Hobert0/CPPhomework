### ��Ŀ����
��һ��ѧ����student������ѧ���������ɼ���һ����ʦ��teacher��������ʦ������ְ�ơ������๲��һ����Ա����print������������������Ϣ��ѧ���������ɼ�����ʦ������ְ�ơ�
print�������������е����������£��븴��ʹ��
> cout<<"student's name:"<<S.name<<"   "<<S.score<<endl;
cout<<"Teacher's name:"<<T.name<<"   "<<T.pro<<endl;

main�����������£��븴��ʹ��
> int main()
{
	char stuname[20],teaname[20],teapro[20]; 
	cout<<"������ѧ��������"<<endl; 
	cin>>stuname; 
	cout<<"�������ʦ������"<<endl;
	cin>>teaname;
	cout<<"�������ʦְ�ƣ�"<<endl;  
	cin>>teapro;
	Stu student(stuname,88);
	Tea teacher(teaname,teapro);
	print(student,teacher);
	return 0;
}

###����
>wangcheng
zhaokai
professor

###���
>������ѧ��������
wangcheng    //����Ϊ������������
�������ʦ������
zhaokai    //����Ϊ������������
�������ʦְ�ƣ�
professor    //����Ϊ������������
student's name:wangcheng   88
Teacher's name:zhaokai   professor

