#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/stat.h>

uint32_t set(uint32_t n){
	return n;
}
int main(int argc, char* argv[]){
	uint8_t f1[4] = {0};
	uint8_t f2[4] = {0};
	FILE* fp1 = fopen(argv[1],"rb");
	fread(f1,sizeof(uint8_t),4,fp1);
	fclose(fp1);
	FILE* fp2 = fopen(argv[2],"rb");
	fread(f2,sizeof(uint8_t),4,fp2);
	fclose(fp2);
	      	
	uint32_t* p1 = reinterpret_cast<uint32_t*>(f1);
	uint32_t* p2 = reinterpret_cast<uint32_t*>(f2);
	uint32_t n1 = ntohl(*p1);
	uint32_t n2 = ntohl(*p2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1,n1,n2,n2,n1+n2,n1+n2);


//add-nbo.c
	return 0;

}
