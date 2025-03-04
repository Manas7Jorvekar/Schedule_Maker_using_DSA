#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"header.h"

int main() {
    // Read data from CSV file and populate the timetable
    FILE* file = fopen("database.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Class classData;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", 
               classData.classroom, classData.day, classData.time,
               classData.faculty, classData.subject, classData.class_name);
        insertClass(classData);
    }
    
    fclose(file);

    Schedule_new_lecture("Ahilya_Dhere", "SY_CE1", "VCPDE");

    printf("\n \n \n");
    printf("Your updated schedule is as follows : \n \n");
    display_schedule_for_faculty("Ahilya_Dhere");

    printf("\n \n \n");
    displayTimetable();

    return 0;
}