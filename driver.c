#include<stdio.h>
#include<stdlib.h>
#include"library.h"
int main()
{
	int opt;
	do
	{
		printf("1. Matrices\n2. Polynomials\n3. Stacks and queues\n4. Postfix expressions\n5. Linked lists\n6. Searching\n7. Sorting\n8. Exit\nChoose an option.. ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:matrix();
			       break;
			case 2:polynomial();
			       break;
			case 3:staque();
			       break;
			case 4:postfix();
			       break;
			case 5:linklist();
			       break;
			case 6:search();
			       break;
			case 7:sort();
			       break;
			case 8:exit(0);
		}
	}while(1);
	return 0;
}
