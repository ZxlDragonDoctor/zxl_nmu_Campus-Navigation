#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
#define MAX   65355
//顶点定义 
typedef struct vertex
{
	int  vnumber;//顶点编号 
	char vname[N];//顶点名称 
	char intro[N];//顶点简绍，信息 
}vertex;
//图定义 
typedef struct 
{
	int vexnum,sidenum;//实际顶点数，边数
	int edge[N][N];//边的集合
	vertex vex[60];//顶点数组 
}map;
map m;
//定义全局变量 
    int adist[N],apath[N];
	int dist[N][N],path[N][N];
	int visited[N];    
//函数声明
void Initmap(); 
void Initnum(); 
int locatevet(map m,int v); 
void Dijkstra(map m,int v);
void DisPath(map m,int dist[],int path[],int s[],int v); 
void floyd(map m);
void mapintro(map m);
void menu();
void schoolmap();
void pathtest(map m,int l,int n,int k);
int allpath(map m);
int newmap(map *m);
int incside(map *m);
int incvet(map *m) ;
int delvet(map *m);
int delside(map *m);
void printmapstr(map m);
int changemap(map *m);
int userlog();
void  mainwork(); 

//初始化图信息 
void Initmap()
{
	
	int i,j;
	m.vexnum=51;//定义顶点个数
	m.sidenum=79;//定义边的条数
    for(i=1;i<=m.vexnum;i++)
    {
    	m.vex[i].vnumber=i;
	}//初始化顶点编号 
	

//初始化顶点信息 
    strcpy(m.vex[1].vname,"西篮球场");            	strcpy(m.vex[1].intro,"位于西校区的篮球场"); 
	strcpy(m.vex[2].vname,"网球场");           	strcpy(m.vex[2].intro,"位于西校区的网球场"); 
	strcpy(m.vex[3].vname,"西区宿舍楼 ");	       strcpy(m.vex[3].intro,"学校最西边宿舍楼群"); 
	strcpy(m.vex[4].vname,"西苑餐厅");	strcpy(m.vex[4].intro,"为西苑学生提供就餐场所"); 
	strcpy(m.vex[5].vname,"西区教学楼");	strcpy(m.vex[5].intro,"30.31号教学楼"); 
	strcpy(m.vex[6].vname,"八号宿舍");	strcpy(m.vex[6].intro,"新建女生宿舍"); 
	strcpy(m.vex[7].vname,"假山公园");	strcpy(m.vex[7].intro," 有假山，水池，走廊亭台，园林"); 
	strcpy(m.vex[8].vname,"菜鸟驿站");strcpy(m.vex[8].intro,"可以收发快递");
	strcpy(m.vex[9].vname,"北天桥");strcpy(m.vex[9].intro,"连接东西校区的桥，偏北"); 
	strcpy(m.vex[10].vname,"超市");strcpy(m.vex[10].intro,"满足师生购物"); 
	strcpy(m.vex[11].vname,"北公寓");strcpy(m.vex[11].intro,"最北边的宿舍楼群"); 
	strcpy(m.vex[12].vname,"北苑餐厅");strcpy(m.vex[12].intro,"北校学生就餐的地方"); 
	strcpy(m.vex[13].vname,"洗浴厅");strcpy(m.vex[13].intro,"为全校学生提供洗浴条件"); 
	strcpy(m.vex[14].vname,"北门");strcpy(m.vex[14].intro,"北校进出口"); 
	strcpy(m.vex[15].vname,"小操场");strcpy(m.vex[15].intro,"位于学校北部，可以踢球跑步"); 
	strcpy(m.vex[16].vname,"音舞学院");strcpy(m.vex[16].intro,"音舞学院教学楼"); 
	strcpy(m.vex[17].vname,"体育馆");strcpy(m.vex[17].intro,"练习舞蹈乒乓球羽毛球排球的地方，含健身房"); 
	strcpy(m.vex[18].vname,"预科教育学院");strcpy(m.vex[18].intro,"提供预科教育"); 
	strcpy(m.vex[19].vname,"商学院");strcpy(m.vex[19].intro,"商学院总部"); 
	strcpy(m.vex[20].vname,"经济学院");strcpy(m.vex[20].intro,"经济学院总部"); 
	strcpy(m.vex[21].vname,"法学院");strcpy(m.vex[21].intro,"法学院总部"); 
	strcpy(m.vex[22].vname,"外国语学院");strcpy(m.vex[22].intro,"外国语学院总部"); 
	strcpy(m.vex[23].vname,"电气学院");strcpy(m.vex[23].intro,"电气学院总部"); 
	strcpy(m.vex[24].vname,"管理学院");strcpy(m.vex[24].intro,"管理学院总部"); 
	strcpy(m.vex[25].vname,"土木学院 ");strcpy(m.vex[25].intro,"土木学院总部"); 
	strcpy(m.vex[26].vname,"计算机学院");strcpy(m.vex[26].intro,"计算机学院总部"); 
	strcpy(m.vex[27].vname,"接待中心");strcpy(m.vex[27].intro,"接待贵宾的地方"); 
	strcpy(m.vex[28].vname,"土木工程实验中心");strcpy(m.vex[28].intro,"土木学院学生进行实验学习的地方"); 
	strcpy(m.vex[29].vname,"启明星幼儿园");strcpy(m.vex[29].intro,"学校东部建立的幼儿园"); 
	strcpy(m.vex[30].vname,"家属楼");strcpy(m.vex[30].intro,"教职工居住的地方"); 
	strcpy(m.vex[31].vname,"南天桥");strcpy(m.vex[31].intro,"连接东西校区的桥，偏南"); 
	strcpy(m.vex[32].vname,"明湖");strcpy(m.vex[32].intro,"学校的湖，景色优美，有黑天鹅出没"); 
	strcpy(m.vex[33].vname,"南公寓");strcpy(m.vex[33].intro,"最南边的宿舍楼群"); 
	strcpy(m.vex[34].vname,"南苑餐厅");strcpy(m.vex[34].intro,"南苑学生就的地方"); 
	strcpy(m.vex[35].vname,"东篮球场");strcpy(m.vex[35].intro,"位于东校区的篮球场"); 
	strcpy(m.vex[36].vname,"网球场");strcpy(m.vex[36].intro,"位于东校区的篮球场"); 
	strcpy(m.vex[37].vname,"图书馆");strcpy(m.vex[37].intro,"学生查询资料书籍的地方"); 
	strcpy(m.vex[38].vname,"大操场");strcpy(m.vex[38].intro,"国家级操场"); 
	strcpy(m.vex[39].vname,"芳华楼");strcpy(m.vex[39].intro,"女生宿舍"); 
	strcpy(m.vex[40].vname,"和谐广场");strcpy(m.vex[40].intro,"处处花香，青石地板，羌笛杨柳，名人雕像，曼妙古亭"); 
	strcpy(m.vex[41].vname,"行政主楼");strcpy(m.vex[41].intro,"学校的行政中心，建筑独特，视野开阔"); 
	strcpy(m.vex[42].vname,"国旗台");strcpy(m.vex[42].intro,"升国旗的地方"); 
	strcpy(m.vex[43].vname,"实验楼");strcpy(m.vex[43].intro,"实验设施多样且完善，有着浓厚的实验气氛"); 
	strcpy(m.vex[44].vname,"德馨楼");strcpy(m.vex[44].intro,"德馨楼"); 
	strcpy(m.vex[45].vname,"医务室");strcpy(m.vex[45].intro,"学生看病的地方"); 
	strcpy(m.vex[46].vname,"基础教育学院");strcpy(m.vex[46].intro,"基础教育学院"); 
	strcpy(m.vex[47].vname,"文化苑");strcpy(m.vex[47].intro,"文化苑"); 
	strcpy(m.vex[48].vname,"留学生宿舍");strcpy(m.vex[48].intro,"留学生宿舍"); 
	strcpy(m.vex[49].vname,"活动中心");strcpy(m.vex[49].intro,"举办各种活动的地方"); 
	strcpy(m.vex[50].vname,"游泳馆");strcpy(m.vex[50].intro,"游泳健身之地"); 
	strcpy(m.vex[51].vname,"东门");strcpy(m.vex[51].intro,"东校进出口"); 
for(i=1;i<=m.vexnum;i++)
  for(j=1;j<=m.vexnum;j++)
      m.edge[i][j]=MAX;//初始化权值 

	m.edge[1][2]=10;	m.edge[1][3]=50;	m.edge[1][4]=50;  	m.edge[1][5]=80;
	m.edge[2][4]=80;  	m.edge[2][5]=80;	   m.edge[3][4]=80;    	m.edge[4][5]=50;
	m.edge[4][7]=200;	m.edge[5][6]=200;	m.edge[5][7]=200;	m.edge[6][8]=50;
	m.edge[6][31]=100;	m.edge[6][7]=150;	m.edge[7][9]=200;	m.edge[7][31]=100;
	m.edge[7][8]=150;	m.edge[8][31]=50;	m.edge[9][10]=80;   m.edge[9][16]=50;	m.edge[10][11]=50;
	m.edge[10][12]=90;	m.edge[11][12]=150;	m.edge[12][13]=50;	m.edge[12][17]=80;
	m.edge[13][14]=20;	m.edge[14][15]=20;	m.edge[15][30]=300;	m.edge[16][17]=80;
    m.edge[18][20]=40;	m.edge[19][30]=250;	m.edge[20][21]=30;	m.edge[21][22]=50;
	m.edge[22][23]=100;m.edge[22][38]=50;     m.edge[22][40]=50;  m.edge[23][24]=80;m.edge[23][40]=80;m.edge[23][41]=120;
	m.edge[24][42]=80;	m.edge[24][25]=80;    m.edge[24][29]=250;	m.edge[25][26]=30;	m.edge[25][27]=80;
	m.edge[26][28]=150;	m.edge[26][51]=150;   m.edge[29][30]=20;	m.edge[31][33]=100;	m.edge[31][32]=100;
	m.edge[32][38]=150;	m.edge[33][34]=100;	m.edge[33][35]=80;	m.edge[34][35]=30;
	m.edge[34][39]=50;m.edge[35][36]=30;	    m.edge[35][38]=80;	m.edge[36][37]=30;	m.edge[37][40]=80;
	m.edge[37][39]=50;	m.edge[38][40]=140;	m.edge[40][41]=50;	m.edge[41][42]=20;
	m.edge[41][43]=90;	m.edge[42][51]=300;	m.edge[43][44]=20;	m.edge[43][50]=150;	
	m.edge[44][45]=250;	m.edge[45][46]=70;	m.edge[46][47]=150;	m.edge[46][51]=130;	
	m.edge[46][47]=120;	m.edge[47][48]=200;	m.edge[48][50]=140;	m.edge[49][50]=20;
for(i=1;i<=m.vexnum;i++)
  for(j=1;j<=m.vexnum;j++)
      m.edge[j][i]=m.edge[i][j];//对称矩阵 


} 
	//查询景点在图中的序号
int locatevet(map m,int v)
{
	int i;
	for(i=1;i<=m.vexnum;i++)
		if(v==m.vex[i].vnumber) return i;//找到返回顶点i
	return 0;//未找到
}
//初始化全局变量
void Initnum()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for( j=0;j<N;j++)
		{
		   dist[i][j]=0;
		   path[i][j]=0;	
		 }	 
	}
	for(i=0;i<N;i++)
	{
		adist[i]=0;
		apath[i]=0;
		visited[i]=0;
	}
	
}
//求两景点所有路径 
void pathtest(map m,int u,int v,int k)
{ 
	int length=0;
	if(apath[k]==v)
	{
		for(int d=0;d<k;d++)
		{
			printf("%s--->",m.vex[apath[d]].vname);
			length+=m.edge[apath[d]][apath[d+1]]; 
		} 
		 printf("%s\n",m.vex[v].vname);
		 printf("从%s到%s的路径为:%d\n",m.vex[u].vname,m.vex[v].vname,length);
	 } 
	 else 
	 {
	  for(int i=1;i<=m.vexnum;i++)
	 	{
		 	if(m.edge[apath[k]][i]<MAX&&visited[i]!=1)
		 	   {
		 		apath[++k]=i;
		 		visited[i]=1;
		 		pathtest(m,u,v,k);
		 		visited[i]=0;//达到终点后，置经过路径未访问 
			    k--;//退栈 
			   }
		 }
		 
	 }
	 
	 
}
int  allpath(map m)
{
	int k,i,j,l,n;
	printf("\n\n请输入您想要查询的两个景点的编号：\n\n");
	scanf("%d%d",&i,&j);printf("\n\n");
	l=locatevet(m,i); 
	n=locatevet(m,j);
	apath[0]=l;
	visited[l]=1;
	pathtest(m,l,n,0);
	return 1;
}
//求最佳游览路线(迪杰斯特拉算法) 
void Dijkstra(map m)
{
	int v;
	printf("请输入起点编号：");
	scanf("%d",&v);
	if(locatevet(m,v)<1||locatevet(m,v)>m.vexnum)
	{
		printf("该编号不存在，请重新输入起点编号：");
		scanf("%d",&v); 
	}
    int s[N];
    int dist[N];
    int path[N];	 
	int minedge;
	int u;
	int i,j;
	for( i=1;i<=m.vexnum;i++)
	{
		s[i]=0;
		dist[i]=m.edge[v][i];
		if(m.edge[v][i]<MAX)
		{
			path[i]=v;
			
		}
		else path[i]=-1;
		
	}
     s[v]=1;
     for(int n=1;n<=m.vexnum-1;n++)
     {
     	minedge=MAX;
         for(j=1;j<=m.vexnum;j++)
         {
         	if(s[j]==0&&dist[j]<minedge)
         	{
         		minedge=dist[j];
         		u=j;
			 }
		 }
		 s[u]=1; 
		 for(j=1;j<=m.vexnum;j++)
		 {
		 	
		 	if(s[j]==0)
		 	{
		 		if(m.edge[u][j]<MAX&&(m.edge[u][j]+dist[u])<dist[j])
		 		{
		 			dist[j]=m.edge[u][j]+dist[u];
		 			path[j]=u;
		 			
				 }
				 
			 }
		 }
	 }
	 printf("所有最佳路线\n"); 
	 DisPath(m,dist,path,s,v);
}
void DisPath(map m,int dist[],int path[],int s[],int v)
{
	int apath[N];
	int  j=0;
	int i;
	int k;
	
	for(i=1;i<=m.vexnum;i++) 
		{
		if(s[i]==1&&v!=i)
		 {
			printf("从%s到%s的最短路径为%d\n",m.vex[v].vname,m.vex[i].vname,dist[i]);
		
		apath[j]=i; 
		k=path[i];
	    
		if(k==-1)
		   printf("无路线");
		else 
		 {
			while(k!=v)
			{
				apath[++j]=k;
				k=path[k];
			 }
			 apath[++j]=v; 	 
		   printf("%s",m.vex[apath[j]].vname);
		   while(j!=0)
		   {
		   	printf("-->%s",m.vex[apath[--j]].vname);
		   }
		   printf("\n");
		    
		}
	  }
    }
		
  } 

//求任意两点间最短路径(弗洛伊德算法) 
void floyd(map m)
{

	int i,j,k;
	for( i=1;i<=m.vexnum;i++)
	{
		for( j=1;j<=m.vexnum;j++)
		{
			dist[i][j]=m.edge[i][j];
			if(i!=j&&m.edge[i][j]<MAX)
			{
				path[i][j]=i;
			}
			else path[i][j]=-1;
		 } 
	 } 
		 
	 for(k=1;k<=m.vexnum;k++)
	    {
	    	for(i=1;i<=m.vexnum;i++)
	          {
		        for(j=1;j<m.vexnum;j++)
		           if(dist[i][j]>(dist[i][k]+dist[k][j]))
		           {
		           	dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[k][j];
			    }
			  }
		}


	int u,v,x,d=0;
	int apath[N];
	printf("请输入起点和终点编号(用空格隔开)\n");
	scanf("%d%d",&u,&v);
	if(locatevet(m,v)==0||locatevet(m,u)==0)
	{
		printf("该起点或终点不存在\n");
		printf("请重新输入起点和终点的编号\n");
		scanf("%d%d",&u,&v);
	}
	apath[d]=v;
	x=path[u][v];
	if(x==-1)
	{
		printf("无路径\n");
	}
	else 
	{
		while(x!=u&&x!=-1)
		   {
		   	apath[++d]=x;
			x=path[u][x];
		   }
		 printf("%s",m.vex[u].vname);
		 for(d;d>=0;d--)
		 {
		 	printf("--->%s",m.vex[apath[d]].vname);
		 }
		 printf("\n");
		 printf("最短路径长度为:%d\n",dist[u][v]);
		 }	 
}
//显示景点信息 
void mapintro(map m)
{
	int i;
	printf(" \n\n编号     景点名称                        简介\n");
	printf("*************************************************************************\n");
	for(i=1;i<=m.vexnum;i++)
	{
		if(m.vex[i].vnumber!=-1)
			printf("%-10d%-25s%-70s\n",m.vex[i].vnumber,m.vex[i].vname,m.vex[i].intro);
	}
	printf("*************************************************************************\n");
}

//主界面 
void menu()
{	printf(" ┌──────────────────────────────────────────────────────┐\n");
	printf(" │ ╭ ═══════════════════════════════════════════════ ╮  │\n");
	printf(" │ ││        欢 迎 使 用 校 园 导 游 系 统          ││  │\n");
  	printf(" │ ╰ ═══════════════════════════════════════════════ ╯  │\n");
  	printf(" │                      欢迎来到                        │\n"); 
  	printf(" │                    北方民族大学                      │\n");
  	printf(" │                     菜 单 选 择                      │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  1.主页                **   2.查看游览路线      * │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  3.查询景点间最短路径  **   4.查询景点间所有路径* │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  5.学校景点介绍        **   6.学校地图          * │\n");
	printf(" │  *************************************************** │\n");
	printf(" │  *  7.更改图信息          **   0.退出              * │\n");
	printf(" │  *************************************************** │\n");
	printf(" └──────────────────────────────────────────────────────┘\n");
}
//学校地图 
void schoolmap()
{
printf(" ________________________________________北方民族大学东校区地图____________________________________________________ \n");
printf("│  │             │                │  │         │ 12 13 14北门____                                                  │ \n");
printf("│  │     3       │        7       │  │11北公寓 │ 北 洗  │       │                                                  │\n");
printf("│ 1│ 西区宿舍楼  │       假       │  │_________│ 苑 浴  │ 小操场│                  30家       属       楼          │\n");
printf("│篮│             │                │  │  10超市   餐 厅  │ 15    │                   29启明星幼儿园      28         │\n");
printf("│  │     4       │            9 北│天│桥         厅     │_______│                                      土实        │\n");
printf("│  │  西苑餐厅   │                │  │              17                                                 木验        │\n");
printf("│球│             │                │  │ 16音舞学院   体  18预科教育学院 19商学院                        工中        │\n");
printf("│  │             │       山       │  │              育          20经济学院                             程心        │\n");
printf("│  │             │                │  │              馆        21法学院                 27接待中心                  │\n");
printf("│场│             │                │  │                                                             26计算机学院    │\n");
printf("│——│             │                │  │   ______          22外国语学院 23电气学院   24管理学院 25土木学院           │\n");
printf("│2 │      5      │                │  │  │  明  │   _______  ________________      41 42                          51│\n");
printf("│网│    西 区    │       公       │  │  │ 32   │  │38 大  ││                │     行 国                          东│\n");
printf("│  │  教 学 楼   │                │  │  │      │  │       ││       40       │     政 旗                          门│\n");
printf("│球│             │                │  │  │      │  │   操  ││   和 谐 广 场  │     主 台                            │\n");
printf("│  │             │                │  │  │      │  │       ││                │     楼                               │\n");
printf("│场│             │                │  │  │  湖  │  │   场  ││________________│                                      │\n");
printf("│__│             │       园       │  │  │______│  │_______│网                                                      │\n");
printf("│                │                │  │                   36球 37图书馆        43实验楼 44德馨楼                    │\n");
printf("│                │________________│  │             35篮球场场                                  45医务室  46基础教  │\n");
printf("│                                 │  │                                                                       学院  │\n");
printf("│   6 八号宿舍                31南│天│桥                                                                           │\n");
printf("│                                 │  │_____________                                                                │\n");
printf("│                 8 菜鸟驿站      │  │            │ 34南苑餐厅39芳华楼        50游泳馆                             │\n");
printf("│                                 │  │  33南公寓  │                         49活动中心 48留学生宿舍     47文化苑   │\n");
printf("│                                 │  │            │                                                                │\n");
printf("│_________________________________│  │____________│________________________________________________________________│\n");

}
//更改图部分信息
int newmap(map *m)
{
	int changenum,i,l,n,t,distance,v0,v1;
	printf("\n下面请输入你要修改的景点的个数：\n");//修改定点对应的景点
	scanf("%d",&changenum);
	while(changenum<0||changenum>m->vexnum)
	{
		printf("\n你的输入有误，请重新输入");
		scanf("%d",&changenum);
	}
	for(i=0;i<changenum;i++)
	{
		printf("\n请输入景点编号：");
		scanf("%d",&l);
		t=locatevet(*m,l);
		printf("\n请输入修改后景点的名称：");
		scanf("%s",&m->vex[t].vname);
		printf("\n请输入修改后景点的简介:");
		scanf("%s",&m->vex[t].intro);
	}
	printf("\n下面请输入你要修改的边的个数");
	scanf("%d",&changenum);
	while(changenum<0||changenum>m->vexnum);
	{
		printf("\n你的输入有误，请重新输入");
		scanf("%d",&changenum);
	}
	if(changenum!=0)
	printf("\n下面请输入更新边的信息：\n");
	for(i=1;i<=changenum;i++)
	{
		printf("\n修改的第%d条边的起点 终点 长度为:",i);
		scanf("%d %d %d",&v0,&v1,&distance);
		l=locatevet(*m,v0);
		n=locatevet(*m,v1);
		if(l>=0&&n>=0)
		{
			m->edge[l][n]=distance;
			m->edge[n][l]=m->edge[l][n];
		}
	}
	return 1;
}
//增加一条边
int incside(map *m)
{
	int l,n,distance;
	printf("\n请输入边的起点和终点编号，权值:");
	scanf("%d%d%d",&l,&n,&distance);
	while(l<0||l>m->vexnum||n<0||n>m->vexnum)
	{
		printf("输入错误，请重新输入");
		scanf("%d %d",&l,&n);
	}
	if(locatevet(*m,l)<0)
	{
		printf("此节点%d已删除",l);
		return 1;
	}
	if(locatevet(*m,n)<0)
	{
		printf("此节点%d已被删除",n);
		return 1;
	}
	m->edge[l][n]=distance;
	m->edge[n][l]=m->edge[l][n];
	m->sidenum ++;
	return 1;
}
//增加一个结点
int incvet(map *m)
{
	int i;
	m->vexnum++;//顶点数加一
	printf("请输入您要增加结点的信息：");
	printf("\n编号:");
	scanf("%d",&m->vex[m->vexnum].vnumber);
	printf("名称:");
	scanf("%s",&m->vex[m->vexnum].vname);
	printf("简介:");
	scanf("%s",&m->vex[m->vexnum].intro);
	for(i=1;i<=m->vexnum;i++)
	{
		m->edge[m->vexnum][i]=MAX;
		m->edge[i][m->vexnum]=MAX;
	}
	return 1;
}
//删除一个结点
int delvet(map *m)
{
	int i=0,j,l,v;
	if(m->vexnum<=0)
	{
		printf("图中已无顶点");
		return 1;
	}
	printf("\n下面请输入您要删除的景点编号：");
	scanf("%d",&v);
	while(v<0||v>m->vexnum)
	{	
		printf("\n输入错误！请重新输入:");
		scanf("%d",&v);
	}
	l=locatevet(*m,v);
	if(l<0)
	{	
		printf("顶点%d已删除\n",v);
		return 1;
	}
	for(i=l;i<=m->vexnum-1;i++)
		for(j=1;j<=m->vexnum;j++)//将二维数组中的第m+1行依次向前移动一行（删除第m行） 
	      m->edge[i][j]=m->edge[i+1][j]; 
	for(i=l;i<=m->vexnum-1;i++)
		for(j=1;j<=m->vexnum;j++)//将二维数组中的第m+1列依次向前移动一列（删除第m列）
		  m->edge[j][i]=m->edge[j][i+1];
	m->vex[v].vnumber=-1;//表示此点已删除，后期打印也不会显示该点 
	m->vexnum--;//顶点个数-1 
	return 1;
}
//删除一条边
int delside(map *m)
{
	int l,n,v0,v1;
	if(m->sidenum<=0)
	{
		printf("图中没有边了，无法删除");
		return 1;
	}
	printf("\n下面请输入您要删除的边的起点和终点编号：");
	scanf("%d %d",&v0,&v1);
	l=locatevet(*m,v0);
	if(m<0)
	{	
		printf("此%d顶点已删除",v0);
		return 1;
	}
	n=locatevet(*m,v1);
	if(n<0)
	{
		printf("此%d顶点已删除",v1);
		return 1;
	}
	m->edge[l][n]=MAX;//将删掉的边的权值改为无穷
	m->edge[n][l]=MAX;
	m->sidenum--;//图的边数减一
	return 1;
}
//输出图的邻接矩阵的值
void printmapstr(map m)
{
	int i,j,k=0;
	for(i=1;i<=m.vexnum;i++)
	{
		if(m.vex[i].vnumber!=-1)
			printf("%4d",i);
	}
	printf("\n");
	for(i=1;i<=m.vexnum;i++)
	{
		for(j=1;j<=m.vexnum;j++)
		{
			if(m.edge[i][j]==MAX)
				printf(" **** ");
			else
				printf("%4d",m.edge[i][j]);
			k++;
			if(k%m.vexnum==0)
				printf("\n");
		}
	}
}
//管理员界面 
int changemap(map *m)
{
	int choice;
		
	printf("(1)删除结点  (1)删除边\n");
	printf("(3)增加结点     (4)增加边    (5)更新信息\n");
	printf("(6)输出邻接矩阵 (7)返回主页		\n");
	do
	{
		printf("请输入你的选择：");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:delvet(m);break;
			case 2:delside(m);break;
			case 3:incvet(m);break;
			case 4:incside(m);break;
			case 5:newmap(m);break;
			case 6:printmapstr(*m);break;		
			case 7:system("cls");menu();return 1;
			default:printf("未找到该功能，请输入有效选项！\n");break;
		}
	}while(choice);
}
int userlog()
    {
	int i;
	int a[6]={1,2,3,1,2,3},b[6];
	printf("\n请输入六位密码(用空格隔开)：\n");
	for(i=0;i<6;i++)
		scanf("%d",&b[i]);
	for(i=0;i<6;i++)
	{
		if(a[i]!=b[i])
		{
			printf("密码错误！自动返回主页面\n");
			menu();
			return 0;
		}
	}
	printf("密码正确，登陆成功！\n\n");
	changemap(&m);
}

void mainwork()
{
	
	Initmap();
	menu();
	int choice;
	
	do
	{
		printf("请输入你的选择:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:system("cls");menu();break;
		case 2:system("cls");Initnum();Dijkstra(m); break;
		case 3:system("cls");Initnum();floyd(m);break;
		case 4:system("cls");Initnum();allpath(m);break;
		case 5:system("cls");mapintro(m);break;
		case 6:system("cls");schoolmap();break;
		case 7:system("cls");userlog();break;
		case 0:system("cls");printf("谢谢使用\n");break;
		default:printf("未找到该功能，请输入有效选项！\n");break;
		}
	}while(choice);
}
int main()
{
	
	mainwork();
	return 0;
}
 

    
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     






