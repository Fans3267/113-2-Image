// pch.cpp: 對應到先行編譯標頭的來源檔案

#include "pch.h"

extern "C" {
    __declspec(dllexport)void histogram_equalize(int f0[],int w,int h,int g0[])
    {
        int total = w * h;

        int histogram[256];
        for(int value=0;value<w*h;value++)
        {
            if (f0[value] >= 0 && f0[value] < 256)
                histogram[f0[value]]++;
        }

        // 累積分佈函數
        int cdf[256];
        cdf[0] = histogram[0];
        for (int i = 1; i < 256; i++)
        {
            cdf[i] = cdf[i - 1] + histogram[i];
        }

        // 均衡後的灰度值
        int equalizedValues[256];
        for (int i = 0; i < 256; i++)
        {
            equalizedValues[i] = (cdf[i] * 255) / total;
        }
        for (int value = 0; value < 256; value++)
        {
            if (equalizedValues[value] >= 0 && equalizedValues[value] < 256)
                g0[equalizedValues[value]]++;
        }

    }
}


// 使用先行編譯的標頭時，需要來源檔案才能使編譯成功。
