#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define USERNAME "delhimetro"
#define PASSWORD "password123"

int STN1,STN2;
int LN1,LN2;
struct User {
    char username[20];
    char password[20];
    float balance;
};


void login(struct User *user);
void mainMenu(struct User *user);
void addBalance(struct User *user);
void viewBalance(struct User *user);
void bookTickets(struct User *user);
void displayStations(char *line[], int count);
int selectStation(char *line[], int count);
float calculateFare(int start, int end);
void maskedInput(char *password);
void printPattern();

char *yellowLineStations[] = {"Samaypur Badli",
"Rohini Sector 18, 19",
"Haiderpur Badli Mor",
"Jahangirpuri",
"Adarsh Nagar",
"Azadpur",
"Model Town",
"GTB Nagar",
"Vishwavidyalaya",
"Vidhan Sabha",
"Civil Lines",
"Kashmere Gate",
"Chandni Chowk",
"Chawri Bazar",
"New Delhi",
"Rajiv Chowk",
"Patel Chowk",
"Central Secretariat",
"Udyog Bhawan",
"Lok Kalyan Marg",
"Jor Bagh",
"INA",
"AIIMS",
"Green Park",
"Hauz Khas",
"Malviya Nagar",
"Saket",
"Qutab Minar",
"Chhatarpur",
"Sultanpur",
"Ghitorni",
"Arjan Garh",
"Guru Dronacharya",
"Sikanderpur",
"MG Road",
"IFFCO Chowk",
"Huda City Centre"};
char *pinkLineStations[] = {"Majlis Park",
"Azadpur",
"Netaji Subhash Place",
"Shakurpur",
"Punjabi Bagh West",
"ESI Hospital",
"Rajouri Garden",
"Mayapuri",
"Naraina Vihar",
"Delhi Cantt",
"Durgabai Deshmukh South Campus",
"Sir Vishweshwaraiah Moti Bagh",
"Bhikaji Cama Place",
"Sarojini Nagar",
"INA",
"South Extension",
"Lajpat Nagar",
"Vinobapuri",
"Ashram",
"Hazrat Nizamuddin",
"Mayur Vihar Phase-I",
"Mayur Vihar Pocket-I",
"Trilokpuri Sanjay Lake",
"Vinod Nagar East",
"Mandawali - West Vinod Nagar",
"IP Extension",
"Anand Vihar",
"Karkarduma",
"Karkarduma Court",
"Krishna Nagar",
"East Azad Nagar",
"Welcome",
"Jaffrabad",
"Maujpur - Babarpur",
"Gokulpuri",
"Johri Enclave",
"Shiv Vihar"};
char *blueLineStations[] = {"Dwarka Sector 21",
   "Dwarka Sector 8",
  "Dwarka Sector 9",
  "Dwarka Sector 10",
  "Dwarka Sector 11",
  "Dwarka Sector 12",
  "Dwarka Sector 13",
  "Dwarka Sector 14",
  "Dwarka",
  "Dwarka Mor",
  "Nawada",
  "Uttam Nagar West",
  "Uttam Nagar East",
  "Janakpuri West",
  "Janakpuri East",
 "Tilak Nagar",
  "Subhash Nagar",
  "Tagore Garden",
  "Rajouri Garden",
  "Ramesh Nagar",
  "Moti Nagar",
  "Kirti Nagar",
  "Shadipur",
  "Patel Nagar",
  "Rajendra Place",
   "Karol Bagh",
  "Jhandewalan",
  "Ramakrishna Ashram Marg",
  "Rajiv Chowk",
  "Barakhamba Road",
  "Mandi House",
  "Pragati Maidan",
  "Indraprastha",
  "Yamuna Bank",
  "Akshardham",
  "Mayur Vihar Phase-I",
  "Mayur Vihar Ext",
  "New Ashok Nagar",
  "Noida Sector 15",
   "Noida Sector 16",
  "Noida Sector 18",
  "Golf Course",
  "Botanical Garden",
   "Noida City Centre",
   "Noida Sector 34",
   "Noida Sec 52",
   "Noida Sec 61",
   "Noida Sec 59",
   "Noida Sec 62",
   "Noida Electronic City"};
char *greenLineStations[] = {"Kirti Nagar","Satguru Ram Singh Marg","Inderlok",
 "Ashok Park Main",
 "Punjabi Bagh West",
 "Shivaji Park",
 "Madipur",
 "Paschim Vihar East",
 "Paschim Vihar West",
 "Peera Garhi",
 "Udyog Nagar",
 "Maharaja Surajmal Stadium",
 "Nangloi",
 "Nangloi Railway Station",
 "Rajdhani Park",
 "Mundka",
 "Mundka Industrial Area",
 "Ghevra Metro Station",
 "Tikri Kalan",
 "Tikri Border",
 "Pandit Shree Ram Sharma",
 "Bahadurgarh City",
 "Brigadier Hoshiyar Singh"};
char *redLineStations[] = {
"Rithala",
"Rohini West",
"Rohini East",
"Pitampura",
"Kohat Enclave",
"Netaji Subhash Place",
"Keshav Puram",
"Kanhaiya Nagar",
"Inderlok",
"Shastri Nagar",
"Pratap Nagar",
"Pul Bangash",
"Tis Hazari",
"Kashmere Gate",
"Shastri Park",
"Seelampur",
"Welcome",
"Shahdara",
"Mansarovar Park",
"Jhilmil",
"Dilshad Garden",
"Shahid Nagar"
"Raj Bagh",
"Rajendra Nagar",
"Shyam Park",
"Mohan Nagar",
"Arthala",
"New Bus Adda"
};
char *violetLineStations[] = {"Kashmere Gate",
"Lal Quila",
"Jama Masjid",
"Delhi Gate",
"ITO",
"Mandi House",
"Janpath",
"Central Secretariat",
"Khan Market",
"Jawaharlal Nehru Stadium",
"Jangpura",
"Lajpat Nagar",
"Moolchand",
"Kailash Colony",
"Nehru Place",
"Kalkaji Mandir",
"Govindpuri",
"Okhla",
"Jasola Apollo",
"Sarita Vihar",
"Mohan Estate",
"Tughlakabad",
"Badarpur Border",
"Sarai",
"NHPC Chowk",
"Mewala Maharajpur",
"Sector 28",
"Badkal Mor",
"Old Faridabad",
"Neelam Chowk Arjonda",
"Bata Chowk",
"Escort Mujesar",
"Sant Surdas"
"Raja Nahar Singh"
};
char *aquaLineStations[] = {"Noida Sec 52","Noida Sector 51",
  "Noida Sector 50",
  "Noida Sector 76",
  "Noida Sector 101",
  "Noida Sector 81",
   "NSEZ",
  "Noida Sector 83",
   "Noida Sector 137",
  "Noida Sector 142",
 "Noida Sector 143",
  "Noida Sector 144",
 "Noida Sector 145",
  "Noida Sector 146",
   "Noida Sector 147",
  "Noida Sector 148",
   "Knowledge Park II",
  "Pari Chowk",
  "Alpha 1",
  "Alpha 2",
  "Delta 1",
  "GNIDA Office",
   "Depot"};
char *magentaLineStations[] = { "Janakpuri West",
"Dabri Mor - Janakpuri South",
"Dashrath Puri",
"Palam",
"Sadar Bazaar Cantonment",
    "Terminal 1-IGI Airport",
"Shankar Vihar",
"Vasant Vihar",
"Munirka",
"RK Puram",
"IIT Delhi",
    "Hauz Khas",
"Panchsheel Park",
"Chirag Delhi",
"Greater Kailash",
"Nehru Enclave",
"Kalkaji Mandir",
    "Okhla NSIC",
"Sukhdev Vihar",
"Jamia Millia Islamia",
"Okhla Vihar",
"Jasola Vihar Shaheen Bagh",
    "Kalindi Kunj",
"Okhla Bird Sanctuary",
"Botanical Garden"
};
char *orangeLineStations[] = {
    "New Delhi",
"Shivaji Stadium",
"Dhaula Kuan",
"Delhi Aerocity",
"IGI Airport (Terminal 3)",
    "Dwarka Sector 21"
};
char *greyLineStations[] = {
    "Dwarka",
"Nangli",
"Najafgarh",
"Dhansa Bus Stand"
};

int yellowLineCount = 37, pinkLineCount = 36, blueLineCount = 50;
int redLineCount = 27, greenLineCount = 23, violetLineCount = 33;
int aquaLineCount = 23, magentaLineCount = 25, orangeLineCount = 6;
int greyLineCount = 4;

//Declaration stuff till now

void printPattern() {
	printf("						{@@}  (  )  {@}   {   }	  @@	()	@@	@\n");
	printf("					{	 }	\n");
	printf("                          	 (@@@@@@@@@)  \n");
	printf("			      {		}\n");
	printf("		_____	{@@@@}	\n");
	printf("	       |=====|			__________________			       _________________\n");
	printf("      	  _D___|     |_________________/		  |_____|__|________-----_____|________________| \n");
	printf("	|(_____)....       |	     ][ __________________/   |       |              -| ____   ____ |	       _________________________\n");
	printf("       /	    |      |	     ][    |	     |        |       |               | |__|   |__| |	     _|	________________________|_____A	\n");
	printf("      |		    |	   |         ][	   |________----------------------------------|  [______]   |      -|                                | \n");
	printf("     ||_________________|__|_______''__[____| |___(}{)(}{)(}{)__________________|____|		   |        |               DMRC             |\n");
	printf("    |/   |	  |-------------------|__________|[][]  [][]         D               |-------------|_____ __|________________________________|__ \n");
	printf("  __/  __|        |-~~~~~)       /`~~~~~)      /~~~~~~)       /~~~~~~)_______Y_____________________|____|_| |________________________________|__| \n");
	printf("   |/-___|________|-     O---------------O------------O---------------O___________(~~)_______)                   |_D__D__D_|    |__D__D__D__| \n");
	printf("   	(____/     (_____/       (______/      (______/       (______/            (__)                            (_)  (_)        (_)  (_)	\n");
	printf("         ~~~~       ~~~~~         ~~~~~~         ~~~~           ~~~~               ~~                              ~    ~          ~    ~ \n");
}
//This Train is made by Prashant. Don't copy :)

void login(struct User *user) {//Function for verifying user details and logging the user in
    char inputUsername[20];
    char inputPassword[20];

    printf("\n                                       === Delhi Metro Management System ===\n");
    printf("                                           === Welcome To Delhi Metro===\n");
    printf("Enter your username: ");
    scanf("%s", inputUsername);

    printf("Enter your password: ");
    maskedInput(inputPassword);

    if (strcmp(inputUsername, USERNAME) == 0 && strcmp(inputPassword, PASSWORD) == 0) {
        strcpy(user->username, USERNAME);
        strcpy(user->password, PASSWORD);
        user->balance = 0;  // Initial balance
        printf("\nLogin successful! Welcome to Delhi Metro Management system.\n");
        mainMenu(user);
    } else {
        printf("\nIncorrect username or password. Please try again.\n");
    }
}

void mainMenu(struct User *user) {//Function responsible for main menu
    int choice;
    while (1) {
        printf("===== Main Menu =====\n");
        printf("1. Add Balance\n");
        printf("2. View Balance\n");
        printf("3. Book Tickets\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBalance(user);
                break;
            case 2:
                viewBalance(user);
                break;
            case 3:
                bookTickets(user);
                break;
            case 4:
                printf("Thank you for using the Delhi Metro Management System!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void addBalance(struct User *user) {//Adding of balance in user account
    float amount;
    printf("Enter amount to add: ");
    scanf("%f", &amount);

    if (amount > 0) {
        user->balance += amount;
        printf("Balance successfully updated!\n\n");
    } else {
        printf("Invalid amount.\n\n");
    }
}

void viewBalance(struct User *user) {//Viewing balance of the user
    printf("Current balance: ₹ %.2f\n\n", user->balance);
}

void bookTickets(struct User *user) {
    int lineChoice, startStation, endStation,GRBG=1;
    float fare;
H:
    printf("===== Select Line =====\n");
    printf("1. Yellow Line\n");
    printf("2. Pink Line\n");
    printf("3. Blue Line\n");
    printf("4. Red Line\n");
    printf("5. Green Line\n");
    printf("6. Violet Line\n");
    printf("7. Aqua Line\n");
    printf("8. Magenta Line\n");
    printf("9. Orange Line\n");
    printf("10. Grey Line\n");
    printf("Choose a line: ");
    scanf("%d", &lineChoice);

    switch (lineChoice) {
        case 1:
            displayStations(yellowLineStations, yellowLineCount);
            if(GRBG==1)
            {
                startStation = selectStation(yellowLineStations, yellowLineCount);
            }
            if (GRBG==2)
            {
                endStation = selectStation(yellowLineStations, yellowLineCount);
            }
            break;

        case 2:
            displayStations(pinkLineStations, pinkLineCount);
            if(GRBG==1)
            {
                startStation = selectStation(pinkLineStations, pinkLineCount);
            }
            if (GRBG==2)
            {
                endStation = selectStation(pinkLineStations, pinkLineCount);
            }
            break;
        case 3:
            displayStations(blueLineStations, blueLineCount);
            if(GRBG==1)
            {
                startStation = selectStation(blueLineStations, blueLineCount);
            }
            if (GRBG==2)
            {
                endStation = selectStation(blueLineStations, blueLineCount);
            }
            break;
        case 4:
            displayStations(redLineStations, redLineCount);
            if(GRBG==1)
            {
                startStation = selectStation(redLineStations, redLineCount);
            }
            if (GRBG==2)
            {
                endStation = selectStation(redLineStations, redLineCount);
            }
            break;

        case 5:
            displayStations(greenLineStations, greenLineCount);
            if(GRBG==1)
            {
                startStation = selectStation(greenLineStations, greenLineCount);
            }
            if (GRBG==2)
            {
                endStation = selectStation(greenLineStations, greenLineCount);
            }
            break;

        case 6:
            displayStations(violetLineStations, violetLineCount);
            if(GRBG==1)
            {
                startStation = selectStation(violetLineStations, violetLineCount);
            }
            if (GRBG==2)
            {
                endStation = selectStation(violetLineStations, violetLineCount);
            }
            break;

        case 7:
            displayStations(aquaLineStations, aquaLineCount);
            if(GRBG==1)
            {
                startStation = selectStation(aquaLineStations, aquaLineCount);
            }
            if (GRBG==2)
            {
                endStation = selectStation(aquaLineStations, aquaLineCount);
            }
            break;

        case 8:
            displayStations(magentaLineStations, magentaLineCount);
            if(GRBG==1)
            {
                startStation = selectStation(magentaLineStations, magentaLineCount);
            }
            if (GRBG==2)
            {
                endStation = selectStation(magentaLineStations, magentaLineCount);
            }
            break;

        case 9:
            displayStations(orangeLineStations, orangeLineCount);
            if(GRBG==1)
            {
                startStation = selectStation(orangeLineStations, orangeLineCount);
            break;
            }
            if (GRBG==2)
            {
                endStation = selectStation(orangeLineStations, orangeLineCount);
            }
            break;

        case 10:
            displayStations(greyLineStations, greyLineCount);
            if(GRBG==1)
            {
                startStation = selectStation(greyLineStations, greyLineCount);
            }
            if (GRBG==2)
            {
                endStation = selectStation(greyLineStations, greyLineCount);
            }
            break;
        default:
            {
               printf("Invalid choice.\n");
            }
            if(GRBG==1)
            {
                LN1=lineChoice;
            }
            if(GRBG==2)
            {
                LN2=lineChoice;
            }
}
            GRBG++;
            if (GRBG<=2)
            {
            goto H;
            }

    if (startStation == endStation && LN1==LN2) {
        printf("ERROR : Start and destination stations CANNOT be the SAME.\n\n");
        return;
    }

fare = PATH(startStation,LN1,endStation,LN2) ;
    if (user->balance >= fare) {
        user->balance -= fare;
        int distance = abs(endStation - startStation); // Calculate the distance separately
        int time = distance * 3;  // Assuming 3 minutes per station
        printf("Ticket booked successfully! Fare: ₹%.2f\nRemaining balance: ₹%.2f\n", fare, user->balance);
        printf("The Time Taken = %d min\n", time);  // Displaying the time taken
    } else {
        printf("Insufficient balance. Please add funds.\n\n");
    }
}


void displayStations(char *line[], int count){ //Displaying stations on the screen
    for(int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, line[i]);
    }
}

int selectStation(char *line[], int count) {//Taking input of station
    int station;
    printf("Select station number: ");
    scanf("%d", &station);

    if (station < 1 || station > count) {
        printf("Invalid selection. Please try again.\n");
        return selectStation(line, count);
    }
    return station - 1;
}

//cut from here

void maskedInput(char *password) {//Function for Masked passsword
    int i = 0;
    char ch;
    while ((ch = getch()) != '\r') {
        if (ch == '\b' && i > 0) {
            i--;
            printf("\b \b");
        } else if (ch != '\b') {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
}

struct LINES {
char **STNS;
}LN[11];

int main() {

LN[1].STNS=&yellowLineStations;
LN[2].STNS=&pinkLineStations;
LN[3].STNS=&blueLineStations;
LN[4].STNS=&redLineStations;
LN[5].STNS=&greenLineStations;
LN[6].STNS=&violetLineStations;
LN[7].STNS=&aquaLineStations;
LN[8].STNS=&magentaLineStations;
LN[9].STNS=&orangeLineStations;
LN[10].STNS=&greyLineStations;

    struct User user;
    printPattern();
    login(&user);
    return 0;
}




int PATH (int Q/*STN1*/,int W/*LN1*/,int E/*STN2*/, int R/*LN2*/)//Krish's fare calcultion
{
    int MONEY;
    int I,J,K,L,F;
    if(W==R)
    {
        MONEY=(Q-E)*5;
        if(MONEY<0)
        {
            MONEY=MONEY*(-1);
        }
        return MONEY;
    }
    for(I=1;I<11;I++)
    {
        for(J=1;J<11;J++)
        {
            if(strcmp(LN[W].STNS[I],LN[R].STNS[J])==0)//1 line interchange
            {
                K=(STN1-I);
                L=(STN2-J);
                if(K<0)
                {
                    K=K*(-1);
                }
                if(L<0)
                {
                    L=L*(-1);
                }
                F=K+L;
                return F*5;
            }
        }
    }

return 10000;
}
