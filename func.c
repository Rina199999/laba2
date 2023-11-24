#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
int ch(int *m){
	if(scanf("%u", m)==1)
		return 0;
	else{
		printf("error\n");
		while(getchar()!='\n');
		return 1;
	}
}
void write(struct SportMatches *arr, int n){
	if (n<=0)
		return;
	FILE *f=fopen("file.txt", "w");
	if(!f)
		return;
	fprintf(f, "%d\n",n);
	for (int i=0; i<n; i++)
		fprintf(f, "%s %s %d\n", arr[i].teamname, arr[i].country, arr[i].numberofplayers);
	fclose(f);
}
void read(struct SportMatches **arr, int *n){
	FILE *f=fopen("file.txt", "r");
	if(!f)
		return;
	if(fscanf(f,"%d", n)!=1)
		return;
	if(*n<=0)
		return;
	*arr=(struct SportMatches *)calloc(*n, sizeof(struct SportMatches));
	for (int i=0; i<*n; i++)
		fscanf(f, "%s %s %d", (*arr)[i].teamname, (*arr)[i].country, &(*arr)[i].numberofplayers);
	fclose(f);
}
void create(struct SportMatches **arr, int *n){
	printf("n=");
	if(ch(n))
		return;
	if (*n<=0)
		return;
	*arr=(struct SportMatches *)calloc(*n, sizeof(struct SportMatches));
	for (int i=0;i<*n;i++){
		printf("Team name = ");
		scanf("%s",(*arr)[i].teamname);
		printf("Country = ");
                scanf("%s",(*arr)[i].country);
		printf("Number of players = ");
		if(ch(&(*arr)[i].numberofplayers))
			return;
		}
}
void find(struct SportMatches *arr, int *n, int nn){
	char x1[40];
	switch(nn){
		case 1:
			printf("Введите название команды\n");
			scanf("%40s", x1);
			while(getchar()!='\n');
			for (int i=0; i<*n; i++){
				if(!strcmp(arr[i].teamname, x1)){
					printf("%s %s %d\n", arr[i].teamname, arr[i].country, arr[i].numberofplayers);
				}
			}
			break;
		case 2:
                        printf("Введите страну\n");
                        scanf("%40s", x1);
                        while(getchar()!='\n');
                        for (int i=0; i<*n; i++){
                                if(!strcmp(arr[i].country, x1)){
                                        printf("%s %s %d\n", arr[i].teamname, arr[i].country, arr[i].numberofplayers);
                                }
                        }
			break;
		case 3:
			int x2;
			printf("Введите количество игроков\n");
                        if(ch(&x2))
				return;
			for(int i=0; i<*n; i++){
				if(x2==arr[i].numberofplayers){
					printf("%s %s %d\n", arr[i].teamname, arr[i].country, arr[i].numberofplayers);
                                }
			}
			break;
		default:
			printf("Такого столбца не существует\n");
			break;
	}
}
