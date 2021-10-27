struct song_node ** make_library();

struct song_node ** add_song(struct song_node ** library, struct song_node * sn);

int library_index(char *a);

struct song_node * search_song(struct song_node ** library, char * a, char * n);

struct song_node * search_artist(struct song_node ** library, char * a);

void print_letter(struct song_node ** library, char letter);

void print_artist(struct song_node ** library, char * a);

void print_library(struct song_node ** library);

void print_shuffle(struct song_node ** library);

struct song_node ** delete_song(struct song_node ** library, char * a, char * n);

struct song_node ** clear_library(struct song_node ** library);