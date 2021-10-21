struct song_node{
char name[100];
char artist[100];
struct song_node *next;
};

void print_nodes(struct song_node *sn);

struct song_node *make_node(char *n, char *a);

void print_list(struct song_node *sn);

struct song_node * insert_front(struct song_node * sn, char *n, char *a);

struct song_node * free_list(struct song_node *sn);

struct song_node * remove_node(struct song_node *front, char *n, char *a);

