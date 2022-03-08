#include<stdio.h>

#define MaxSize 100
typedef int ElemType;
typedef int Age;
typedef struct stu {
    int data[100];
    int length;
} SqList;

void InitList(SqList &L);

int Insert(SqList &L, int i, int x);

void display(const SqList &L);

int main() {
    SqList L;
    InitList(L);

    for (int i = 2; i <= 5; i++) {
        Insert(L, 0, i);
    }
    // 输出在第一个位置连续插入2-5的结果
    display(L);

    Insert(L, 5, 10);
    // 输出在第五个位置插入10的结果
    display(L);


    return 1;
}

void display(const SqList &L) {
    printf("%d\n", L.length);
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}


void InitList(SqList &L) {
    L.length = 1;
    L.data[0] = 1;
}

int Insert(SqList &L, int i, int x) {
    int j;
    // 插入索引不存在
    // [1, 2, 3] length=3 因为插入的位置需要在list里，所以不可以大于length+1
    // length 小于等于0也不可以插入，因为无合法数据
    if (i > L.length + 1 || L.length <= 0)
        return 0;
    else {
        L.length++;
        // 从最后一位往前遍历，将每一位往后娜一个位置
        for (j = L.length; j >= i; j--) {
            L.data[j] = L.data[j - 1];
        }
        L.data[i - 1] = x;
    }
    return 1;
}



