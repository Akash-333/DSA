#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 25

struct playlist
{
	char songName[MAXSIZE];	        //data members of a dll
	char singerName[MAXSIZE];
	float songSize;
	char movieName[MAXSIZE];

	struct playlist *next;		//Link part of dll
	struct playlist *previous;
};
typedef struct playlist *NODE;

//Function prototyping

NODE DLLgetNewNode();
NODE DLLinsertAtFront(NODE);
NODE DLLinsertAtEnd(NODE);
NODE DLLinsertAfter(NODE, char[]);

NODE DLLdeleteSpecific(NODE, char[]);
void DLLdisplayPlaylist(NODE);

void searchBySinger(NODE,NODE, char[]);

NODE playSong(NODE, NODE, char[]);
NODE playNextSong(NODE playing);
NODE playPreviousSong(NODE);
NODE search(NODE,NODE, char[]);


// Main function definition
int main()
{
    int choice=0;
    char key[MAXSIZE];
    char songKey[MAXSIZE];
    char singerNameKey[MAXSIZE];
    NODE playing=NULL;
    NODE head=NULL;
    while(1)
    {
    printf("\n___________\nMusic Player\n___________\n");
	printf("\nMenu:\n====================\n");
	printf("\n1.Insert song at the beginning of the playlist");
	printf("\n2.Insert song at the end of the playlist");
	printf("\n3.Insert song after");
	printf("\n4.Display playlist");
	printf("\n5.Play song");
	printf("\n6.Play next song");
	printf("\n7.Play previous song");
	printf("\n8.to search");
	printf("\nOther:Exit application\n____________________\n");
	printf("Enter your choice: ");
    	scanf("%d",&choice);


switch(choice)
        {
            case 1: head=DLLinsertAtFront(head);
                    break;
            case 2: head=DLLinsertAtEnd(head);
                    break;
           case 3: printf("Enter the song after which the read song has to be entered: ");
                    scanf("%s",songKey);
                    head=DLLinsertAfter(head, songKey);
                    break;
            case 4: DLLdisplayPlaylist(head);
                    break;
            case 5: printf("\nEnter the song to be played: ");
              	     scanf("%s",key);
                     playing=playSong(head, playing, key);
                     break;
            case 6:playing=playNextSong(playing);
                    break;
            case 7:playing=playPreviousSong(playing);
                    break;
            case 8: printf("\nEnter the song to be searched through singer name: ");
              	     scanf("%s",key);
              	     playing=playSong(head, playing, key);
              	     break;
            default: return 0;

        }
    }

    return 0;
}



//DLLgetNewNode function defination
NODE DLLgetNewNode()
 {
	NODE newNode = (NODE)malloc(sizeof(struct playlist));
	if(newNode==NULL)
	{
		printf("Song not created\n");
		exit(0);
	}
	printf("\nEnter the song details:\n");
	printf("Song name: ");
	scanf("%s", newNode->songName);
	printf("Singer name: ");
	scanf("%s", newNode->singerName);
	printf("Song size in MB: ");
	scanf("%f", &newNode->songSize);
	printf("Movie name: ");
	scanf("%s",newNode->movieName);

	newNode->previous = NULL;
	newNode->next = NULL;
	return newNode;
}


//DLLinsertFront() function defination
NODE DLLinsertAtFront(NODE head)
{
	NODE newNode = DLLgetNewNode();

	if(head == NULL)		//if list empty
	{
		head = newNode ;
  		return head ;
	}

	newNode ->next = head;		//inserting NODE at front
	head->previous = newNode ;
	head = newNode ;
	return head;
}



//DLLinsertAtEnd() function

NODE DLLinsertAtEnd(NODE head)
{
	NODE newNode = DLLgetNewNode();
	if(head == NULL)
	{

 	head = newNode;
 	return head;
	}
	else
	{

	    NODE cur = head;
		while(cur -> next != NULL)
			{
			cur = cur -> next;
			}
            cur -> next = newNode;
            newNode -> previous = cur;









	return head;
	}
}


//DLLinsertAfter() function definition
NODE DLLinsertAfter(NODE head, char key[MAXSIZE])
{
	NODE newNode = DLLgetNewNode();
	NODE temp1 = head, temp2 =NULL;

	if(head == NULL)
	{
		printf("Adding song is not possible as the play list is empty\n");
		return head;
	}
	while(temp1->next!=NULL)
    {
        if(strcmp(temp1 -> songName,key)==0)
		{

                break;
		}
        temp1=temp1->next;

	}
	if(temp1->next==NULL)
    {
        if(strcmp(temp1 -> songName,key)==0)
		{

                temp1->next=newNode;
                newNode->previous=temp1;
                return head;
		}
		else
        {
                printf("Entered song is not found!! cant add new song\n");
                return head;
        }
    }


		temp2 = temp1 -> next;
		temp1 -> next = newNode ;
		newNode -> previous = temp1;
		newNode -> next = temp2;
		temp2 -> previous = newNode ;
		return head;

}

//DLLdiplayList() function

void DLLdisplayPlaylist(NODE head)
{
	NODE temp = head;
	if(head == NULL)
		printf("\nList is Empty!!!");
	else
	{
		printf("\nList elements are: \n");
		while(temp != NULL)
		{
		  printf("%s\t %s\t %s\t %f\n", temp->songName, temp->singerName,
                  temp->movieName, temp->songSize);
		temp = temp->next;
		}
	}
}

//play song() function
NODE playSong(NODE head, NODE playing, char key[MAXSIZE])
{
	NODE temp = head;
	int flag=0;
	if(head == NULL)
		printf("\nList is Empty!!!");
	else
	{
		while(temp != NULL)
		{
		  if(strcmp(temp->songName,key)==0)
		 {
		     flag=1;
		     printf("The song playing is: %s\t %s\t %s\t %f\n", temp->songName, temp->singerName,temp->movieName, temp->songSize);
             return temp;
		 }
		temp = temp->next;
		}
		if(flag==0)
		{
		    printf("Song %s not found", key);
		}
	}
return playing;
}


//playNextSong function
NODE playNextSong(NODE playing)
{
	if(playing== NULL)
	{
		printf("\nNo next song found!!!");
	}
	else
	{
		  playing=playing->next;
		  if(playing!=NULL)
		  {
		  printf("The song playing is: %s\t %s\t %s\t %f\n", playing->songName, playing->singerName,playing->movieName, playing->songSize);
		  return playing;
		  }
		  printf("\nNo next song found!!!");
	}
return playing;
}

//playNextSong function
NODE playPreviousSong(NODE playing)
{

	if(playing==NULL)
	{
		printf("\nNo previous song found!!!");
	}
	else
	{
		  playing=playing->previous;
		  printf("The song playing is: %s\t %s\t %s\t %f\n", playing->songName, playing->singerName,playing->movieName, playing->songSize);
		  return playing;
	}
return playing;
}
NODE search(NODE head,NODE playing,char key[MAXSIZE])
{
NODE temp = head;
	int flag=0;
	if(head == NULL)
		printf("\nList is Empty!!!");
	else
	{
		while(temp != NULL)
		{
		  if(strcmp(temp->singerName,key)==0)
		 {
		     flag=1;
		     printf("The song is: %s\t %s\t %s\t %f\n", temp->songName, temp->singerName,temp->movieName, temp->songSize);
             return temp;
		 }
		temp = temp->next;
		}
		if(flag==0)
		{
		    printf("Song %s not found", key);
		}
	}
return playing;
}

