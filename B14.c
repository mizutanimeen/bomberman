#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>

#define GYO 15		/* �}�b�v�̍s�� */
#define RETU 21		/* �}�b�v�̗� */
char nickname[1000];
/* �}�b�v�f�[�^ */
int map_1[GYO][RETU] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 2, 2, 0, 2, 2, 2, 2, 0, 1},
	{1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1},
	{1, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 1},
	{1, 2, 1, 0, 1, 0, 1, 2, 1, 2, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 1},
	{1, 2, 1, 0, 1, 2, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 1},
	{1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1},
	{1, 2, 2, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1},
	{1, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 1},
	{1, 2, 1, 2, 1, 0, 1, 2, 1, 2, 1, 0, 1, 2, 1, 0, 1, 2, 1, 0, 1},
	{1, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 2, 0, 2, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int map_2[GYO][RETU] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1},
	{1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1, 0, 1},
	{1, 0, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 0, 0, 1},
	{1, 2, 1, 0, 1, 0, 1, 2, 1, 2, 1, 2, 1, 0, 1, 0, 1, 2, 1, 0, 1},
	{1, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 0, 2, 2, 2, 0, 0, 0, 0, 1},
	{1, 2, 1, 0, 1, 2, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 2, 2, 2, 1},
	{1, 2, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 2, 1, 0, 1, 0, 1, 2, 1},
	{1, 2, 2, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 0, 2, 2, 2, 1},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 1, 0, 1, 2, 1, 0, 1, 0, 1, 2, 1},
	{1, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 2, 2, 2, 1},
	{1, 0, 1, 2, 1, 0, 1, 2, 1, 2, 1, 2, 1, 2, 1, 0, 1, 2, 1, 0, 1},
	{1, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
int map[GYO][RETU];

//�u���b�N�̌�����
char cellAA[][5+1] = {
	"�@",// CELL_TYPE_NONE
	"��",// CELL_TYPE_HARD_BLOCK
	"��",// CELL_TYPE_SOFT_BLOCK
	"��",//CELL_TYPE_BOMB
	"��",//CELL_TYPE_BLAST
};
//�A�C�e���̌�����
char itemAA[][3+1] = {
	"�g", //have
	"�o", //power
	"�b", //count
};
//�萔
#define HAVE_BOMB_MAX (5)
#define BOMB_COUNT (5)
#define ENEMY_NUM (3)
#define ITEM_NUM (5)
#define ITEM_TYPE (3)
//�\����
typedef struct {
	int x;
	int y;
	int count;
}Bomb;
typedef struct {
	int x;
	int y;
	int power;
	int have_bomb;
	int life;
}Player;
typedef struct {
	int x;
	int y;
	int live;
}Enemy;
typedef struct {
	int x;
	int y;
	int type;
}Item;
//�\���̂̏�����
Player player = {1,1,1,1,3};
Enemy enemy[ENEMY_NUM] = {{3,4,1},{10,11,1},{7,9,1}};
Bomb bomb[HAVE_BOMB_MAX] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
Item item[ITEM_NUM] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
void name_command(){
	char name1[10] = "����ɌN";
	char name2[18] = "�{�}�[�߂܂���";
	int i = 0;int flag1 = 0;int flag2 = 0;int k = 0;
	
	if(strlen(nickname) != strlen(name1)){
		flag1 = 1;
	}
	
	if(strlen(nickname) != strlen(name2)){
		flag2 = 1;
	}

	while(nickname[i]!='\0' && name1[i]!='\0'){
		if(nickname[i]!=name1[i]){
			flag1 = 1;
			break;
		}
		i++;
	}
	i = 0;
	while(nickname[k]!='\0' && name2[k]!='\0'){
		if(nickname[k]!=name2[k]){
			flag2 = 1;
			break;
		}
		k++;
	}	
	if(flag1==0){
		player.power = 100;
		player.life = 500;
		player.have_bomb = 5;
		
	}
	if(flag2==0){
		system("cls");
		printf("���̉��i�J�E���g�_�E���j����");
		player.have_bomb = 0;
		while(1){if(getch() == '\r'){break;}}
	}
}
//���O
void namescan(){
	system("cls");
	printf("�v���C���[�̖��O:");scanf("%s",nickname);
	name_command();
}

//�X�e�[�W�P�̃~�b�V�����Q�̃A�C�e���l������
int item_get_m2 = 1;
//�{���̏����J�E���g��
int bomb_count = BOMB_COUNT;
//���݂̃X�e�[�W
int stage = 1;
//�n�߂��Ƃ��̎��ԂƏI��������̎���
double start_time = 0;
double clear_time = 0;

//TopPage����J�ڂ���Q�[�������y�[�W
void InfoPage(){
	system("cls");
	printf("-���[��-\n");
	printf("�@�@�}�b�v�ɂ��邷�ׂĂ̓G�𔚒e�œ|������N���A�I\n");
	printf("�@�@�G�ɂԂ������蔚���Ɋ������܂��Ǝ��S�I\n");
	printf("�@�@�c�@���P�����ăX�^�[�g�n�_����ăX�^�[�g�I\n");
	printf("�@�@�c�@�͂R�I\n");
	printf("\n");
	printf("-�A�C�e��-\n");
	printf("�@�E�o\n");
	printf("�@�@�����͈̔͂�1�}�X���g��I\n");
	printf("�@�E�g\n");
	printf("�@�@�g�p�\�Ȕ��e�̐�������ǉ��I\n");
	printf("�@�E�b\n");
	printf("�@�@���e�̔����J�E���g��1�J�E���g���x���I\n");
	printf("\n");
	printf("\n");
	printf("Enter�Ŗ߂�\n");
	while(1){if(getch() == '\r'){break;}}
}
	
//�X�e�[�W�J�n�O�̃X�^�[�g���
void TopPage(char *m1,char *m2,char *m3){
	system("cls");
	printf(
	"\x1b[47m�@�@�@�@�@�@�@�@\x1b[40m�@�@\x1b[47m�@�@�@�@�@�@�@�@�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\x1b[47m\n"
	"�@�@�@�@�@�@�@\x1b[40m�@\x1b[41m�@�@\x1b[40m�@\x1b[47m�@�@�@�@�@�@�@\x1b[47m�@\x1b[40m�@�@�@�@�@�@�@�@�@�@�@�@\x1b[47m�@�@�@�@\x1b[47m\n"
	"�@�@�@�@�@\x1b[40m�@�@�@�@�@�@�@�@\x1b[47m�@�@�@�@�@\x1b[47m�@\x1b[40m�@�@�@�@�@�@�@�@�@�@�@�@\x1b[47m�@�@�@�@\x1b[47m\n"
	"�@�@�@�@\x1b[40m�@\x1b[47m�@�@�@�@�@�@�@�@\x1b[40m�@\x1b[47m�@�@�@�@\x1b[47m�@\x1b[40m�@�@ \x1b[31m\x1b[1mEnter�ŃX�^�[�g�@�@\x1b[47m�@�@�@�@\x1b[47m\n"
	"�@�@�@\x1b[40m�@\x1b[47m�@\x1b[43m�@�@�@�@�@�@�@�@\x1b[47m�@\x1b[40m�@\x1b[47m�@�@�@\x1b[47m�@\x1b[40m�@�@�@�@�@�@�@�@�@�@�@�@\x1b[47m�@�@�@�@\x1b[47m\n"
	"�@�@�@\x1b[40m�@\x1b[47m�@\x1b[43m�@\x1b[40m�@\x1b[43m�@�@�@�@\x1b[40m�@\x1b[43m�@\x1b[47m�@\x1b[40m�@\x1b[47m�@�@�@�@\x1b[40m�@�@�@�@�@�@�@�@�@�@�@�@\x1b[47m�@�@�@�@\n"
	"�@�@�@\x1b[40m�@\x1b[47m�@\x1b[43m�@\x1b[40m�@\x1b[43m�@�@�@�@\x1b[40m�@\x1b[43m�@\x1b[47m�@\x1b[40m�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\n"
	"�@�@�@\x1b[40m�@\x1b[47m�@\x1b[43m�@\x1b[40m�@\x1b[43m�@�@�@�@\x1b[40m�@\x1b[43m�@\x1b[47m�@\x1b[40m�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\n"
	"�@�@�@\x1b[40m�@\x1b[47m�@\x1b[43m�@�@�@�@�@�@�@�@\x1b[47m�@\x1b[40m�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\n"
	"�@�@�@�@\x1b[40m�@\x1b[47m�@�@�@�@�@�@�@�@\x1b[40m�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\n"
	"�@�@�@�@\x1b[40m�@�@�@�@�@�@�@�@�@�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\n"
	"�@�@\x1b[40m�@�@\x1b[47m�@\x1b[40m�@\x1b[44m�@�@�@�@�@�@\x1b[40m�@\x1b[47m�@\x1b[40m�@�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\n"
	"�@\x1b[40m�@\x1b[41m�@�@\x1b[47m�@\x1b[40m�@�@�@\x1b[43m�@�@\x1b[40m�@�@�@\x1b[47m�@\x1b[41m�@�@\x1b[40m�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\n"
	"�@\x1b[40m�@\x1b[41m�@�@\x1b[40m�@\x1b[41m�@�@\x1b[44m�@�@�@�@\x1b[41m�@�@\x1b[40m�@\x1b[41m�@�@\x1b[40m�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\n"
	"�@\x1b[47m�@\x1b[40m�@�@\x1b[41m�@�@�@�@\x1b[40m�@�@\x1b[41m�@�@�@�@\x1b[40m�@�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\n"
	"�@\x1b[47m�@�@\x1b[40m�@�@�@�@�@\x1b[47m�@\x1b[40m�@�@�@�@�@�@\x1b[47m�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\n"
	"�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@\x1b[49m\x1b[39m	\x1b[0m\n");	
	puts("");
	printf("�X�e�[�W%d\n",stage);
	printf("�~�b�V�����P�F %s\n",m1);
	printf("�~�b�V�����Q�F %s\n",m2);
	printf("�~�b�V�����R�F %s\n",m3);
	printf("\n");
	printf("q�Ő���������\n");
	while(1){
		int key = getch();
		if(key == '\r'){
			break;
		} else if(key == 113){//q
			InfoPage();
			TopPage(m1,m2,m3);
			break;
		}
	}
}
//�Q�[���I�[�o�[�ɂȂ������ɑJ�ڂ���y�[�W
void GameOverPage(void){
	system("cls");
	printf(
	"�@�@�@�@�@�@�@�����@�@�@�@�@�@�@������������������������������������������������\n"
	"�@�@�@�@�@�@���������@�@�@�@�@���@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n"
	"�@�@�@�@�����������������@�@�@���@�@�@ %s����A�f�`�l�d�n�u�d�q�@�@�@�@�@�@�@�@��\n"
	"�@�@�@���������������������@�@���@�@�@�@���̓N���A���悤�c�@�@�@�@�@�@�@�@�@�@��\n"
	"�@�@�����@�@�@�@�@�@�@�@�����@���@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n"
	"�@�@�����@���@�@�@�@���@�����@������������������������������������������������\n"
	"�@�@�����@�@���@�@���@�@�����@�@�@�@�@�@�@�@\n"
	"�@�@�����@���@�@�@�@���@�����@�@�@�@�@�@�@�@\n"
	"�@�@�����@�@�@�@�@�@�@�@�����@�@�@�@�@�@�@�@\n"
	"�@�@�@���������������������@�@�@�@�@�@�@�@�@\n"
	"�@�@�@���������������������@�@�@�@�@�@�@�@�@\n"
	"�@�����������������������������@�@�@�@�@�@�@\n"
	"���@�@���������@�@���������@�@���@�@�@�@�@�@\n"
	"���@�@���@�@���������@�@���@�@���@�@�@�@�@�@\n"
	"�@�����@�@�@�@�����@�@�@�@�����@�@�@�@�@�@�@\n"
	"�@�@�����������@�������������@�@�@�@�@�@�@�@\n",nickname);
	exit(1);
}
//�X�e�[�W�N���A��ɑJ�ڂ���y�[�W
void ResultPage(int m1,int m2,int m3){
	system("cls");
	printf(
	"�@�@�@�@�@�@�@�����@�@�@�@�@�@�@������������������������\n"
	"�@�@�@�@�@�@���������@�@�@�@�@���@�@�@�@�@�@�@�@�@�@�@��\n"
	"�@�@�@�@�����������������@�@�@���@�@�X�e�[�W�N���A�@�@��\n"
	"�@�@�@���������������������@�@���@�@�@�@�@�@�@�@�@�@�@��\n"
	"�@�@�����@�@�@�@�@�@�@�@�����@�������������������������@\n"
	"�@�@�����@���@�@�@�@���@�����@�@�@�@�@�@�@�@\n"
	"�@�@�����@���@�@�@���@�@�����@�@�@�@�@�@�@�@\n"
	"�@�@�����@���@�@�@�@���@�����@�@�@�@�@�@�@�@\n"
	"�@�@�����@�@�@�@�@�@�@�@�����@�@�@�@�@�@�@�@\n"
	"�@�@�@���������������������@�@�@�@�@�@�@�@�@\n"
	"�@�@�@���������������������@�@�@�@�@�@�@�@�@\n"
	"�@�����������������������������@�@�@�@�@�@�@\n"
	"���@�@���������@�@���������@�@���@�@�@�@�@�@\n"
	"���@�@���@�@���������@�@���@�@���@�@�@�@�@�@\n"
	"�@�����@�@�@�@�����@�@�@�@�����@�@�@�@�@�@�@\n"
	"�@�@�����������@�������������@�@�@�@�@�@�@�@\n");
	printf("�N���A�^�C���F %5.1f\n",(clear_time-start_time)/1000);
	if(m1){
		printf("�~�b�V�����P�F�B��\n");
	} else {
		printf("�~�b�V�����P�F���B��\n");
	}
	if(m2){
		printf("�~�b�V�����Q�F�B��\n");
	}else {
		printf("�~�b�V�����Q�F���B��\n");
	}
	if(m3){
		printf("�~�b�V�����R�F�B��\n");
	}else {
		printf("�~�b�V�����R�F���B��\n");
	}
	printf("Enter�Ŏ���\n");
	while(1){if(getch() == '\r'){break;}}
}
//�S�X�e�[�W�N���A��̃y�[�W
void ClearPage(void){
	system("cls");
	printf(
	"�@�@�@�@�@�@�@�����@�@�@�@�@�@�@������������������������\n"
	"�@�@�@�@�@�@���������@�@�@�@�@���@�@�@�@�@�@�@�@�@�@�@��\n"
	"�@�@�@�@�����������������@�@�@���@�@�@���߂łƂ��@�@�@��\n"
	"�@�@�@���������������������@�@���@�@�@�@�@�@�@�@�@�@�@��\n"
	"�@�@�����@�@�@�@�@�@�@�@�����@�������������������������@\n"
	"�@�@�����@���@�@�@�@���@�����@�@�@�@�@�@�@�@\n"
	"�@�@�����@���@�@�@���@�@�����@�@�@�@�@�@�@�@\n"
	"�@�@�����@���@�@�@�@���@�����@�@�@�@�@�@�@�@\n"
	"�@�@�����@�@�@�@�@�@�@�@�����@�@�@�@�@�@�@�@\n"
	"�@�@�@���������������������@�@�@�@�@�@�@�@�@\n"
	"�@�@�@���������������������@�@�@�@�@�@�@�@�@\n"
	"�@�����������������������������@�@�@�@�@�@�@\n"
	"���@�@���������@�@���������@�@���@�@�@�@�@�@\n"
	"���@�@���@�@���������@�@���@�@���@�@�@�@�@�@\n"
	"�@�����@�@�@�@�����@�@�@�@�����@�@�@�@�@�@�@\n"
	"�@�@�����������@�������������@�@�@�@�@�@�@�@\n");
	printf("�S�X�e�[�W�N���A\n");
}
//���j���[
void print_menu(){
	printf("\n");
	printf("�@Player: %s\n",nickname);
	printf("�@Stage: %d\n",stage);
	printf("�@Time: %5.1f\n",(clock()-start_time)/1000);
	printf("�@life: %d\n",player.life);
	printf("�@Bomb: %d/%d\n",player.have_bomb,HAVE_BOMB_MAX);
	printf("�@Power: %d\n",player.power);
	printf("�@Bomb Count: %d\n",bomb_count);
	printf("\n");
	printf("-------------------------\n");
	printf("\n");
	printf("�@�ړ�: w a s d\n");	/* ������� */
	printf("�@���e�ݒu:enter\n");
	printf("�@�I��:esc\n");
}
//���������ׂč폜
void reset_explosion(){
	for(int y=0; y<GYO; y++){ 
		for(int x=0; x<RETU; x++){
			if(map[y][x] == 4){map[y][x]=0;}
		}
	}
}

//�_���[�W���󂯂����A�Q�[���I�[�o�[���ǂ����m�F
void check_damage_gameover(void){
	for(int i = 0; i< ENEMY_NUM; i++){
		if(!enemy[i].live){continue;}
		if(player.x == enemy[i].x && player.y == enemy[i].y){
			player.life--;
			player.x = 1;
			player.y = 1;
			reset_explosion();
			if(player.life <= 0){
				GameOverPage();
			}
		}
	}
	if(map[player.y][player.x] == 4){
		player.life--;
		player.x = 1;
		player.y = 1;
		reset_explosion();
		if(player.life <= 0){
			GameOverPage();
		}
	}
}
//�����̐�����S�p�����Ƃ��ăv�����g
void print_bomb_count(int count){
	switch (count)
	{
	case 1: 
		printf("�P");
		break;
	case 2:
		printf("�Q");
		break;
	case 3:
		printf("�R");
		break;
	case 4:
		printf("�S");
		break;
	case 5:
		printf("�T");
		break;
	case 6:
		printf("�U");
		break;
	case 7:
		printf("�V");
		break;
	case 8:
		printf("�W");
		break;
	case 9:
		printf("�X");
	default:
		printf("��");
	}
}
//����x,y�̈ʒu�ɑ��݂���bom��index��Ԃ�
int can_print_bomb_index(int x,int y){
	for(int i = 0; i< player.have_bomb; i++){
		if(x == bomb[i].x && y == bomb[i].y){
			return i;
		}
	}
	return -1;
}
//���݁A�g���Ă��Ȃ��{����index��Ԃ�
int can_use_bomb_index(void){
	for(int i = 0; i < player.have_bomb; i++){
		if(bomb[i].count < 0){
			return i;
		}
	}
	return -1;
}
//bomb�̃J�E���g��S���P���炷
void count_down_bomb(void){
	for(int i = 0; i< player.have_bomb; i++){
		bomb[i].count--;
	}
}
//����x,y�̈ʒu�ɑ��݂���enemy��index��Ԃ�
int can_print_enemy_index(int x,int y){
	for(int i = 0; i< ENEMY_NUM; i++){
		if(x == enemy[i].x && y == enemy[i].y){
			return i;
		}
	}
	return -1;
}
//���݁A�g���Ă��Ȃ��A�C�e����index��Ԃ�
int can_use_item_index(){
	for(int i = 0; i < ITEM_NUM; i++){
		if(item[i].type == -1){
			return i;
		}
	}
	return -1;
}
//����x,y�̈ʒu�ɑ��݂���item��index��Ԃ�
int can_print_item_index(int x,int y){
	for(int i = 0; i< ITEM_NUM; i++){
		if(x == item[i].x && y == item[i].y){
			return i;
		}
	}
	return -1;
}

void item_create(int bx,int by,int px, int py,int p){
	int item_index = can_use_item_index(); //�A�C�e���\���ɋ󂫂����邩
	if(item_index != -1){
		if((time(NULL)+(rand() % 7 + 1))%5 >= 3){ //�A�C�e������
			item[item_index].type = (time(NULL)+(rand() % 7 + 1))%ITEM_TYPE;
			item[item_index].x = bx+px*p;
			item[item_index].y = by+py*p;
		}
	}
}

//������\��
void explosion(int bx,int by,int px, int py,int index){
	int flag = 1;
	bomb[index].count = -1;
	for(int p=0; p<=player.power; p++){
		if(map[by+py*p][bx+px*p] != 1 && flag == 1){
			for(int i = 0; i<ITEM_NUM;i++){
				if(item[i].y == by+py*p && bx+px*p == item[i].x){
					item[i].type = -1;
					item[i].y = -1;
					item[i].x = -1;
				}
			}
			if(map[by+py*p][bx+px*p] == 2){ //�j��\�u���b�N����󂵂���~�߂�
				flag = 0;
				item_create(bx,by,px,py,p);
			}
			map[by+py*p][bx+px*p] = 4; //������`��
			for(int i = 0; i< ENEMY_NUM; i++){ // �G�̓|������
				if(by+py*p==enemy[i].y && bx+px*p == enemy[i].x){
					enemy[i].live = 0;
				}
			}
			if(by+py*p==player.y && bx+px*p ==player.x){//�v���C���[�̎��ʔ���
				player.life--;
				player.x = 1;
				player.y = 1;
				reset_explosion();
				if(player.life <= 0){
					GameOverPage();
				}
			}
			for(int i=0; i<player.have_bomb;i++){
				if(by+py*p == bomb[i].y && bx+px*p == bomb[i].x && bomb[i].count >= 0){ // ���e�ɓ��������炻�̔��e�����j
					bomb[i].count = 0;
					if(index > i){
						int a = bomb[i].x;
						int b = bomb[i].y;
						explosion(a,b,1,0,i);
						explosion(a,b,-1,0,i);
						explosion(a,b,0,1,i);
						explosion(a,b,0,-1,i);
					}
				}
			}
		} else {
			break;
		}
	}
}

/* �}�b�v��\�� */
void draw_map(void)
{
	system("cls");
	for(int i=0;i<player.have_bomb;i++){ // ���e�̃J�E���g���O�Ȃ甚��������.
		if(bomb[i].count == 0){
			int bx = bomb[i].x;
			int by = bomb[i].y;
			explosion(bx,by,1,0,i);
			explosion(bx,by,-1,0,i);
			explosion(bx,by,0,1,i);
			explosion(bx,by,0,-1,i);
		}
	}
	for(int y=0; y<GYO; y++){
		for(int x=0; x<RETU; x++){
			if (map[y][x] == 4){
				printf(cellAA[map[y][x]]);
			}else if(can_print_enemy_index(x,y) != -1){
				if(enemy[can_print_enemy_index(x,y)].live){
					printf("�G");
				} else {
					if(x == player.x && y == player.y){
						printf("�l");
						
					}else if(can_print_item_index(x,y) != -1){
						printf(itemAA[item[can_print_item_index(x,y)].type]);
					} else {
						printf(cellAA[0]);
					}
				}
			}else if(x == player.x && y == player.y){
				printf("�l");
			}else if(can_print_item_index(x,y) != -1){
				printf(itemAA[item[can_print_item_index(x,y)].type]);
			}else if(can_print_bomb_index(x,y) != -1){
				int index = can_print_bomb_index(x,y);//���̍��W�̃{���̃C���f�b�N�X���擾
				map[y][x] = 3; //�{���ݒu
				if (bomb[index].count <= 0){ //�J�E���g��0�ȉ��̃{���͕\�����Ȃ�
					map[y][x] = 0;
					printf(cellAA[0]);
				} else {
					print_bomb_count(bomb[index].count); //�{���̃J�E���g��\��
				}
			} else {
				printf(cellAA[map[y][x]]);//�}�b�v�̔ԍ��̃u���b�N��\��
			}
		}
		printf("\n");
	}
	print_menu();
}

int enemy_not_conflict(int index,int x,int y){
	for(int i = 0; i< ENEMY_NUM; i++){
		if (index == i){ continue; }
		if(enemy[i].x == (enemy[index].x + x) && enemy[i].y == enemy[index].y + y){
			return 0; //False ���̓G�ƈʒu�����
		}
	}
	return 1; // True
}
//�G�̍s���p�^�[���i�K���j
void enemy_move(void){
	for(int i = 0; i< ENEMY_NUM; i++){
		//�ړ��悪�����Ȃ��ꏊ(0)�����̓G�����Ȃ����m�F
		//�s���p�^�[�������Ԃɂ���ĕύX
		switch((time(NULL)+i+(rand() % 10 + 1))%4){
			case 0:
				if(map[enemy[i].y][enemy[i].x+1] == 0 && enemy_not_conflict(i,1,0))
					enemy[i].x++;
				else if(map[enemy[i].y+1][enemy[i].x] == 0 && enemy_not_conflict(i,0,1))
					enemy[i].y++;
				else if(map[enemy[i].y][enemy[i].x-1] == 0 && enemy_not_conflict(i,-1,0))
					enemy[i].x--;
				else if(map[enemy[i].y-1][enemy[i].x] == 0 && enemy_not_conflict(i,0,-1))
					enemy[i].y--;
				break;
			case 1:
				if(map[enemy[i].y+1][enemy[i].x] == 0 && enemy_not_conflict(i,0,1))
					enemy[i].y++;
				else if(map[enemy[i].y][enemy[i].x-1] == 0 && enemy_not_conflict(i,-1,0))
					enemy[i].x--;
				else if(map[enemy[i].y-1][enemy[i].x] == 0 && enemy_not_conflict(i,0,-1))
					enemy[i].y--;
				else if(map[enemy[i].y][enemy[i].x+1] == 0 && enemy_not_conflict(i,1,0))
					enemy[i].x++;
				break;
			case 2:
				if(map[enemy[i].y][enemy[i].x-1] == 0 && enemy_not_conflict(i,-1,0))
					enemy[i].x--;
				else if(map[enemy[i].y-1][enemy[i].x] == 0 && enemy_not_conflict(i,0,-1))
					enemy[i].y--;
				else if(map[enemy[i].y][enemy[i].x+1] == 0 && enemy_not_conflict(i,1,0))
					enemy[i].x++;
				else if(map[enemy[i].y+1][enemy[i].x] == 0 && enemy_not_conflict(i,0,1))
					enemy[i].y++;
				break;
			case 3:
				if(map[enemy[i].y-1][enemy[i].x] == 0 && enemy_not_conflict(i,0,-1))
					enemy[i].y--;
				else if(map[enemy[i].y][enemy[i].x+1] == 0 && enemy_not_conflict(i,1,0))
					enemy[i].x++;
				else if(map[enemy[i].y+1][enemy[i].x] == 0 && enemy_not_conflict(i,0,1))
					enemy[i].y++;
				else if(map[enemy[i].y][enemy[i].x-1] == 0 && enemy_not_conflict(i,-1,0))
					enemy[i].x--;
				break;
		}
	}
}
//�N���A����
int clear_check(){
	for(int i=0;i<ENEMY_NUM;i++){
		if(enemy[i].live){
			return 0;
		}
	}
	return 1;
}

/* �v���C���[�s���̂��߂̃L�[���͎�t */
void key_input(int key)
{
	//�ړ��悪�����Ȃ��ꏊ���m�F
	if(key == 119 && map[player.y-1][player.x] == 0 || map[player.y-1][player.x] == 4)			/* w�L�[ */
		player.y --;
	else if(key == 115 && map[player.y+1][player.x] == 0 || map[player.y+1][player.x] == 4)		/* s�L�[ */
		player.y ++;
	else if(key == 97 && map[player.y][player.x-1] == 0 || map[player.y][player.x-1] == 4)		/* a�L�[ */
		player.x --;
	else if(key == 100 && (map[player.y][player.x+1] == 0 || map[player.y][player.x+1] == 4))		/* d�L�[ */
		player.x ++;
	else if(key == '\r' && can_use_bomb_index() != -1){ /* enter�L�[ */  
		int index = can_use_bomb_index(); //�g���ĂȂ��{�����擾,�����ݒ�
		bomb[index].x = player.x;
		bomb[index].y = player.y;
		map[player.y][player.x] = 3;
		bomb[index].count = bomb_count;
	}
	else if(key == 27){exit(1);}/* esc�L�[ */
}

void item_get_check(){
	for(int i = 0; i < ITEM_NUM; i++){
		if(item[i].x == player.x && item[i].y == player.y){
			switch (item[i].type)
			{
			case 0:
				if(player.have_bomb<HAVE_BOMB_MAX){
					player.have_bomb++;
				}
				break;
			case 1:
				player.power++;
				break;
			case 2:
				bomb_count++;
				break;
			}
			item[i].x = -1;
			item[i].y = -1;
			item[i].type = -1;
			item_get_m2 = 0;
		}
	}
}

void main_game(char *m1,char *m2,char *m3,double roop_time) {
	TopPage(m1,m2,m3);
	bomb_count = BOMB_COUNT;
	draw_map();	/* �}�b�v��\�� */
	double base_time = 0;
	start_time = clock();
	while(1){
		if(clock()-base_time >= roop_time){
			base_time = clock();
			enemy_move();/* �G�ړ� */
			check_damage_gameover();//�Q�[���I�[�o�[���ǂ����m�F
			count_down_bomb();//�{���̃J�E���g��i�߂�
			reset_explosion();
			draw_map();	/* �}�b�v��\�� */
		}
		if(clear_check()){
			clear_time = clock();
			break;
		}//�N���A�`�F�b�N
		if ( kbhit() ){
			key_input(getch());/* �v���C���[�s���̂��߂̃L�[���͎�t */
			item_get_check();//�A�C�e���擾
			check_damage_gameover();//�Q�[���I�[�o�[���ǂ����m�F
			draw_map();	/* �}�b�v��\�� */
		}
	}
}

void bomb_set(void){
	for(int i = 0; i < HAVE_BOMB_MAX; i++){
		bomb[i].x = -1;
		bomb[i].y = -1;
		bomb[i].count = -1;
	}
}
void item_set(void){
	for(int i = 0; i < ITEM_NUM; i++){
		item[i].x = -1;
		item[i].y = -1;
		item[i].type = -1;
	}
}
void enemy_set(int index,int x,int y){
	enemy[index].x = x;
	enemy[index].y = y;
	enemy[index].live = 1;
}
void player_set(){
	player.x = 1;
	player.y = 1;
	player.have_bomb = 1;
	player.power = 1;
	player.life = 3;
}

int main(void)
{
	//�R�R��map_2�Ƃ�����ă����_���ɂ���΃}�b�v�����_���ɂł���
	srand(time(NULL));
	int i = rand() % 2;
	if(i == 0){
		memcpy(map, map_2, sizeof(map_2));
	}
	else{
		memcpy(map, map_1, sizeof(map_1));
	}

	//�X�e�[�W�P
	namescan();
	enemy[1].live = 0;
	main_game("60�b�ȓ��ɃN���A","�A�C�e�����P����炸�ɃN���A","�P�x�����ꂸ�ɃN���A",500.0);
	//�~�b�V�����B������
	int r1=0,r2=0,r3=0;
	if((clear_time-start_time)/1000 <= 60){r1 = 1;}
	if(item_get_m2){r2 = 1;}
	if(player.life == 3){r3 = 1;}
	ResultPage(r1,r2,r3);


	if(i == 0){
		memcpy(map, map_1, sizeof(map_1));
	}
	else{
		memcpy(map, map_2, sizeof(map_2));
	}
	stage++;
	item_get_m2 = 1;
	player_set();
	enemy_set(0,3,4);enemy_set(1,7,8);enemy_set(2,10,11);
	bomb_set();
	item_set();
	name_command();
	//�X�e�[�W�Q
	main_game("90�b�ȓ��ɃN���A","�A�C�e�����P����炸�ɃN���A","�P�x�����ꂸ�ɃN���A",300.0);
	//�~�b�V�����B������
	r1=0,r2=0,r3=0;
	if((clear_time-start_time)/1000 <= 90){r1 = 1;}
	if(item_get_m2){r2 = 1;}
	if(player.life == 3){r3 = 1;}
	ResultPage(r1,r2,r3);

	ClearPage();
	return 0;
}

//����
//�c�@�𑝂₷�A�C�e������H
//�c�@���X�e�[�W�ς���Ă������p���H