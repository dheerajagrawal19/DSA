#include "MainSource.h"

void main() {
	//SNLLMainFunction(); 	//SNStackMainFunction(); 	//SNQueueMainFunction(); 	//SNBSTMainFunction();
	FUN_POINTER tmp = SNBSTMainFunction;
	tmp();
	getchar();
}