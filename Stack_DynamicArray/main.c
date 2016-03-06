//
//  main.c
//  Stack_DynamicArray
//
//  Created by chenyufeng on 16/3/6.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

#include <stdio.h>
#include "StackFunction.h"
#include <stdlib.h>

static int *stack;//声明数组
static int staticSize;//数组大小
static int top_element = -1;//指向数组的指针

void createStack(int size){

    if (staticSize == 0) {
        staticSize = size;
        stack = (int *)malloc(staticSize *sizeof(int));
        if (stack == NULL) {
            printf("数组内存分配失败\n");
        }
    }
}

void destroyStack(){

    if (staticSize > 0) {
        staticSize = 0;
        free(stack);
        stack = NULL;
        top_element = -1;
    }
}

void push(int value){

    if (!isFull()) {
        stack[++top_element] = value;
    }
}

void pop(){

    if (!isEmpty()) {
        top_element--;
    }
}

int top(){

    if (!isEmpty()) {
        return stack[top_element];
    }

    return -32768;
}

int isEmpty(){

    return top_element == -1;
}

int isFull(){

    return top_element == staticSize - 1;
}

void printStack(){

    int i = top_element;
    printf("打印出动态数组堆栈里面的值: ");
    if(i == -1){
        printf("这是个空堆栈");
    }else{
        while(i!= -1){
            printf("%d ",stack[i--]);
        }
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {

    createStack(50);
    printStack();

    push(6);push(3);push(9);push(1);push(4);
    printf("栈中压入数据后：\n");
    printStack();
    pop();pop();

    printf("弹出数据后，栈内的元素为：\n");
    printStack();

    printf("取栈顶的元素:%d\n",top());

    destroyStack();
    printStack();

    return 0;
}

















