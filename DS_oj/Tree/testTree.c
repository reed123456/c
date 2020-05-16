#include"tree.h"
//ABC##DE##F##g#H##
void main()
{
	const char *VLR = "ABCDEFGH";  //VLR+LVR ==> 
	const char *LVR = "CBEDFAGH";
	const char *LRV = "CEFDBHGA";  //LRV+LVR ==>     //VLR + LRV ==> ?
	BinTree bt;
	BinTreeCreateByVLR_LVR(&bt, VLR, LVR);
}