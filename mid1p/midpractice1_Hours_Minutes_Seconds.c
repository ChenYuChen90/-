    #include <stdio.h>  //OK

    int main(void){
        int time1[6], time2[6], ans[6], time3[6]; //注意陣列在這行設的6是012345這6格
        unsigned long long sum1,sum2;
        scanf("%d/%d %d:%d:%d", &time1[1], &time1[2], &time1[3], &time1[4], &time1[5]);
        scanf("%d/%d %d:%d:%d", &time2[1], &time2[2], &time2[3], &time2[4], &time2[5]);
        sum1 = ((((time1[1]*30+time1[2])*24+time1[3])*60+time1[4])*60+time1[5]);
        sum2 = ((((time2[1]*30+time2[2])*24+time2[3])*60+time2[4])*60+time2[5]);

        if(sum2 > sum1){
            for(int i = 1 ; i <= 5 ; i++){
                time3[i] = time2[i];
                time2[i] = time1[i];
                time1[i] = time3[i];
            }
        }
        ans[5] = time1[5] - time2[5];
        if(ans[5] < 0)
            ans[5] += 60, time1[4]--;
        
        ans[4] = time1[4] - time2[4];
        if(ans[4] < 0)
            ans[4] += 60, time1[3]--;
        
        ans[3] = time1[3] - time2[3];
        if(ans[3] < 0)
            ans[3] += 24, time1[2]--;
        
        ans[2] = time1[2] - time2[2];
        if(ans[2] < 0)
            ans[2] += 30, time1[1]--;
        
        ans[1] = time1[1] - time2[1];  
        
        printf("%d %d\n", ans[1], ans[2]);
        printf("%02d:%02d:%02d\n",ans[3], ans[4], ans[5]);
        return 0;
    }