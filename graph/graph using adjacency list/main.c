#include"graph.h"

int  main() {
    graph g;
    init_graph(&g, 9);

    add_edge(&g, 0, 'B', 2);
    add_edge(&g, 0, 'C', 4);
    add_edge(&g, 0, 'D', 6);
    add_edge(&g, 1, 'A', 2);
    add_edge(&g, 1, 'C', 5);
    add_edge(&g, 2, 'A', 4);
    add_edge(&g, 2, 'B', 5);
    add_edge(&g, 2, 'D', 1);
    add_edge(&g, 2, 'E', 2);
    add_edge(&g, 3, 'A', 6);
    add_edge(&g, 3, 'C', 1);
    add_edge(&g, 3, 'F', 3);
    add_edge(&g, 3, 'H', 4);
    add_edge(&g, 4, 'C', 2);
    add_edge(&g, 4, 'F', 1);
    add_edge(&g, 4, 'G', 5);
    add_edge(&g, 4, 'I', 3);
    add_edge(&g, 5, 'D', 3);
    add_edge(&g, 5, 'G', 4);
    add_edge(&g, 5, 'E', 1);
    add_edge(&g, 6, 'E', 5);
    add_edge(&g, 6, 'F', 4);
    add_edge(&g, 7, 'D', 4);
    add_edge(&g, 8, 'E', 3);

    printf("DFS : ");
    dfs(&g, 'C');
    printf("\nBFS : ");
    bfs(&g, 'C');
    printf("\n");
    printf("\nis connected : %d\n", isConnected(&g));
    printf("\nconnected : %d ", no_of_Connected_components(&g));
    return 0;
}
