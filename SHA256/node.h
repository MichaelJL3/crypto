struct node{
	int val;
	char word[20];
	struct node *next;
};

void insert(struct node *head, int n);
void list_n(struct node *head);
