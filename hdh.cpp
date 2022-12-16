// Banker's Algorithm
#include <stdio.h>

int main()
{

    // P0, P1, P2, P3, P4 are the Process names here
 

    int n, m;
    int answer[n];
    int inndex = 0;

    n = 5; // Number of processes

    m = 3; // Number of resources

    int alloc[5][3] = { { 0, 1, 0 }, // P0    // Allocation Matrix

                        { 2, 0, 0 }, // P1

                        { 3, 0, 2 }, // P2

                        { 2, 1, 1 }, // P3

                        { 0, 0, 2 } }; // P4
 

    int max[5][3] = { { 7, 5, 3 }, // P0    // MAX Matrix

                      { 3, 2, 2 }, // P1

                      { 9, 0, 2 }, // P2

                      { 2, 2, 2 }, // P3

                      { 4, 3, 3 } }; // P4
 

    int avail[3] = { 3, 3, 2 }; // Available Resources
 

    int f[n], ans[n], index = 0;

    for (int k = 0; k < n; k++) {

        f[k] = 0;

    }

    int need[n][m];

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++)

            need[i][j] = max[i][j] - alloc[i][j];

    }

    int flag = 1;
    while (flag) {
       flag = 0;
       for (int i = 0; i < n; i++) {
           if (f[i] == 0) {
           	int save = 0;
           	for (int k = 0; k < m; k++) {
           		if (need[i][k] > avail[k]) {
           			save = 1;
           			break;
				   }
			   }
			   if (save == 0) { 
			   	answer[index] = i;
			   	index++;
               f[i] = 1;
               for (int j = 0; j < m; j++) {
                   avail[j] += alloc[i][j];
               }
               flag = 1;
               }
           } 
       }
   }
   bool check = true;
   for (int i  = 0; i < n;i++) {
       if (f[i]==0) {
           check = false;
           break;
       }
   }
   
   if (check == true) {
   	printf("He thong an toan\n");
   	printf("Chuoi an toan cua he thong\n");
   	for (int i = 0; i < n-1; i++) {
   		printf("P%d -> ", answer[i]);
	   }
	   printf("P%d", answer[n-1]);
   }
   else {
   	printf("He thong khong an toan\n");
   }
}
