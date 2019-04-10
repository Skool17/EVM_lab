#include "computer.h"

using namespace std;
int main(){
	int *value;
    int *command;
    int *operand;
	value = (int*) malloc(sizeof(int));
	command = (int*) malloc(sizeof(int));
	operand = (int*) malloc(sizeof(int));
	sc_commandEncode(10,20,value);
	sc_commandDecode(*value,command,operand);
	printf("%X %X", *command, *operand);
	return 0;
}


int sc_memoryInit(){
	for(int i = 0; i < N; i++){
		Mem_Mas[i] == 0;
	}
}

int sc_memorySet(int adress, int value){
	if((adress>=0)&&(adress <= N)){
	Mem_Mas[adress] = value;
	return 0;
	}
	else{
		return Error_Adress;
	}
}

int sc_memoryGet( int adress, int * value){	
	if((adress>=0)&&(adress < N)){
		*value = Mem_Mas[adress];
		return 0;
	}
	else{
		return Error_Adress;
	}
}

int sc_memorySave(char *filename){
	FILE *f = fopen(filename,"wb");
	int n;
	if(f == NULL){
		return Error_Open_File;
	}
		n = fwrite(Mem_Mas,sizeof(int),1,f);
		if(n != 1)
			return Error_File_Size;
		else
			return 0;
}

int sc_memoryLoad(char){
	FILE *f = fopen("Base.dat","rb");
	int n;
	if(f==NULL){
		return Error_Open_File;
	}
	n = fread(Mem_Mas,sizeof(int),1,f);
	for(int i = 0; i < N; i++){
		Mem_Mas[i] &= 0x7FFF; // ïî ðàçðÿäíîå È
		cout<<"Mem_Mas["<<i<<"] = "<<Mem_Mas[i]<<" "; 
	}
	fclose(f);
	if(n!=1)
		return Error_File_Size;
	else
		return 0;
}

int sc_regInit(){	//èíèöèàëèçèðóåò ðåãèñòð ôëàãîâ íóëåâûì çíà÷åíèåì
	Mem_Flag = 0;
	return 1;
}

int sc_regSet(int reg, int value){
	if(reg >= Flag_Reg_Size)
		return 0;
	if(value == 0)
		BIT_CLEAR(Mem_Flag, reg);
	else if(value == 1)
		BIT_SET(Mem_Flag, reg);
	else 
		return 0;
	return 1;		
}

int sc_commandEncode(int command, int operand, int *value)//êîäèðîâêà êîìàíäû
{
	if(operand > 127 || command > 127)
	return 0;
	*value = 0;
	int temp;
	temp = command;
	*value = operand;
	temp = temp << 7;
	*value = *value  | temp;
	return 1;
}
int sc_commandDecode(int value, int *command, int *operand){	//Äåêîäèðîâàíèå êîìàíäû
	if(BIT_CHECK(value,COMMAND_LENGTH - 1))
	return 0;
	int temp;
	temp = value;
	temp = temp >> 7;
	*command = temp;
	temp = value;
	temp = temp & 0x000000FF;
	temp = temp & (~(1 << 7));
	*operand = temp;
	return 1;
}
