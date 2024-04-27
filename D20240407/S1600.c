#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/uthash.h"
typedef struct ThroneInheritance
{
    struct ThroneInheritance *parent;
    struct ThroneInheritance *bro;
    struct ThroneInheritance *children;
    char *name;
} ThroneInheritance;

typedef struct
{
    int name;
    ThroneInheritance *node;
    UT_hash_handle hh;
} Hash_Item;

Hash_Item *item = (Hash_Item *)malloc(sizeof(Hash_Item) * 10e5);

ThroneInheritance *createThrone(char *name)
{
    ThroneInheritance *throneInheritanceBirth = (ThroneInheritance *)malloc(sizeof(ThroneInheritance));
    throneInheritanceBirth->bro = NULL;
    throneInheritanceBirth->children = NULL;
    throneInheritanceBirth->parent = NULL;
    throneInheritanceBirth->name = kingName;
    return throneInheritanceBirth;
}

ThroneInheritance *throneInheritanceCreate(char *kingName)
{
    ThroneInheritance *obj = createThrone(kingName);
    Hash_Item *temp = (Hash_Item *)malloc(sizeof(Hash_Item));
    temp->name = kingName;
    temp->node = obj;
    HASH_ADD(hh, item, name, strlen(kingName), temp)
    return obj;
}

void throneInheritanceBirth(ThroneInheritance *obj, char *parentName, char *childName)
{
    ThroneInheritance *node;
    HASH_FIND(hh, item, name, sizeof(parentName), node);
    if (node->children == NULL)
    {
        node->children = createThrone(childName);
        node->children->parent = node;
        return;
    }
    else
    {
        node = node->children;
    }
    while (node != NULL)
    {
        node = node->bro;
    }
    node->bro = createThrone(childName);
    node->bro->parent = node->parent;
    return;
}

void throneInheritanceDeath(ThroneInheritance *obj, char *name)
{
    ThroneInheritance *node;
    HASH_FIND(hh, item, name, sizeof(parentName), node);
    
}

char **throneInheritanceGetInheritanceOrder(ThroneInheritance *obj, int *retSize)
{
}

void throneInheritanceFree(ThroneInheritance *obj)
{
}