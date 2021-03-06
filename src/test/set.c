#include <stdio.h>
#include "set.h"
#include "atom.h"
#include "test.h"

static void
test()
{
	struct set *s = setCreate();
	setOperate(s,atomLiteral("Hello"),SET_PUSHONCE);
	setOperate(s,atomLiteral("World"),SET_PUSHONCE);
	setOperate(s,atomLiteral("Hello"),SET_PUSHONCE);
	setOperate(s,atomLiteral("Foobar"),SET_PUSHONCE);
	setOperate(s,atomLiteral("Foobar"),SET_POP);

	void *i = NULL;

	do {
		const char * v = setTraverse(s,&i);
		printf("%s\n",v);
	} while(i);


	setRelease(s);
}

