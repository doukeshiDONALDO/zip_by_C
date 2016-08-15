#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#define BUF 256
int
main (int argc, char *argv[])
{
	FILE	*fp;
	char	buf[BUF];
	char	cmd1[] = "unzip flag";

	char	cmd[25];

	int i;


	for(i=999;i>=0;i--){
		sprintf(cmd,"%s%d",cmd1,i);
		if ( (fp=popen(cmd,"r")) ==NULL) {//コマンド実行
			err(EXIT_FAILURE, "%s", cmd);//エラー出力をし終了
		}
		while(fgets(buf, BUF, fp) != NULL) {
			(void) fputs(buf, stdout);	//コマンドの出力結果を標準出力に出力
		}
		(void) pclose(fp);
	}	
	exit (EXIT_SUCCESS);
}
