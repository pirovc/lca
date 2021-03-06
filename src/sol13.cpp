/* Segment tree on the Euler traverse
*       TIME:   O(N) pre-processing
		O(log N) per query
*       MEMORY: O(N)
*/

#include "lib/segment_tree.h"
#include "lib/tree.h"

int *T, *depth, *euler;
Aint A;

int best(int x, int y){
	return depth[x] < depth[y] ? x : y;
}

void prepare(int* T, int N){
	buildEuler(T, N, depth, euler);
	for (int i = euler[0]; i; i--)
		T[ euler[i] ] = i;
	::T = T;

	A.flush(euler, best);
}

int lca(int x, int y){
	if (T[x] < T[y])
		return A.query(T[x], T[y]);
	return A.query(T[y], T[x]);
}

int main(int argc, char** argv){
	lca_online(argv[1], argv[2], prepare, lca);
	return 0;
}
