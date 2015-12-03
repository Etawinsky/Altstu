unsigned height(node* p)
{
	if(p)
		return p->height;
	else 
		return 0;
}

int bfactor(node* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(node* p)
{
	unsigned hl = height(p->left);
	unsigned hr = height(p->right);
	if(hl > hr)
		p->height = hl;
	else 	
		p->height = hr;
}

node* rotateright(node* p) 
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* p) 
{
	node* q = p->right;
	p->right = q->left;
	q->left = p;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p)
{
	fixheight(p);
	if( bfactor(p) == 2 ){
		if(bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if( bfactor(p)==-2 ){
		if( bfactor(p->left) > 0  )
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; 
}
