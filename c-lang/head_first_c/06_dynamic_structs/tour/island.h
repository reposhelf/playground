typedef struct island {
    char *name;
    const char *opens;
    const char *closes;
    struct island *next;
} island;

void display(island *start);
island *create(char *name);
void release(island *start);