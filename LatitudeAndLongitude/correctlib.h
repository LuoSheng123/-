//#pragma once

#ifndef CORRECT_H
#define CORRECT_H

#include "bmplib.h"

//�Ҷ�ͼ��
typedef struct
{
	int width;
	int height;
	unsigned char* grayData;
}GrayImage;

/*//����ͼ�����
typedef struct
{
	double radius;	//Բ�뾶
	double centerX;	//Բ������
	double centerY;
}ImageParam;*/

//��������
typedef struct
{
	double radius;	//Բ�뾶

	double fx;	//������������
	double fy;	//�������������
	double cx;	//ͼ���׼�������	//Բ������
	double cy;	//ͼ���׼��������	//Բ������
	double k1;	//����������1
	double k2;	//����������2
	double p1;	//����������1
	double p2;	//����������2
}CorrectParam;

GrayImage *Image2Gray(ClImage *img);
int ObtainParam(CorrectParam *param, GrayImage *gray);
int EasyObtainParam(CorrectParam *param, ClImage *img);
void ImageCoord2RectangularCoord(int x0, int y0, int u, int v, int *x, int *y);
void CorrectMap(int R, double f, int x, int y, int *u, int *v);
ClImage *Correct1(ClImage *mImg, CorrectParam *param, double f);
ClImage *ShowValidArea(ClImage *mImg, CorrectParam *param);
ClImage *Correct2(ClImage *bmpIn, CorrectParam *param);
ClImage *Correct3(ClImage *bmpIn, CorrectParam *param);

#endif  