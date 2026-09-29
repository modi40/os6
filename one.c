#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct {
char name[30];
int start;
int length;
} File;
int n;
int bit[500];
File dir[100];
int file_count = 0;
void show_bit_vector() {
int i;
printf("\nBit Vector (0 = Free, 1 = Allocated):\n");
for(i = 0; i < n; i++) {
printf("%d ", bit[i]);
if((i + 1) % 20 == 0) printf("\n");
}
printf("\n");
}
void create_file() {
char fname[30];
int len, i, j;
printf("Enter file name: ");
scanf("%s", fname);
printf("Enter length (blocks required): ");
scanf("%d", &len);
int start_idx = -1;
for(i = 0; i <= n - len; i++) {
int free_streak = 1;
for(j = 0; j < len; j++) {
if(bit[i + j] == 1) {
free_streak = 0;
break;
}
}
if(free_streak) {
start_idx = i;
break;
}
}
if(start_idx == -1) {
printf("Error: Contiguous blocks of length %d not available!\n", len);
return;
}
for(j = 0; j < len; j++) bit[start_idx + j] = 1;
strcpy(dir[file_count].name, fname);
dir[file_count].start = start_idx;
dir[file_count].length = len;
file_count++;
printf("File '%s' created starting at block %d.\n", fname, start_idx);
}
void show_directory() {
int i;
if(file_count == 0) {
printf("Directory is empty.\n");
return;
}
printf("\nDirectory:\nFile Name\tStart Block\tLength\n");
for(i = 0; i < file_count; i++) {
printf("%s\t\t%d\t\t%d\n", dir[i].name, dir[i].start, dir[i].length);
}
}
int main() {
int ch, i;
srand(time(NULL));
printf("Enter total number of disk blocks: ");
scanf("%d", &n);
for(i = 0; i < n; i++) bit[i] = 0;
int initial_alloc = n / 5;
for(i = 0; i < initial_alloc; i++) {
int r = rand() % n;
bit[r] = 1;
}
while(1) {
printf("\n--- MENU ---\n");
printf("1. Show Bit Vector\n");
printf("2. Create New File\n");
printf("3. Show Directory\n");
printf("4. Exit\n");
printf("Enter choice: ");
if(scanf("%d", &ch) != 1) break;
if(ch == 1) show_bit_vector();
else if(ch == 2) create_file();
else if(ch == 3) show_directory();
else if(ch == 4) break;
else printf("Invalid choice!\n");
}
return 0;
}
