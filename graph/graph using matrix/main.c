#include"graph.h"

int  main() {
    graph g, g1;
    init_graph(&g, "matrix2.txt");
    printGraph(g);
    printf("\nDFS : ");
    dfs(&g, 0);
    printf("\nBFS : ");
    bfs(&g, 0);
    printf("\n\n");

    printf("prims algo\n");
    init_graph(&g1, "prims.txt");
    edge *E1;
    printGraph(g1);
    E1 = prims(&g1, 0);
    for(int i = 0; i < g1.n-1; i++)
        printf("\n%d - %d - %d", E1[i].s + 1, E1[i].d + 1, E1[i].w);

    printf("\nkruskal algo\n");
    graph g2;
    init_graph(&g2, "kruskal2.txt");
    printGraph(g2);
    E1 = kruskal(&g2);
    for(int i = 0; i < g2.n-1; i++)
        printf("\n%d - %d - %d", E1[i].s, E1[i].d, E1[i].w);
    printf("\n");

    printf("\n\n");
    printf("Dijkstra algo\n");
    graph g3;
    init_graph(&g3, "Dijkstra.txt");
    printGraph(g3);
    int *c = Dijkstra(&g3, 0);
    printf("\nsolution:\n");
    for(int i = 0; i < g3.n; i++)
        printf("%d  ", c[i]);
    printf("\n\n");

    printf("All pair shortest\n");
    int **a = all_pair_shortest(&g3);
    for(int i = 0; i < g3.n; i++){
        for(int j = 0; j < g3.n; j++){
            if(a[i][j]==INT_MAX)
               printf("%c  ",236);//prints infinity
            else
                printf("%d  ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    graph g4;
    init_graph(&g4, "connected.txt");
    printGraph(g4);
    printf("\nis connected : %d\n", isConnected(&g4));
    printf("\nconnected : %d ", no_of_Connected_components(&g4));

    printf("\n");
    graph g5;
    init_graph(&g5, "bipartite.txt");
    printGraph(g5);
    printf("\nis Bipartite: %d\n", isBipartite(g5));

    printf("\n");
    graph g6;
    init_graph(&g6, "strongly.txt");
    printGraph(g6);
    printf("\nis Strongly Connected : %d\n", isStronglyConnected(&g6));

    printf("\n");
    graph g7;
    init_graph(&g7, "path.txt");
    printGraph(g7);
    printf("\nis path : %d\n", is_path_from_uv(&g7, 0, 1));

    printf("\n\n");
    printf("Bellman Ford\n");
    graph g8;
    init_graph(&g8, "bellman.txt");
    printGraph(g8);
    c = Bellman_ford(&g8, 0);
    if(c!=0){
        for(int i = 0; i < g8.n; i++)
            printf("\n%c : %d", i+65, c[i]);
    }

    return 0;
}
