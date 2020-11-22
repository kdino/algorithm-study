#include<stdio.h>

int main(void){
	int i, j;
	char title[100];

	int f = 50;
	int b = 50;

	FILE* ptr = fopen("bible.txt","r"); 
	FILE *fp = fopen("output.txt", "w");

	for(i=0; i<66; ++i){
		fscanf(ptr, "%s", title);
		while(1){
			fscanf(ptr, "%d	%d", &f, &b);
			if(f==999 && b==999) break;
			fprintf(fp, "%s, %d, %d\n", title, f, b);
		}
	}


	return 0;
}