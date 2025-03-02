// pch.cpp: 對應到先行編譯標頭的來源檔案

#include "pch.h"

extern "C" {
    __declspec(dllexport)void mosaic(int f0[],int w,int h,int g0[])
    {
		int halfw = w / 2, halfh = h / 2;
		int startbit = (halfh/2)*w + (halfw/2);
		int endbit = (h-(halfh / 2)) * w + (halfw / 2);

		//0~255(256)

		for (; startbit < endbit; startbit + w * 2) {
			int currentbit = startbit;
			int endofcurrent = startbit + halfw;
			for (; currentbit < endofcurrent; currentbit + 2) {
				g0[currentbit] = f0[currentbit];
				g0[currentbit + 1] = f0[currentbit];
				g0[currentbit + w] = f0[currentbit];
				g0[currentbit + w + 1] = f0[currentbit];
			}
		}
		/*
		for (int i = 0; i < 4; i += 2)
		{
			for (int j = 0; j < 4; j += 2)
			{
				for (int i0 = 0; i0 < 2; i0++)
					for (int j0 = 0; j0 < 2; j0++)
						a[i + i0][j + j0] = a[i][j];
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}*/
    }
}


// 使用先行編譯的標頭時，需要來源檔案才能使編譯成功。
