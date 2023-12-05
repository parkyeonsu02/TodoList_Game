#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<Windows.h>

void draw(int a[30][30]) //맵 생성 함수
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (a[i][j] == 0)
				printf("■");
			else if (a[i][j] == 1)
				printf("※");
			else if (a[i][j] == 2)
				printf("●");
		}
		printf("\n");
	}
}

void land() { //지뢰찾기 게임 진행 함수
	int map[30][30];
	int hide[30][30];
	srand((unsigned)time(NULL));
	int a, b, c, d, k;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			map[i][j] = 0;
			hide[i][j] = 0;
		}
	}
	printf("생성할 지뢰개수를 입력해주세요(30*30)\n");
	scanf_s("%d", &k);
	for (int i = 0; i < k; i++)
	{
		while (1)
		{
			a = rand() % 30;
			b = rand() % 30;
			if (map[a][b] == 1)
				;
			else
			{
				map[a][b] = 1;
				break;
			}
		}
		map[a][b] = 1;
	}
	while (1)
	{
		draw(hide);
		printf("x좌표입력: ");
		scanf_s("%d", &c);
		printf("y좌표 입력: ");
		scanf_s("%d", &d);

		c--;
		d--;

		if (c >= 30 || d >= 30 || c < 0 || d < 0)
		{
			printf("범위안의 숫자를 입력해주세요\n");
			Sleep(1000);
		}

		else if (map[c][d] == 1)
		{
			hide[c][d] = 1;
			system("cls");
			draw(hide);
			printf("꽝입니다.\n");
			Sleep(2000);
			break;
		}
		else if (hide[c][d] == 2)
		{
			printf("이미 방문했습니다.\n");
		}
		else if (map[c][d] == 0)
		{
			printf("맞았습니다.\n");
			hide[c][d] = 2;
		}
		Sleep(1000);
		system("cls");
	}
	printf("지뢰위치\n");
	draw(map);
	printf("============================\n");
	printf("오늘 하루도 수고하셨습니다.");
}

int main(void) {
	char list[10][100] = { 0, };	 //배열 초기화
	int sum = 0, a, end;
	do {
		printf("=========================================================================================\n");
		printf_s("어떤 작업을 실행하시겠습니까? 1) todolist 작성 2) 완료된 일 삭제 3) list확인 4) 종료 >>");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			printf_s("할 일을 입력해주세요.(최대 10개. ';'을 입력하면 저장이 중지됩니다.)>>");
			for (int i = 0; i < 10; i++) {
				scanf_s("%s", list[i], 100);	
				if (list[i][0] == ';') {		
					printf_s("입력을 중단합니다.\n");
					break;

				}
				printf_s("%d) %s\n", i+1, list[i]);
			}
			break;
		case 2:
			printf_s("어떤 일을 완료하셨습니까?");
			scanf_s("%d", &end);
			list[end][0] = NULL;	
			sum += 1;
			break;
		case 3:
			printf_s("현재 남은 일을 출력합니다.\n");
			for (int i = 0; i < 10; i++) {
				printf_s("%d)%s\n", i+1, list[i]);	
			}
			break;
		case 4:
			printf_s("프로그램을 종료합니다.\n");
			printf_s("당신의 포인트는:%d\n", sum);
			int con;
			printf_s("지뢰찾기 게임을 진행하시겠습니까?(1.Y/2.N)>>");
			scanf_s("%d", &con);
			if (con == 1) {
				printf_s("지뢰찾기 게임을 시작하겠습니다.(소요 포인트: 5pt)\n");
				if (sum > 5) {
					sum -= 5;
					land();
					if (sum > 5) {
						int n1;
						printf("지뢰 찾기 게임에 한 번 더 도전하시겠습니까?(1.Y / 2.N):");
						scanf_s("%d", &n1);
						if (n1 == 1) {
							sum -= 5;
							land();
							break;
						}
					}
					
				}
				else {
					printf("포인트가 부족합니다.\n");
					break;
				}
			}
			else if(con==2) {
				printf_s("오늘도 수고하셨습니다.\n");
			}
			return 0;
		default:
			printf_s("다시 입력해주세요.\n");
			break;
		}
	} while (1 <= a < 5);
	
	return 0;
}