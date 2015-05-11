#ifndef EZ_LIST_H
#define EZ_LIST_H

typedef struct list_head_t {
    struct list_head_t *next, *prev;
} list_head;

void init_list_head(list_head *list);

void list_add(list_head *newNode, list_head *head) ;

void list_del(list_head *entry) ;

int list_empty(list_head *head) ;

#endif /* EZ_LIST_H */