#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 6���� ��, P���� ����
// ���� ���� ������ ���� �߻��ϴ�
// (1 �� N �� 500,000, 2 �� P �� 300,000)

/*
	����
	- ���κ� top �迭
	- ���κ� fret 2���� �迭 ���� stackó�� Ȱ���ϱ�
	- while���� ���ؼ� ���ǿ� ���߾ �պ��̰� ����
*/

int main() {
	int N, P, cnt = 0;
	scanf("%d", &N);
	scanf("%d", &P);
	int top[6] = { -1 };
	// �� �ٺ� top �ʱⰪ �Ҵ�
	int* fret[6];
	for (int i = 0; i < 6; i++) {
		fret[i] = (int*)malloc(sizeof(int));
	}
	// �� ������ stack �Ҵ�
	while (N > 0) {
		N--;
		int line, fretnum;
		scanf("%d", &line);
		scanf("%d", &fretnum);
		line--;
		//�ε����� ����ϱ� ���� -1 ���ֱ�
		while (1) {
			if (top[line] == -1) {
				//������ ����ִٸ�
				top[line]++;
				fret[line] = (int*)realloc(fret[line], sizeof(int) * (top[line] + 1));
				fret[line][top[line]] = fretnum;
				cnt++;
				break;
			}
			else {
				//������ ������� �ʴٸ�
				if (fret[line][top[line]] < fretnum) {
					// ���� �����̸� �� ���̱�
					top[line]++;
					fret[line] = (int*)realloc(fret[line], sizeof(int) * (top[line] + 1));
					fret[line][top[line]] = fretnum;
					cnt++;
					break;

				}
				else if (fret[line][top[line]] == fretnum) {
					//���� �����̸� �ൿ x
					break;
				}
				else {
					//�� ���� �����̸� �ն���
					top[line]--;
					cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < 6; i++) {
		free(fret[i]);
	}
	return 0;
}