#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int ES;
int PS;
int QA,QB,Z=0,a=0;

FILE *archivo;

struct formatohoras{
    int horas;
    int minutos;
    int segundos;

};

typedef struct formatohoras HH;

HH sumadehoras(HH n1,HH n2);
HH horaactual;
HH horaLL;
HH horaLLA;
HH horaLLB;
HH horaLLFS;
HH horaAB[TAM];
HH horaFS;
HH horadescanso; //
HH horafindescanso;

HH frecuenciaD;
HH frecuenciaFD;
HH frecuenciaLLA;
HH frecuenciaLL;
HH frecuenciaLLB;
HH frecuenciaLLFS;
HH frecuenciaFS;
HH frecuenciaAB;
HH menorhora(HH n1,HH n2);
HH menorhora1(HH n1,HH n2,HH n3);
HH aleatoria(HH n1,HH n2);

void problema1(void);
void problema2(void);
void problema3(void);
void problema4(void);
void problema5(void);

void cargardatos1(void);
void mostrardatos1(void);
void mostrarsinFS1(void);
void iterar1(void);

void cargardatos2(void);
void mostrardatos2(void);
void mostrarsinFS2(void);
void iterar2(void);

void cargardatos3(void);
void mostrardatos3(void);
void mostrarsinFS3(void);
void cargarE(void);
void iterar3(void);

void cargardatos4(void);
void mostrardatos4(void);
void mostrarsinFS4(void);
void iterar4(void);

void cargardatos5(void);
void mostrardatos5(void);
void mostrarsinFS5(void);
void iterar5(void);


int main (){
    printf("Ingrese el numero del problema que quiere resolver: ");
    scanf("%1d",&a);
    fflush(stdin);
    switch(a){
        case 1: printf("\nEligio problema 1\n");
                problema1();
        break;
        case 2: printf("\nEligio problema 2\n");
                problema2();
        break;
        case 3: printf("\nEligio problema 3\n");
                problema3();
        break;
        case 4: printf("\nEligio problema 4\n");
                problema4();
        break;
        case 5: printf("\nEligio problema 5\n");
                problema5();
        break;

    }
    return 0;
}

void problema1(){
printf("\t\t BIENVENIDO A LA COLA \n\n");
    archivo=fopen("Sistema de cola 1.txt","w+");
    if(archivo==NULL){
        printf("ERROR");
    }
    fprintf(archivo,"Hora Actual:\t\t");
    fprintf(archivo,"Hora de Prox. LLegada:\t\t\t");
    fprintf(archivo,"Hora Prox FS:\t\t");
    fprintf(archivo,"Cantidad de clientes:\t\t");
    fprintf(archivo,"Puesto de Servicio PS:");
    fprintf(archivo,"\n");
    cargardatos1();
    iterar1();
    mostrardatos1();
    mostrarsinFS1();
    fclose(archivo);
}
void problema2() {
 printf("\t\t BIENVENIDO A LA COLA \n\n");
    archivo=fopen("Sistema de cola 2.txt","w+");
    if(archivo==NULL){
        printf("ERROR");
    }
    fprintf(archivo,"Hora Actual:\t\t");
    fprintf(archivo,"Hora de Prox. LLegada:\t\t\t");
    fprintf(archivo,"Hora Prox FS:\t\t\t");
    fprintf(archivo,"Hora Descanso:\t\t\t"); //
    fprintf(archivo,"Hora Fin Des:\t\t\t"); //

    fprintf(archivo,"Cantidad de clientes:\t\t\t");
    fprintf(archivo,"Puesto de Servicio PS:\t\t\t");
    fprintf(archivo,"Estado de servidor:\t\t\t"); //
    fprintf(archivo,"\n");
    cargardatos2();
    iterar2();
    mostrardatos2();
    mostrarsinFS2();
    fclose(archivo);
}
void problema3() {
printf("\t\t BIENVENIDO A LA COLA \n\n");
    archivo=fopen("Sistema de cola 3.txt","w+");
    if(archivo==NULL){
        printf("ERROR");
    }
    fprintf(archivo,"Hora Actual:\t\t");
    fprintf(archivo,"Hora de Prox. LLegada:\t\t");
    fprintf(archivo,"Hora Prox FS:\t\t");
    fprintf(archivo,"hora prox aband.:\t\t");
    fprintf(archivo,"Cantidad de clientes:\t");
    fprintf(archivo,"Puesto de Servicio PS:");
    fprintf(archivo,"\n");
    cargardatos3();
    //cargarE();
    mostrardatos3();
    iterar3();

    mostrarsinFS3();
    fclose(archivo);
}
void problema4() {
printf("\t\t BIENVENIDO A LA COLA \n\n");
    archivo=fopen("Sistema de cola 4.txt","w+");
    if(archivo==NULL){
        printf("ERROR");
    }
    fprintf(archivo,"Hora Actual:\t\t");
    fprintf(archivo,"Hora de Prox. LLegada A:\t\t");
    fprintf(archivo,"Hora de Prox. LLegada B:\t\t");
    fprintf(archivo,"Hora Prox FS:\t\t");
    fprintf(archivo,"Cantidad de clientes A:\t\t");
    fprintf(archivo,"Cantidad de clientes B:\t\t");
    fprintf(archivo,"Puesto de Servicio PS:");
    fprintf(archivo,"\n");
    cargardatos4();
    if(PS==1){
        mostrardatos4();
    } else{
    mostrarsinFS4();
    }
    iterar4();
    fclose(archivo);
}
void problema5() {
printf("\t\t BIENVENIDO A LA COLA \n\n");
    archivo=fopen("Sistema de cola 5.txt","w+");
    if(archivo==NULL){
        printf("ERROR");
    }
    fprintf(archivo,"Hora Actual:\t\t");
    fprintf(archivo,"Hora de Prox. LLegada a cola:\t\t");
    fprintf(archivo,"Hora de Prox. LLegada FS:\t\t");
    fprintf(archivo,"Hora Prox FS:\t\t");
    fprintf(archivo,"Cantidad de clientes en cola:\t\t");
    fprintf(archivo,"Estado de zona de seguridad:\t\t");
    fprintf(archivo,"Puesto de Servicio PS:");
    fprintf(archivo,"\n");
    cargardatos5();
    if(PS==1){
        mostrardatos5();
    } else{
    mostrarsinFS5();
    }
    iterar5();
    fclose(archivo);
}

HH sumadehoras (HH n1,HH n2){
    HH salida;
    salida.horas=n1.horas+n2.horas;
    salida.minutos=n1.minutos+n2.minutos;
    salida.segundos=n1.segundos+n2.segundos;
    if (salida.horas>=24){
        salida.horas=salida.horas%24;
    }
    if (salida.minutos>=60){
        salida.horas=salida.horas+1;
        salida.minutos=salida.minutos%60;
    }
    if (salida.segundos>=60){
        salida.minutos=salida.minutos+1;
        salida.segundos=salida.segundos%60;
    }
    return salida;
}

void cargardatos1(){
    printf("Ingrese la hora actual inicial HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaactual.horas,&horaactual.minutos,&horaactual.segundos);
    printf("\nIngrese la Hora proxima de llegada HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaLL.horas,&horaLL.minutos,&horaLL.segundos);
    printf("\nEl puesto de servicio esta ocupado? S/N :");
    fflush(stdin);
    char respuesta[5];
    gets(respuesta);
    if (respuesta[0]=='n'||respuesta[0]=='N'){
        PS=0;

    }
    if(respuesta[0]=='s'||respuesta[0]=='S'){
        PS=1;

    }
    printf("\nIngrese la hora proxima de fin de servicio HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaFS.horas,&horaFS.minutos,&horaFS.segundos);
     printf("\nIngrese la frecuencia del fin de servicio en SEG : ");
    fflush(stdin);
    scanf("%d",&frecuenciaFS.segundos);
    printf("\nIngrese la frecuencia de la llegada de un cliente en SEG: ");
    fflush(stdin);
    scanf("%d",&frecuenciaLL.segundos);
    fflush(stdin);
    printf("\nIngrese la cantidad de clientes en cola iniciales : ");
    fflush(stdin);
    scanf("%d",&QA);

}
void cargardatos2(){
    printf("Ingrese la hora actual HH:MM:SS : "); //
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaactual.horas,&horaactual.minutos,&horaactual.segundos);
    printf("\nIngrese la Hora de Llegada de cliente HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaLL.horas,&horaLL.minutos,&horaLL.segundos);
     printf("\nIngrese la hora proxima de fin de servicio HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaFS.horas,&horaFS.minutos,&horaFS.segundos);
    printf("\nEl puesto de servicio esta ocupado? S/N :");
    fflush(stdin);
    char respuesta[5];
    gets(respuesta);
    if (respuesta[0]=='n'||respuesta[0]=='N'){
        PS=0;

    }
    if(respuesta[0]=='s'||respuesta[0]=='S'){
        PS=1;

    }
    printf("\nIngrese la hora proxima de descanso HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horadescanso.horas,&horadescanso.minutos,&horadescanso.segundos);
     printf("\nIngrese la frecuencia descanso en SEG : ");//
    fflush(stdin);
    scanf("%d",&frecuenciaD.segundos);//
    printf("\nIngrese la frecuencia de fin de desanso en SEG: ");//
    fflush(stdin);
    scanf("%d",&frecuenciaFD.segundos);//
    fflush(stdin);
    printf("\nIngrese la cantidad de clientes en cola iniciales : ");
    fflush(stdin);
    scanf("%d",&QA);

}
void cargardatos3(){
    printf("Ingrese la hora actual inicial HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaactual.horas,&horaactual.minutos,&horaactual.segundos);
    printf("\nIngrese la Hora proxima de llegada HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaLL.horas,&horaLL.minutos,&horaLL.segundos);
    printf("\nEl puesto de servicio esta ocupado? S/N :");
    fflush(stdin);
    char respuesta[5];
    gets(respuesta);
    if (respuesta[0]=='n'||respuesta[0]=='N'){
        PS=0;

    }
    if(respuesta[0]=='s'||respuesta[0]=='S'){
        PS=1;

    }
    printf("\nIngrese la hora proxima de fin de servicio HH:MM:SS : ");
    fflush(stdin);

    scanf("%2d:%2d:%2d",&horaFS.horas,&horaFS.minutos,&horaFS.segundos);
     printf("\nIngrese la frecuencia del fin de servicio en SEG : ");
    fflush(stdin);
    scanf("%d",&frecuenciaFS.segundos);
    printf("\nIngrese la frecuencia de la llegada de un cliente en SEG: ");
    fflush(stdin);
    scanf("%d",&frecuenciaLL.segundos);
    fflush(stdin);
    printf("\nIngrese la cantidad de clientes en cola iniciales : ");
    fflush(stdin);
    scanf("%d",&QA);
    fflush(stdin);
    printf("\nIngrese la frecuencia de abandono de cola en segundos : ");
    fflush(stdin);
    scanf("%d",&frecuenciaAB.segundos);

    horaAB[0]=sumadehoras(horaLL,frecuenciaAB);

}
void cargardatos4(){
    printf("Ingrese la hora actual inicial HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaactual.horas,&horaactual.minutos,&horaactual.segundos);
    printf("\nIngrese la Hora proxima de llegada CLIENTE A HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaLLA.horas,&horaLLA.minutos,&horaLLA.segundos);
    printf("\nIngrese la Hora proxima de llegada CLIENTE B HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaLLB.horas,&horaLLB.minutos,&horaLLB.segundos);
    printf("\nEl puesto de servicio esta ocupado? S/N :");
    fflush(stdin);
    char respuesta[5];
    gets(respuesta);
    if (respuesta[0]=='n'||respuesta[0]=='N'){
        PS=0;

    }
    if(respuesta[0]=='s'||respuesta[0]=='S'){
        PS=1;

    }
    printf("\nIngrese la hora proxima de fin de servicio HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaFS.horas,&horaFS.minutos,&horaFS.segundos);
     printf("\nIngrese la frecuencia del fin de servicio en SEG : ");
    fflush(stdin);
    scanf("%d",&frecuenciaFS.segundos);
    printf("\nIngrese la frecuencia de la llegada de un cliente A en SEG: ");
    fflush(stdin);
    scanf("%d",&frecuenciaLLA.segundos);
     printf("\nIngrese la frecuencia de la llegada de un cliente B en SEG: ");
    fflush(stdin);
    scanf("%d",&frecuenciaLLB.segundos);
    fflush(stdin);
    printf("\nIngrese la cantidad de clientes en cola A al inicio : ");
    fflush(stdin);
    scanf("%d",&QA);
    printf("\nIngrese la cantidad de clientes en cola B al inicio : ");
    fflush(stdin);
    scanf("%d",&QB);

}
void cargardatos5(){
    printf("Ingrese la hora actual inicial HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaactual.horas,&horaactual.minutos,&horaactual.segundos);
    printf("\nIngrese la Hora proxima de llegada CLIENTE HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaLLA.horas,&horaLLA.minutos,&horaLLA.segundos);
    printf("\nIngrese la Hora proxima de llegada CLIENTE A PS HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaLLFS.horas,&horaLLFS.minutos,&horaLLFS.segundos);
    printf("\nEl puesto de servicio esta ocupado? S/N :");
    fflush(stdin);
    char respuesta[5];
    gets(respuesta);
    if (respuesta[0]=='n'||respuesta[0]=='N'){
        PS=0;

    }
    if(respuesta[0]=='s'||respuesta[0]=='S'){
        PS=1;

    }
    printf("\nIngrese la hora proxima de fin de servicio HH:MM:SS : ");
    fflush(stdin);
    scanf("%2d:%2d:%2d",&horaFS.horas,&horaFS.minutos,&horaFS.segundos);
     printf("\nIngrese la frecuencia del fin de servicio en SEG : ");
    fflush(stdin);
    scanf("%d",&frecuenciaFS.segundos);
    printf("\nIngrese la frecuencia de la llegada de un cliente en SEG: ");
    fflush(stdin);
    scanf("%d",&frecuenciaLLA.segundos);
     printf("\nIngrese la frecuencia de la llegada a Puesto de Servicio en SEG: ");
    fflush(stdin);
    scanf("%d",&frecuenciaLLFS.segundos);
    fflush(stdin);
    printf("\nIngrese la cantidad de clientes en cola A al inicio : ");
    fflush(stdin);
    scanf("%d",&QA);

}

void mostrardatos1(void){
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaactual.horas,horaactual.minutos,horaactual.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLL.horas,horaLL.minutos,horaLL.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaFS.horas,horaFS.minutos,horaFS.segundos);
    fprintf(archivo,"%d\t\t\t",QA);
    if(PS==0){
        fprintf(archivo,"Libre\t\t");
    }
    else{
        fprintf(archivo,"Ocupado\t\t");
    }
    fprintf(archivo,"\n");
}
void mostrarsinFS1(void){
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaactual.horas,horaactual.minutos,horaactual.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLL.horas,horaLL.minutos,horaLL.segundos);
    fprintf(archivo,"--:--:--  \t\t\t");
    fprintf(archivo,"%d\t\t\t",QA);
    if(PS==0){
        fprintf(archivo,"Libre\t\t");
    }
    else{
        fprintf(archivo,"Ocupado\t\t");
    }
    fprintf(archivo,"\n");
}
void mostrardatos2(void){
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaactual.horas,horaactual.minutos,horaactual.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLL.horas,horaLL.minutos,horaLL.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaFS.horas,horaFS.minutos,horaFS.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horadescanso.horas,horadescanso.minutos,horadescanso.segundos);//
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horafindescanso.horas,horafindescanso.minutos,horafindescanso.segundos);//
    fprintf(archivo,"%d\t\t\t",QA);
    if(PS==0){
        fprintf(archivo,"Libre\t\t");
    }
    else{
        fprintf(archivo,"Ocupado\t\t");
    }
    fprintf(archivo,"\n\n");
}
void mostrarsinFS2(void){
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaactual.horas,horaactual.minutos,horaactual.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLL.horas,horaLL.minutos,horaLL.segundos);
    fprintf(archivo,"--:--:--  \t\t\t");
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horadescanso.horas,horadescanso.minutos,horadescanso.segundos);//
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horafindescanso.horas,horafindescanso.minutos,horafindescanso.segundos);//
    fprintf(archivo,"%d\t\t\t",QA);
    if(PS==0){
        fprintf(archivo,"Libre\t\t");
    }
    else{
        fprintf(archivo,"Ocupado\t\t");
    }
    fprintf(archivo,"\n\n");
}
void mostrardatos3(void){
    fprintf(archivo,"%2d:%2d:%2d\t\t",horaactual.horas,horaactual.minutos,horaactual.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLL.horas,horaLL.minutos,horaLL.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaFS.horas,horaFS.minutos,horaFS.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaAB[0].horas,horaAB[0].minutos,horaAB[0].segundos);
    fprintf(archivo,"%d\t\t",QA);
    if(PS==0){
        fprintf(archivo,"Libre\t\t");
    }
    else{
        fprintf(archivo,"Ocupado\t\t");
    }
    fprintf(archivo,"\n\n");
}
void mostrarsinFS3(void){
    fprintf(archivo,"%2d:%2d:%2d\t\t",horaactual.horas,horaactual.minutos,horaactual.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLL.horas,horaLL.minutos,horaLL.segundos);
    fprintf(archivo,"--:--:-- \t\t\t");
    fprintf(archivo,"--:--:-- \t\t\t");
    fprintf(archivo,"%d\t\t",QA);
    if(PS==0){
        fprintf(archivo,"Libre\t");
    }
    else{
        fprintf(archivo,"Ocupado\t");
    }
    fprintf(archivo,"\n\n");
}
void mostrardatos4(void){
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaactual.horas,horaactual.minutos,horaactual.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLLA.horas,horaLLA.minutos,horaLLA.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLLB.horas,horaLLB.minutos,horaLLB.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaFS.horas,horaFS.minutos,horaFS.segundos);
    fprintf(archivo,"%d\t\t\t",QA);
    fprintf(archivo,"%d\t\t\t",QB);
    if(PS==0){
        fprintf(archivo,"Libre\t\t");
    }
    else{
        fprintf(archivo,"Ocupado\t\t");
    }
    fprintf(archivo,"\n");
}
void mostrarsinFS4(void){
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaactual.horas,horaactual.minutos,horaactual.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLLA.horas,horaLLA.minutos,horaLLA.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLLB.horas,horaLLB.minutos,horaLLB.segundos);
    fprintf(archivo,"--:--:--  \t\t\t");
    fprintf(archivo,"%d\t\t\t",QA);
    fprintf(archivo,"%d\t\t\t",QB);
    if(PS==0){
        fprintf(archivo,"Libre\t\t");
    }
    else{
        fprintf(archivo,"Ocupado\t\t");
    }
    fprintf(archivo,"\n");
}
void mostrardatos5(void){
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaactual.horas,horaactual.minutos,horaactual.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLLA.horas,horaLLA.minutos,horaLLA.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLLFS.horas,horaLLFS.minutos,horaLLFS.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaFS.horas,horaFS.minutos,horaFS.segundos);
    fprintf(archivo,"%d\t\t\t",QA);
    fprintf(archivo,"%d\t\t\t",Z);
    if(PS==0){
        fprintf(archivo,"Libre\t\t");
    }
    else{
        fprintf(archivo,"Ocupado\t\t");
    }
    fprintf(archivo,"\n");
}
void mostrarsinFS5(void){
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaactual.horas,horaactual.minutos,horaactual.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLLA.horas,horaLLA.minutos,horaLLA.segundos);
    fprintf(archivo,"%2d:%2d:%2d\t\t\t",horaLLFS.horas,horaLLFS.minutos,horaLLFS.segundos);
    fprintf(archivo,"--:--:--  \t\t\t");
    fprintf(archivo,"%d\t\t\t",QA);
    fprintf(archivo,"%d\t\t\t",Z);
    if(PS==0){
        fprintf(archivo,"Libre\t\t");
    }
    else{
        fprintf(archivo,"Ocupado\t\t");
    }
    fprintf(archivo,"\n");
}

HH menorhora(HH n1,HH n2){
    HH salida;
    int segundosn1;
    int segundosn2;
    segundosn1=n1.segundos+(n1.minutos*60)+(n1.horas*60*60);
    segundosn2=n2.segundos+(n2.minutos*60)+(n1.horas*60*60);
    if(segundosn1<segundosn2){
        salida=n1;
    }
    else{
        salida=n2;
    }
    return salida;
}
HH menorhora1(HH n1,HH n2,HH n3){
    HH salida;
    int segundosn1;
    int segundosn2;
    int segundosn3;
    segundosn1=n1.segundos+(n1.minutos*60)+(n1.horas*60*60);
    segundosn2=n2.segundos+(n2.minutos*60)+(n2.horas*60*60);
    segundosn3=n3.segundos+(n3.minutos*60)+(n3.horas*60*60);
    if(segundosn1<segundosn2 && segundosn1<segundosn3){
            salida=n1;
    }
    else{ if(segundosn2<segundosn3 && segundosn2<segundosn1){
        salida=n2;
    }
    else{
        salida=n3;
    }
    }
    return salida;
}

void cargarE(void){
horaAB[i]=sumadehoras(horaLL,frecuenciaAB);
}
void iterar1(void){
    int bandera=0;
    HH referencia;
    do{
        referencia=menorhora(horaFS,horaLL);
        int comparacion,menor;
        menor=horaLL.segundos+(horaLL.minutos*60)+(horaLL.horas*60*60);
        comparacion=referencia.segundos+(referencia.minutos*60)+(referencia.horas*60*60);


        if(menor==comparacion){
            horaactual=horaLL;
            horaLL=sumadehoras(horaLL,frecuenciaLL);
            if(PS==1){
            QA++;
            }
            PS=1;
            mostrardatos1();
        }
        else{
            horaactual=horaFS;
            if(QA!=0){
                QA--;
                horaFS=sumadehoras(horaFS,frecuenciaFS);
                PS=1;
                mostrardatos1();
            }
            else{
                horaFS=sumadehoras(horaLL,frecuenciaFS);
                PS=0;
                bandera++;
                mostrarsinFS1();
            }
        }
    }
    while(bandera<3);
}
void iterar2(void){
    int bandera=0;
    HH referencia;

    do{
        srand(time(NULL));
    frecuenciaLL.segundos=4+rand()%43;//
    frecuenciaFS.segundos=1+rand()%11;//

        referencia=menorhora1(horaFS,horaLL,horadescanso);
        int comparacion,menor;
        menor=horaLL.segundos+(horaLL.minutos*60)+(horaLL.horas*60*60);
        comparacion=referencia.segundos+(referencia.minutos*60)+(referencia.horas*60*60);


        if(menor==comparacion){
            horaactual=horaLL;
            horaLL=sumadehoras(horaLL,frecuenciaLL);

            if(PS==1){
            QA++;
            }
            PS=1;
            mostrardatos2();
        }
        else{
            referencia=menorhora(horaFS,horadescanso);
            int comparacion,menor;
            menor=horadescanso.segundos+(horadescanso.minutos*60)+(horadescanso.horas*60*60);
            comparacion=referencia.segundos+(referencia.minutos*60)+(referencia.horas*60*60);

            if(menor==comparacion){
            horaactual=horadescanso;
            horafindescanso=sumadehoras(horadescanso,frecuenciaFD);
            horadescanso=sumadehoras(horafindescanso,frecuenciaD);
            horaFS=sumadehoras(horafindescanso,frecuenciaFS);

            ES=0;
            mostrardatos2();
            }
            else{

                if(QA!=0){
                horaactual=horaFS;
                QA--;
                horaFS=sumadehoras(horaFS,frecuenciaFS);
                PS=1;
                mostrardatos2();
                }
                else{
                horaFS=sumadehoras(horaLL,frecuenciaFS);
                PS=0;
                bandera++;
                mostrarsinFS2();
            }
        }
        }
    }

    while(bandera<4);

}
void iterar3(void){
    int bandera=0;
    HH referencia;
    int comparacion,menor;
    do{
            if(i==0){/*Modificar agregar en funcion mostrar y tambien tambien agregarle en funcion cargarE la hora de llegada. ERA ESTO LO QUE FALTABA AHORA ESTA SOLUCIONADO :D
                    ESTA PARTE DEL CODIGO SIRVE PARA QUE CUANDO EL ITERADOR i=0 IGNORE EL CALCULO DE ABANDONO YA QUE AL INICIO AL EN EL CASO Q SE DE UN FIN DE SERVICIO SERIA ILOGICO RECALCULAR EL ABANDONO*/
            referencia=menorhora(horaFS,horaLL);
        menor=horaLL.segundos+(horaLL.minutos*60)+(horaLL.horas*60*60); //Variable que guarda los segundos totales de la hora de llegada
        comparacion=referencia.segundos+(referencia.minutos*60)+(referencia.horas*60*60);


        if(menor==comparacion){
            horaactual=horaLL;

            if(PS==1){QA++;
            cargarE();i++;}
            PS=1;

            horaLL=sumadehoras(horaLL,frecuenciaLL);
            mostrardatos3();
        }
        else{
            horaactual=horaFS;
            if(QA!=0){
                QA--;
                horaFS=sumadehoras(horaFS,frecuenciaFS);
                PS=1;
                //i--;
                mostrardatos3();
            }
            else{
                horaFS=sumadehoras(horaLL,frecuenciaFS);
                PS=0;
                bandera++;
                mostrarsinFS3();
            }
        }
    }
    else{ //PARTE DEL CODIGO QUE CALCULA LAS TRES VARIABLES UNA VEZ QUE YA LLEGO EL PRIMER CLIENTE



        referencia=menorhora1(horaFS,horaLL,horaAB[0]);
        menor=horaLL.segundos+(horaLL.minutos*60)+(horaLL.horas*60*60);
        comparacion=referencia.segundos+(referencia.minutos*60)+(referencia.horas*60*60);


        if(menor==comparacion){
            horaactual=horaLL;
            if(PS==1){
            QA++;cargarE();
            i++;
            }
            PS=1;
            horaLL=sumadehoras(horaLL,frecuenciaLL);
             /*añadir hora de llegada a */

            mostrardatos3();
        }
        else{// si no es la hora de llegada recalcular entre el fin de servicio y abandono cual es el menor de los dos
                referencia=menorhora(horaFS,horaAB[0]);
            menor=horaAB[0].segundos+(horaAB[0].minutos*60)+(horaAB[0].horas*60*60);
            comparacion=referencia.segundos+(referencia.minutos*60)+(referencia.horas*60*60);

            if(menor==comparacion && QA!=0){  //Calcula el abandono solo si hay gente en la cola
            horaactual=horaAB[0];
            QA--;
            for(j=0;j<TAM;j++){
            horaAB[j]=horaAB[j+1]; // Al irse el primero de la cola tiene que borrar su tiempo y hacer pasar al que sigue
            }
           i--;

            mostrardatos3();

            }
            else{

            if(QA!=0){
                horaactual=horaFS;//Modifique RJ

                horaFS=sumadehoras(horaFS,frecuenciaFS);
                PS=1;
                /*quitar primer elemento de v[i]*/

                for(j=0;j<TAM;j++){
            horaAB[j]=horaAB[j+1];
            }
                QA--;
                i--;
                mostrardatos3();
            }
            else{
                horaFS=sumadehoras(horaLL,frecuenciaFS);
                PS=0;
                bandera++;
                mostrarsinFS3();
            }
            }
        }

    }
    }
    while(bandera<4);

}
void iterar4(void){
    int bandera=0;
    HH referencia;
    do{
        referencia=menorhora1(horaFS,horaLLA,horaLLB);
        int comparacion,menor;
        menor=horaLLA.segundos+(horaLLA.minutos*60)+(horaLLA.horas*60*60);
        comparacion=referencia.segundos+(referencia.minutos*60)+(referencia.horas*60*60);


        if(menor==comparacion){
            horaactual=horaLLA;
            horaLLA=sumadehoras(horaLLA,frecuenciaLLA);
            if(PS==1){
            QA++;
            }
            PS=1;
            mostrardatos4();
        }
        else{
             referencia=menorhora(horaFS,horaLLB);
        int comparacion,menor;
        menor=horaLLB.segundos+(horaLLB.minutos*60)+(horaLLB.horas*60*60);
        comparacion=referencia.segundos+(referencia.minutos*60)+(referencia.horas*60*60);
            if(menor==comparacion){
                horaactual=horaLLB;
            horaLLB=sumadehoras(horaLLB,frecuenciaLLB);
            if(PS==1){
            QB++;
            }
            PS=1;
            mostrardatos4();
            }
            else{
            horaactual=horaFS;
            if(QA!=0 && PS==1){
                QA--;
                horaFS=sumadehoras(horaFS,frecuenciaFS);
                PS=1;
                mostrardatos4();
            }
            else{
             if(QB!=0 && PS==1){
                QB--;
                horaFS=sumadehoras(horaFS,frecuenciaFS);
                PS=1;
                mostrardatos4();
             }
             else {
                horaFS=sumadehoras(horaFS,frecuenciaFS);
                PS=0;
                bandera++;
                mostrarsinFS4();
             }
            }
            }
        }
    }
    while(bandera<3);
}
void iterar5(void){
    int bandera=0;
    HH referencia;
    do{
        referencia=menorhora1(horaFS,horaLLA,horaLLFS);
        int comparacion,menor;
        menor=horaLLA.segundos+(horaLLA.minutos*60)+(horaLLA.horas*60*60);
        comparacion=referencia.segundos+(referencia.minutos*60)+(referencia.horas*60*60);


        if(menor==comparacion){
            horaactual=horaLLA;
            horaLLA=sumadehoras(horaLLA,frecuenciaLLA);

            QA++;


            mostrardatos5();
        }
        else{
             referencia=menorhora(horaFS,horaLLFS);
        int comparacion,menor;
        menor=horaLLFS.segundos+(horaLLFS.minutos*60)+(horaLLFS.horas*60*60);
        comparacion=referencia.segundos+(referencia.minutos*60)+(referencia.horas*60*60);
            if(menor==comparacion){
                horaactual=horaLLFS;

            if(PS==0){

            if(Z==1){
                PS=1;
                Z=0;
                horaFS=sumadehoras(horaLLFS,frecuenciaFS);
                horaLLFS=sumadehoras(horaFS,frecuenciaLLFS);
            }
            else{ if(QA!=0){ QA--; Z=1;}
                horaLLFS=sumadehoras(horaLLFS,frecuenciaLLFS);
            }

            }

            mostrardatos5();
            }
            else{
            horaactual=horaFS;
            if(QA!=0 && PS==1){
                    PS=0;
                QA--;
                horaLLFS=sumadehoras(horaFS,frecuenciaLLFS);
                horaFS=sumadehoras(horaFS,frecuenciaFS);

                Z=1;
                mostrarsinFS5();
            }
            else{

                horaLLFS=sumadehoras(horaFS,frecuenciaLLFS);
                PS=0;
                bandera++;
                mostrarsinFS5();

            }
            }
        }
    }
    while(bandera<3);
}
