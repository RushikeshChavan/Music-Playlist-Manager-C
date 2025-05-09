# include <stdio.h>
# include <string.h>
# define size 4

int name_len=10;
int curr=-1;
char Playlist [size][10];
int front=-1;
int rear=-1;

int isEmpty(){
    return front==-1;
}

int isFull(){
    return (front==(rear+1)%size) ;
}

void add(char newSong[]){
    if(isFull()){
        printf("Playlist is full!!! %s song couldn't get add!!!❌",newSong);
        return ;
    }
    
    if (isEmpty()){
        rear=0;
        front=0;
    }else{
        rear=(rear+1)%size;
    }
    
    strcpy(Playlist[rear],newSong);
    printf("\n%s song is added to playlist✅",Playlist[rear]);
}

void delete(){
    if(isEmpty()){
        printf("Playlist is empty! There is no element to remove");
        return ;
    }
    
    printf("\n%s is deleted !!!❌",Playlist[front]);
    if(front==rear){
        front=-1;
        rear=-1;
        curr=-1;
    }else{
        front=(front+1) % size;
        curr=(curr+1)%size;
    }    
}

void Display(){
    if(isEmpty()){
        printf("\nPlaylist is empty ! There is nothing to Display☹️\n");
        return ;
    }
    printf("\n\n===== \tPlaylist\t =====");
    for(int i=front; i!=rear; i=(i+1)%size){
        printf("\n%s",Playlist[i]);
    }
    printf("\n%s",Playlist[rear]);

}

void current(){
     if(curr==-1){
        printf("Not any song is playing...");
        return ;
     }
     printf("\n%s is playing right now...",Playlist[curr]);
}

void next(){

     if(isEmpty()){
        printf("There is no song in playlist to play");
        curr=-1;
        return ;
     }

     if(curr==rear){
        printf("\n%s is started to play\n",Playlist[curr]);
        printf("You reached the last song!!!");
        return;
     }
     
     curr=(curr+1)%size;
     printf("\n%s is started to play",Playlist[curr]);
}

void first(){
     curr=front;
     if(isEmpty()){
        printf("Playlist is Empty, Add some songs first");
        return ;
     }
     
     printf("\n%s song is playing right now...",Playlist[curr]);
}

void menu(){
    printf("\n\n1.Add new song \n2.Delete the song \n3.Display the playlist\n4.Show the current song\n5.Play the next song\n6.Play my first song\n7.Exit\n");
}

int main(){
    int choice, a=1 ;
    char newSong[10];
    
    while (a==1){
        menu();
        printf("Enter your choice :- ");
        scanf("%d",&choice);
        getchar();
        
        switch(choice){
            case 1: printf("Enter New song name :- ");
                    //scanf("[/n^]*%s",newSong);
                    fgets(newSong, sizeof(newSong), stdin);
                    newSong[strcspn(newSong, "\n")] = '\0';
                    //gets(newSong);
                    add(newSong);
                    break;
            
            case 2: delete();
                    break;
                    
            case 3: Display();
                    break;

            case 4: current();
                    break;

            case 5: next();
                    break;

            case 6: first();
                    break;
                    
            case 7: a=0;
                    break;

            
                    
          default : printf("Please enter valid choice");       
        }
    }
}
