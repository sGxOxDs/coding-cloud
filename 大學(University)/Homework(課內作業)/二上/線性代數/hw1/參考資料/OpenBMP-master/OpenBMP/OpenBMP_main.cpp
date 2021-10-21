/*****************************************************************
Name : OpenBMP
Date : 2017/06/11
By   : CharlotteHonG
Final: 2018/06/01

�Բӹ�@�����i�H�ѦҡG
https://charlottehong.blogspot.com/2017/06/c-raw-bmp.html
���ԲӪ�BMP���Y�P�禡�ѻ�
*****************************************************************/
#include <iostream>
using namespace std;

#include "OpenBMP/OpenBMP.hpp"
#include "Timer.hpp"

void WarpScale_rgb(const basic_ImgData &src, basic_ImgData &dst, double ratio);
void bilinear(const ImgData & src, ImgData & dst, double ratio);

//================================================================
int main(int argc, char const *argv[]) {
	Timer t0;
	ImgData imgTest1, imgOut;


	// Ū��
	const ImgData img("ImgInput/test1.bmp");
	// �Ϥ��򥻸�T
	img.info_print();
	// ��X
	//img.bmp("ImgOutput/test_orig.bmp");



	// ���ܥb�i�Ͻd��
	/*imgOut = img.toConvertGray();
	for (size_t i = 0; i < imgOut.size()/2; i++) {
		imgOut[i]=255;
	} imgOut.bmp("ImgOutput/out_test.bmp");*/



	// ��Ƕ�1 (�|���ܦۤv)
	/*imgOut = img;
	imgOut.convertGray();
	imgOut.bmp("ImgOutput/out_test-gray1.bmp");
	// ��Ƕ�2 (���|���ܦۤv)
	imgOut = img.toConvertGray();
	imgOut.bmp("ImgOutput/out_test-gray2.bmp");*/



	// at2d() ����
	/*imgOut.resize(100, 100, 24);
	for (size_t j = 0; j < imgOut.height; j++) {
		for (size_t i = 0; i < imgOut.width; i++) {
			auto p = imgOut.at2d(j, i);
			p[0]=128; p[1]=128; p[2]=128;
		}
	} imgOut.bmp("ImgOutput/out_test-at2d.bmp");*/



	// �^������
	/*imgOut = img.toSnip(500, 500, 00, 100);
	imgOut.bmp("ImgOutput/out_test-toSnip.bmp");*/


	// ���ɴ���
	/*t0.start();
	WarpScale_rgb(img, imgOut, 5);
	//bilinear(img, imgOut, 5);
	t0.print("BASIC bilinear time");
	imgOut.bmp("ImgOutput/out_test1.bmp");*/


	// �s��u�ʴ��ɴ���
	/*int testCount=3;
	t0.start();
	bilinear(img, imgTest1, 0.5);
	for (size_t i = 0; i < testCount; i++) {
		ImgData temp;
		bilinear(imgTest1, temp, 2.0);
		bilinear(temp, imgTest1, 0.5);
	}
	bilinear(imgTest1, imgOut, 2.0);
	t0.print("BASIC bilinear time");
	imgOut.bmp("ImgOutput/out_test1.bmp");
	// �ֳt�u�ʴ��ɴ���
	t0.start();
	WarpScale_rgb(img, imgTest1, 0.5);
	for (size_t i = 0; i < testCount; i++) {
		ImgData temp;
		WarpScale_rgb(imgTest1, temp, 2.0);
		WarpScale_rgb(temp, imgTest1, 0.5);
	}
	WarpScale_rgb(imgTest1, imgOut, 2.0);
	t0.print("FAST  bilinear time");
	imgOut.bmp("ImgOutput/out_test2.bmp");*/



	// �j�p�۲�
	/*imgOut.clear();
	cout << "imgTest == img? " << (imgOut==img) << endl;
	imgOut.resize(img);
	cout << "imgTest == img? " << (imgOut==img) << endl;*/

	
	
	// ���յe�u�禡
	/*imgOut = ImgData("ImgInput/lena.bmp");
	imgOut.convertRGB();
	for (size_t i = 0; i < 36; i++) {
		Draw::draw_arrowRGB(imgOut, 200, 200, 100.f*sqrt(2), i*10);
	} imgOut.bmp("arrow.bmp");*/



	// ��¦��k�ϥνd��
	// ��Ƶ��c
	vector<unsigned char> raw_img;
	uint32_t width, height;
	uint16_t bits;
	// Ū�g Bmp 
	OpenBMP::bmpRead(raw_img, "ImgInput/test.bmp", &width, &height, &bits);
	OpenBMP::bmpWrite("ImgOutput/out_test.bmp", raw_img, width, height, bits);
	// �g raw �ɮ�
	OpenBMP::rawWrite("ImgOutput/test.raw", raw_img);
	// ��Ƕ�
	OpenBMP::raw2gray(raw_img, raw_img);
	OpenBMP::bmpWrite("ImgOutput/out_test_gray.bmp", raw_img, width, height, 8);
	return 0;
}
//================================================================

// �ֳt�u�ʴ���_�֤�
static void fast_Bilinear_rgb(unsigned char* p, 
	const basic_ImgData& src, double y, double x)
{
	// �_�I
	int _x = (int)x;
	int _y = (int)y;
	// ������
	double l_x = x - (double)_x;
	double r_x = 1.f - l_x;
	double t_y = y - (double)_y;
	double b_y = 1.f - t_y;
	int srcW = src.width;

	// �p��RGB
	double R , G, B;
	int x2 = (_x+1) > (int)srcW-1? (int)srcW-1: _x+1;
	int y2 = (_y+1) > (int)srcW-1? (int)srcW-1: _y+1;
	R  = (double)src.raw_img[(_y * srcW + _x) *3 + 0] * (r_x * b_y);
	G  = (double)src.raw_img[(_y * srcW + _x) *3 + 1] * (r_x * b_y);
	B  = (double)src.raw_img[(_y * srcW + _x) *3 + 2] * (r_x * b_y);
	R += (double)src.raw_img[(_y * srcW + x2) *3 + 0] * (l_x * b_y);
	G += (double)src.raw_img[(_y * srcW + x2) *3 + 1] * (l_x * b_y);
	B += (double)src.raw_img[(_y * srcW + x2) *3 + 2] * (l_x * b_y);
	R += (double)src.raw_img[(y2 * srcW + _x) *3 + 0] * (r_x * t_y);
	G += (double)src.raw_img[(y2 * srcW + _x) *3 + 1] * (r_x * t_y);
	B += (double)src.raw_img[(y2 * srcW + _x) *3 + 2] * (r_x * t_y);
	R += (double)src.raw_img[(y2 * srcW + x2) *3 + 0] * (l_x * t_y);
	G += (double)src.raw_img[(y2 * srcW + x2) *3 + 1] * (l_x * t_y);
	B += (double)src.raw_img[(y2 * srcW + x2) *3 + 2] * (l_x * t_y);

	p[0] = (unsigned char) R;
	p[1] = (unsigned char) G;
	p[2] = (unsigned char) B;
}
// �ֳt�u�ʴ���
void WarpScale_rgb(const basic_ImgData &src, basic_ImgData &dst, double ratio){
	// ���b
	if (src.bits != 24) runtime_error("IMG is not 24bit.");
	// ��l�� dst
	dst.width  = (int)((src.width  * ratio) +0.5);
	dst.height = (int)((src.height * ratio) +0.5);
	dst.bits   = src.bits;
	dst.raw_img.resize(dst.width * dst.height * dst.bits>>3);

	// �Y�p�����v
	double r1W = ((double)src.width )/(dst.width );
	double r1H = ((double)src.height)/(dst.height);
	// ��j�����v
	double r2W = (src.width -1.0)/(dst.width -1.0);
	double r2H = (src.height-1.0)/(dst.height-1.0);
	// �Y�p�ɭԪ��~�t
	double deviW = ((src.width-1.0)  - (dst.width -1.0)*(r1W)) /dst.width;
	double deviH = ((src.height-1.0) - (dst.height-1.0)*(r1H)) /dst.height;

	// �]�s�Ϯy��
#pragma omp parallel for
	for (int j = 0; j < (int)dst.height; ++j) {
		for (int i = 0; i < (int)dst.width; ++i) {
			// �վ���
			double srcY=0, srcX=0;
			if (ratio < 1.0) {
				//srcY = ((j+0.5f)/Ratio) - 0.5;
				//srcX = ((i+0.5f)/Ratio) - 0.5;
				srcX = i*(r1W+deviW);
				srcY = j*(r1H+deviH);
			} else if (ratio >= 1.0) {
				srcX = i*r2W;
				srcY = j*r2H;
			}

			// ������ɭ�
			unsigned char* p = &dst.raw_img[(j*dst.width + i) *3];
			if (ratio>1) {
				fast_Bilinear_rgb(p, src, srcY, srcX);
			} else {
				fast_Bilinear_rgb(p, src, srcY, srcX);
			}
		}
	}
}
// �@��u�ʴ���
void bilinear(const ImgData& src, ImgData& dst, double ratio) {
	// ���]�m�ؼйϹ��j�p
	dst.resize((uint16_t)(src.width*ratio), (uint16_t)(src.height*ratio), src.bits);
	// �Y�p�����v
	double r1W = ((double)src.width )/(dst.width );
	double r1H = ((double)src.height)/(dst.height);
	// ��j�����v
	double r2W = (src.width -1.0)/(dst.width -1.0);
	double r2H = (src.height-1.0)/(dst.height-1.0);
	// �Y�p�ɭԪ��~�t
	double deviW = ((src.width-1.0)  - (dst.width -1.0)*(r1W)) /dst.width;
	double deviH = ((src.height-1.0) - (dst.height-1.0)*(r1H)) /dst.height;

#pragma omp parallel for
	for (int j = 0; j < (int)dst.height; j++) {
		for (int i = 0; i < (int)dst.width; i++) {
			double srcY=0, srcX=0;
			// �վ���
			if (ratio < 1.0) {
				srcX = i*(r1W+deviW);
				srcY = j*(r1H+deviH);
			} else if (ratio >= 1.0) {
				srcX = i*r2W;
				srcY = j*r2H;
			}
			auto dstImg = dst.at2d(j, i);
			auto srcImg = src.at2d_linear(srcY, srcX);
			for (uint16_t rgb = 0; rgb < src.bits>>3; rgb++) {
				dstImg[rgb] = static_cast<unsigned char>(srcImg[rgb]);
			}
		}
	}
}
