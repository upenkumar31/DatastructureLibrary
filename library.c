#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void matmult(int a[10][10],int b[10][10],int m,int n,int o,int p);
void matmult(int a[10][10],int b[10][10],int m,int n,int o,int p)
{
 int i,j,k,c[10][10];
 if(n==o)
 {
  printf("Enter the elements of matrix A row wise\n");
  for(i=0;i<m;i++)
   for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
  printf("Enter the elements of matrix B row wise\n");
  for(i=0;i<o;i++)
   for(j=0;j<p;j++)
    scanf("%d",&b[i][j]);
  printf("\nThe matrix A is\n");
  for(i=0;i<m;i++)
  {
   for(j=0;j<n;j++)
    printf("%d\t",a[i][j]);
   printf("\n");
  }
  printf("\nThe matrix B is\n");
  for(i=0;i<o;i++)
  {
   for(j=0;j<p;j++)
    printf("%d\t",b[i][j]);
   printf("\n");
  }
  for(i=0;i<m;i++)
   for(j=0;j<p;j++)
    c[i][j]=0;
  for(i=0;i<m;i++)
   for(j=0;j<p;j++)
    for(k=0;k<n;k++)
     c[i][j]+=a[i][k]*b[k][j];
  printf("\nThe matrix C is\n");
  for(i=0;i<m;i++)
  {
   for(j=0;j<p;j++)
    printf("%d\t",c[i][j]);
   printf("\n");
  }
 }
 else
  printf("Matrix multiplication not possible!!!");
}
void trimatrix(int a[10][10],int n);
void trimatrix(int a[10][10],int n)
{
 int i,j,up=0,lw=0;
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
   if(i>j&&a[i][j]!=0)
    up=1;
   if(i<j&&a[i][j]!=0)
    lw=1;
  }
 if(up==0&&lw==0)
  printf("The matrix is diagonal matrix");
 else if(up==0)
  printf("The matrix is upper triangled");
 else if(lw==0)
  printf("The matrix is lower triangled");
 else
  printf("The matrix is regular matrix");
}
void saddle(int a[10][10],int m,int n);
void saddle(int a[10][10],int m,int n)
{
 int i,j,k,l,hr,hc,lr,lc;
 printf("Enter the number of rows and columns of the matrix ");
 scanf("%d %d",&m,&n);
 printf("Enter the elements\n");
 for(i=0;i<m;i++)
  for(j=0;j<n;j++)
   scanf("%d",&a[i][j]);
 printf("\nThe matrix is\n");
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
   printf("%d\t",a[i][j]);
  printf("\n");
 }
 printf("The saddle ponts in the matrix are at\n");
 for(i=0;i<m;i++)
  for(j=0;j<n;j++)
  {
   hr=a[i][0];
   lr=a[i][0];
   hc=a[0][j];
   lc=a[0][j];
   for(k=0;k<m;k++)
   {
    if(a[k][j]>hc)
     hc=a[k][j];
    if(a[k][j]<lc)
     lc=a[k][j];
   }
   for(l=0;l<n;l++)
   {
    if(a[i][l]>hr)
     hr=a[i][l];
    if(a[i][l]<lr)
     lr=a[i][l];
   }
   if((a[i][j]==hr&&a[i][j]==lc)||(a[i][j]==hc&&a[i][j]==lr))
    printf("%d %d\n",i+1,j+1);
  }
}
void identity(int a[10][10],int n);
void identity(int a[10][10],int n)
{
 int i,j,id=0,di=0;
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
   if(i!=j&&a[i][j]!=0)
    di=1;
   if(i==j&&a[i][j]!=1)
    id=1;
  }
 if(!di)
 {
  if(!id)
   printf("The matrix is identity matrix");
  else
   printf("The matrix is diagonal matrix");
 }
 else
  printf("The matrix is ordinary matrix");
}
void reverse(int a[10],int n);
void reverse(int a[10],int n)
{
 int i;
 for(i=0;i<(n/2);i++)
 {
  a[i]=a[i]+a[n-i-1];
  a[n-i-1]=a[i]-a[n-i-1];
  a[i]=a[i]-a[n-i-1];
 }
}
void matrix();
void matrix()
{
 int opt,yes=1;
 do
 {
  printf("1. Matrix multiplication\n2. Check whether matrix is upper or lower triangular\n3. Check whether saddle point exists\n4. Check whether matrix is identity or diagonal\n5. Reverse the elements of an array\n6. Go back\nChoose an option.. ");
  scanf("%d",&opt);
  switch(opt)
  {
   case 1:{
           int a[10][10],b[10][10],m,n,o,p;
           printf("Enter the rows and columns of matrix A ");
	   scanf("%d %d",&m,&n);
	   printf("Enter the rows and columns of matrix B ");
           scanf("%d %d",&o,&p);
	   matmult(a,b,m,n,o,p);
	   break;
	  }
   case 2:{
	   int a[10][10],n,i,j;
	   printf("Enter the order of the matrix ");
	   scanf("%d",&n);
	   printf("Enter the elements\n");
	   for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	     scanf("%d",&a[i][j]);
	   printf("\nThe matrix is\n");
	   for(i=0;i<n;i++)
	   {
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	   }
	   trimatrix(a,n);
	   break;
	  }
   case 3:{
	   int a[10][10],m,n,i,j;
	   printf("Enter the number of rows and columns of the matrix ");
	   scanf("%d %d",&m,&n);
	   printf("Enter the elements\n");
	   for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
	     scanf("%d",&a[i][j]);
	    printf("\nThe matrix is\n");
	    for(i=0;i<m;i++)
	    {
	     for(j=0;j<n;j++)
	      printf("%d\t",a[i][j]);
	     printf("\n");
	    }
	    saddle(a,m,n);
	    break;
	   }
   case 4:{
           int a[10][10],n,i,j;
	   printf("Enter the order of the matrix ");
	   scanf("%d",&n);
	   printf("Enter the elements\n");
	   for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	     scanf("%d",&a[i][j]);
	   printf("\nThe matrix is\n");
	   for(i=0;i<n;i++)
	   {
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	   }
	   identity(a,n);
	   break;
	  }
   case 5:{
           int a[10],i,n;
           printf("Enter the size of the array ");
           scanf("%d",&n);
           printf("Enter the elements\n");
           for(i=0;i<n;i++)
            scanf("%d",&a[i]);
           printf("The array is\n");
           for(i=0;i<n;i++)
            printf("%d\t",a[i]);
           reverse(a,n);
           printf("\nThe reversed array is\n");
           for(i=0;i<n;i++)
            printf("%d\t",a[i]);
           break;
          }
   case 6:yes=0;
  }
 }while(yes);
}
int cf,fre;
struct poly{
 int deg;
 int coef;
 }term[100];
void polyadd(int af,int al,int bf,int bl);
void polyadd(int af,int al,int bf,int bl)
{
 int p,q;
 p=af;
 q=bf;
 while(p<=al&&q<=bl)
 {
  if(term[p].deg==term[q].deg)
  {
   term[fre].deg=term[p].deg;
   term[fre].coef=term[p].coef+term[q].coef;
   p++;
   q++;
   fre++;
  }
  else if(term[p].deg>term[q].deg)
  {
   term[fre].deg=term[p].deg;
   term[fre].coef=term[p].coef;
   p++;
   fre++;
  }
  else if(term[q].deg>term[p].deg)
  {
   term[fre].deg=term[q].deg;
   term[fre].coef=term[q].coef;
   q++;
   fre++;
  }
 }
 while(p<=al)
 {
  term[fre].deg=term[p].deg;
  term[fre].coef=term[p].coef;
  p++;
  fre++;
 }
 while(q<=bl)
 {
  term[fre].deg=term[q].deg;
  term[fre].coef=term[q].coef;
  q++;
  fre++;
 }
}
void polymult(int af,int al,int bf,int bl);
void polymult(int af,int al,int bf,int bl)
{
 int p,q,r,s,dg,co,count;
 struct poly temp;
 for(p=af;p<=al;p++)
  for(q=bf;q<=bl;q++)
  {
   dg=term[p].deg+term[q].deg;
   co=term[p].coef*term[q].coef;
   count=0;
   for(r=cf;r<fre;r++)
    if(term[r].deg==dg)
    {
     term[r].coef+=co;
     count=1;
    }
   if(!count)
   {
    term[fre].deg=dg;
    term[fre].coef=co;
    fre++;
   }
  }
 for(r=cf;r<fre;r++)
  for(s=(r+1);s<fre;s++)
   if(term[s].deg>term[r].deg)
   {
    temp=term[s];
    term[s]=term[r];
    term[r]=temp;
   }
}
void polynomial();
void polynomial()
{
 int opt,yes=1;
 do
 {
  printf("1. Add two polynomials\n2. Multiply two polynomials\n3. Go back\nChoose an option.. ");
  scanf("%d",&opt);
  switch(opt)
  {
   case 1:{
           int af,al,bf,bl,m,n,i;
           printf("Enter the number of terms of f(x) ");
           scanf("%d",&n);
           af=0;
           al=n-1;
           printf("Enter the number of terms of g(x) ");
           scanf("%d",&m);
           bf=n;
           bl=n+m-1;
           for(i=0;i<n;i++)
           {
            printf("Enter the coefficient and degree of %dth term of f(x) ",i+1);
            scanf("%d %d",&term[i].coef,&term[i].deg);
           }
           for(i=n;i<(n+m);i++)
           {
            printf("Enter the coefficient and degree of %dth term of g(x) ",i-n+1);
            scanf("%d %d",&term[i].coef,&term[i].deg);
           }
           printf("f(x) is ");
           for(i=af;i<al;i++)
            printf("(%d)x%d+",term[i].coef,term[i].deg);
           printf("(%d)x%d",term[i].coef,term[i].deg);
           printf("\ng(x) is ");
           for(i=bf;i<bl;i++)
            printf("(%d)x%d+",term[i].coef,term[i].deg);
           printf("(%d)x%d",term[i].coef,term[i].deg);
           cf=fre=n+m;
           polyadd(af,al,bf,bl);
           printf("\nThe added polynomial is ");
           for(i=cf;i<(fre-1);i++)
            printf("(%d)x%d+",term[i].coef,term[i].deg);
           printf("(%d)x%d",term[i].coef,term[i].deg);
           break;
          }
   case 2:{
           int af,al,bf,bl,m,n,i;
           printf("Enter the number of terms of f(x) ");
           scanf("%d",&n);
           af=0;
           al=n-1;
           printf("Enter the number of terms of g(x) ");
           scanf("%d",&m);
           for(i=0;i<(n*m);i++)
            term[i].deg=term[i].coef=0;
           bf=n;
           bl=n+m-1;
           for(i=0;i<n;i++)
           {
            printf("Enter the coefficient and degree of %dth term of f(x) ",i+1);
            scanf("%d %d",&term[i].coef,&term[i].deg);
           }
           for(i=n;i<(n+m);i++)
           {
            printf("Enter the coefficient and degree of %dth term of g(x) ",i-n+1);
            scanf("%d %d",&term[i].coef,&term[i].deg);
           }
           printf("f(x) is ");
           for(i=af;i<al;i++)
            printf("(%d)x%d+",term[i].coef,term[i].deg);
           printf("(%d)x%d",term[i].coef,term[i].deg);
           printf("\ng(x) is ");
           for(i=bf;i<bl;i++)
            printf("(%d)x%d+",term[i].coef,term[i].deg);
           printf("(%d)x%d",term[i].coef,term[i].deg);
           cf=fre=n+m;
           polymult(af,al,bf,bl);
           printf("\nThe multiplied polynomial is ");
           for(i=cf;i<(fre-1);i++)
            printf("(%d)x%d+",term[i].coef,term[i].deg);
           printf("(%d)x%d",term[i].coef,term[i].deg);
           break;
          }
   case 3:yes=0;
  }
 }while(yes);
}
typedef struct linkstack
{
	int data;
	struct linkstack *next;
}stack;
stack *top=NULL;
void spush(int);
int spop();
void stackprint();
void stackfreeall();
void spush(int x)
{
	stack *q=(stack *)malloc(sizeof(stack));
	if(q==NULL)
	{
		printf("Stack overflow");
		exit(0);
	}
	q->data=x;
	q->next=top;
	top=q;
}
int spop()
{
	stack *q;
	int x;
	if(top==NULL)
		return NULL;
	q=top;
	top=top->next;
	x=q->data;
	free(q);
	return x;
}
void stackprint()
{
	stack *q=top;
	if(top==NULL)
		printf("Stack underflow");
	else
	{
		printf("The stack contains\n");
		while(q!=NULL)
		{
			printf("%d ",q->data);
			q=q->next;
		}
	}
	printf("\n");
}
void stackfreeall()
{
	stack *q;
	while(top!=NULL)
	{
		q=top;
		top=top->next;
		free(q);
	}
}
void stacklink();
void stacklink()
{
	int ch,x,yes=1;
	do
	{
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\nChoose an option.. ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to be pushed ");
			       scanf("%d",&x);
			       spush(x);
			       stackprint();
			       break;
			case 2:x=spop();
			       if(x==NULL)
			       		printf("Stack underflow");
			       else
			       		printf("The popped element is %d\n",x);
			       break;
			case 3:stackprint();
			       break;
			case 4:stackfreeall();
			       yes=0;
			       break;
			default:printf("Wrong choice. Choose again..");
		}
	}while(yes);
}
typedef struct linkedqueue
{
	int data;
	struct linkedqueue *next;
}queue;
queue *qfront=NULL,*qrear=NULL;
void qinsert(int);
int qdelete();
void qprint();
void qfreeall();
void qinsert(int x)
{
	queue *q=(queue *)malloc(sizeof(queue));
	if(q==NULL)
	{
		printf("Queue overflow");
		exit(0);
	}
	q->data=x;
	q->next=NULL;
	if(qfront==NULL)
		qfront=q;
	else
		qrear->next=q;
	qrear=q;
}
int qdelete()
{
	queue *q;
	int x;
	if(qfront==NULL)
		return NULL;
	x=qfront->data;
	q=qfront;
	qfront=qfront->next;
	free(q);
	return x;
}
void qprint()
{
	queue *q=qfront;
	if(qfront==NULL)
		printf("Queue underflow");
	else
	{
		printf("The queue contains\n");
		while(q!=NULL)
		{
			printf("%d ",q->data);
			q=q->next;
		}
	}
	printf("\n");
}
void qfreeall()
{
	queue *q;
	while(qfront!=NULL)
	{
		q=qfront;
		qfront=qfront->next;
		free(q);
	}
}
void queuelink();
void queuelink()
{
	int ch,x,yes=1;
	do
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nChoose an option.. ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to be inserted ");
			       scanf("%d",&x);
			       qinsert(x);
			       qprint();
			       break;
			case 2:x=qdelete();
			       if(x==NULL)
			       		printf("Queue underflow");
			       else
			       		printf("The deleted element is %d\n",x);
			       break;
			case 3:qprint();
			       break;
			case 4:qfreeall();
			       yes=0;
			       break;
			default:printf("Wrong choice. Choose again..");
		}
	}while(yes);
}
typedef struct circlink
{
	int data;
	struct circlink *next;
}cqueue;
cqueue *cfront=NULL,*crear=NULL;
void cqueueinsert(int);
int cqueuedelete();
void cqueueprint();
void cqueuefreeall();
void cqueueinsert(int x)
{
	cqueue *q=(cqueue *)malloc(sizeof(cqueue));
	if(q==NULL)
	{
		printf("Circular queue overflow");
		exit(0);
	}
	q->data=x;
	if(cfront==NULL)
		cfront=q;
	else
		crear->next=q;
	q->next=cfront;
	crear=q;
}
int cqueuedelete()
{
	cqueue *q;
	int x;
	if(cfront==NULL)
		return NULL;
	x=cfront->data;
	if(cfront!=crear)
	{
		q=cfront;
		crear->next=cfront->next;
		cfront=cfront->next;
		free(q);
		return x;
	}
	free(cfront);
	cfront=crear=NULL;
	return x;
}
void cqueueprint()
{
	cqueue *q=cfront->next;
	if(cfront==NULL)
		printf("Circular queue underflow");
	else
	{
		printf("The circular queue contains\n");
		printf("%d ",cfront->data);
		while(q!=cfront)
		{
			printf("%d ",q->data);
			q=q->next;
		}
	}
	printf("\n");
}
void cqueuefreeall()
{
	cqueue *q;
	while(cfront!=crear)
	{
		q=cfront;
		cfront=cfront->next;
		free(q);
	}
	free(crear);
}
void circlink();
void circlink()
{
	int ch,x,yes=1;
	do
	{
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\nChoose an option.. ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to be inserted ");
			       scanf("%d",&x);
			       cqueueinsert(x);
			       cqueueprint();
			       break;
			case 2:x=cqueuedelete();
			       if(x==NULL)
			       		printf("Circular queue underflow");
			       else
			       		printf("The deleted element is %d\n",x);
			       break;
			case 3:cqueueprint();
			       break;
			case 4:cqueuefreeall();
			       yes=0;
			       break;
			default:printf("Wrong choice. Choose again..");
		}
	}while(yes);
}
typedef struct dequelink
{
	int data;
	struct dequelink *next;
}deque;
deque *dfront=NULL,*drear=NULL;
void dinsfront(int);
void dinsrear(int);
int ddelfront();
int ddelrear();
void dequeprint();
void dequefreeall();
void dinsfront(int x)
{
	deque *q=(deque *)malloc(sizeof(deque));
	if(q==NULL)
	{
		printf("Deque overflow");
		exit(0);
	}
	q->data=x;
	q->next=dfront;
	dfront=q;
	if(drear==NULL)
		drear=q;
}
void dinsrear(int x)
{
	deque *q=(deque *)malloc(sizeof(deque));
	if(q==NULL)
	{
		printf("Deque overflow");
		exit(0);
	}
	q->data=x;
	q->next=NULL;
	if(dfront==NULL)
		dfront=q;
	else
		drear->next=q;
	drear=q;
}
int ddelfront()
{
	deque *q;
	int x;
	if(dfront==NULL)
		return NULL;
	q=dfront;
	x=dfront->data;
	dfront=dfront->next;
	free(q);
	return x;
}
int ddelrear()
{
	deque *q=dfront;
	int x;
	if(dfront=NULL)
		return NULL;
	if(dfront==drear)
	{
		x=dfront->data;
		free(dfront);
		dfront=drear=NULL;
		return x;
	}
	while(q->next!=drear)
		q=q->next;
	q->next=drear->next;
	x=drear->data;
	free(drear);
	drear=q;
	return x;
}
void dequeprint()
{
	deque *q=dfront;
	if(dfront==NULL)
		printf("Deque underflow");
	else
	{
		printf("The deque contains\n");
		while(q!=NULL)
		{
			printf("%d ",q->data);
			q=q->next;
		}
	}
	printf("\n");
}
void dequefreeall()
{
	deque *q;
	while(dfront!=NULL)
	{
		q=dfront;
		dfront=dfront->next;
		free(q);
	}
}
void dequelink();
void dequelink()
{
	int ch,x,yes=1;
	do
	{
		printf("1. Insert from front\n2. Insert from rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\nChoose an option.. ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to be inserted ");
			       scanf("%d",&x);
			       dinsfront(x);
			       dequeprint();
			       break;
			case 2:printf("Enter the element to be inserted ");
			       scanf("%d",&x);
			       dinsrear(x);
			       dequeprint();
			       break;
			case 3:x=ddelfront();
			       if(x==NULL)
			       		printf("Deque underflow");
			       else
			       		printf("The deleted element is %d\n",x);
			       break;
			case 4:x=ddelrear();
			       if(x==NULL)
			       		printf("Deque underflow");
			       else
			       		printf("The deleted element is %d\n",x);
			       break;
			case 5:dequeprint();
			       break;
			case 6:dequefreeall();
			       yes=0;
			       break;
			default:printf("Wrong choice. Choose again..");
		}
	}while(yes);
}
void staque();
void staque()
{
	int opt,yes=1;
	do
	{
		printf("1. Stacks\n2. Queues\n3. Circular queues\n4. Dequeues\n5. Go back\nChoose an option.. ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:stacklink();
			       break;
			case 2:queuelink();
			       break;
			case 3:circlink();
			       break;
			case 4:dequelink();
			       break;
			case 5:yes=0;
		}
	}while(yes);
}
typedef struct singlist
{
	int data;
	struct singlist *next;
}slist;
void screate(slist *,int);
slist * sinsert(slist *,int,int);
slist * sdelete(slist *,int);
void sprint(slist *);
int scount(slist *);
void ssearch(slist *,int);
void sfreeall(slist *);
void screate(slist *p,int n)
{
	int x,i;
	slist *q;
	for(i=1;i<=n;i++)
	{
		printf("Enter value ");
		scanf("%d",&x);
		p->data=x;
		if(i!=n)
		{
			q=(slist *)malloc(sizeof(slist));
			if(q==NULL)
			{
				printf("Sorry!!");
				exit(0);
			}
			q->next=p->next;
			p->next=q;
			p=q;
		}
	}
}
slist * sinsert(slist *p,int x,int pos)
{
	slist *q=(slist *)malloc(sizeof(slist)),*r=p;
	if(q==NULL)
	{
		printf("Sory!!");
		exit(0);
	}
	q->data=x;
	if(pos==1)
	{
		q->next=p;
		r=q;
	}
	else if(pos==(scount(p)+1))
	{
		while(p->next!=NULL)
			p=p->next;
		q->next=NULL;
		p->next=q;
	}
	else
	{
		int ct=2;
		while(ct!=pos)
		{
			ct++;
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
	}
	return r;
}
slist * sdelete(slist *p,int pos)
{
	slist *q=p,*r=p;
	if(pos==1)
	{
		p=p->next;
		free(q);
		r=p;
	}
	else if(pos==scount(p))
	{
		while(p->next->next!=NULL)
			p=p->next;
		q=p->next;
		free(q);
		p->next=NULL;
	}
	else
	{
		int ct=2;
		while(ct!=pos)
		{
			p=p->next;
			ct++;
		}
		q=p->next;
		p->next=p->next->next;
		free(q);
	}
	return r;
}
void sprint(slist *p)
{
	printf("The list contains ");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int scount(slist *p)
{
	int ct=0;
	while(p!=NULL)
	{
		ct++;
		p=p->next;
	}
	return ct;
}
void ssearch(slist *p,int x)
{
	int pos=1;
	printf("The element was found at ");
	while(p!=NULL)
	{
		if(p->data==x)
			printf("%d ",pos);
		pos++;
		p=p->next;
	}
	printf("\n");
}
void sfreeall(slist *p)
{
	slist *q;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}
void s_list();
void s_list()
{
	slist *head=(slist *)malloc(sizeof(slist));
	if(head==NULL)
	{
		printf("Sorry!!");
		exit(0);
	}
	head->next=NULL;
	int ch,n,pos,yes=1;
	do
	{
		printf("1. Create the list\n2. Insert at any position\n3. Delete at any position\n4. Print the list\n5. Count umber of nodes\n6. Search for an element\nChoose an option or any other to exit ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the number of nodes ");
			       scanf("%d",&n);
			       screate(head,n);
			       sprint(head);
			       break;
			case 2:printf("Enter element to insert and the position ");
			       scanf("%d %d",&n,&pos);
			       head=sinsert(head,n,pos);
			       sprint(head);
			       break;
			case 3:printf("Enter the position whose element is to be deleted ");
			       scanf("%d",&pos);
			       head=sdelete(head,pos);
			       sprint(head);
			       break;
			case 4:sprint(head);
			       break;
			case 5:printf("The list contains %d nodes\n",scount(head));
			       break;
			case 6:printf("Enter the element which is to be searched ");
			       scanf("%d",&n);
			       ssearch(head,n);
			       break;
			default:sfreeall(head);
			        yes=0;
		}
	}while(yes);
}
int stck[20];
int tp=-1;
void rcreate(slist *,int);
void rprint(slist *);
void rreverse(slist *p);
void rfreeall(slist *);
void rcreate(slist *p,int n)
{
	int x,i;
	slist *q;
	for(i=1;i<=n;i++)
	{
		printf("Enter value ");
		scanf("%d",&x);
		p->data=x;
		if(i!=n)
		{
			q=(slist *)malloc(sizeof(slist));
			if(q==NULL)
			{
				printf("Sorry!!");
				exit(0);
			}
			q->next=p->next;
			p->next=q;
			p=q;
		}
	}
}
void rprint(slist *p)
{
	printf("The list contains ");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void rreverse(slist *p)
{
	slist *q=p;
	while(p!=NULL)
	{
		stck[++tp]=p->data;
		p=p->next;
	}
	while(q!=NULL)
	{
		q->data=stck[tp--];
		q=q->next;
	}
}
void rfreeall(slist *p)
{
	slist *q;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}
void r_list();
void r_list()
{
	int n;
	slist *head=(slist *)malloc(sizeof(slist));
	if(head==NULL)
	{
		printf("Sorry!!");
		exit(0);
	}
	head->next=NULL;
	printf("Enter the number of nodes ");
	scanf("%d",&n);
	rcreate(head,n);
	rprint(head);
	rreverse(head);
	printf("List reversed\n");
	rprint(head);
	rfreeall(head);
}
typedef struct doublist
{
	int data;
	struct doublist *prev,*next;
}dlist;
void dcreate(dlist *,int);
dlist * dinsert(dlist *,int,int);
dlist * ddelete(dlist *,int);
void dprint(dlist *);
int dcount(dlist *);
void dfreeall(dlist *);
void dcreate(dlist *p,int n)
{
	int i,x;
	dlist *q;
	for(i=1;i<=n;i++)
	{
		printf("Enter value ");
		scanf("%d",&x);
		p->data=x;
		if(i!=n)
		{
			q=(dlist *)malloc(sizeof(dlist));
			if(q==NULL)
			{
				printf("Sorry!!");
				exit(0);
			}
			q->next=p->next;
			p->next=q;
			q->prev=p;
			p=q;
		}
	}
}
dlist * dinsert(dlist *p,int x,int pos)
{
	dlist *q=(dlist *)malloc(sizeof(dlist)),*r=p;
	if(q==NULL)
	{
		printf("Sorry!!");
		exit(0);
	}
	q->data=x;
	if(pos==1)
	{
		q->next=p;
		p->prev=q;
		q->prev=NULL;
		r=q;
	}
	else if(pos==(dcount(p)+1))
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=q;
		q->prev=p;
		q->next=NULL;
	}
	else
	{
		int ct=2;
		while(ct!=pos)
		{
			ct++;
			p=p->next;
		}
		q->next=p->next;
		q->prev=p;
		p->next->prev=q;
		p->next=q;
	}
	return r;
}
dlist * ddelete(dlist *p,int pos)
{
	dlist *q=p,*r=p;
	if(pos==1)
	{
		p=p->next;
		p->prev=NULL;
		r=p;
		free(q);
	}
	else if(pos==dcount(p))
	{
		while(p->next->next!=NULL)
			p=p->next;
		q=p->next;
		free(q);
		p->next=NULL;
	}
	else
	{
		int ct=2;
		while(ct!=pos)
		{
			p=p->next;
			ct++;
		}
		q=p->next;
		p->next->next->prev=p;
		p->next=p->next->next;
		free(q);
	}
	return r;
}
void dprint(dlist *p)
{
	printf("The list contains ");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int dcount(dlist *p)
{
	int ct=0;
	while(p!=NULL)
	{
		ct++;
		p=p->next;
	}
	return ct;
}
void dfreeall(dlist *p)
{
	dlist *q;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}
void d_list();
void d_list()
{
	dlist *head=(dlist *)malloc(sizeof(dlist));
	if(head==NULL)
	{
		printf("Sorry!!");
		exit(0);
	}
	head->prev=head->next=NULL;
	int ch,n,pos,yes=1;
	do
	{
		printf("1. Create the list\n2. Insert at any position\n3. Delete at any position\n4. Print the list\nChoose an option or any other to exit ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the number of nodes ");
			       scanf("%d",&n);
			       dcreate(head,n);
			       dprint(head);
			       break;
			case 2:printf("Enter element to insert and the position ");
			       scanf("%d %d",&n,&pos);
			       head=dinsert(head,n,pos);
			       dprint(head);
			       break;
			case 3:printf("Enter the position whose element is to be deleted ");
			       scanf("%d",&pos);
			       head=ddelete(head,pos);
			       dprint(head);
			       break;
			case 4:dprint(head);
			       break;
			default:dfreeall(head);
			        yes=0;
		}
	}while(yes);
}
typedef struct circlist
{
	int data;
	struct circlist *next;
}clist;
void ccreate(clist *,int);
clist * cinsert(clist *,int,int);
clist * cdelete(clist *,int);
void cprint(clist *);
int ccount(clist *);
void cfreeall(clist *);
void ccreate(clist *p,int n)
{
	int x,i;
	clist *q;
	for(i=1;i<=n;i++)
	{
		printf("Enter value ");
		scanf("%d",&x);
		p->data=x;
		if(i!=n)
		{
			q=(clist *)malloc(sizeof(clist));
			if(q==NULL)
			{
				printf("Sorry!!");
				exit(0);
			}
			q->next=p->next;
			p->next=q;
			p=q;
		}
	}
}
clist * cinsert(clist *p,int x,int pos)
{
	clist *q=(clist *)malloc(sizeof(clist)),*r=p;
	if(q==NULL)
	{
		printf("Sory!!");
		exit(0);
	}
	q->data=x;
	if(pos==1)
	{
		q->next=p;
		while(p->next!=r)
			p=p->next;
		p->next=q;
		r=q;
	}
	else if(pos==(ccount(p)+1))
	{
		while(p->next!=r)
			p=p->next;
		q->next=r;
		p->next=q;
	}
	else
	{
		int ct=2;
		while(ct!=pos)
		{
			ct++;
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
	}
	return r;
}
clist * cdelete(clist *p,int pos)
{
	clist *q=p,*r=p;
	if(pos==1)
	{
		q=p->next;
		while(r->next!=p)
			r=r->next;
		r->next=q;
		free(p);
		r=q;
	}
	else if(pos==ccount(p))
	{
		while(p->next->next!=r)
			p=p->next;
		q=p->next;
		free(q);
		p->next=r;
	}
	else
	{
		int ct=2;
		while(ct!=pos)
		{
			p=p->next;
			ct++;
		}
		q=p->next;
		p->next=p->next->next;
		free(q);
	}
	return r;
}
void cprint(clist *p)
{
	clist *r=p;
	printf("The list contains ");
	printf("%d ",p->data);
	p=p->next;
	while(p!=r)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int ccount(clist *p)
{
	clist *r=p->next;
	int ct=1;
	while(p!=r)
	{
		ct++;
		r=r->next;
	}
	return ct;
}
void cfreeall(clist *p)
{
	clist *q,*r=p;
	p=p->next;
	while(p!=r)
	{
		q=p;
		p=p->next;
		free(q);
	}
	free(r);
}
void c_list();
void c_list()
{
	clist *head=(clist *)malloc(sizeof(clist));
	if(head==NULL)
	{
		printf("Sorry!!");
		exit(0);
	}
	head->next=head;
	int ch,n,pos,yes=1;
	do
	{
		printf("1. Create the list\n2. Insert at any position\n3. Delete at any position\n4. Print the list\nChoose an option or any other to exit ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the number of nodes ");
			       scanf("%d",&n);
			       ccreate(head,n);
			       cprint(head);
			       break;
			case 2:printf("Enter element to insert and the position ");
			       scanf("%d %d",&n,&pos);
			       head=cinsert(head,n,pos);
			       cprint(head);
			       break;
			case 3:printf("Enter the position whose element is to be deleted ");
			       scanf("%d",&pos);
			       head=cdelete(head,pos);
			       cprint(head);
			       break;
			case 4:cprint(head);
			       break;
			default:cfreeall(head);
			        yes=0;
		}
	}while(yes);
}
void linklist();
void linklist()
{
	int opt,yes=1;
	do
	{
		printf("1. Work with singly linked lists\n2. Reverse a singly linked list\n3. Work with doubly linked lists\n4. Work with circular lists\n5. Go back\nChoose an option.. ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:s_list();
			       break;
			case 2:r_list();
			       break;
			case 3:d_list();
			       break;
			case 4:c_list();
			       break;
			case 5:yes=0;
		}
	}while(yes);
}
int lsearch(int a[10],int n,int x);
int lsearch(int a[10],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]==x)
			return i+1;
	return 0;
}
int binsearch(int a[10],int n,int x);
int binsearch(int a[10],int n,int x)
{
	int left,mid,right;
	left=0;
	right=n-1;
	while(left<right)
	{
		mid=(left+right)/2;
		if(x==a[mid])
			return mid+1;
		else if(x<a[mid])
			right=mid-1;
		else
			left=mid+1;
	}
	return 0;
}
void insort(int a[10],int n);
void insort(int a[10],int n)
{
 int i,j,key;
 for(i=1;i<n;i++)
 {
  key=a[i];
  j=i-1;
  while(j>=0&&a[j]>key)
  {
   a[j+1]=a[j];
   j--;
  }
  a[j+1]=key;
 }
}
void search();
void search()
{
	int opt,yes=1;
	do
	{
		printf("1. Linear search\n2. Binary search\n3. Go back\nChoose an option.. ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:{
				int a[10],i,n,x,pos;
				printf("Enter the number of elements ");
				scanf("%d",&n);
				printf("Enter the elements ");
				for(i=0;i<n;i++)
					scanf("%d",&a[i]);
				printf("Enter the element to search for ");
				scanf("%d",&x);
				pos=lsearch(a,n,x);
				if(!pos)
					printf("Element not found ");
				else printf("Element found at position %d",pos);
				break;
			       }
			case 2:{
			        int a[10],i,n,x,pos;
			        printf("Enter the number of elements ");
				scanf("%d",&n);
				printf("Enter the elements ");
				for(i=0;i<n;i++)
					scanf("%d",&a[i]);
				printf("Enter the element to search for ");
				scanf("%d",&x);
				insort(a,n);
				pos=binsearch(a,n,x);
				if(!pos)
					printf("Element not found ");
				else printf("Element found at position %d",pos);
				break;
			       }
			case 3:yes=0;
		}
	}while(yes);
}
int a[10];
void bubsort(int a[10],int n);
void bubsort(int a[10],int n)
{
 int i,j,temp;
 for(i=(n-1);i>0;i--)
  for(j=0;j<i;j++)
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
}
void selsort(int a[10],int n);
void selsort(int a[10],int n)
{
 int i,imax,j,temp;
 for(i=(n-1);i>0;i--)
 {
  imax=0;
  for(j=0;j<=i;j++)
   if(a[j]>a[imax])
    imax=j;
   temp=a[i];
   a[i]=a[imax];
   a[imax]=temp;
  }
}
void inssort(int a[10],int n);
void inssort(int a[10],int n)
{
 int i,j,key;
 for(i=1;i<n;i++)
 {
  key=a[i];
  j=i-1;
  while(j>=0&&a[j]>key)
  {
   a[j+1]=a[j];
   j--;
  }
  a[j+1]=key;
 }
}
int mergesort(int,int);
void merge(int,int,int);
int mergesort(int start,int end)
{
 int mid;
 if((end-start)<2)
  return 1;
 mid=(end+start)/2;
 mergesort(start,mid);
 mergesort(mid,end);
 merge(start,mid,end);
}
void merge(int start,int mid,int end)
{
 int i,j,k,b[10],c[10];
 for(i=start;i<mid;i++)
  b[i-start]=a[i];
 for(i=mid;i<end;i++)
  c[i-mid]=a[i];
 i=j=0;
 k=start;
 while(i<(mid-start)&&j<(end-mid))
 {
  if(b[i]<=c[j])
  {
   a[k]=b[i];
   i++;
  }
  else
  {
   a[k]=c[j];
   j++;
  }
  k++;
 }
 while(i<(mid-start))
 {
  a[k]=b[i];
  i++;
  k++;
 }
 while(j<(end-mid))
 {
  a[k]=c[j];
  j++;
  k++;
 }
}
int partition(int,int);
void quicksort(int,int);
void quicksort(int low,int high)
{
 int p;
 if(low<high)
 {
  p=partition(low,high);
  quicksort(low,p);
  quicksort((p+1),high);
 }
}
int partition(int low,int high)
{
 int p=low,q=high,pivot=a[low],temp;
 while(p<q)
 {
  while(a[p]<pivot)
   p++;
  while(a[q]>pivot)
   q--;
  if(p<q)
  {
   temp=a[p];
   a[p]=a[q];
   a[q]=temp;
  }
 }
 return q;
}
void sort();
void sort()
{
 int opt,yes=1;
 do
 {
  printf("1. Bubble sort\n2. Selection sort\n3. Insertion sort\n4. Merge sort\n5. Quick sort\n6. Go back\nChoose an option.. ");
  scanf("%d",&opt);
  switch(opt)
  {
   case 1:{
           int a[10],i,n;
           printf("Enter the number of elements ");
           scanf("%d",&n);
           printf("Enter the elements ");
           for(i=0;i<n;i++)
            scanf("%d",&a[i]);
           bubsort(a,n);
           printf("Using bubble sort the sorted elements are\n");
           for(i=0;i<n;i++)
            printf("%d ",a[i]);
           printf("\n");
           break;
          }
   case 2:{
           int a[10],i,n;
           printf("Enter the number of elements ");
           scanf("%d",&n);
           printf("Enter the elements ");
           for(i=0;i<n;i++)
            scanf("%d",&a[i]);
           selsort(a,n);
           printf("Using selection sort the sorted elements are\n");
           for(i=0;i<n;i++)
            printf("%d ",a[i]);
           printf("\n");
           break;
          }
   case 3:{
           int a[10],i,n;
           printf("Enter the number of elements ");
           scanf("%d",&n);
           printf("Enter the elements ");
           for(i=0;i<n;i++)
            scanf("%d",&a[i]);
           inssort(a,n);
           printf("Using insertion sort the sorted elements are\n");
           for(i=0;i<n;i++)
            printf("%d ",a[i]);
           printf("\n");
           break;
          }
   case 4:{
           int i,n;
           printf("Enter the number of elements ");
           scanf("%d",&n);
           printf("Enter the elements ");
           for(i=0;i<n;i++)
            scanf("%d",&a[i]);
           mergesort(0,n);
           printf("Using merge sort the sorted elements are\n");
           for(i=0;i<n;i++)
            printf("%d ",a[i]);
           printf("\n");
           break;
          }
   case 5:{
           int i,n;
           printf("Enter the number of elements ");
           scanf("%d",&n);
           printf("Enter the elements ");
           for(i=0;i<n;i++)
            scanf("%d",&a[i]);
           quicksort(0,n-1);
           printf("Using quick sort the sorted elements are\n");
           for(i=0;i<n;i++)
            printf("%d ",a[i]);
           printf("\n");
           break;
          }
   case 6:yes=0;
  }
 }while(yes);
}
int prec(char);
int prec(char a)
{
	switch(a)
	{
		case '^':return 3;
		case '*':
		case '/':return 2;
		case '+':
		case '-':return 1;
		default:return 0;
	}
}
void inpost();
void inpost()
{
	char x[100],stack[10];
	int top=0,i=0;
	stack[0]='#';
	printf("Enter the infix expression ");
	scanf("%s",x);
	printf("The corresponding postfix expression is ");
	while(x[i]!='\0')
	{
		if(x[i]>=65&&x[i]<=90)
			printf("%c",x[i]);
		else if(x[i]=='(')
			stack[++top]='(';
		else if(x[i]==')')
		{
			while(stack[top]!='(')
				printf("%c",stack[top--]);
			top--;
		}
		else if(x[i]=='^'||x[i]=='/'||x[i]=='*'||x[i]=='+'||x[i]=='-')
		{
			if(prec(x[i])>prec(stack[top]))
				stack[++top]=x[i];
			else
			{
				printf("%c",stack[top--]);
				stack[++top]=x[i];
			}
		}
		i++;
	}
	while(top!=0)
		printf("%c",stack[top--]);
}
void evalpost();
void evalpost()
{
	char ch;
	int a,b,stack[20],top=-1;
	printf("Enter an expression ");
	getchar();
	while(ch!='\n')
	{
		scanf("%c",&ch);
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
		{
			a=stack[top--];
			b=stack[top--];
			switch(ch)
			{
				case '+':stack[++top]=(b+a);
				         break;
				case '-':stack[++top]=(b-a);
				         break;
				case '*':stack[++top]=(b*a);
				         break;
				case '/':stack[++top]=(b/a);
				         break;
				case '^':stack[++top]=pow(b,a);
			}
		}
		else if(ch!='\n')
			stack[++top]=(ch-48);
	}
	printf("The result is %d\n",stack[top]);
}
void postfix();
void postfix()
{
	int opt,yes=1;
	do
	{
		printf("1. Convert postfix to infix expresseion\n2. Evaluate a postfix expression\n3. Go back\nChoose an option... ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:inpost();
			       break;
			case 2:evalpost();
			       break;
			case 3:yes=0;
		}
	}while(yes);
}
