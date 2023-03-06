#include <stdio.h>
#define MAX_SIZE 100000

int main() {
    int n, q, type, x, max = 0;
    int arr[MAX_SIZE];
    
    // Read input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Process queries
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            arr[n++] = x;
            if (x > max) {
                max = x;
            }
        } else {
            printf("%d\n", max);
        }
    }
    
    return 0;
}
