#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define BUFF_SIZE 1024*1024*64

void closeAll(char * newFile,char * buff,FILE * f,FILE * cf){
    if(newFile)free(newFile);
    if(buff)free(buff);
    if(cf)fclose(cf);
    if(f)fclose(f);
}

int main(int argc,char * argv[]){
	printf("��ӭʹ��.kgtemp����ʵ�ó���\n�����������ѱ�д��huaying1988���룡\n");
	if(argc<2){
		printf("ʹ�÷�����%s <file path>\n",argv[0]);
		return -1;
	}
	FILE * f=fopen(argv[1],"rb");
	printf("���ڽ����ļ��� %s\n",argv[1]);
	if(f==0){
		printf("�޷����ļ���%s!!\n",argv[1]);
		return -2;
	}
	//char buff[1024*1024*1];//1M
	char * buff=(char *)malloc(BUFF_SIZE*sizeof(char));
	if(buff<=0){
		printf("���棺�޷����ö�̬�ڴ����\n");
		fclose(f);
		return -4;
	}
	int fnLen=0;
	char * newFile=(char *)malloc(((fnLen=strlen(argv[1]))+6)*sizeof(char));
	if(newFile<=0){
		printf("���ļ�·�����޷����ö�̬�ڴ����\n");
		closeAll(NULL,buff,f,NULL);
		return -4;
	}
	int readLen=0;
	strcpy(newFile,argv[1]);
	strcpy(newFile+fnLen,".flac");
    printf("�����ļ���%s\n",newFile);
    FILE * cf=fopen(newFile,"wb");
    if(cf==0){
        printf("�޷����ļ���%s\n",newFile);
        closeAll(newFile,buff,f,NULL);
        return -5;
    }
    char key[]={0xAC,0xEC,0xDF,0x57};
    int r = fseek(f,1024,SEEK_SET);
    if(r!=0){
        printf("Ѱ���ļ�ʧ�ܣ����ؽ����%d\n",r);
        closeAll(newFile,buff,f,cf);
        return -6;
    }
    int i=0;
    while(!feof(f)){
        //readLen=fread(buff,1,sizeof(buff),f);
        readLen=fread(buff,1,BUFF_SIZE,f);
        //printf("pre read %d, but real read %d\n",sizeof(buff),readLen);
        printf("pre read %d, real read %d\n",BUFF_SIZE,readLen);
        if(readLen==0){
            printf("��ȡ��0�ֽڣ�����Ϊɶ��\n");
            closeAll(newFile,buff,f,cf);
            return -6;
        }
        for(i=0;i<readLen;i++){
            char k = key[i%4];
            char kh = k >> 4;
            char kl = k & 0xf;
            char b = buff[i];
            char low = b & 0xf ^ kl;//���ܺ�ĵ�4λ
            char high = (b >> 4) ^ kh ^ low & 0xf;//���ܺ�ĸ�4λ
            buff[i] = (char)(high << 4 | low);
        }
        if(fwrite(buff,readLen,1,cf)==0){
            printf("д����0�ֽڣ���ֱ�������ţ�\n");
            closeAll(newFile,buff,f,cf);
            return -7;
        }
    }
    printf("%s�����ѳɹ���\n",argv[1]);
    closeAll(newFile,buff,f,cf);
	return 0;
}

