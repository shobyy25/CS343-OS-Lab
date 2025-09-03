#include "types.h"
#include "user.h"
#include "stat.h"

int main(void){
    static char batman_buff[2000];
    int res = draw((void*) batman_buff, sizeof(batman_buff));

    printf(1, "The draw system-call returns: %d\n%s", res, batman_buff);

    exit();
}