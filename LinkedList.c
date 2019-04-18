#include<stdio.h>
#include<stdlib.h>
struct ts
{
  int data;
  struct ts *next;
};
struct ts *head=NULL;
struct ts *curr=NULL;
int cnt=0;
struct ts* createNode(int val)
{
  struct ts *tmp=(struct ts*)malloc(sizeof(struct ts));
  tmp->data=val;
  tmp->next=NULL;
  return tmp;
}
struct ts* createList(int val, int pos)
{
  struct ts* ptr;
  ptr=createNode(val);
  if(pos==0)
  {
    if(head==NULL)
    {
      head=ptr;
      curr=ptr;
    }
    else
    {
      ptr->next=head;
      head=ptr;
      cnt++;
    }
  }  
  else if(pos>0)
  {
    struct ts* tmp=head;
    struct ts* prev=head;
    int cntr=0;
    while(tmp!=NULL)
    {
      if(pos==cntr)
      {
        prev->next=ptr;
        ptr->next=tmp;
        cnt++;
        cntr=0;
        return ptr;
      }
      else
      {
        prev=tmp;
        tmp=tmp->next;
        cntr++;
      }
    }
    if(pos==(cnt+1))
    {
      curr->next=ptr;
      curr=ptr;
      cnt++;
    }
    else
      printf("\nCannotinsert at position %d\n",pos);
  }
}
void printData()
{
  struct ts* ptr=head;
  printf("\nvalues are:::::\n");
  while(ptr!=NULL)
  {
    printf("%d\n",ptr->data);
    ptr=ptr->next;
  }
  
}
int main()
{
  struct ts* ptr;
  for(int i=1;i<5;i++)
  {
    ptr=createList(i,(i-1));
  }
  ptr=createList(8,1);
  ptr=createList(12,5);
  ptr=createList(40,4);
  printData();
  return 0;
}
