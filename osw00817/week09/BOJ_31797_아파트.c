#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct apt {
	int person;
	int floor;
} apt;

int compare(const void* a, const void* b) {
	return (apt*)a->floor - (apt*)b->floor;
}

int main() {
	/*
	5 3
	1 6
	3 4
	2 5
	*/
	int N, M;
	scanf("%d %d", &N, &M);
	int size = M * 2;
	apt* list = (apt*)malloc(sizeof(apt) * (size));
	for (int i = 1; i <= size; i*=2) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		printf("%d ", i);
	}
	qsort(list,size+1,sizeof()

	int alchol = N % (M * 2);
	if (alchol == 0)
		alchol = N;
	printf("%d", list[alchol]);
	*/
	//������� 
	// 4 2
	// 1 2
	// 5 6
	// �� ���°��
	// list �迭�� 1 1 null null
	// list �迭�� 2 2 null null �� �Ǵ� ��찡 �߻�
	// ���������� �����ϸ� ���� �б� ó���� ���� ������ ��굵 ����ؾ���
	// ==> ������ => ����@@

	// �迭 �ް�, ���� �Ѵ��� , �ϴ°� �׳� ����
}

/*
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int size = M * 2;
	int* list = (int*)malloc(sizeof(int) * (size + 1));
	for (int i = 1; i <= M; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		list[(tmp1%size != 0) ? tmp1%size : size] = i;
		list[(tmp2%size != 0) ? tmp2%size : size] = i;
	}
	int alchol = N % (M * 2);
	if (alchol == 0)
		alchol = N;
	printf("%d", list[alchol]);
}
*/