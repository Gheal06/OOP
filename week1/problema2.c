#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char words[101][101];
int len[101];
int order[101];
bool cmp(int a, int b){
    if(len[a]<len[b]) return false;
    if(len[a]>len[b]) return true;
    return strncmp(words[a],words[b],100)<0;
}
int main()
{
    int n=0;
    while(scanf("%s",words[n])==1){ /// trebuie pus dupa input ctrl D pe linux/mac, respectiv ctrl Z pe windows, ca semnal de EOF
        order[n]=n;
        len[n]=strlen(words[n]);
        n++;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(cmp(order[j],order[i])){
                order[j]^=order[i];
                order[i]^=order[j];
                order[j]^=order[i];
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%s\n",words[order[i]]);
    return 0;
}

