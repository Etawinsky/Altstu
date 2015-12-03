struct avltree{
	int key;
	unsigned height;
	avltree *left;
	avltree *right;
};

unsigned height(node* p);
int bfactor(node* p);
