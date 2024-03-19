#define  _CRT_SECURE_NO_WARNINGS
#include "Depot.h"

Depot::Depot(const char* name) : num(0)
{
  strncpy(depot_id, name, DEPOT_ID_MAX);
  for(int i=0; i<MAX_TRANS; i++){
    atbase[0] = nullptr;
  }
}

void Depot::operator+=(Tram&){
}

void Depot::send_first(){
}

int Depot::atBase(){
return 0;
}
