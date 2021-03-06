# include "List.h"

int main()
{

    SqList L,Lb;    
    Status i;
    ElemType e;


    int j,k;
    i = InitList(&L);
    printf("初始化L后：L.length=%d\n", L.length);

    for (j = 1; j <= 5; j++)
    {
        i = ListInsert(&L, j, j);
    }
    ListTraverse(L);
    printf("L.length=%d \n", L.length);
  
   i = ListEmpty(L);
   printf("L是否空：i=%d(1:是 0:否)\n", i);

   i = ClearList(&L);
   printf("清空L后：L.length=%d\n", L.length);

    i = ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n", i);

    for (j = 1; j <= 10; j++)
    {
        ListInsert(&L, j, j);
    }
    ListTraverse(L);
    printf("L.length=%d \n", L.length);

    GetElem(L, 5, &e);
    printf("第5个元素的值为：%d\n", e);

    for (j = 3; j <= 4; j++)
    {
        k = LocateElem(L, j);
        if (k)
        {
            printf("第%d个元素的值为%d\n", k, j);
        }  
        else
        {
            printf("没有值为%d的元素\n", j);
        }    
    }


    k = ListLength(L);    // k为表长
    for (j = k + 1; j >= k; j--)
    {
        i = ListDelete(&L, j, &e);  // 删除第j个数据
        if (i == ERROR)
        {
            printf("删除第%d个数据失败\n", j);
        }
        else
        {
            printf("删除第%d个的元素值为：%d\n", j, e);
        }    
    }
    printf("依次输出L的元素：");
    ListTraverse(L);

    j = 5;
    ListDelete(&L, j, &e); // 删除第5个数据 
    printf("删除第%d个的元素值为：%d\n", j, e);
    printf("依次输出L的元素：");
    ListTraverse(L);

    //构造一个有Lb
    i = InitList(&Lb);
    for (j = 1; j <= 15; j++)
    {
        i = ListInsert(&Lb, j, j);
    }
    ListTraverse(Lb);

    unionL(&L, Lb);
    printf("依次输出合并了Lb的L的元素：");
    ListTraverse(L);

    return 0;
}