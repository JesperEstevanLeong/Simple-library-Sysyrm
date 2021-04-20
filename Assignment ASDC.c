#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check = false;
bool get = false;
int padcount = 0, phcount = 0;  // counter for pad, ph
int historyDP= 0, historyWM = 0;
int LecturerID, SeriesNum, date, i, a, j, k, k1, k2, k3;
int u, u2, u4, u5, u6, u7, u9, u10;
int uu, uu2, uu4, uu5, uu6, uu7, uu9, uu10;
char name[50], u3[50], u8[50], uu3[50], uu8[50]; //global declare

struct node {
    int LecturerID, SeriesNum, date;
    char name[50];
    struct node* next;
} *newnode, *newDP, *newWH, *oldDP, *oldWH, *temp, *prev, *prev2,
*temp2, *temp5, *temp6, *temp7, *temp8, *temp9, *temp10, *temp11,
*temp12, *temp13, *temp14, *temp15, *temp16, *temp17, *temp18,
*temp19, *temp20, *t, *tmpdisplay;  //struct and pointer

void Checker(int Lecturer) {
    check = true;
    temp = newDP;
    if (temp != NULL) {
        while (temp != NULL) {
            if (temp->LecturerID == Lecturer) {
                check = false;
                break;
            }
            temp = temp->next;
        }
    }
} //check whether the lecturer have borrowed before 
void Checker2(int Lecturer) {
    check = true;
    temp = newWH;
    if (temp != NULL) {
        while (temp != NULL) {
            if (temp->LecturerID == Lecturer) {
                check = false;
                break;
            }
            temp = temp->next;
        }
    }
} //check whether the lecturer have borrowed before 
void Checker3(int Lecturer) {
    check = false;
    temp = newDP;
    if (temp != NULL) {
        while (temp != NULL) {
            if (temp->LecturerID == Lecturer) {
                check = true;
                break;
            }
            temp = temp->next;
        }
    }
}  //Check whether the lecturer has returned or not
void Checker4(int Lecturer) {
    check = false;
    temp = newWH;
    if (temp != NULL) {
        while (temp != NULL) {
            if (temp->LecturerID == Lecturer) {
                check = true;
                break;
            }
            temp = temp->next;
        }
    }
}  //Check whether the lecturer has returned or not
void CheckerSerial(int SNum) {
    get = true;
    temp = newDP;
    if (temp != NULL) {
        while (temp != NULL) {
            if (temp->SeriesNum == SNum) {
                get = false;
                break;
            }
            temp = temp->next;
        }
    }
}  //check whether the Serial Number have borrowed before 
void CheckerSerial2(int SNum) {
    get = true;
    temp = newWH;
    if (temp != NULL) {
        while (temp != NULL) {
            if (temp->SeriesNum == SNum) {
                get = false;
                break;
            }
            temp = temp->next;
        }
    }
}   //check whether the Serial Number have borrowed before 
void createlist() {
    newDP = NULL; newWH = NULL; oldDP = NULL; oldWH = NULL;
}// create a list
void IDSORT() {
    if (newDP == NULL) {
        printf("\n\nList is empty\n\n");
    } // check if the list is empty then print run this
    else {
        for (i = padcount - 2 ; i >= 0; i--) {

            temp5 = newDP;
            temp6 = temp5->next;
            for (j = 0; j <= i; j++) {
                if (temp5->LecturerID > temp6->LecturerID) {
                    k = temp5->LecturerID;
                    temp5->LecturerID = temp6->LecturerID;
                    temp6->LecturerID = k;             // bubble sort
                }
                temp5 = temp6;
                temp6 = temp6->next;
            }
        }
        t = newDP;
        while (t != NULL) {
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("-                  Outstanding  Report                    - \n");
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("  LecturerID       Name      SerialNumber        Date       \n");
            printf("     %d             %s           %d             %d          \n", t->LecturerID, t->name, t->SeriesNum, t->date);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("\n");
            t = t->next;
        } // when the report is not empty print the report
    }
}
void IDSORT2() {
    if (oldDP == NULL) {
        printf("\n\nList is empty\n\n");
    }   // check if the list is empty then print run this
    else {
        for (i = historyDP - 2; i >= 0; i--) {

            temp9 = oldDP;
            temp10 = temp9->next;
            for (j = 0; j <= i; j++) {
                if (temp9->LecturerID > temp10->LecturerID)
                {
                    k2 = temp9->LecturerID;
                    temp9->LecturerID = temp10->LecturerID;
                    temp10->LecturerID = k2;                    // bubble sort
                }
                temp9 = temp10;
                temp10 = temp10->next;
            }
        }
        t = oldDP;
        while (t != NULL) {
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("-                  Historical   Report                    - \n");
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("  LecturerID       Name      SerialNumber        Date       \n");
            printf("     %d             %s           %d             %d          \n", t->LecturerID, t->name, t->SeriesNum, t->date);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            t = t->next;
        }// when the report is not empty print the report
    }
}
void IDSORT3() {
    if (newWH == NULL) {
        printf("\n\nList is empty\n\n");
    }   // check if the list is empty then print run this
    else {
        for (i = phcount - 2; i >= 0; i--) {

            temp7 = newWH;
            temp8 = temp7->next;
            for (j = 0; j <= i; j++) {
                if (temp7->LecturerID > temp8->LecturerID)
                {
                    k1 = temp7->LecturerID;
                    temp7->LecturerID = temp8->LecturerID;
                    temp8->LecturerID = k1;     // bubble sort
                }
                temp7 = temp8;
                temp8 = temp8->next;
            }
        }
        t = newWH;
        while (t != NULL) {
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("-                  Outstanding  Report                    - \n");
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("  LecturerID       Name      SerialNumber        Date       \n");
            printf("     %d             %s           %d             %d          \n", t->LecturerID, t->name, t->SeriesNum, t->date);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("\n");
            t = t->next;
        }// when the report is not empty print the report
    }
}
void IDSORT4() {
        if (oldWH == NULL) {
            printf("\n\nList is empty\n\n");
        }   // check if the list is empty then print run this
        else {
            for (i = historyWM - 2; i >= 0; i--) {

                temp11 = oldWH;
                temp12 = temp11->next;
                for (j = 0; j <= i; j++) {
                    if (temp11->LecturerID > temp12->LecturerID)
                    {
                        k3 = temp11->LecturerID;
                        temp11->LecturerID = temp12->LecturerID;
                        temp12->LecturerID = k3;      // bubble sort
                    }
                    temp11 = temp12;
                    temp12 = temp12->next;
                }
            }
            t = oldWH;
            while (t != NULL) {
                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                printf("-                  Historical   Report                    - \n");
                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                printf("  LecturerID       Name      SerialNumber        Date       \n");
                printf("     %d             %s           %d             %d          \n", t->LecturerID, t->name, t->SeriesNum, t->date);
                printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
                printf("\n");
                t = t->next;
            }// when the report is not empty print the report
        }
    }
void DATESORT() {
    if (newDP == NULL) {
        printf("\n\nList is empty\n\n");
    }  // check if the list is empty then print run this
    else {
        for (i = padcount - 2; i >= 0; i--) {
            temp13 = newDP;
            temp14 = temp13->next;
            for (j = 0; j <= i; j++) {
                if (temp13->date > temp14->date) {
                    u = temp13->date;
                    u2 = temp13->LecturerID;
                    strcpy(u3, temp13->name);
                    u5 = temp13->SeriesNum;

                    temp13->date = temp14->date;
                    temp13->LecturerID = temp14->LecturerID;
                    strcpy(temp13->name, temp14->name);
                    temp13->SeriesNum = temp14->SeriesNum;

                    temp14->date = u;
                    temp14->LecturerID = u2;
                    strcpy(temp14->name, u3);
                    temp14->SeriesNum = u5;                // bubble sort

                }
                temp13 = temp14;
                temp14 = temp14->next;
            }
        }
        t = newDP;
        while (t != NULL) {
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("-                  Outstanding  Report                    - \n");
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("  LecturerID       Name      SerialNumber        Date       \n");
            printf("     %d             %s           %d             %d          \n", t->LecturerID, t->name, t->SeriesNum, t->date);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("\n");
            t = t->next;
        }// when the report is not empty print the report
    }
}
void DATESORT2() {
    if (oldDP == NULL) {
        printf("\n\nList is empty\n\n");
    }  // check if the list is empty then print run this
    else {
        for (i = historyDP - 2; i >= 0; i--) {
            temp17 = oldDP;
            temp18 = temp17->next;
            for (j = 0; j <= i; j++) {
                if (temp17->date > temp18->date) {
                    uu = temp17->date;
                    uu2 = temp17->LecturerID;
                    strcpy(uu3, temp17->name);
                    uu5 = temp17->SeriesNum;

                    temp17->date = temp18->date;
                    temp17->LecturerID = temp18->LecturerID;
                    strcpy(temp17->name, temp18->name);
                    temp17->SeriesNum = temp18->SeriesNum;

                    temp18->date = uu;
                    temp18->LecturerID = uu2;
                    strcpy(temp18->name, uu3);
                    temp18->SeriesNum = uu5;     // bubble sort
                } 
                temp17 = temp18;
                temp18 = temp18->next;
            }
        }
        t = oldDP;
        while (t != NULL) {
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("-                  Historical   Report                    - \n");
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("  LecturerID       Name      SerialNumber        Date       \n");
            printf("     %d             %s           %d             %d          \n", t->LecturerID, t->name, t->SeriesNum, t->date);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("\n");
            t = t->next;
        }// when the report is not empty print the report
    }
}
void DATESORT3() {
    if (newWH == NULL) {
        printf("\n\nList is empty\n\n");
    }  // check if the list is empty then print run this
    else {
        for (i = phcount - 2; i >= 0; i--) {
            temp15 = newWH;
            temp16 = temp15->next;
            for (j = 0; j <= i; j++) {
                if (temp15->date > temp16->date) {
                    u6 = temp15->date;
                    u7 = temp15->LecturerID;
                    strcpy(u8, temp15->name);
                    u10 = temp15->SeriesNum;

                    temp15->date = temp16->date;
                    temp15->LecturerID = temp16->LecturerID;
                    strcpy(temp15->name, temp16->name);
                    temp15->SeriesNum = temp16->SeriesNum;

                    temp16->date = u6;
                    temp16->LecturerID = u7;
                    strcpy(temp16->name, u8);
                    temp16->SeriesNum = u10;                // bubble sort
                }
                temp15 = temp16;
                temp16 = temp16->next;
            }
        }
        t = newWH;
        while (t != NULL) {
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("-                  Outstanding  Report                    - \n");
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("  LecturerID       Name      SerialNumber        Date       \n");
            printf("     %d             %s           %d             %d          \n", t->LecturerID, t->name, t->SeriesNum, t->date);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("\n");
            t = t->next;
        }// when the report is not empty print the report
    }
}
void DATESORT4() {
    if (oldWH == NULL) {
        printf("\n\nList is empty\n\n");
    }  // check if the list is empty then print run this
    else {
        for (i = historyWM - 2; i >= 0; i--) {
            temp19 = oldWH;
            temp20 = temp19->next;
            for (j = 0; j <= i; j++) {
                if (temp19->date > temp20->date) {
                    uu6 = temp19->date;
                    uu7 = temp19->LecturerID;
                    strcpy(uu8, temp19->name);
                    uu10 = temp19->SeriesNum;

                    temp19->date = temp20->date;
                    temp19->LecturerID = temp20->LecturerID;
                    strcpy(temp19->name, temp20->name);
                    temp19->SeriesNum = temp20->SeriesNum;

                    temp20->date = uu6;
                    temp20->LecturerID = uu7;
                    strcpy(temp20->name, uu8);
                    temp20->SeriesNum = uu10;                // bubble sort

                }
                temp19 = temp20;
                temp20 = temp20->next;
            }
        }
        t = oldWH;
        while (t != NULL) {
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("-                  Historical  Report                    - \n");
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("  LecturerID       Name      SerialNumber        Date       \n");
            printf("     %d             %s           %d             %d          \n", t->LecturerID, t->name, t->SeriesNum, t->date);
            printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
            printf("\n\n");
            t = t->next;
        }// when the report is not empty print the report
    }
}
void display(char item[50], int z)
{
    if (newDP == NULL) {
        printf("List is empty\n\n");
    }   // check if the list is empty then print run this
    else {
        tmpdisplay = newDP;
        while (tmpdisplay != NULL)
        {
            if (strcmp(item, "SeriesNum") == 0) {
                if (tmpdisplay->SeriesNum == z) {
                    printf("LecturerID       == %d\n", tmpdisplay->LecturerID);
                    printf("Name             == %s\n", tmpdisplay->name);
                    printf("SerialNumber     == %d\n", tmpdisplay->SeriesNum);
                    printf("Date             == %d\n", tmpdisplay->date);
                    printf("\n");
                }
            }// if serial number is correct print record 
            else if (strcmp(item, "LecturerID") == 0) {
                if (tmpdisplay->LecturerID == z) {
                    printf("LecturerID       == %d\n", tmpdisplay->LecturerID);
                    printf("Name             == %s\n", tmpdisplay->name);
                    printf("SerialNumber     == %d\n", tmpdisplay->SeriesNum);
                    printf("Date             == %d\n", tmpdisplay->date);
                    printf("\n");
                }// if lecturer ID is correct print record
            }tmpdisplay = tmpdisplay->next;
        }
    }
}
void display2(char item[50], int z) {
    if (newWH == NULL) {
        printf("List is empty\n\n");
    }  // check if the list is empty then print run this
    else {
        tmpdisplay = newWH;
        while (tmpdisplay != NULL)
        {
            if (strcmp(item, "SeriesNum") == 0) {
                if (tmpdisplay->SeriesNum == z) {
                    printf("LecturerID       == %d\n", tmpdisplay->LecturerID);
                    printf("Name             == %s\n", tmpdisplay->name);
                    printf("SerialNumber     == %d\n", tmpdisplay->SeriesNum);
                    printf("Date             == %d\n", tmpdisplay->date);
                    printf("\n\n");
                }
            }// if serial number is correct print record 
            else if (strcmp(item, "LecturerID") == 0) {
                if (tmpdisplay->LecturerID == z) {
                    printf("LecturerID       == %d\n", tmpdisplay->LecturerID);
                    printf("Name             == %s\n", tmpdisplay->name);
                    printf("SerialNumber     == %d\n", tmpdisplay->SeriesNum);
                    printf("Date             == %d\n", tmpdisplay->date);
                    printf("\n\n");
                }// if lecturer is correct print record 
            }tmpdisplay = tmpdisplay->next;
        }
    }
}
void Insertion() {
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("- - - - - - - - - - - - -\n");
    printf("-        Borrow         -\n");
    printf("- - - - - - - - - - - - -\n");
    printf("- - - - - - - - - - - - -\n");
    printf("-     1.Digital Pad     -\n");
    printf("-2.Wireless Microphones -\n");
    printf("-      3.Main menu      -\n");
    printf("- - - - - - - - - - - - -\n");
    printf("Which item you want to borrow or back to main menu? \n");
    printf(">");
    scanf("%d", &a);
    if (a == 1) {
        if (padcount <= 20) {
            printf("Lecturer ID (000 - 999) :\n");
            printf(">");
            scanf("%d", &LecturerID);
            Checker(LecturerID);
            if (check) {  /// check if lecturer ID is exist or not
                printf("Lecturer Name   :\n");
                printf(">");
                scanf("%s", newnode->name);
                printf("Serial Number (000 - 999):\n");
                printf(">");
                scanf("%d", &SeriesNum);
                    CheckerSerial(SeriesNum);
                    if (get) { /// check if Serial  Number is exist or not
                    printf("Date (yyyymmdd format):\n");
                    printf(">");
                    scanf("%d", &date);
                    printf("\n");
                    printf("- - - - - - - - - - - - - - - - -\n");
                    printf("- Selected item is Digital Pad  -\n");
                    printf("- - - - - - - - - - - - - - - - -\n");
                    printf("Lecturer ID              :%d\n", LecturerID);
                    printf("Lecturer Name            :%s\n", newnode->name);
                    printf("Serial Number            :%d\n", SeriesNum);
                    printf("Date (yyyymmdd format)   :%d\n", date);
                    printf("- - - - - - - - - - - - - - - - -\n");
                    newnode->LecturerID = LecturerID;
                    newnode->SeriesNum = SeriesNum;
                    newnode->date = date;
                    newnode->next = NULL;

                    if (newDP == NULL)
                        newDP = newnode;
                    else if (LecturerID < newDP->LecturerID)
                    {
                        newnode->next = newDP;
                        newDP = newnode;
                    }
                    else {
                        temp = newDP;
                        while (temp != NULL)
                        {
                            if (LecturerID > temp->LecturerID)
                            {
                                prev = temp;
                            }
                            temp = temp->next;
                        }
                        newnode->next = prev->next;
                        prev->next = newnode;
                    }
                    padcount++;
                }
                else {
                    printf("Wrong input...\n");
                }
            }
                else {
                    printf("Wrong input...\n");

                }
            
        }
        else {
            printf("Digital Pad is out of stock..\n");
        }
    } else if (a == 2) {
        if (phcount <= 20) {
            printf("Lecturer ID (000 - 999):\n");
            printf(">");
            scanf("%d", &LecturerID);
            Checker2(LecturerID);
            if (check) {
                printf("Lecturer Name   :\n");
                printf(">");
                scanf("%s", newnode->name);
                printf("Serial Number (000 - 999):\n");
                printf(">");
                scanf("%d", &SeriesNum);
                CheckerSerial2(SeriesNum);
                if (get) {
                    printf("Date (yyyymmdd format):\n");
                    printf(">");
                    scanf("%d", &date);
                    printf("\n\n");
                    printf("- - - - - - - - - - - - - - - - - - -\n");
                    printf("Selected item is Wireless Microphone \n");
                    printf("- - - - - - - - - - - - - - - - - - -\n");
                    printf("-Lecturer ID              :%d\n", LecturerID);
                    printf("-Lecturer Name            :%s\n", newnode->name);
                    printf("-Serial Number            :%d\n", SeriesNum);
                    printf("-Date (yyyymmdd format)   :%d\n", date);
                    printf("- - - - - - - - - - - - - - - - - - -\n");
                    newnode->LecturerID = LecturerID;
                    newnode->SeriesNum = SeriesNum;
                    newnode->date = date;
                    newnode->next = NULL;

                    if (newWH == NULL)
                        newWH = newnode;
                    else if (LecturerID < newWH->LecturerID)
                    {
                        newnode->next = newWH;
                        newWH = newnode;
                    }
                    else {
                        temp = newWH;
                        while (temp != NULL)
                        {
                            if (LecturerID > temp->LecturerID)
                            {
                                prev = temp;
                            }
                            temp = temp->next;
                        }
                        newnode->next = prev->next;
                        prev->next = newnode;
                    }
                    phcount++;
                }

                else {
                    printf("Wrong input...\n");
                }
            }
            else {
                printf("Wrong input...\n");
            }

        }
        else {
            printf("Wireless microphone is out of stock..\n");
        }
    }
    else if (a == 3) {
        printf("return to Main Menu.....\n");
    }
    else {
        printf("opps..Wrong Input\n\n\n");
    }
}
void Deletion()  {
    int re = 0;

    printf("- - - - - - - - - - - - -\n");
    printf("-         Return        -\n");
    printf("- - - - - - - - - - - - -\n");
    printf("- - - - - - - - - - - - -\n");
    printf("-     1.Digital Pad     -\n");
    printf("-2.Wireless Microphone  -\n");
    printf("-      3.Main Menu      -\n");
    printf("- - - - - - - - - - - - -\n");
    printf("\n");

    printf("Which item do you want to return ?\n");
    printf(">");
    scanf("%d", &re);

    if (re == 1) {
        printf("Your selected item is Digital Pad\n");
        printf("LecturerID: \n");
        printf(">");
        scanf("%d", &LecturerID);
        Checker3(LecturerID);
        if (check) {
            if (newDP != NULL) {
                if (newDP->LecturerID == LecturerID) {
                    temp = newDP;
                    newDP = newDP->next;
                }
                else {
                    temp = newDP;
                    while (temp->LecturerID != LecturerID) {
                        prev = temp;
                        temp = temp->next;

                    }
                    prev->next = prev->next->next;
                }
                temp->next = NULL;
                padcount--;

                if (oldDP == NULL) {
                    oldDP = temp;
                }
                else {
                    prev = oldDP;
                    while (prev->next != NULL) {
                        prev = prev->next;
                    }
                    prev->next = temp;
                }
                historyDP++;
            }
            printf("!! This item had been returned !!\n");
            printf("\n\n");
        }
        else {
            printf("\n");
            printf("Wrong Input...\n");
        }
    }
    else if (re == 2) {
        printf("Your selected item is Wireless Microphone \n");
        printf("LecturerID: \n");
        printf(">");
        scanf("%d", &LecturerID);
        Checker4(LecturerID);
        if (check) {
            if (newWH != NULL) {
                if (newWH->LecturerID == LecturerID) {
                    temp2 = newWH;
                    newWH = newWH->next;
                }
                else {
                    temp2 = newWH;
                    while (temp2->LecturerID != LecturerID) {
                        prev2 = temp2;
                        temp2 = temp2->next;
                    }
                    prev2->next = prev2->next->next;
                }
                temp2->next = NULL;
                phcount--;

                if (oldWH == NULL) {
                    oldWH = temp2;
                }
                else {
                    prev2 = oldWH;
                    while (prev2->next != NULL) {
                        prev2 = prev2->next;
                    }
                    prev2->next = temp2;
                }
                historyWM++;
            }
            printf("!! This item had been returned !!\n");
            printf("\n\n");
        }
        else {
            printf("\n");
            printf("Wrong Input...\n\n");
        }
    }
    else if (re == 3) {
        printf("Return to main menu.....\n");
    }
    else {
        printf("!!!Wrong Input!!!\n");
    }
}  // Delete data from the list
void Search() {
    int option;
    int order = 0;

    printf("- - - - - - - - - - - - -\n");
    printf("-  Search Loan Record   -\n");
    printf("- - - - - - - - - - - - -\n");
    printf("- - - - - - - - - - - - -\n");
    printf("-     1.Digital pad     -\n");
    printf("- 2.Wireless Microphone -\n");
    printf("-      3.Main Menu      -\n");
    printf("- - - - - - - - - - - - -\n");
    printf("Your option is ?\n");
    printf(">");
    scanf("%d", &option);

    if (option == 1) {
        printf("Your selected option is Digital Pad.\n");
        printf("- - - - - - - - - - - - -\n");
        printf("-        Search by      -\n");
        printf("- - - - - - - - - - - - -\n");
        printf("- - - - - - - - - - - - -\n");
        printf("-    1.Serial Number    -\n");
        printf("-     2.Lecturer ID     -\n");
        printf("-      3.Main Menu      -\n");
        printf("- - - - - - - - - - - - -\n");
        printf("You want your list is search by ? \n");
        printf(">");
        scanf("%d", &order);

        if (order == 1) {
            printf("Serial Number\n");
            printf(">");
            scanf("%d", &SeriesNum);
            printf("\n");
            printf("Program is processing ....\n");
            printf("- - - - - - - - - - - - - - - -\n");
            printf("-     Outstanding Record      -\n");
            printf("- - - - - - - - - - - - - - - -\n");
            display("SeriesNum", SeriesNum);
        }
        else if (order == 2) {

            printf("Lecturer ID\n");
            printf(">");
            scanf("%d", &LecturerID);
            printf("\n");
            printf("Program is processing ....\n");
            printf("- - - - - - - - - - - - - - - -\n");
            printf("-     Outstanding Record      -\n");
            printf("- - - - - - - - - - - - - - - -\n");
            display("LecturerID", LecturerID);
        }
        else if(order == 3) {
            printf("Return to main menu.....\n");
        }
        else {
            printf("!!Wrong Input!!");
        }
    }
    else if (option == 2) {
        printf("Your selected item is Wireless Microphone.\n");
        printf("- - - - - - - - - - - - -\n");
        printf("-        Search By      -\n");
        printf("- - - - - - - - - - - - -\n");
        printf("- - - - - - - - - - - - -\n");
        printf("-    1.Serial Number    -\n");
        printf("-     2.Lecturer ID     -\n");
        printf("-      3.Main Menu      -\n");
        printf("- - - - - - - - - - - - -\n");
        printf("You want your list is search by ? \n");
        printf(">");
        scanf("%d", &order);

        if (order == 1) {
            printf("Serial Number\n");
            printf(">");
            scanf("%d", &SeriesNum);
            printf("\n");
            printf("Program is processing ....\n");
            printf("- - - - - - - - - - - - - - - -\n");
            printf("-     Outstanding Record      -\n");
            printf("- - - - - - - - - - - - - - - -\n");
            display2("SeriesNum", SeriesNum);
            printf("\n");
        }
        else if (order == 2) {
            printf("Lecturer ID\n");
            printf(">");
            scanf("%d", &LecturerID);
            printf("\n");
            printf("Program is processing ....\n");
            printf("- - - - - - - - - - - - - - - -\n");
            printf("-     Outstanding Record      -\n");
            printf("- - - - - - - - - - - - - - - -\n");
            display2("LecturerID", LecturerID);
            printf("\n");
        }
        else if (order == 3){
            printf("Return to main menu.....\n");
        }
        else {
            printf("!!Wrong Input!!");
        }
    }
}   // Search data from the list
void Generate() {

    int b, o, f, oo, ff;
    int report = 0;
    int report1 = 0;

    printf("- - - - - - - - - - - - - -\n");
    printf("-    Generate Report      -\n");
    printf("- - - - - - - - - - - - - -\n");
    printf("- - - - - - - - - - - - - -\n");
    printf("-      1.Digital Pad      -\n");
    printf("-  2. Wireless Microphone -\n");
    printf("-       3.Main Menu       -\n");
    printf("- - - - - - - - - - - - - -\n");
    printf("Your option is ?\n");
    printf(">");
    scanf("%d", &b);
    if (b == 1) {
        printf("- - - - - - - - - - - - - -\n");
        printf("-      Type of report     -\n");
        printf("- - - - - - - - - - - - - -\n");
        printf("-  1.Outstanding reports  -\n");
        printf("-   2.Historical reports  -\n");
        printf("-       3.Main Menu       -\n");
        printf("- - - - - - - - - - - - - -\n");
        printf("Your option is ?\n");
        printf(">");
        scanf("%d", &report);
        printf("\n");
        if (report == 1) {
            printf("- - - - - - - - - - - - - -\n");
            printf("-         order by        -\n");
            printf("- - - - - - - - - - - - - -\n");
            printf("-     1.Lecturer ID       -\n");
            printf("-         2.Date          -\n");
            printf("-       3.Main Menu       -\n");
            printf("- - - - - - - - - - - - - -\n");
            printf("Your option is ?\n");
            printf(">");
            scanf("%d", &o);
            if (o == 1) {
                printf("Digital Pad Outstanding report will be generating ....\n\n");
                IDSORT();
               
            }
            else if (o == 2) {
                printf("Digital Pad Outstanding report will be generating ....\n\n");
                DATESORT();
            }
            else if (o == 3) {
                printf("Return to Main Menu...\n");
            }
            else {
                printf("!!!Opps...Wrong input !!!\n\n");
            }
        }
        else if (report == 2) {
            printf("- - - - - - - - - - - - - -\n");
            printf("-         Order by        -\n");
            printf("- - - - - - - - - - - - - -\n");
            printf("-     1.Lecturer ID       -\n");
            printf("-         2.Date          -\n");
            printf("-       3.Main Menu       -\n");
            printf("- - - - - - - - - - - - - -\n");
            printf("Your option is ?\n");
            printf(">");
            scanf("%d", &f);
            if (f == 1) {
                printf("Digital Pad Historical report will be generating ....\n\n");
                IDSORT2();
            }
            else if (f == 2) {
                printf("Digital Pad Historical report will be generating ....\n\n");
                DATESORT2();
            }
            else if (f == 3) {
                printf("Return to Main Menu...\n");
            }
            else {
                printf("!!!Opps...Wrong input !!!\n\n");
            }
        }
    }
    else if (b == 2) {
        printf("- - - - - - - - - - - - - -\n");
        printf("       Type of report      \n");
        printf("- - - - - - - - - - - - - -\n");
        printf("-  1.Outstanding reports  -\n");
        printf("-   2.Historical reports  -\n");
        printf("-       3.Main Menu       -\n");
        printf("- - - - - - - - - - - - - -\n");
        printf("Your option is ?\n");
        printf(">");
        scanf("%d", &report1);
        if (report1 == 1) {
            printf("\n");
            printf("- - - - - - - - - - - - - -\n");
            printf("-         Order by        -\n");
            printf("- - - - - - - - - - - - - -\n");
            printf("-     1.Lecturer ID       -\n");
            printf("-         2.Date          -\n");
            printf("-       3.Main Menu       -\n");
            printf("- - - - - - - - - - - - - -\n");
            printf("Your option is ?\n");
            printf(">");
            scanf("%d", &ff);
            if (ff == 1) {
                printf("Wireless Microphone Outstanding report will be generating ....\n\n");
                IDSORT3();
            }
            else if (ff == 2) {
                printf("Wireless Microphone Outstanding report will be generating ....\n\n");
                DATESORT3();
               
            }
            else if (ff == 3) {
                printf("Return to Main Menu...\n");
            }
            else {
                printf("!!!Opps...Wrong input !!!\n\n");
            }

        }
        else if (report1 == 2) {
            printf("- - - - - - - - - - - - - -\n");
            printf("-         Order by        -\n");
            printf("- - - - - - - - - - - - - -\n");
            printf("-     1.Lecturer ID       -\n");
            printf("-         2.Date          -\n");
            printf("-       3.Main Menu       -\n");
            printf("- - - - - - - - - - - - - -\n");
            printf("Your option is ?\n");
            printf(">");
            scanf("%d", &oo);
            if (oo == 1) {
                printf("Wireless Microphone Historical report will be generating ....\n\n");
                IDSORT4();
            }
            else if (oo == 2) {
                printf("Wireless Microphone Historical report will be generating ....\n\n");
                DATESORT4();
            }
            else if (oo == 3) {
                printf("Return to Main Menu...\n");
            }
            else {
                printf("!!!Opps...Wrong input !!!\n\n");
            }
        }
        else if (report1 == 3) {
            printf("Return to Main Menu....\n\n");
        }
        else {
            printf("!!!Opps...Wrong input !!!\n\n");
        }
    }
    else if (b == 3) {
        printf("Return to Main Menu....\n\n");
    }
    else
    {
        printf("!!!Opps...Wrong input !!!\n\n");
    }
}   // Generate report according the list
void menu(int choice) {
    switch (choice)
    {
    case 1:
        Insertion(); break;
    case 2:
        Deletion(); break;
    case 3:
        Search(); break;
    case 4:
        Generate(); break;
    case 5:
        printf(" Program is Exiting......\n\n\n");
        printf("Program had been exit\n"); break;
    default:
        printf("!!! Wrong Input !!!\n"); break;
    }
}

void main() {
    int choice = 0; {};
    createlist();

    printf("- - - - - - - - - - - - - - - - -\n");
    printf("-     Welcome To The System     -\n");
    printf("- - - - - - - - - - - - - - - - -\n");
    printf("\n");
    while (choice != 5) {
        printf("- - - - - - - - - - - - -\n");
        printf("-       Main Menu       -\n");
        printf("- - - - - - - - - - - - -\n");
        printf("-       1.Borrow        -\n");
        printf("-       2.Return        -\n");
        printf("-  3.Check Loan Record  -\n");
        printf("-   4.Generate Report   -\n");
        printf("-        5.Exit         -\n");
        printf("- - - - - - - - - - - - -\n");
        printf("\n");
        printf("Which function would you like to select ? \n");
        printf(">");
        scanf("%d", &choice);
        printf("Your selected function is: %d\n", choice);
        printf("Program is processing . . . \n");
        printf("\n");
        menu(choice);
    }
}