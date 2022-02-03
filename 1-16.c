#include <stdio.h>
#define MAXLINE 20

int getline(char line[], int);
void copy(char to[], char from[]);

int main(){
	int len;
	int max;
	int runningtotal;
	int saveflag;
	char line[MAXLINE];
	char saveline[MAXLINE];
	char longest[MAXLINE];

	saveflag = max = len = runningtotal = 0;
	while ((runningtotal += len = getline(line, MAXLINE)) > 0){
		if (len == (MAXLINE - 1)){
			if (saveflag == 0){
				copy(saveline, line);
				saveflag = 1;
			}
			continue;
		}
		if (runningtotal > max){
			if (runningtotal > (MAXLINE - 1))
				copy(longest, saveline);
			else
				copy(longest, line);
			max = runningtotal;
			runningtotal = 0;
		}	
	}
	if (max > 0){
		printf("length: %d\n", max);
		printf("%s", longest);
	}
	return 0;
}

int getline(char string[], int lim){
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		string[i] = c;
	if (c == '\n'){
		string[i] = '\0';
		++i;
	}
	string[i] = '\0';
	return i;
}

void copy(char to[], char from[]){
	 int i;

	 i = 0;
	 while((to[i] = from[i]) != '\0')
	 	++i;
}