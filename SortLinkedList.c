#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int num;
  struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
NodePtr findLargestNode(NodePtr);
NodePtr addToHead(NodePtr, int);
NodePtr moveToHead(NodePtr, NodePtr);
NodePtr sortList(NodePtr);
NodePtr previous(NodePtr, NodePtr);
void printList(NodePtr);

int main(){
  int values[] = {40, 15, 1, 6, 2};
  NodePtr top, tail;
  top = tail = NULL;

  int i;

  for(i = 0; i < 5; i++){
    top = addToHead(top, values[i]);
  }

  printList(top);

  printf("New list\n");
  top = sortList(top);
  printList(top);

  return 0;
}

NodePtr sortList(NodePtr head){
  if(head == NULL)return NULL;
  else{
    NodePtr largest = findLargestNode(head);
    head = moveToHead(head, largest);
    head->next = sortList(head->next);
    return head;
  }
}


NodePtr moveToHead(NodePtr head, NodePtr node){
  NodePtr prev = previous(head, node);
  if(prev!=NULL){
    prev->next = node->next;
    node->next = head;
    head = node;
  }
  return node;
}


NodePtr makeNode(int n){
  NodePtr np = (NodePtr)malloc(sizeof(Node));
  np->num = n;
  np->next = NULL;
  return np;
}

NodePtr findLargestNode(NodePtr head){
    NodePtr np = makeNode(-1);

    while(head!=NULL){
      if(np->num <= head->num)np = head;
      head = head->next;
    }
    return np;
}

NodePtr previous(NodePtr head, NodePtr position){
    while(head!=NULL && head->next!= position)
      head = head->next;
    return head;
}

NodePtr addToHead(NodePtr head, int n){
  NodePtr np = makeNode(n);
  if(head == NULL)head = np;
  else{
    np->next = head;
    head = np;
  }
  return head;
}

void printList(NodePtr head){
  while(head!=NULL){
    printf("%d ", head->num);
    head = head->next;
  }
  printf("\n");
}
