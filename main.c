#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int main(){
	struct SportMatches *arr=NULL;
	int n=0;
	int stop=0;
	while (stop!=1){
		int key=0;
		printf("1-create, 2-read, 3-print, 4-find\n");
		ch(&key);
		switch(key){
			case 1:
				create(&arr, &n);
				if(arr)
					write(arr, n);
				break;
			case 2:
				read(&arr, &n);
				if(!arr)
					printf("read error\n");
				else
					printf("loaded %d\n", n);
				break;
			case 3:
				for(int i=0; i<n; i++)
					printf("%s %s %d\n", arr[i].teamname, arr[i].country, arr[i].numberofplayers);
				break;
			case 4:
				printf("1-team name, 2-country, 3-number of players\n");
				int x;
				scanf("%d", &x);
				find(arr, &n, x);
				break;
			default:
				stop=1;
				break;
			}
		}
	if(arr)
		free(arr);
	return 0;
}
