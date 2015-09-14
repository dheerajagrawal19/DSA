#pragma once

#include<iostream>

using namespace std;

#define max(a, b) a>b?a:b

#define swap(x,y) do{ unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
					memcpy(swap_temp, &y, sizeof(x)); \
					memcpy(&y, &x, sizeof(x)); \
					memcpy(&x, swap_temp, sizeof(x)); \
					}while (0)

typedef int(*FUN_POINTER)();