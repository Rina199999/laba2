struct SportMatches{
	char teamname[40];
	char country[40];
	int numberofplayers;
};
int ch(int *m);
void write(struct SportMatches *arr, int n);
void read(struct SportMatches **arr, int *n);
void create(struct SportMatches **arr, int *n);
void find(struct SportMatches *arr, int *n, int nn);
