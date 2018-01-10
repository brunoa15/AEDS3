#include <stdio.h>

int main(void)
{
    int i,qtdFeit,vida,dano,mana,aux;
    double totMana;

    while(scanf("%d %d",&qtdFeit,&vida)!=EOF)
    {
        //scanf("%d %d",&qtdFeit,&vida);
        for(i=0,totMana=0;i<qtdFeit;i++)
        {
            scanf("%d %d",&dano,&mana);
            aux=dano;
            while(!dano==0 && !vida==0)
            {
                dano--;
                vida--;     
            }
            totMana+=((double)mana/aux)*(aux-dano);
        }
        if(vida==0)
            printf("%.0lf\n",totMana);
        else
            printf("-1\n");
    }
    return 0;
}