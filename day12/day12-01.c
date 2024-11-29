#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = 0;
    int left[10001]={0,};
    int right[10001]={0,};
    int top,i,nleft=0,nright=0;
    
    for(i=0;i<topping_len;i++){
        top=topping[i];
        if(right[top]==0)nright++;
        right[top]++;
    }
    
    for(i=0;i<topping_len;i++){
        top=topping[i];
        right[top]--;
        if(right[top]==0)nright--;
        if(left[top]==0)nleft++;
        left[top]++;
        if(nleft==nright)answer++;
    }
    return answer;
}
