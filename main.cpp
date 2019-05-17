#include <stdio.h>
#include <stdlib.h>



struct node //yek sakhtar gere dorost mikonim, ke daray do farzand chap va rast ast
{
     int data;
     struct node* chap;
     struct node* rast;
};



struct node* nodejadid(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));//yek hafeze barmidarad
     node->data = data;
     node->chap = NULL;//farzand chap  va rast khali hastand
     node->rast = NULL;
     return(node);
}
void p(struct node* node)//yek tabe tarif kardim baray print kardan
{
     if (node == NULL)//agar node resid be hich yani ta ongh raftim va tamam
          return;
     p(node->chap);//farzand rast ra print kon
     printf("%d ", node->data);//data node ra print kon
     p(node->rast);//farzand rast ra print kon
}
/*
dar asl be in shekl mishe :
        1
       / \
      /   \
     2     3
    / \     \
   /   \     \
  4     5     6


  va be in shekl neshan mide:

  4  2  5  1  3  6
*/

void swaptree(struct node*node)//hala baray jabeja kardan tabe tarif mikonim
{
  if(node==NULL) return; //agar node vojod nadash ya be tah drakht residim
  struct node*temp=node->chap;//vagarna farzand chap ra beriz to temp
  node->chap=node->rast;//farzand rast ra beriz dar chap
  node->rast=temp;// va bad temp beriz dat farzand rast
  swaptree(node->chap);//sepas khod ra farakhani kon va baray farzand rast va chp ham kamin kar ro bokon
  swaptree(node->rast);
}
int main()
{
     struct node *root  = nodejadid(1);
     root->chap         = nodejadid(2);
     root->rast         = nodejadid(3);
     root->chap->chap   = nodejadid(4);
     root->chap->rast   = nodejadid(5);
     root->rast->rast   = nodejadid(6);
     root->rast->chap   = nodejadid(7);
     root->rast->rast->rast   = nodejadid(8);


//__________________________________________________________-
     printf("\n vorodi dade shode : \n");
     p(root);

     swaptree(root);

     printf("\n vorodri khoroji:  \n");
     p(root);
//__________________________________________________________-
      return 0;
}
