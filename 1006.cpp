//#include <iostream>
//
//int main(void)
//{
//	float wh = 1.0/120;
//	float wm = 1.0;
//	float ws = 6.0;
//	float sh, sm, ss;
//	int hm, hs, ms;
//	float percent;
//	int ang;
//	while(std::cin>>ang)
//	{
//		if (ang == -1)
//		{
//			continue;
//		}
//		int coutsec = 0;
//		for (int i=0; i<(12*3600); i++)
//		{
//			sh = i*wh;
//			sm = i*wm;
//			ss = i*ws;
//			hm = abs(((int)sh%360) - ((int)sm%360));
//			hs = abs(((int)sh%360) - ((int)ss%360));
//			ms = abs(((int)sm%360) - ((int)ss%360));
//			if (hm>=ang && hs>=ang && ms>=ang)
//			{
//				coutsec++;
//			}
//		}
//		percent = (float)coutsec/(12*3600);
//		std::cout<<percent*100<<std::endl;
//	}
//}

//#include <iostream>
//#include <cstdlib>
//#include <cstdio>
//#include <cmath>
//
//int main(void)
//{
//	float wh = 1.0/120;
//	float wm = 0.1;
//	float ws = 6.0;
//	float sh, sm, ss;
//	float hm, hs, ms;
//	float percent;
//	float ang;
//	while(std::cin>>ang)
//	{
//		if (ang == -1)
//		{
//			continue;
//		}
//		int coutsec = 0;
//		for (int i=0; i<3600; i++)
//		{
//			sh = (i%(120*360))*wh;
//			sm = (i%3600)*wm;
//			ss = (i%60)*ws;
//			hm = (fabs(sh - sm)>180) ? 360-fabs(sh - sm): fabs(sh - sm);
//			hs = (fabs(sh - ss)>180) ? 360-fabs(sh - ss): fabs(sh - ss);
//			ms = (fabs(ss - sm)>180) ? 360-fabs(ss - sm): fabs(ss - sm);
//			if (hm>=ang && hs>=ang && ms>=ang)
//			{
//				coutsec++;
//			}
//			else
//			{
//				int a = 0;
//			}
//		}
//		percent = (float)coutsec*11/3600/12;
//		std::cout<<percent*100<<std::endl;
//	}
//}

#include <stdio.h>
#include <stdlib.h>
double D;
int H,M;
double S, Total;
int signal;
double minimum;
double maximum;
void get_next()
{
	double HM,HS,MS; // HM��ʱ��ͷ���ļн�, HS��ʱ�������ļн�, MS�Ƿ��������ļн� 
	double HL,ML,SL; // HL��ʱ���λ��, ML�Ƿ����λ��, SL�������λ�� 
	double t1,t2,t3; // ��ʱֵ 
	SL = 6*S; // �����λ����6�ȳ��Ե�ǰ������ 
	ML = 6*(M+S/60); // �����λ����6�ȳ��Ե�ǰ�ķ��� + ��ǰ����������10 
	HL = 30*(H+M/60.0+S/3600); // ʱ���λ����30�ȳ��Ե�ǰ��Сʱ�� + ����������2 + ��������120 
	HM = ML - HL; // �Է�����ǰ, ��������ʱ��ļн� 
	HS = SL - HL; // ��������ǰ, ��������ʱ��ļн� 
	MS = SL - ML; // ��������ǰ, �������ͷ���ļн� 
	while(HM+1e-6>=D) HM -= 360; // ���ʱ��ͷ���ļн� >= D, ��ô��360 
	while(HM+1e-6<D-360) HM += 360; // ���ʱ��ͷ���ļн� < D-360, ��ô��360 
	while(HS+1e-6>=D) HS -= 360; // ����Ĳ�����һ����, Ŀ���ǰ�ÿ���нǿ����� D-360 �� D֮��
	while(HS+1e-6<D-360) HS += 360; // �����Ļ�, ֻҪ�н�С��-D, ���Ǿ���Happy��
	while(MS+1e-6>=D) MS -= 360; // �����-D��D֮��, �Ͳ�happy   
	while(MS+1e-6<D-360) MS += 360;
	if(HM>=-D||HS+1e-10>=-D||MS+1e-10>=-D) // ������κ�һ���нǴ��� -D��D֮�� 
	{
		signal = 0; // ���ΪUnhappy 
		t1 = (D - HM)/(1.0/10 - 1.0/120); // ʱ��ͷ�����Ҫ����t1�ű��happy 
		t2 = (D - HS)/(6-1.0/120); // ʱ�������Ҫ����t2�ű��happy 
		t3 = (D - MS)/(6-1.0/10); // ���������Ҫ����t3�ű��happy 
		minimum = 0; // ��������t1, t2, t3�����ֵ 
		if(HM>=-D) minimum = minimum > t1? minimum : t1;
		if(HS+1e-6>=-D) minimum = minimum > t2? minimum : t2;
		if(MS+1e-6>=-D) minimum = minimum > t3? minimum : t3;
		S += minimum; // �ƶ����뵽���ܵ�happy�� 
		while(S>=60) // �ָ������ı�ʾ��ʽ 
		{
			S-=60;
			M++;
		}
		while(M>=60) // �ָ������ı�ʾ��ʽ 
		{
			M-=60;
			H++;
		}
		return;
	}
	else
	{
		signal = 1; // ���Ϊhappy 
		t1 = (-D - HM)/(1.0/10 - 1.0/120); // ʱ��ͷ��뾭��t1����unhappy 
		t2 = (-D - HS)/(6-1.0/120); // ʱ������뾭��t2����unhappy 
		t3 = (-D - MS)/(6-1.0/10); // ����ͷ��뾭��t3����unhappy 
		maximum = 100000;  // ��������t1, t2, t3����Сֵ 
		maximum = maximum < t1? maximum : t1;
		maximum = maximum < t2? maximum : t2;
		maximum = maximum < t3? maximum : t3;
		S += maximum; // �ƶ���unhappy�� 
		while(S>=60) // �ָ������ı�ʾ��ʽ 
		{
			S-=60;
			M++;
		}
		while(M>=60) // �ָ������ı�ʾ��ʽ 
		{
			M-=60;
			H++;
		}
		return;
	}
}
int main()
{
	while(scanf("%lf",&D)&&D!=-1) // ��ȡ���� 
	{
		if(D==0) // ���⴦�� 
		{
			printf("100.000\n");
			continue;
		}
		if(D>=120) // ���⴦�� 
		{
			printf("0.000\n");
			continue;
		}
		H = M = 0; // ��ʼ��ʱ�� 
		S = 0; // ��ʼ��ʱ�� 
		Total = 0; // Happytime 
		while(1)
		{
			get_next(); // �õ���һ���ٽ�ʱ�� 
			if(H>=12) break; // �������12Сʱ, �Ͳ�����, ���� 
			if(signal) Total += maximum; // ��������ڵ���һ���ٽ�ʱ����Happy��, �ͼ���Maximum��Happyʱ�� 
		}
		printf("%.3lf\n",Total/432); // Total/432 % �����ܹ�happy�İٷֱ� 43200��12Сʱ�������������ðٷ�����ʾ����43200/100=432
	}
}