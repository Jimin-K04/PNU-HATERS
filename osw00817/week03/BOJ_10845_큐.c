#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10001

/*
push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�.
���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

typedef struct {
	int data[SIZE];
	int front, rear;
}Queue;

void init(Queue* Q) {
	Q->front = Q->rear = -1;
}
int isEmpty(Queue* Q) {
	return Q->front == Q->rear;
}
int isFull(Queue* Q) {
	return Q->rear == SIZE - 1;
}
void enqueue(Queue* Q, int e) {
	if (!isFull(Q)) {
		Q->rear++;
		Q->data[Q->rear] = e;
	}
}
int dequeue(Queue* Q) {
	if (!isEmpty(Q)) {
		Q->front++;
		return Q->data[Q->front];
	}
}
int main() {
	int loop = 0;
	scanf("%d", &loop);

	Queue Queue;
	init(&Queue);

	while (loop > 0) {
		loop--;
		char command[6];
		scanf("%s", command);
		if (strcmp(command, "push") == 0) {
			//���� X�� ť�� �ִ� �����̴�.
			int num = 0;
			scanf("%d", &num);
			enqueue(&Queue, num);
		}
		else if (strcmp(command, "pop") == 0) {
			//pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. 
			//���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
			if (isEmpty(&Queue)) {
				printf("%d\n", -1);
			}
			else {
				printf("%d\n", dequeue(&Queue));
			}
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", Queue.rear - Queue.front);
		}
		else if (strcmp(command, "empty") == 0) {
			if (isEmpty(&Queue)) {
				printf("%d\n", 1);
			}
			else {
				printf("%d\n", 0);
			}
			// ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
		}
		else if (strcmp(command, "front") == 0) {
			if (isEmpty(&Queue)) {
				printf("%d\n", -1);
				break;
			}
			printf("%d\n", Queue.data[Queue.front + 1]);
			//ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
		}
		else if (strcmp(command, "back") == 0) {
			if (isEmpty(&Queue)) {
				printf("%d\n", -1);
				break;
			}
			printf("%d\n", Queue.data[Queue.rear]);
			//ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
		}
	}
}