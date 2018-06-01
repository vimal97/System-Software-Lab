
#define TQUANT 4 
int currentQuant; 
void selectNextProcess() 
{ 
struct process *temp; 
if(current!=NULL) 
{ 
currentQuant++; 
if(current->completedtime==current->bt||currentQuant==TQUANT) 
{ 
temp=queue; 
while(temp->next!=NULL) 
temp=temp->next; 
temp->next=queue; 
queue=queue->next; 
temp->next->next=NULL; 
current=NULL; 
} 
} 
if(current==NULL) 
{ 
temp=queue; 
while(temp!=NULL) 
{ 
if(temp->completedtime<temp->bt) 

{ 
current=temp; 
currentQuant=0; 
break; 
} 
temp=temp->next; 
} 
} 
} 

