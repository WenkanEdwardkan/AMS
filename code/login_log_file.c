#include "header/login_log_file.h"

//����Log�ļ�
void saveLog(login_log *log) {
    FILE *fp;

    if ((fp = fopen("login_log_info.txt", "a")) == NULL) {   //���ļ�
        printf("File open error.\n");
    }

    fprintf(fp, "%s\t", log->card->aName);
    fprintf(fp, "%s\t", log->card->aPwd);
    fprintf(fp, "%d\t", log->card->nStatus);
    fprintf(fp, "%lld\t", log->card->tStart);
    fprintf(fp, "%lld\t", log->card->tEnd);
    fprintf(fp, "%f\t", log->card->fTotalUse);
    fprintf(fp, "%lld\t", log->card->tLast);
    fprintf(fp, "%d\t", log->card->nUseCount);
    fprintf(fp, "%f\t", log->card->fBalance);
    fprintf(fp, "%d\t", log->card->nDel);
    fprintf(fp, "%d\t", log->opt);
    fprintf(fp, "%lld\n", log->time);

    if ( fclose(fp)) {          //�ر��ļ�
        printf("File close error.\n");
    }

}

//����Log�ļ�
void updateLog() {

    FILE *fp;
    login_log *p;
    p = headl;

    if ((fp = fopen("login_log_info.txt", "w+")) == NULL) {
        printf("File open error.\n");
    }

    if ( fclose(fp)) {                    //�ر��ļ�
        printf("Can not close the file!\n");
    }

    while ( p != NULL) {
        if ( p->card != NULL) {        //
            saveLog(p);
        }
        p = p->next;
    }
}