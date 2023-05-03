#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 1000

// The Nearest Neighbor algorithm for solving TSP
void tsp_nn(int n, double cost[MAX_N][MAX_N], int tour[]) {
    bool visited[MAX_N] = { false };
    tour[0] = 0;
    visited[0] = true;
    for (int i = 1; i < n; i++) {
        double min_cost = 9999;
        int next_city = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                if (cost[tour[i-1]][j] < min_cost) {
                    min_cost = cost[tour[i-1]][j];
                    next_city = j;
                }
            }
        }
        tour[i] = next_city;
        visited[next_city] = true;
    }
    tour[n] = 0;
}
// A function to print the tour
void print_tour(int n, double cost[MAX_N][MAX_N], int tour[]) {
    double total_cost = 0;
    for (int i = 0; i < n; i++) {
        printf("%d ", tour[i]);
        if (i > 0) {
            total_cost += cost[tour[i-1]][tour[i]];
        }
    }
    printf("0 ");
    total_cost += cost[tour[n-1]][0];
    printf("\nTotal cost: %lf\n", total_cost);
}

int main() {
    int n;
    double cost[MAX_N][MAX_N];
    int tour[MAX_N+1];
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &cost[i][j]);
        }
    }
    tsp_nn(n, cost, tour);
    printf("The tour is:\n");
    print_tour(n, cost, tour);
    return 0;
}