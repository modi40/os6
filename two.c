#include <stdio.h>
#include <stdlib.h>
int main() {
int disk_size = 200, n, head, i, j, total = 0;
printf("Enter disk size (default 200): ");
if(scanf("%d", &disk_size) != 1) return 0;
printf("Enter number of requests: ");
if(scanf("%d", &n) != 1) return 0;
int req[100];
printf("Enter requests: ");
for(i = 0; i < n; i++) scanf("%d", &req[i]);
printf("Enter starting head position: ");
scanf("%d", &head);
for(i = 0; i < n - 1; i++) {
for(j = 0; j < n - i - 1; j++) {
if(req[j] > req[j + 1]) {
int t = req[j];
req[j] = req[j + 1];
req[j + 1] = t;
}
}
}
int right[100], left[100], r_cnt = 0, l_cnt = 0;
for(i = 0; i < n; i++) {
if(req[i] >= head) right[r_cnt++] = req[i];
else left[l_cnt++] = req[i];
}
printf("\nC-SCAN Order of Service (Direction: Right):\n%d", head);
int cur = head;
for(i = 0; i < r_cnt; i++) {
total += abs(cur - right[i]);
cur = right[i];
printf(" -> %d", cur);
}
if(cur != disk_size - 1) {
total += abs(cur - (disk_size - 1));
cur = disk_size - 1;
printf(" -> %d", cur);
}
total += (disk_size - 1);
cur = 0;
printf(" -> %d", cur);
for(i = 0; i < l_cnt; i++) {
total += abs(cur - left[i]);
cur = left[i];
printf(" -> %d", cur);
}
printf("\nTotal number of head movements: %d\n", total);
return 0;
}
