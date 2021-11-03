#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 2 //Ventas
#define TAMcombustible 4 //tipos combus

struct eSurtidor{

  char combustible[4][20]; //tipo
  int litros;
};

struct ePlayero{

   char nombre[4][20];
   int surt; //surtidor
   int carga;

   struct eSurtidor surtidor;
};

//--Pr y func

int numeroAleatorio(int desde, int hasta,int iniciar);
int valida_surtidor(int surtidor);
int valida_opcionCombustibles(int opcion);
void cantidad_litros(int tam, int surtidor[], struct ePlayero playero[]);
void write_Archivo(int tam, struct ePlayero playero[]);

void surtidorMasUsado(int tam, struct ePlayero playero[]);

int main(){

    struct ePlayero playero[TAM];
    int i, numSurtidor, ns, op, lt, opLimpia;
    int acum=0;

     printf("\nNUESTROS EMPLEADOS - Javier, Jose y Victoria\n");
     for(i=0; i<TAM; i++){ //entra data

         fflush(stdin);
         printf("\nNombre Playero: ");
         gets(playero->nombre[i]);
         strlwr(playero->nombre[i]); //Minuscula

         printf("\nNum surtidor 1 / 4: ");
         scanf("%d", &numSurtidor);

         ns = valida_surtidor(numSurtidor);

         playero[i].surt = ns;


            if( playero[i].surt==1 ||  playero[i].surt==2
               || playero[i].surt ==3 || playero[i].surt ==4){


                printf("COMBUSTIBLES YPF\n");
                printf("\n1.NAFTA SUPER");
                printf("\n2.NAFTA PREMIUM");
                printf("\n3.DIESEL SUPER");
                printf("\n4.DIESEL PREMIUM");
                printf("\n\nOpcion a cargar: ");
                scanf("%d", &op);

                opLimpia = valida_opcionCombustibles(op);

                switch(opLimpia){

                 case 1: //n Super
                       printf("\nCOMBUSTIBLE SELECCIONADO - Nafta Super\n");
                       strcpy(playero[i].surtidor.combustible, "Nafta Super");

                       /*
                       printf("Nafta super\n");
                       printf("\nIngrese cant de litros: ");
                       scanf("%d", &playero[i].surtidor.litros); */

                       lt = numeroAleatorio(0, 1000, 1);

                       playero[i].surtidor.litros = lt;

                       printf("LITROS INGRESADOS: %d", playero[i].surtidor.litros);

                       printf("\nCarga realizada con exito!!\n");

                    break;

                 case 2: //n premium
                       printf("\nCOMBUSTIBLE SELECCIONADO - Nafta Premium\n");
                       strcpy(playero[i].surtidor.combustible, "Nafta Premium");

                       lt = numeroAleatorio(0, 1000, 1);

                       playero[i].surtidor.litros = lt;

                       printf("LITROS INGRESADOS: %d", playero[i].surtidor.litros);

                       printf("\nCarga realizada con exito!!\n");

                    break;


                 case 3: //n premium
                       printf("\nCOMBUSTIBLE SELECCIONADO - Diesel Super\n");

                       strcpy(playero[i].surtidor.combustible, "Diesel Super");

                       lt = numeroAleatorio(0, 1000, 1);

                       playero[i].surtidor.litros = lt;

                       printf("LITROS INGRESADOS: %d", playero[i].surtidor.litros);

                       printf("\nCarga realizada con exito!!\n");


                    break;

                 case 4: //n premium
                       printf("\nCOMBUSTIBLE SELECCIONADO - Diesel Premium\n");
                       strcpy(playero[i].surtidor.combustible, "Diesel Premium");

                       lt = numeroAleatorio(0, 1000, 1);

                       playero[i].surtidor.litros = lt;

                       printf("LITROS INGRESADOS: %d", playero[i].surtidor.litros);

                       printf("\nCarga realizada con exito!!\n");


                    break;


                 default:

                       printf("No existe opcion combustible");

                }//switch

             }//if
      }



     surtidorLitros_cant(TAM, playero); // 3

     surtidorMasUsado(TAM, playero); // 4


    //Prototipo
     printf("\n\tDATOS CARGADOS EN EL ARCHIVO!!");
     write_Archivo(TAM, playero);


    return 0;
}




//////  -------------PARSARLO A FUNCIONES.H Y FUNCIONES. C

/**
  Numero aleatorio (GENERA LA CANTIDAD DE LITROS!!)
*/

int numeroAleatorio(int desde, int hasta,int iniciar){

  if(iniciar)
      srand(time(NULL));
  return desde + (rand()%(hasta + 1 - desde));

}


/***
param : surtidor (hace referencia al numero ingresado por teclado)

Valido numero surtidor entre 1 y 4( a 3 intentos)
**/

int valida_surtidor(int surtidor){

      int i;

      while(i<3){

          if(surtidor ==1 || surtidor ==2 ||
             surtidor ==3 || surtidor == 4){

             //system("cls");

             printf("\n--------------------------------------");
             printf("\n\tSURTIDOR %d  DISPONIBLE \n", surtidor);
             printf("--------------------------------------\n");
             break;

          }else if(surtidor !=1 || surtidor !=2 ||
                   surtidor !=3 || surtidor !=4){

            fflush(stdin);
            printf("\n\tERROR!. Reingrese surtidor: "); scanf("%d", &surtidor);
          }

          i++;

      }//val while

    return surtidor;
}


/***
param : valido la opcion de los tipos de combustibles(hace referencia al numero ingresado por teclado)

Valido numero surtidor entre 1 y 4( a 3 intentos)
**/

int valida_opcionCombustibles(int opcion){

      int i;
      int op;

      while(i<3){

          if(opcion ==1 || opcion ==2 ||
             opcion ==3 || opcion == 4){

             printf("\nOpcion combustible correcta\n");
             break;

          }else if(opcion !=1 || opcion !=2 ||
                   opcion!=3 || opcion !=4){

             printf("\n\tERROR. reingrese opcion: ");
             fflush(stdin);
             scanf("%d", &opcion);
          }

          i++;

      }//val while


    return opcion;
}



void surtidorLitros_cant(int tam, struct ePlayero playero[]){

 int i, acum1=0, acum2=0, acum3=0, acum4=0;

    for(i=0; i<tam; i++){

         if(playero[i].surt == 1){

            acum1 += playero[i].surtidor.litros;

         }else if(playero[i].surt == 2){

            acum2 += playero[i].surtidor.litros;

         }else if(playero[i].surt == 3){

            acum3 += playero[i].surtidor.litros;

         }else{

            acum4 += playero[i].surtidor.litros;

         }
     }

     printf("\nLITROS SURTIDOR 1: %d", acum1);
     printf("\nLITROS SURTIDOR 2: %d", acum2);
     printf("\nLITROS SURTIDOR 3: %d", acum3);
     printf("\nLITROS SURTIDOR 4: %d", acum4);
}


/** \brief Este procedimiento se encarga de informar cuandtas veces fue utlizado un surtidor
 */

void surtidorMasUsado(int tam, struct ePlayero playero[]){

  int i, cont=0;
  int elMasUsado;

        for(i=0; i<tam; i++){
          //for(j=i+1; j<tam; j++){

            if(playero[i].surt == elMasUsado){

                elMasUsado = playero[i].surt;
                cont++;

             }

        }//for

        printf("\nEl surtidor mas usado fue el: %d  - cant de veces: %d", elMasUsado
               , cont);

}



/** \brief GUARDO LOS DATOS EN EL ARCHIVO!!
 *
 * \param int tam
 * \param int surtidor (dato limpio - ya validado)
 * \param estructura del empleado
 *
 */

void write_Archivo(int tam, struct ePlayero playero[]){

    int i;
    FILE *f;

    f = fopen("Ventas.txt", "w");

      fprintf(f,"\nVentas del Mes: Estacion de Servicio YPF\n\n");
      fprintf(f, "\n CARGA   -  PLAYERO   - SURTIDOR  -   TIPO COMBUSTIBLE  - LITROS");


      for(i=0; i<tam; i++){ //entre data

         fprintf(f,"\n%d       -    %s     -   %d       -    %s     -   %d", i+1, playero->nombre[i],
                 playero[i].surt, playero[i].surtidor.combustible  , playero[i].surtidor.litros);

      }

    fclose(f);

}



