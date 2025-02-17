// pch.cpp: 對應到先行編譯標頭的來源檔案

#include "pch.h"
extern "C" {
    __declspec(dllexport)void negative(int f0[],int w,int h,int g0[])
    {
        for (int i = 0; i < w * h; i++)
        {
            g0[i] = 255 - f0[i];
        }
    }

}


// 使用先行編譯的標頭時，需要來源檔案才能使編譯成功。
