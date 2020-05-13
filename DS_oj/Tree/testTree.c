#include"tree.h"


//ABC##DE##F##g#H##

void main()
{
	const char *VLR = "ABCDEFGH";  //VLR+LVR ==> 
	const char *LVR = "CBEDFAGH";
	const char *LRV = "CEFDBHGA";  //LRV+LVR ==>     //VLR + LRV ==> ?

	const char *str = "ABC##DE##F##G#H##";
	BinTree  bt;
	BinTreeInit(&bt);
	BinTreeCreateByStr(&bt, str);

	printf("VLR: ");
	PreOrder(&bt);
	printf("\n");

	BinTreeDestroy(&bt);
	system("pause");
	return 0;
}