#include <stdio.h>

int main() {
  int temp, size = 10, k;
  int arr[] = {95, 16, 3, 4, 0, 84, 25, 2, 73, 1};

  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      if(arr[i] < arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  while(1) {
    int low = 0, high = size - 1, mid;
    printf("K: ");
    scanf("%d", &k);

    if(k == -100) break;
    while(low <= high) {
      mid = (low+high) / 2;
      if(arr[mid] == k) {
        printf("Position is %d\n", mid+1); // From question position = index + 1
        break;
      } else if(arr[mid] > k) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    if(low > high) {
      printf("Not found!\n");
    }
  }

    // while(1) {
    //   mid = (low+high)/2;
    //   if(arr[mid] == k) {
    //     printf("Position is %d\n", mid);
    //     break;
    //   } else if(arr[mid] > k) {
    //     high = mid - 1;
    //   } else if(arr[mid] < k) {
    //     low = mid + 1;
    //   }  
    //   if(high - low == 1 || high - low == -1) {
    //     if(arr[high] == k) {
    //       printf("Position is %d\n", high);
    //     } else if(arr[low] == k) {
    //       printf("Position is %d\n", low);
    //     } else {
    //       printf("Not found!\n");
    //     }
    //     break;
    //   };
    // }

  return 0;
}