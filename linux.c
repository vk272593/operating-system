#include<stdio.h>
int nf;
int ns;
struct Faculty
{
    char faculty_name[100];
    int ftime;
}f[10];
struct Student
{
	char student_name[100];
	int stime;
}s[10];
void main()
{   
    int i,f_t_slice,s_t_slice;
    int time1=1,time2=61;
	printf("Enter no. of faculty ");
	scanf("%d",&nf);
	for(i=0;i<nf;i++)
	{
		printf("Enter name of faculty%d ",(i+1));
		scanf("%s",&f[i].faculty_name);
			
		printf("Enter time(in mins) of query for faculty%d ",(i+1));
		scanf("%d",&f[i].ftime);
	}
	printf("Enter no. of students ");
	scanf("%d",&ns);
	for(i=0;i<ns;i++)
	{
		printf("Enter name of student%d ",(i+1));
		scanf("%s",&s[i].student_name);
		printf("Enter time(in mins) of query for student%d ",(i+1));
		scanf("%d",&s[i].stime);
	}
	//			printf("%s query cannot be heard for so long ",f[1].faculty_name);
	f_t_slice=60/nf;
	s_t_slice=60/ns;
	printf("Faculty:-----------------\n");

	for(i=0;i<nf;i++)
	{  
	if(f[i].ftime>f_t_slice)
		{
			time1=time1+f_t_slice;
		printf("%s query cannot be heard for so long \n",f[i].faculty_name);
		}
		else if(f[i].ftime==f_t_slice)
		{
			time1=time1+f_t_slice;
			printf("%s query has been heard\n ",f[i].faculty_name);
		}
	    else
		{
			time1=time1+f[i].ftime;
		printf("%s query has been heard \n",f[i].faculty_name);
	}
	}
	printf("Student:-----------------\n");
	for(i=0;i<ns;i++)
	{
		if(s[i].stime>s_t_slice)
		{
			time2+=s_t_slice;
			printf("%s query cannot be heard for so long \n",s[i].student_name);
		}
		else if(s[i].stime=s_t_slice)
		{
			time2+=s_t_slice;
			printf("%s query has been heard \n",s[i].student_name);
		}
		else
		{
			time2+=s[i].stime;
			printf("%s query has been heard \n",s[i].student_name);
		}
	}
    int	total=time1+time2-60;
	int avg=total/(nf+ns);
	printf("Total querying time = %d \n",total);
	printf("Average querying time = %d \n",avg);
}
