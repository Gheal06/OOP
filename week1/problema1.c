#include<stdio.h>

int custom_atoi(const char* s){
    int n=0;
    for(int i=0;s[i];i++)
        n=(n<<1)+(n<<3)+(s[i]^48); // 2n+8n+(s[i]-48), probabil e marginal mai eficient decat inmultirea
    return n;
}
int main()
{
    FILE* fn=fopen("ini.txt","r");
    int n,sum=0;
    while(fscanf(fn,"%d",&n)==1)
        sum+=n;
    printf("%d",sum);
    return 0;
}

