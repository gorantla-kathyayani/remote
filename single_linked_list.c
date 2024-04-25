#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *next;
	int data;
};
struct node *head=NULL;
struct node *newnode,*temp;
int len=0;
/* Creating the list  */
void create_node()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("ENTER THE DATA: ");
	scanf("%d",&newnode->data);
	getchar();
	newnode->next=NULL;
	if(head==NULL)
	{
		head=temp=newnode;
	}
	else	
	{
		temp->next=newnode;
		temp=newnode;
	}
}

/* Displaying the list   */
void display_node()
{
	len=1;
	temp=head;
	if(head==NULL)
	{
		printf("empty list\n");
		return;
	}
	printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("%d-->",temp->data);
	while(temp->next!=NULL)
	{
		temp=temp->next;
		printf("%d-->",temp->data);
		len++;
	}
	printf("NULL\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
}

/* Delete all the nodes bigger than the given list */
void del_big_nodes(int val)
{
	if(head==NULL)
	{
		printf("Invalid list---create the list 1st\n");
		return;
	}
	temp=head;
	struct node *t1;
	while(temp!=NULL&&temp->data>val)
	{
		t1=temp;
		head=temp->next;
		temp=head;
		free(t1);
		len--;
	}

	t1=temp;
	if(temp!=NULL)
		temp=temp->next;
	while(temp!=NULL) 
	{
		if(temp->data>val)
		{
			t1->next=temp->next;
			free(temp);
			temp=t1->next;
			len--;
		}
		else
		{
			t1=temp;
			temp=temp->next;
		}
	}
}

//Delete all nodes between given numbers                      finddddddddddddd
void del_bet_nodes(int data1,int data2)
{
	if(head==NULL)
        {
                printf("Invalid----create the list first\n");
                return;
        }
	temp=head;
	struct node *t1;
	while(temp!=NULL && ((temp->data>data1 && temp->data<data2)||(temp->data<data1 && temp->data>data2)))
	{
		head=temp->next;
		free(temp);
		temp=head;
		len--;

	}
	t1=temp;
        if(temp!=NULL)
                temp=temp->next;

	while(temp!=NULL)
	{
		if((temp->data>data1&& temp->data<data2)||(temp->data<data1 && temp->data>data2))
		{
			t1->next=temp->next;
			free(temp);
			temp=t1->next;
			len--;
		}
		else
		{
			t1=temp;
			temp=temp->next;
		}
	}
}	

// Delete all nodes less than given number from the list
void del_small_nodes(int val)
{
	struct node *t1;
	if(head==NULL)
        {
                printf("Invalid----create the list first\n");
                return;
        }

	temp=head;
	while(temp!=NULL&&temp->data<val)
	{
		t1=temp;
		head=temp->next;
		temp=temp->next;
		free(t1);
		len--;
	}
	t1=temp;
	if(temp != NULL)
		temp = temp->next;

	while(temp!=NULL) 
	{
		if(temp->data<val)
		{
			t1->next=temp->next;
			free(temp);
			temp=t1->next;
			len--;
		}
		else
		{
			t1=temp;
			temp=temp->next;
		}
	}
}

// Delete all nodes other than between given numbers
void del_non_bet_nodes(int data1,int data2)
{
	if(head==NULL)
        {
                printf("Invalid----create the list first\n");
                return;
        }
	temp=head;
	struct node *t1;
	while((temp!=NULL) && ((temp->data>data1 || temp->data<data2)&&(temp->data<data1 || temp->data>data2)))
        {
                t1=temp;
                temp=temp->next;
                head=temp;
                free(t1);
		len--;
	}
	t1=temp;
	if(temp!=NULL)
	{
		temp=temp->next;
	}

        while(temp!=NULL)
        {
                if((temp->data<data1 || temp->data>data2)&&(temp->data>data1 || temp->data<data2))
                {
                        t1->next=temp->next;
                        free(temp);
			temp=t1->next;
			len--;
                }
                else
                {
			t1=temp;
            		temp=temp->next;
                }
        }

}


// Deleting the node at given position
void del_pos(int pos)
{
	if(head==NULL||pos<=0||pos>len)
        {
                printf("Invalid position\n");
                return;
        }
	temp=head;
	struct node *t1;
	int count=1;
	while(count<(pos-1))
	{
		temp=temp->next;
		count++;
	}
	if(pos==1)
	{
		t1=head;
		head=temp->next;
		free(t1);
		len--;
	}
	else
	{
		t1=temp->next;
		temp->next=temp->next->next;
		free(t1);
                len--;
	}
}

// Delete the node at a given position from end
void del_pos_end(int pos)
{
	int x=pos;
	if(head==NULL||pos<=0||pos>len)
        {
                printf("Invalid position\n");
                return;  
        }
	temp=head;
	struct node *t1=head;
	struct node *t2=NULL;
	for(int i=1;i<pos;i++)
	{
		if(temp==NULL)
		{
			return;
		}
		temp=temp->next;
	}

	while(temp->next!=NULL)
	{
		t2=t1;
		t1=t1->next;
		temp=temp->next;
	}
	if(t2==NULL)
	{
		head=head->next;
	}
	else
	{
		t2->next=t1->next;
	}
	free(t1);
	len--;
}

// Delete all nodes from a given position to beginning from end
void del_nodes_pos_beg_end(int pos)
{
	printf("len=%d\n",len);
	if(head==NULL|| pos<=0)
        {
                printf("Invalid position\n");
                return;
        }
	temp=head;
	struct node *t1;
	int p=len-pos+1;
	int count=1;
	while(count<p)
	{
		t1=temp;
		temp=temp->next;
		head=temp;
		free(t1);
		count++;
		len--;
	}
}

// Delete the node from list based on data after given occurrence
void del_pos_occur(int data,int occur)
{
	if(head==NULL||occur<0)
        {
                printf("Invalid occurance or no nodes\n");
                return;
        }
	temp=head;
	int count=0,flag=0;
	struct node *t1=NULL;
	while(temp!=NULL)
	{
		if(temp->data==data)
		{
			count++;
			if(count>occur)
			{
				flag=1;
				if(t1==NULL)
				{
					head=temp->next;
					free(temp);
					temp=head;
				}
				else
				{
					t1->next=temp->next;
					free(temp);
					temp=t1->next;
				}
				continue;
			}
		}
		t1=temp;
		temp=temp->next;
	}
        if(!flag)
        {
            printf("Nodes having data %d more than %d occurences not found\n",data,occur);
        }

}


// Delete all nodes at a given position from end
void del_all_pos_end(int pos)
{
	if(head==NULL||pos<=0||pos>len)
	{
		printf("invalid position\n");
		return;
	}
	temp=head;
        struct node *t1=head;
        struct node *t2=NULL;
        for(int i=1;i<pos;i++)
        {
                if(temp==NULL)
                {
                        return;
                }
                temp=temp->next;
        }

        while(temp->next!=NULL)
        {
                t2=t1;
                t1=t1->next;
                temp=temp->next;
        }
        if(t2==NULL)
        {
                head=NULL;
        }
        else
        {
                t2->next=NULL;
        }
	while(t1!=NULL)
	{
		struct node *q=t1;
		t1=t1->next;
		free(q);
		len--;
	}
}

int main()
{
	int select,val,pos;
	int data1,data2,data,occur;
	while(1)
	{
		printf("\n\n__________***********_________\n");
		printf("1.create_node\n2.display_nodes\n3.del_big_than_given_no\n4.del_nodes_bet_no.\n5.del_less_than_given_no:\n6.del_non_bet_nos:\n7.del_pos\n8.del_pos_end\n9.del_pos_beg_from_end\n10.del_occ\n11.del_all_pos_to_end\n");
		printf("__________***********__________\n\n");
		printf("select case :");
		scanf("%d",&select);
		switch(select)
		{
			case 1: /* Creating the list */ 
				create_node();
				break;

			case 2: /* Displaying the list */
				display_node();
				break;

			case 3:  /* Delete all nodes bigger than given data from the list */
				printf("enter a value to delete greater elements:");
				scanf("%d",&val);
				del_big_nodes(val);
				break;

			case 4:  /* Delete all nodes between given numbers */ 
				printf("enter the values to delete between the no:");
				scanf("%d %d",&data1,&data2);
				del_bet_nodes(data1,data2);
				break;

			case 5:  /* Delete all nodes less than given number from the list */
				printf("enter a value to delete all node smaller than that value:");
				scanf("%d",&val);
				del_small_nodes(val);
				break;

			case 6:  /* Delete all nodes other than between given numbers */
				printf("enter values to delete all other than between the numbers");
                                scanf("%d %d",&data1,&data2);
				del_non_bet_nodes(data1,data2);
				break;

			case 7:   /* Delete node at given position  */
				printf("enter deleting position:");
				scanf("%d",&pos);
				del_pos(pos);
				break;

			case 8: /* Delete the node at a given position from end */
				printf("enter deleting position from end:");
				scanf("%d",&pos);
				del_pos_end(pos);
				break;
				
			case 9: /* Delete all nodes from a given position to beginning from end */
				printf("enter position to delete the nodes to positon from end:");
				scanf("%d",&pos);
				del_nodes_pos_beg_end(pos);
				break;

			case 10: /* Delete the node from list based on data after given occurrence */
				printf("enter the data:");
				scanf("%d",&data);
				printf("enter occurence from where it is deleted");
				scanf("%d",&occur);
				del_pos_occur(data,occur);
				break;
			case 11: /*  Delete all nodes at a given position from end */
				printf("enter postion to delete all nodes from end:");
				scanf("%d",&pos);
				del_all_pos_end(pos);
				break;

			default:
				printf("select the correct the number\n");
				break;
		}
	}
}


