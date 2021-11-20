#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct teams
{
    int sno;
    char teams[20];
}team; //to access teams members
typedef struct points
{
    int sno;
    char teams[20];
    int played;
    int won;
    int lost;
    int tied;
    int total_points;
}point; //to access point table attributes
typedef struct best_players
{
    int sno;
    char name[20];
    char teams[20];
    char type[15];
    int total_points;
}best; //to access best_players
//function prototypes

void PrintTeams(team[]);
void PrintPoints(point[]);
void PrintBest_Players(best[]);
void add_to_teams(team[]);
void add_to_points(point[]);
void add_to_bestplayers(best[]);
void update_points(point[]);
void update_best_players(best[]);
void view_qualified_teams(team[], point[]);

//global counter to keep tracks of positions in all structures
int counter1 = 0; //for teams
int counter2 = 0; //for points
int counter3 = 0; //for best_players

int main()
{
    printf("\nWELCOME TO KABADDI TOURNAMENT RECORDS\n");
    struct teams team[5] = { {1, "Patna_Pirates"}, {2, "Dabang_Delhi"},
    {3, "Bengaluru_Bulls"}, {4, "Mumbai_Indians"}, {5, "Telugu_Titans"} };
    struct points point[5] = { {1, "Patna_Pirates", 22, 20, 1, 1, 103},
    {2, "Dabang_Delhi", 22, 19, 2, 1, 98}, {3, "Bengaluru_Bulls", 22, 18, 4, 0, 90},
    {4, "Mumbai_Indians", 22, 17, 4, 1, 88}, {5, "Telugu_Titans", 22, 16, 4, 2, 86}};
    struct best_players best[5] = { {1, "Pardeep_Narnal", "Patna_Pirates", "Raider ", 350},
    {2, "Naveen_Kumar", "Dabang_Delhi", "Raider ", 290},
    {3, "Pawan_Sehrawat", "Bengaluru_Bulls", "Raider ", 269},
    {4, "Fazal_Attrachli", "Mumbai_Indians", "Defender", 269},
    {5, "Vishal_Bhardwaj", "Telugu_Titans", "Defender", 180}};
    int temp = 1;
    while(temp)
    {
        printf("\nOperations to be performed are as follows:\n");
        printf("Click 1 to view all the tables\n");
        printf("Click 2 to add new record to table teams\n");
        printf("Click 3 to add new record to table points\n");
        printf("Click 4 to add new record to table best_players\n");
        printf("Click 5 to update table Points\n");
        printf("Click 6 to update table best_players\n");
        printf("Click 7 to view the qualified teams\n");
        printf("Click 8 to exit\n");
        int choice;
        printf("Enter your choice: "); //getting user's choice
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\n->VIEWING ALL THE TABLES!");
                PrintTeams(team); //function calling
                PrintPoints(point); //function calling
                PrintBest_Players(best); //function calling
                break;
            case 2:
                printf("\n->ADDING NEW RECORD TO TABLE TEAMS!");
                add_to_teams(team); //function calling
                break;
            case 3:
                printf("\n->ADDING NEW RECORDS TO TABLE POINTS!");
                add_to_points(point); //function calling
                break;
            case 4:
                printf("\n->ADDING NEW RECORDS TO TABLE BEST PLAYER!");
                add_to_bestplayers(best); //function calling
                break;
            case 5:
                printf("\n->UPDATING TABLE POINTS!");
                update_points(point); //function calling
                break;
            case 6:
                printf("\n->UPDATING TABLE BEST PLAYERS!");
                update_best_players(best);
                break;
            case 7:
                printf("\n->VIEWING QUALIFIED TEAMS!");
                view_qualified_teams(team, point);
                break;
            case 8:
                printf("\n->PROCESSING EXIT!");
                temp = 0;
                break;
            default:
                printf("\n->INVALID CHOICE!!");
            }
        }
    }
void PrintTeams(struct teams team[]){
    printf("\n\n\tDETAILS OF TEAMS:\n");
    printf("\n\tS.No.\t\tTeam\n");
    for (int x = 0; x < team[x].sno; ++x)
    {
        printf("\n\t%d", x+1); //Serial Number
        printf("\t\t%s",team[x].teams); //Team Names
    }
}
void PrintPoints(struct points point[]){
    printf("\n\n\n\tPOINTS OF THE ALL TEAMS:\n");
    printf("\n\tS.No.\t\tTeam\t\tPlayed\t\tWon\t\tLost\t\tTied\t\tTotal Points\n");
    for(int x = 0; x < point[x].sno; ++x){
        printf("\n\t%d", x+1); //Serial Number
        printf("\t%s",point[x].teams); //Team Names
        printf("\t\t%d",point[x].played); //Matches Played
        printf("\t\t%d",point[x].won); //Matches Won
        printf("\t\t%d",point[x].lost); //Matches Lost
        printf("\t\t%d",point[x].tied); //Matches Tied
        printf("\t\t%d",point[x].total_points); //Total Points
        }
}
void PrintBest_Players(struct best_players best[]){
    printf("\n\n\n\tBEST PLAYERS:\n");
    printf("\n\tS.No.\t\tPlayer Name\t\tTeam\t\t\tPlayer Type\t\tTotal Points\n");
    for(int x = 0; x < best[x].sno; ++x)
    {
        printf("\n\t%d", x+1); //Serial Number
        printf("\t\t%s",best[x].name); //Player Name
        printf("\t\t%s",best[x].teams); //Team Names
        printf("\t\t%s",best[x].type); //Type of Player
        printf("\t\t%d\n",best[x].total_points); //Total Points
    }
}
    void add_to_teams(team teamstable[]){
        counter1++; //increasing the counter for each record added
        printf("\n\tEnter serial number: ");
        scanf("%d",&teamstable[counter1-1].sno);
        printf("\tEnter name of the team: ");
        scanf("%s",&teamstable[counter1-1].teams);
        printf("\tRECORDS ADDED SUCCESSFULLY!\n");
    }
void add_to_points(point pointstable[]){
    counter2++; //increasing the counter for each record added
    printf("\n\tEnter serial number: ");
    scanf("%d", &pointstable[counter2 - 1].sno);
    printf("\tEnter team name: ");
    scanf("%s", &pointstable[counter2 - 1].teams);
    printf("\tEnter number of matches played: ");
    scanf("%d", &pointstable[counter2 - 1].played);
    printf("\tEnter number of matches won: ");
    scanf("%d", &pointstable[counter2 - 1].won);
    printf("\tEnter number of matches lost: ");
    scanf("%d", &pointstable[counter2 - 1].lost);
    printf("\tEnter number of matches tied: ");
    scanf("%d", &pointstable[counter2 - 1].tied);
    pointstable[counter2 - 1].total_points = (pointstable[counter2 - 1].won * 5) +(pointstable[counter2 - 1].tied * 3);
    printf("\tRECORDS ADDED SUCCESSFULLY!\n");
}

void add_to_bestplayers(best bestplayers[]){
    counter3++; //increasing the counter for each record added
    printf("\n\tEnter serial number: ");
    scanf("%d",&bestplayers[counter3-1].sno);
    printf("\tEnter name of the player: ");
    scanf("%s",bestplayers[counter3-1].name);

    printf("\tEnter team name: ");
    scanf("%s",&bestplayers[counter3-1].teams);
    printf("\tEnter type of player: ");
    scanf("%s",&bestplayers[counter3-1].type);
    printf("\tEnter total points : ");
    scanf("%d",&bestplayers[counter3-1].total_points);
    printf("\tRECORDS ADDED SUCCESSFULLY!\n");
}

void update_points(point pointstable[]){
    int n;
    printf("\n\tEnter the serial number of the team: "); //getting the serial number
    scanf("%d",&n);
    printf("\tEnter number of matches played: ");
    scanf("%d",&pointstable[n-1].played);
    printf("\tEnter number of matches won: ");
    scanf("%d",&pointstable[n-1].won);
    printf("\tEnter number of matches lost: ");
    scanf("%d",&pointstable[n-1].lost);
    printf("\tEnter number of matches tied: ");
    scanf("%d",&pointstable[n-1].tied);
    printf("\tRECORDS UPDATED SUCCESSFULLY!\n");
}
void update_best_players(best bestplayers[]){
    int n;
    printf("\n\tEnter the serial number of the team: "); //Getting the serial number
    scanf("%d",&n);
    printf("\tEnter name of the player: ");
    scanf("%s",&bestplayers[n-1].name);
    printf("\tEnter type of player: ");
    scanf("%s",&bestplayers[n-1].type);
    printf("\tEnter total points : ");
    scanf("%d",&bestplayers[n-1].total_points);
    printf("\tRECORDS UPDATED SUCCESSFULLY!\n");
        }
void view_qualified_teams(team qualified_team[], point pointstable[]){
    int i;
    printf("\n\tThe teams having total points more than 80 are being qualified!");
    for(i=0;i<5;++i)
        if (pointstable[i].total_points>80) //to check whether the team is qualified or not
    printf("\n\t%s",qualified_team[i].teams);
    printf("\n");
   }
