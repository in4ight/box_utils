#ifndef RBBOX_OVERLAPS_KERNEL
#define RBBOX_OVERLAPS_KERNEL

void _overlaps(float* overlaps, const float* boxes, const float* query_boxes, int n, int k, int device_id = 0);

#endif
