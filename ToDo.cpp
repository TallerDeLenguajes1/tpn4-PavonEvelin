#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100
​
typedef struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;
​
void cargarTareas(Tarea ***TareasPendientes,int cantTareas);
​
int main(void) {
  srand(time(NULL));
  int cantTareas, tamanio, respuesta;
  char desc[MAX];
  Tarea **TareasPendientes, **TareasRealizadas;
  printf("Ingrese la cantidad de tareas a cargar\n");
  scanf("%d", &cantTareas);
  getchar();
​
  TareasPendientes = (Tarea **)malloc(sizeof(Tarea *)*cantTareas);
  TareasRealizadas = (Tarea **)malloc(sizeof(Tarea *)*cantTareas);
​
  for(int i=0; i<cantTareas; i++){
    TareasPendientes[i] = (Tarea *)malloc(sizeof(Tarea));
    TareasPendientes[i]->TareaID = i+1;
    printf("Escriba una descripcion acerca de la tarea\n");
    gets(desc);
    tamanio = strlen(desc);
    TareasPendientes[i]->Descripcion = (char *)malloc(sizeof(char)*tamanio);
    strcpy(TareasPendientes[i]->Descripcion, desc);
    TareasPendientes[i]->Duracion = rand()%91 +10;
  }
​
  for(int j=0; j<cantTareas; j++){
    printf("================ Tarea N° %d =================\n",j+1);
    printf("ID: %d\n",TareasPendientes[j]->TareaID);
    printf("Descripcion: %s\n",TareasPendientes[j]->Descripcion);
    printf("Duracion: %d\n", TareasPendientes[j]->Duracion);
    printf("\n¿Esta tarea fue realizada? Ingrese 1(si) o 0(no)\n");
    scanf("%d", &respuesta);
    if(respuesta == 1){
      TareasRealizadas[j] = (Tarea *)malloc(sizeof(Tarea));
      TareasRealizadas[j] = TareasPendientes[j];
      TareasPendientes[j] = NULL;
      printf("ID: %d", TareasPendientes[j]->TareaID);
    }
  }
  
  
  
  
  
  
  
  
  
  //CARGA DE TAREAS
  //cargarTareas(&TareasPendientes, cantTareas);
  
  return 0;
}
​
void cargarTareas(Tarea ***TareasPendientes,int cantTareas){
  char descripcion[MAX];
  int tamanio;
  for(int i=0; i<cantTareas; i++){
    *TareasPendientes[i]=(Tarea *)malloc(sizeof(Tarea));
    (*TareasPendientes)[i]->TareaID = i+1;
    printf("Escriba una descripción acerca la tarea\n");
    fflush(stdin);
    gets(descripcion);
    tamanio = strlen(descripcion);
    (*TareasPendientes)[i]->Descripcion = (char *)malloc(sizeof(char)*tamanio);
    strcpy((*TareasPendientes)[i]->Descripcion, descripcion);
    (*TareasPendientes)[i]->Duracion = rand()%91 +10;
​
    printf("Id: %d", (*TareasPendientes)[i]->TareaID);
  }
}





