/* Offline algorithm: Tarjan's LCA algorithm
*	Similar to the previous approach, but use a disjoint data set instead of binary search.
*	TIME: 	O(Nlog*N + Q) -- NOTE: log* N = the iterated logarithm = the number of time we 
			can apply log such that N > 1. For any reasonably sized N, log* N <= 5
*	MEMORY: O(N + Q)
*/

#include "lib/stack.h"
#include "lib/ddset.h"
#include "lib/tree.h"

Stack* query;
int *ans, *T;
Ddset A;

void before(int x){
	while ( !query[x].isEmpty() ){
		int y = query[x].pop();
		if ( ans[y] )
			ans[y] = A[ ans[y] ];
		else
			ans[y] = x;
	}
}

void after(int x){
	if ( T[x] ) A.link( T[x], x );
}

int* process(int* T, int N, Pair* Q, int nrQ){
	alloc(query, N);
	alloc(ans, nrQ);
	for (int i = 1; i <= nrQ; i++){
		query[ Q[i].x ].push(i);
		query[ Q[i].y ].push(i);

	}
	freeSafe(Q);

	::T = T;
	A.resize(N);
	dfs(T, N, before, after);

	return ans;
}

int main(int argc, char** argv){
	lca_offline(argv[1], argv[2], process);
	return 0;
}
