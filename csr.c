#include <stdlib.h>
int m,n,**sp,*A,*IA,*JA,count;
void create_matrix()
{
    int i,j;
    sp=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
    *(sp+i)=(int*)malloc(n*sizeof(int));
    printf("\nenter the values of array\n");
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    scanf("%d",&sp[i][j]);
    printf("the required matrix is\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",sp[i][j]);
        }
        printf("\n");
    }
}
void create_csr()
{
    int c=0,z=0,t=1,l=0,i,j;
    IA=(int*)malloc((m+1)*sizeof(int));
    IA[0]=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(sp[i][j]!=0)
            {
            c++;
            z++;
            }
        }
        IA[t]=IA[t-1]+z;
        t++;
        z=0;
    }
    A=(int*)malloc(c*sizeof(int));
    JA=(int*)malloc(c*sizeof(int));
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(sp[i][j]!=0)
            {
            JA[l]=j;
            A[l]=sp[i][j];
            l++;
            }
        }
    }
    printf("\ncsr representation of the given matrix is\n");
    for(i=0;i<c;i++)
    printf("%d  ",A[i]);
    printf("\n");
    for(i=0;i<m+1;i++)
    
        printf("%d  ",IA[i]);
        printf("\n");
        for(i=0;i<c;i++)
        printf("%d  ",JA[i]);
        count=c;
}
void trans_csr()
{
    int c,t=0,x=0,p=0,u,z=0,y,r=1,ja[count],ia[50],d=0,i;
    c=count;
    u=count;
    while(t<c-1)
    {
        for(i=IA[t];i<IA[t+1];i++)
        {
            ja[x]=p;
            x++;
        }
        p++;
        t++;
    }
    ia[0]=0;
    while(u)
    {
        for(i=0;i<c;i++)
        {
            if(JA[i]==d)
            y++;

        }
        ia[r]=ia[r-1]+y;
        u--;
        r++;
        d++;
        y=0;
    }
     printf("\ntransposed csr representation of the given matrix is\n");
    for(i=0;i<c;i++)
    printf("%d  ",A[i]);
    printf("\n");
    if (m>n)
    {
    for(i=0;i<m+1;i++)
    
        printf("%d  ",ia[i]);
        printf("\n");
    }
    else if(n>m)
    {
        for(i=0;i<n+1;i++)
    
        printf("%d  ",ia[i]);
        printf("\n");
    }
        for(i=0;i<c;i++)
        printf("%d  ",ja[i]);

    


}
int main()
{
    double d;
    int z;
    printf("\nenter the number of rows and columns of original matrix\n");
    scanf("%d %d",&m,&n);
    create_matrix();
    create_csr();
    trans_csr();
    d=2.0/3.0;
    d=d*(m*n);
    z=(int)d;
    if(z>count)
    printf("\ncsr representation is advantageous");
    else
    printf("\ncsr representation is not advantageous");
    return 0;
}

