#include <stdio.h>
#include <stdlib.h>

#define INF -9999999

typedef struct S_T_A_C_K
{
    int *array;
    int top;
    int empty;
    int size;
} Stack;

int *createArray(int size, int value)
{
    int *array = (int *)malloc((size) * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        array[i] = value;
    }

    return array;
}

void stackPush(Stack *s, int val)
{
    if (s->empty)
        s->empty = 0;
    if (s->size - 1 == s->top)
    {
        printf("\nWarning: Stack is Full\n");
        return;
    }
    s->array[++s->top] = val;
}
void stackPop(Stack *s)
{
    if (s->empty)
    {
        printf("\nWarning: Stack is  Empty\n");
        return;
    }
    if (s->top == 0)
    {
        s->top = -1;
        s->empty = 1;
    }
    else
        --s->top;
}
int stackIsEmpty(Stack *s)
{
    return s->empty;
}
int stackTop(Stack *s)
{
    if (s->empty)
    {
        printf("\nWarning: Stack is  Empty\n");
        return -1;
    }
    return s->array[s->top];
}

void stackShow(Stack s)
{
    if (s.empty)
        printf("\n*- Stack is Empty -*\n");
    else
    {

        printf("\n\n[Stack]\n%d <-TOP\n--", s.array[s.top]);
        for (int i = s.top - 1; i >= 0; i--)
        {
            printf("\n");
            printf("%d ", s.array[i]);
            printf("\n");
            printf("--");
        }
        printf("\n");
    }
}

void createStack(Stack *s, int size)
{
    s->array = createArray(size, 12);
    s->top = -1;
    s->empty = 1;
    s->size = size;
}

//

typedef struct q_u_e_u_e
{
    int *array;
    int front;
    int rear;
    int empty;
    int size;
    int ele;
} Queue;

void createQueue(Queue *q, int size)
{
    q->array = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->empty = 1;
    q->ele = 0;
    q->size = size;
}
int QueueIsFull(Queue q)
{
    if ((q.front == 0 && q.rear == q.size - 1) || (q.front == q.rear + 1))
        return 1;
    return 0;
}
int QueueIsEmpty(Queue q)
{
    return q.empty;
}
void QueuePush(Queue *q, int value)
{
    if (QueueIsFull(*q))
    {
        printf("\n[Warning]: Queue is Full\n");
        return;
    }
    else if (QueueIsEmpty(*q))
    {
        q->empty = 0;
        q->array[++(q->front)] = value;
        q->rear++;
        q->ele++;
    }

    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->array[q->rear] = value;
        q->ele++;
    }
}
void QueuePop(Queue *q)
{

    if (QueueIsEmpty(*q))
    {
        printf("\n[Warning]:Queue is Empty\n");
        return;
    }
    else if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
        q->empty = 1;
        q->ele = 0;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        q->ele--;
    }
}
int QueuePeek(Queue q)
{

    if (QueueIsEmpty(q))
    {
        printf("\n[Warning]:Queue is Empty\n");
        return INF;
    }
    else
        return q.array[q.front];
}

void QueueShow(Queue q)
{
    if (QueueIsEmpty(q))
    {
        printf("\n[Warning]:Queue is Empty\n");
        return;
    }
    int ele = q.front;
    printf("[QUEUE]\n\nFRONT->| ");
    for (int i = 1; i <= q.ele; i++)
    {
        printf("%d | ", q.array[ele]);
        ele = (ele + 1) % q.size;
    }
    printf("<-REAR\n");
}
// int main()
// {

//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     int size;

//     read(size);

//     // Stack s;
//     // createStack(&s, 5);
//     // out(s.empty);
//     // stackPush(&s, 1);
//     // stackPush(&s, 2);
//     // stackPush(&s, 3);
//     // stackPush(&s, 4);
//     // stackPush(&s, 5);
//     // stackPop(&s);
//     // stackPop(&s);
//     // stackPop(&s);
//     // stackPop(&s);
//     // stackPop(&s);
//     // stackPop(&s);

//     // stackShow(s);
//     return 0;
// }
// int main()
// {
//     // queue

//     Queue q;
//     createQueue(&q, 5);
//     QueuePush(&q, 1);
//     QueuePush(&q, 2);
//     QueuePush(&q, 3);
//     QueuePush(&q, 4);
//     QueuePush(&q, 5);
//     QueuePop(&q);
//     QueuePop(&q);
//     QueuePop(&q);
//     QueuePop(&q);
//     QueuePop(&q);
//     QueuePush(&q, 6);
//     QueuePush(&q, 1);
//     QueuePush(&q, 0);
//     QueueShow(q);

// }