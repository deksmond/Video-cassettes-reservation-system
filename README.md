# Video cassettes reservation system 

A reservation system designed in C which creates files, stores and does basic manipulations. 

DESCRIPTION

The objective of this project is to realize a database of records that takes all the necessary steps to record, display and borrow a VHS cassette, it takes inventory of a borrower who wants to take one or more cassettes or return cassettes borrowed.

DESCRIPTION OF EACH PHASE OF THE PROJECT
 
   1. The three INCLUDE calls the library for entry and exit ...
   2. There are two structures- VCassette and Vprinter that contain fields for dealing with different and specific cases.
   3. Prototypes that facilitate finding functions in the program
   4. In the main () function, which is the main program, we make a menu that contains the lists of choices to make. There are 7 choices to make in the menu.
   4a. We made a case switch to access the functions alphabetically.

FUNCTIONS

1. void addCassette (): this function is used to add one or more new cassettes in the list of existing cassettes, the contents are the names of the cassettes, the year of production, a code for each cassette and the quantity of the cassette. Here we create a file called ListedesCassette.txt to save the details of each cassette with fopen() in append mode and we use the fields of the VCassette structure.
We test with a condition to find if the file is not NULL, if the condition is met, we demand :
    a. The name of the cassette
    b. The year of production of the cassette
    c. A unique code associated with this cassette
    d. The quantity of this available cassette
After having this information, we make an fprintf() to take the 4 informations entered and put it in the file ListedesCassette.txt we created and so we will have a confirmation message that: THE CASSETTE HAS BEEN RECORDED! And now we use the pborne pointer with fclose() to stop access to the file ListedesCassette.txt. In a NULL case, it would report an error message: THE CASSETTE CAN NOT ADDED!

2. void showCassette (): this function makes a display of all available cassettes that's in the file on the console. It's to help make a choice. We made a loop to access ListedesCassette.txt and to find if the file is different from NULL and if the condition is met, we show all cassettes, otherwise nothing will display. After we use the pborne pointer with fclose() to stop access to the file: ListedesCassette.txt.

3. void addBorrower(): this function is used to add one or more new borrower who wants one or more cassettes in a file DetailsofBorrowers.txt, it contains the surname and first name of borrower, the name of the cassette , the borrower's address and telephone number. Here, we create a file named DetailsofPackers.txt to save the details of each borrower with fopen() in read mode and we use the fields of the VPC structure.
We test with a condition to find if the file is not NULL, if the condition is met we ask for:

    a. The borrower's surname
    b. The first name of the borrower
    c. The name of the cassette
    
Here after we put the name of the tape, we do a scanf(), we loop to check if the tape requested exists in the cassette's file, if it exists there is a message of availability: THE CASSETTE REQUESTED IS AVAILABLE and we pass on to the following to fill the other informations:

    d. The address of the borrower
    e. The telephone number of the borrower
    
After having these informations, we make an fprintf() to take the results and put them in the file DetailsofEmployers.txt that we have created and so we will have a confirmation message that: THIS BORROWER HAS BEEN RECORDED! So in the case where the requested cassette does not exist in the file, it displays an error message: THE DEMANDED CASSETTE IS NOT AVAILABLE.
And now we use the pointer pBorne with fclose() to stop the access to the file DetailsofPackers.txt.

4. void borrowCassette (): this function allows a client to borrow one or more desired cassette.
We access the file ListedesCassette.txt with fopen() in the read mode and test with a condtion if the pointer is different from NULL, if the condition is verified we ask for:

    a. The name of the cassette
    
After putting the name of the tape, we read the file ListedesCassette.txt and we use a loop to check if the tape requested exists in the cassette's file. If it does, there is a message of its existence: FOUND and we pass on to fill the other informations:

    b. The quantity of the cassette
    
When we give a quantity we check for 3 conditions:

    1. If the quantity asked is greater than the quantity available. We receive a message: The quantity available is less than the quantity you want.
    2. If the quantity requested is less than zero. It displays: Put a quantity greater than zero.
    3. If the quantity requested is less than or equal to the quantity available. The amount available is subtracted from the desired quantity, and now the file will contain the quantity remaining after the subtraction.
    
After checking the quantity, it is shown that the cassette is NOT FOUND, if the borrower puts the name of a tape that does not exist in the file.

5. void displayBorrowers(): This function makes a display of all the borrowers that are in the file on the console. This shows each borrower with his/her surname, first name, the tape borrowed, address and phone number. A loop is used to access DetailsofPackers.txt and to check if the file is different from NULL and if the condition is verified, it displays all, otherwise nothing will display. After we use the pointer pborne with fclose() to stop the access to the file DetailsofPackers.txt.
    
6. void returnsCassette (): This function allows the borrower to return the cassette(s) borrowed.
We access the file ListedesCassette.txt with fopen() in the read mode and test with a condtion if the pointer is different from NULL, if the condition is verified we ask:

    c. The name of the cassette
    
After putting the name of the tape, we read the file ListedesCassette.txt and we use a loop to check if the tape requested exists in the cassette file; if it does we get a message of its existence: FOUND and we pass the following:

    d. The amount of tapes taken
    
When we give the quantity borrowed, we add to the quantity available in the file ListedesCassette.txt. There is an update every time a borrower returns a cassette.
After an addititon of the amount borrowed to the quantity in the file, we get a confirmation message: THANK YOU FOR RETURNING THE CASSETTE. And if we put a cassette or quantity that is incorrect in the file, we display: ENTER THE CORRECT INFORMATION. At the end we use the pborne pointer with fclose() to stop access to the file ListedesCassette.txt.

7. void deleteBorrower(): The last function is to delete a borrower after returning the tape(s) borrowed with all his/her details. We open the file DetailsofPackers.txt with fopen() in read mode for reading and we search if the pointer is different from NULL, then we ask for:

    a. The borrower's name
    
We use this information to browse in the file and when we find the borrower, it deletes all the details in relation to this borrower. In the case where the name given is different from what is in the file, it displays an error message: THIS BORROWER DOES NOT EXIST.
 At the end we use the pointer pborne with fclose() to stop the access to the file DetailsdesEprinters.txt.
 
VERY IMPORTANT
To browse the two files DetailsofPackers.txt and ListdesCassette.txt we use a temporary file tmp.txt to read and write for all manipulations.
