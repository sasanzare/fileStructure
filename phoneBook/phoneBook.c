#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 20
struct person {
  char Name[MAX_LENGTH];
  char Postal_Code[MAX_LENGTH];
  char Phone[MAX_LENGTH];
};
/*
  Add
*/
void add() {
  FILE * f, * frb;
  int flag = 1,i = 0;
  struct person p, q;
  char name[MAX_LENGTH];
  f = fopen("phonebook.bin", "rb+");
  printf("\n\rEnter Name : ");
  scanf("%s", q.Name);
  for(;i<=strlen(q.Name);i++){
      if(q.Name[i]>=97&&q.Name[i]<=122){
        q.Name[i]=q.Name[i]-32;
      }
   }
  printf("\n\rEnter Postal Code : ");
  scanf("%s", q.Postal_Code);
  printf("\n\rEnter Phone : ");
  scanf("%s", q.Phone);
  if (f == NULL) {
    frb = fopen("phonebook.bin", "ab+");
    fwrite( & q, sizeof(q), 1, frb);
    fflush(stdin);
    printf("\n\rPhone Number Saved.\n\r\n\r------------------------------------");
    fclose(frb);
  } else {
    while (fread( & p, sizeof(p), 1, f) == 1) {
      if (strcmp(q.Phone, p.Phone) == 0) {
        fseek(f, -sizeof(p), SEEK_CUR);
        fwrite( & q, sizeof(p), 1, f);
        flag = 0;
        break;
      }
      fflush(stdin);
    }
    if (flag) {
      frb = fopen("phonebook.bin", "ab+");
      fwrite( &q, sizeof(q), 1, frb);
      fflush(stdin);
      printf("\n\rPhone Number Saved.\n\r\n\r------------------------------------");
      fclose(frb);
    }
    fclose(f);
  }
}
/*
  List
*/
void list() {
  struct person p;
  FILE * f;
  f = fopen("phonebook.bin", "rb");
  if (f == NULL) {
    printf("\n\rFILE OPENING ERROR !\n\r\n\r------------------------------------");
    exit(1);
  }
  while (fread( & p, sizeof(p), 1, f) == 1) {
    printf("\n\r\n\rName : %s\n\r\n\rPostal Code : %s\n\r\n\rPhone : %s\n\r\n\r------------------------------------", p.Name, p.Postal_Code, p.Phone);
  }
  fclose(f);
}
/*
  Sort
*/
void sort(){
  struct person sort[1000];
  int i=0,k,m=0,j;
  char temp[MAX_LENGTH];
  struct person p;
  FILE * f;
  f = fopen("phonebook.bin", "rb");
  if (f == NULL) {
    printf("\n\rFILE OPENING ERROR !\n\r\n\r------------------------------------");
    exit(1);
  }
  while (fread( &p, sizeof(p), 1, f) == 1) {
    strcpy(sort[i].Name, p.Name);
    strcpy(sort[i].Postal_Code, p.Postal_Code);
    strcpy(sort[i].Phone, p.Phone);
    i++;
  }
  fclose(f);
    for(;m<i;m++){
        for(j=m+1;j<i;j++){
         if(strcmp(sort[m].Name,sort[j].Name)>0){
            strcpy(temp,sort[m].Name);
            strcpy(sort[m].Name,sort[j].Name);
            strcpy(sort[j].Name,temp);
         }
      }
    }

  for (k=i-1;k>=0;k--) {
      printf("\n\r\n\rName : %s\n\r\n\rPostal Code : %s\n\r\n\rPhone : %s\n\r\n\r------------------------------------",sort[k].Name,sort[k].Postal_Code,sort[k].Phone);
  }
}
/*
  Search
*/
void search() {
  struct person p;
  FILE * f;
  char name[MAX_LENGTH];
  int count = 1,i=0;
  f = fopen("phonebook.bin", "rb");
  if (f == NULL) {
    printf("\nError In Opening !\n\r\n\r------------------------------------");
    exit(1);
  }
  printf("\nEnter Name Of Person To Search : ");
  scanf("%s", name);
  for(;i<=strlen(name);i++){
      if(name[i]>=97&&name[i]<=122){
        name[i]=name[i]-32;
      }
   }
  while (fread( & p, sizeof(p), 1, f) == 1) {
    if (strcmp(p.Name, name) == 0) {
      printf("\n\rPhone Number : %s\n\r\n\r------------------------------------", p.Phone);
      count = 0;
    }
  }
  if (count) {
    printf("PERSON NOT FOUND !\n\r\n\r------------------------------------");
  }
  fclose(f);
}
/*
  Delete
*/
void delete() {
  struct person p;
  FILE * f, * ft;
  int flag,i=0;
  char name[MAX_LENGTH];
  f = fopen("phonebook.bin", "rb");
  if (f == NULL) {
    printf("PHONE NUMBER NOT ADDED YET !\n\r\n\r------------------------------------");
  } else {
    ft = fopen("temp", "wb+");
    if (ft == NULL) {
      printf("FILE OPENING ERROR !\n\r\n\r------------------------------------");
    } else {
      printf("Enter Name : ");
      scanf("%s",name);
      for(;i<=strlen(name);i++){
        if(name[i]>=97&&name[i]<=122){
          name[i]=name[i]-32;
        }
      }
      fflush(stdin);
      while (fread( &p, sizeof(p), 1, f) == 1) {
        if (strcmp(p.Name, name) != 0)
          fwrite( & p, sizeof(p), 1, ft);
        if (strcmp(p.Name, name) == 0)
          flag = 1;
      }
      fclose(f);
      fclose(ft);
      if (flag != 1) {
        printf("NO CONTACT'S RECORD TO DELETE !\n\r\n\r------------------------------------");
        remove("temp");
      } else {
        remove("phonebook.bin");
        rename("temp", "phonebook.bin");
        printf("\n\rCONTACT DELETED SUCCESSFULLY.\n\r\n\r------------------------------------");
      }
    }
  }
}

/*
  main
*/
int main() {
  int n;
  printf("\n\r===========  HOMEWORK 1 CREATED BY SASAN ZARE  ===========");
  while (1) {
    printf("\n\r\n\r1-Add\n\r2-List\n\r3-Search\n\r4-Sort\n\r5-Delete\n\r6-Exit\n\rPlease Enter Your Chosen Number : ");
    scanf("%d", & n);
    system("clear"); //  For gcc/g++ compiler in Linux
    switch (n) {
    case 1:add();break;
    case 2:list();break;
    case 3:search();break;
    case 4:sort();break;
    case 5:delete();break;
    case 6:printf("\n\r===========  Have a Good Time ===========\n\r");exit(1);
    default:;
    }
  }
  return 0;
}
