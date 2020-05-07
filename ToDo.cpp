#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

typedef struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

void cargarTareas(Tarea **TareasPendientes,int cantTareas);
void BuscarTareaPorPalabra(Tarea **TareasPendientes,int cantTareas);
void controlar(Tarea **TareasPendientes, int cantTareas);
void mostrar(Tarea **TareasPendientes, Tarea **TareasRealizadas, int cantTareas, int contador);

int main(void) {
  srand(time(NULL));
  int cantTareas, tamanio, respuesta;
  char desc[MAX];
  Tarea **TareasPendientes;
  printf("Ingrese la cantidad de tareas a cargar\n");
  scanf("%d", &cantTareas);
  getchar();

  TareasPendientes = (Tarea **)malloc(sizeof(Tarea *)*cantTareas);
  cargarTareas(TareasPendientes, cantTareas);
  BuscarTareaPorPalabra(TareasPendientes, cantTareas);
  //controlar(TareasPendientes, cantTareas);
  
  return 0;
}

void cargarTareas(Tarea **TareasPendientes,int cantTareas){
  int tamanio;
  char desc[MAX];
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
}

void BuscarTareaPorPalabra(Tarea **TareasPendientes,int cantTareas){
  char palabra[MAX];
  Tarea **TareaBuscada;
  TareaBuscada = (Tarea **) malloc(sizeof(Tarea *));
  printf("Ingrese la descripcion de la tarea que busca\n");
  fflush(stdin);
  gets(palabra);
  for(int i=0; i<cantTareas; i++){
    if(strcmp(TareasPendientes[i]->Descripcion,palabra) == 0){
      TareaBuscada[i] = TareasPendientes[i];
      printf("==================== Tarea Buscada ================\n");
      printf("ID: %d\n", TareasPendientes[i]->TareaID);
      printf("Descripcion: %s\n", TareasPendientes[i]->Descripcion);
      printf("Duracion: %d\n", TareasPendientes[i]->Duracion);
    }
  }
}


void controlar(Tarea **TareasPendientes, int cantTareas){
  int respuesta, contador=0;
  Tarea **TareasRealizadas;
  TareasRealizadas = (Tarea **)malloc(sizeof(Tarea *)*cantTareas);
  for(int j=0; j<cantTareas; j++){
    printf("================ Tarea N° %d =================\n",j+1);
    printf("ID: %d\n",TareasPendientes[j]->TareaID);
    printf("Descripcion: %s\n",TareasPendientes[j]->Descripcion);
    printf("Duracion: %d\n", TareasPendientes[j]->Duracion);
    printf("\n¿Esta tarea fue realizada? Ingrese 1(si) o 0(no)\n");
    fflush(stdin);
    scanf("%d", &respuesta);
    if(respuesta == 1){
      TareasRealizadas[contador] = TareasPendientes[j];
      TareasPendientes[j] = NULL;
      //printf("ID: %d", TareasRealizadas[contador]->TareaID);
      contador++;
    }
  }
  mostrar(TareasPendientes,TareasRealizadas, cantTareas, contador);
}

void mostrar(Tarea **TareasPendientes, Tarea **TareasRealizadas, int cantTareas, int contador){
  printf("\n\n================= Tareas Pendientes ================\n");
  for(int i=0; i<cantTareas-contador; i++){
    printf("================= Tarea N° %d =================\n",TareasPendientes[i]->TareaID);
    printf("ID: %d\n",TareasPendientes[i]->TareaID);
    printf("Descripcion: %s\n",TareasPendientes[i]->Descripcion);
    printf("Duracion: %d\n", TareasPendientes[i]->Duracion);
  }

  printf("\n\n================= Tareas Realizadas ================\n");
  for(int j=0; j<contador; j++){
    printf("================= Tarea N° %d =================\n",TareasRealizadas[j]->TareaID);
    printf("ID: %d\n",TareasRealizadas[j]->TareaID);
    printf("Descripcion: %s\n",TareasRealizadas[j]->Descripcion);
    printf("Duracion: %d\n", TareasRealizadas[j]->Duracion);
  }
}