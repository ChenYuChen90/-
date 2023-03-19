#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100000 + 5
#define L 105
#define P 10

// struct for info of each user
typedef struct Info
{
    int time[P]; // time he use to submit to the i-th pro until get AC
    int verdict[P]; // when do he get AC on i-th pro
}Info;

// struct for score of each user
typedef struct Score
{
    int id, acnum, penalty;
}Score;

Info sub[N];
Score score[N];
char in[L]; // the memory space to store input
int attend[N]; // store whether the i-th user has submission

// compare functionfor qsort
int cmp(const void *a, const void *b){
    Score sa = *(Score*)a, sb = *(Score*)b;
    if(sa.acnum < sb.acnum) return 1;
    else if(sa.acnum > sb.acnum) return -1;
    else {
        if(sa.penalty > sb.penalty) return 1;
        else if(sa.penalty < sb.penalty) return -1;
        else {
            if(sa.id > sb.id) return 1;
            else if(sa.id < sb.id) return -1;
            else return 0;
        }
    }
}
// return time of the input char array in min
int getTime(char* c){
    return (c[-2] - '0') * 600 + (c[-1] - '0') * 60 + (c[1] - '0') * 10 + (c[2] - '0');
}
// get the id according to the input char array
int getID(char* c){
    int i = 0, ret = 0;
    while(c[i] >= '0' && c[i] <= '9'){
        ret = 10 * ret + (c[i] - '0');
        i++;
    }
    return ret;
}
// init the sub[i].verdict[j] to -1, since sub[i].verdict[j] is possible to be 0
// we want to use this variable to dectect whether the user has get AC on this pro (not -1)
void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < P; j++){
            sub[i].verdict[j] = -1;
        }
    }
}
int main(){
    init();
    int T = 10;
    while(T--) fgets(in, L, stdin); // ignore first ten line
    while(fgets(in, L, stdin) != NULL){
        int time, userid, pid, verdict, len;
        time = userid = pid = verdict = -1;
        len = strlen(in);
        for(int i = 0; i < len; i++){
            if(in[i] == '/') break;
        }
        fgets(in, L, stdin); // time
        len = strlen(in);
        for(int i = 0; i < len; i++){
            if(in[i] == ':'){
                time = getTime(in + i);
                break;
            }
        }
        fgets(in, L, stdin); // user
        len = strlen(in);
        for(int i = 0; i < len; i++){
            if(in[i] >= '0' && in[i] <= '9'){
                userid = getID(in + i);
                break;
            }
        }
        fgets(in, L, stdin); // proid
        len = strlen(in);
        for(int i = 0; i < len; i++){
            if(in[i] >= 'A' && in[i] <= 'Z'){
                pid = in[i] - 'A';
                break;
            }
        }
        fgets(in, L, stdin); // verdict
        len = strlen(in);
        for(int i = 0; i < len; i++){
            if(in[i] == 'A'){
                verdict = 1;
                break;
            } else if(in[i] == 'W'){
                verdict = 0;
                break;
            }
        }
        fgets(in, L, stdin); // </tr>
        attend[userid] = 1; // set sttend[userid] to 1 sinnce userid has submission
        if(sub[userid].verdict[pid] == -1){ // ignore the submission that the user has already get AC
            sub[userid].time[pid]++;
            if(verdict == 1) sub[userid].verdict[pid] = time;
        }
    }
    fgets(in, L, stdin); // get </table>
    // set everyone score
    int num = 0;
    for(int i = 0; i < N; i++){
        if(attend[i]){
            score[num].id = i;
            for(int j = 0; j < P; j++){
                if(sub[i].verdict[j] != -1)
                    score[num].acnum += 1, score[num].penalty += sub[i].verdict[j] + 20 * sub[i].time[j] - 20;
            }
            num++;
        }
    }
    qsort(score, num, sizeof(Score), cmp);
    for(int i = 0; i < num; i++){
        printf("%d", score[i].id);
        for(int j = 0; j < P; j++){
            if(sub[score[i].id].verdict[j] == -1){
                if(sub[score[i].id].time[j] > 0) printf(" %d/-", sub[score[i].id].time[j]);
                else printf(" -/-");
            } else {
                printf(" %d/%d", sub[score[i].id].time[j], sub[score[i].id].time[j] * 20 + sub[score[i].id].verdict[j] -20);
            }
        }
        printf(" %d %d\n", score[i].acnum, score[i].penalty);
    }
}


