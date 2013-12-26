typedef struct tree
{
	int depth;
	void *data;
} Tree;

int create();
int insertNode();
int deleteNode();
int heightOfNode();
int depthOfNode();
int search();
