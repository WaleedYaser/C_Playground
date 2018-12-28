#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* table entry */
struct nlist {
	struct nlist *next;			/* next entry in chain */
	char   *name;				/* defined name */
	char   *defn;				/* replacement text */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];			/* pointer table */

struct nlist *lookup(char *s);
struct nlist *install(char *, char *);
int undef(char *);

int main()
{
	install("name", "waleed");
	install("age", "123");
	install("address", "mansoura");
	install("name", "waleed yaser");

	struct nlist *p = lookup("name");
	if (p != NULL)
		printf("%s %s\n", p->name, p->defn);
	undef("name");
	p = lookup("name");
	if (p != NULL)
		printf("%s %s\n", p->name, p->defn);
	else
		printf("name not found\n");

	p = lookup("hello");
	if (p!= NULL)
		printf("%s %s\n", p->name, p->defn);
	else
		printf("hello not found\n");

	return 0;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;		/* not found */
}

char *str_dup(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {		/* not found */
		np = (struct nlist *) malloc(sizeof(struct nlist));
		if (np == NULL || (np->name = str_dup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else									/* already there */
		free((void *) np->defn);			/* free previous defn */
	if ((np->defn = str_dup(defn)) == NULL)
		return NULL;
	return np;
}

/* undef: remove entry from lookup; return 1 if success, 0 otherwise */
int undef(char *name)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL)
		return 0;

	free((void *) np->name);
	free((void *) np->defn);

	hashval = hash(name);
	if (np->next != NULL) {
		np = np->next;
		free((void *) np->next);
		np->next = NULL;
	} else {
		free((void *) np);
		hashtab[hashval] = NULL;
	}

	return 1;
}

char *str_dup(char *s)
{
	char *p;

	p = (char *) malloc(sizeof(s) + 1);
	if (p)
		strcpy(p, s);
	return p;
}
