#include "rbbox_overlaps_kernel.hpp"
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

int main()
{
    int i, j;
    
    float iou[640000];
    float one_box01[5] = {50, -50, 100, 900, 0};
    float one_box02[5] = {47, -49, 102, 898, -1.3};

    float boxes01[800];
    float boxes02[800];
    
    float *p = boxes01;
    for (i = 0; i < 400; i++)
    {
        memcpy(p, one_box01, 5 * sizeof(float));
        p += 5;
    }

    p = boxes02;
    for (i = 0; i < 400; i++)
    {
        memcpy(p, one_box02, 5 * sizeof(float));
        p += 5;
    }

    time_t start, end;

    start = clock();
    for (i = 0; i < 10000; i++)
        _overlaps(iou, boxes01, boxes02, 20, 2, 1);
    end = clock();

    cout << "NMS GPU Time: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << endl;

    for (i = 0; i < 10; i++)
    {
        cout << iou[i] << " ";
    }
    cout << endl;
    
    return 0;
}