# C-Database

A reservation system designed in C which creates files, stores and does basic manipulations. 

NB- THE DESCRIPTION OF THIS COMES IN TWO LANGUAGES HERE FOR ENGLISH SCROLL DOWN FOR FRENCH

//ENGLISH

PROJECT REALIZED- RESERVATION SYSTEM FOR VIDEO CASSETTES

DESCRIPTION

The objective of this project is to realize a database of records that takes all the necessary steps to record, display and borrow a cassette, it allows to take details of a borrower who wants to take one or more cassettes or return cassettes borrowed.

 DESCRIPTION OF EACH PHASE OF THE PROJECT
 
   1. The three INCLUDE is called the library for entry and exit ...
   2. There are two structures- VCassette and Vprinter that contain fields for dealing with different and specific cases.
   3. Prototypes that facilitate finding functions in the program
   4. In the main () function, which is the main program, we make a menu that contains the lists of choices to make. There are 7          choices to make in the menu.
4a. We made a case switch to access the functions by an alphabet.

FUNCTIONS

1. void addCassette (): this function is used to add one or more new cassettes in the list of existing cassettes, the contents are the name of the cassette, the year of production of the cassette, a code for each cassette and the quantity of the cassette.
Here we create a file called ListedesCassette.txt to save the details of each cassette with fopen() in append mode and we use the fields of the VCassette structure.
We tests with a condition to find if the file is not NULL, if the condition is met, we demand :
    a. The name of the cassette
    b. The year of production of the cassette
    c. A unique code associated with this cassette
    d. The quantity of this available cassette
After having this information, we make an fprintf() to take the 4 informations entered and put in the file ListedesCassette.txt we created and so we will have a confirmation message that: THE CASSETTE HAS BEEN RECORDED! And now we use the pborne pointer with fclose() to stop access to the file ListedesCassette.txt. In the case that it is NULL one will have an error message: THE CASSETTE CAN NOT ADDED!

2. void showCassette (): this function makes a display of all available cassettes that's in the file on the console. It's to help make a choice. We made a loop to access ListedesCassette.txt and to find if the file is different from NULL and if the condition is met we show all cassettes, otherwise nothing will display. After we use the pborne pointer with fclose() to stop access to the file ListedesCassette.txt.

3. void addBorrower(): this function is used to add one or more new borrower who wants one or more cassettes in a file DetailsofBorrowers.txt, it contains the surname of borrower, the first name of borrower, the name of the cassette , the borrower's address and the telephone number of this borrower.
Here, we create a file named DetailsofPackers.txt to save the details of each borrower with fopen() in the read mode and we use the fields of the VPC structure.
We test with a condition to find if the file is not NULL, if the condition is met we ask for:
    a. The borrower's surname
    b. The first name of the borrower
    c. The name of the cassette
Here after we put the name of the tape, we do a scanf(), we make a loop to check if the tape requested exists in the cassette's file, if it exists there is a message of availability: THE CASSETTE REQUESTED IS AVAILABLE and we pass on to the following to fill the other informations:
    d. The address of the borrower
    e. The telephone number of the borrower
After having this information, we make an fprintf() to take the results and put them in the file DetailsofEmployers.txt that we have created and so we will have a confirmation message that: THIS BORROWER HAS BEEN RECORDED! So in the case where the requested cassette does not exist in the file, it displays an error message: THE DEMANDED CASSETTE IS NOT AVAILABLE.
And now we use the pointer pBorne with fclose() to stop the access to the file DetailsofPackers.txt.

4. void borrowCassette (): this function allows someone to borrow one or more desired cassette.
We access the file ListedesCassette.txt with fopen() in the read mode and test with a condtion if the pointer is different from NULL, if the condition is verified we ask:
    a. The name of the cassette
After putting the name of the tape, we read the file ListedesCassette.txt and we use a loop to check if the tape requested exists in the cassette's file if it does, there is a message of the existence: FOUND and we pass on to fill the other informations:
    b. The quantity of the cassette
When we give a quantity we check for 3 conditions:
    1. If the quantity asked is greater than the quantity available, we receive a message: The quantity available is less than the quantity you want.
    2. If the quantity requested is less than zero, it displays: Put a quantity greater than zero.
    3. If the quantity requested is less than or equal to the quantity available, the amount available is subtracted from the desired quantity, and now the file will contain the quantity remaining after the subtraction.
After checking the quantity, it is shown that the cassette is NOT FOUND if the borrower puts the name of a tape that does not exist in the file.

5. void displayBorrowers(): This function makes a display of all the borrowers that are in the file on the console. This shows each borrower with his surname, first name, the tape borrowed, address and phone number. We made a loop to access DetailsofPackers.txt and to check if the file is different from NULL and if the condition is verified it displays all, otherwise nothing will display. After we use the pointer pborne with fclose() to stop the access to the file DetailsofPackers.txt.
    
6. void returnsCassette (): This function allows the borrower to return the cassette(s) borrowed.
We access the file ListedesCassette.txt with fopen() in the read mode and test with a condtion if the pointer is different from NULL, if the condition is verified we ask:
    c. The name of the cassette
After putting the name of the tape, we read the file ListedesCassette.txt and we use a loop to check if the tape requested exists in the cassette file if it does we get a message of the existence: FOUND and we pass the following:
    d. The amount of tapes taken
When we give the quantity borrowed we add to the quantity available in the file ListedesCassette.txt. There is an update every time a borrower returns a cassette.
After addititon of the amount borrowed to the quantity in the file, we get a confirmation message: THANK YOU FOR RETURNING THE CASSETTE. And if we put a cassette or quantity that is incorrect in the file, we display: ENTER THE CORRECT INFORMATION. At the end we use the pborne pointer with fclose() to stop access to the file ListedesCassette.txt.

7. void deleteBorrower(): The last function is to delete a borrower after returning the tape(s) borrowed with all his details. We open the file DetailsofPackers.txt with fopen() in read mode for reading and we search if the pointer is different from NULL, then we ask for:
    at. The borrower's name
We use this information to browse in the file and when we find the borrower it deletes all the details in relation to this borrower.
In the case where the name given is different from what is in the file it displays an error message: THIS BORROWER DOES NOT EXIST.
 At the end we use the pointer pborne with fclose() to stop the access to the file DetailsdesEprinters.txt.
 //VERY IMPORTANT
To browse the two files DetailsofPackers.txt and ListdesCassette.txt we use a temporary file tmp.txt to read and write for whatever you want.


Un système de réservation conçu en C qui crée des fichiers, stocke et effectue des manipulations de base.

//FRENCH

PROJET REALISER- SYSTEME DE RESERVATION DES CASSETTES VIDEO

DESCRIPTION

L’objective de ce projet est pour realiser une base des donees qui prend tous les donees necessaire pour enregistrer, afficher et emprunter une cassette, il permet de prendre des details d’un emprunteur qui veut prendre un ou plusieurs cassettes ou bien retourner des cassettes emprunter.

 DESCRIPTION DE CHAQUE PHASE DU PROJET
 
   1. Les trois INCLUDE c’est les appelle des bibliotheque pour les entrees et sorties…
   2. Il y a deux structure VCassette et VEmprunteur qui contient des champs pour traiter les cas differents et specifique.
   3. Les prototypes qui faciliter a trouver des fonction dans le programme
   4. Dans la fonction main() qui est le program principal, on fait un menu qui contient les listes des choix a faire. Il y a 7 choix a faire dans le menu.
  4a. On a fait un cas vaut pour acceder la fonction demander par un alphabet.
  
  
LES FONCTIONS

   1. void ajouterCassette() : cette fonction est utiliser pour ajouter un ou plusieurs nouvelle cassettes dans la liste des cassettes existant, les contenus sont le nom de la cassette, l’annee de production de la cassette, une code pour chaque cassette et la quantite de la cassette.
Ici on cree un fichier qui s’appelle ListedesCassette.txt pour sauvegarde des details de chaque cassette avec fopen() dans le mode append et on utilise les champs de la structure VCassette.
On teste avec une condition pour chercher si le fichier n’est pas NULL, si la condition est verifier on demande :
    a. Le nom de la cassette
    b. L'annee de production de la cassette
    c. Une code unique associer a cette cassette
    d. La quantite de cette cassette disponible
Apres d’avoir ces informations, on fait un fprintf() qui prendre les 4 resultats et mettre dans le fichier ListedesCassette.txt que on a cree  et donc nous aurons une message de confirmation que : LA CASSETTE EST ENREGISTRE! Et maintenat on utilise le pointeur pborne avec fclose() pour arreter l’access au fichier ListedesCassette.txt. Dans le cas qu’il est NULL on aura une message d’erreur : LA CASSETTE NE PEUX PAS AJOUTER!

   2. void afficherCassette() : cette fonction faire une affichage de tous des cassettes disponible qui dans le fichier sur la console. C’est pour aider de faire un choix. On a fait une boucle pour acceder ListedesCassette.txt et chercher si le fichier est different de NULL est si la condition est verifier on affiche tous, sinon rien n’affichera. Apres on utilise le pointeur pborne avec fclose() pour arreter l’access au fichier ListedesCassette.txt.
   
   3. void ajouterEmprunteur() : cette fonction est utiliser pour ajouter un ou plusiuer nouveau emprunteur qui veulent un ou plusieurs cassettes dans un fichier DetailsdesEmprunteurs.txt, il contient le nom d’emprunteur, le prenom d’emprunteur, le nom de la cassette, l’adresse d’emprunteur et le numero de telephone de ce emprunteur.
Ici on cree un fichier qui s’appelle DetailsdesEmprunteurs.txt pour sauvegarde des details de chaque emprunteur avec fopen() dans le mode read et on utilise les champs de la structure VEmprunteur.
On teste avec une condition pour chercher si le fichier n’est pas NULL, si la condition est verifier on demande :
    a. Le nom d'emprunteur
    b. Le prenom d'emprunteur
    c. Le nom de la cassette
Ici apres on mettre le nom de la cassette et on fait un scanf(), on fait une boucle pour verifier si la cassette demander existe dans le fichier de cassette s’il existe on affiche une message de la disponibilite : LA CASSETTE DEMANDE EST DISPONIBLE et on passe toute suite de remplir les autres informations :
    d. L'adresse de l'emprunteur
    e. Le numero de telephone de l'emprunteur
Apres d’avoir ces informations, on fait un fprintf() qui prendre les 5 resultats et mettre dans le fichier DetailsdesEmprunteurs.txt que on a cree et donc nous aurons une message de confirmation que : CETTE EMPRUNTEUR EST ENREGISTRE! Donc dans le cas ou la cassette demander n’existe pas dans le fichier on affiche une message d’erreur : LA CASSETTE DEMANDE N'EST PAS DISPONIBLE.
Et maintenat on utilise le pointeur pBorne avec fclose() pour arreter l’access au fichier DetailsdesEmprunteurs.txt

   4. void emprunterCassette() : cette fonction permet quelqu’un d’emprunter un ou plusiers cassette desirer.
On accede le fichier ListedesCassette.txt avec fopen() dans le mode read et teste avec une condtion si le pointeur est different de NULL, si la condition est verifiee on demande :
    a. Le nom de la cassette
Apres on mettre le nom de la cassette, on lire le fichier ListedesCassette.txt et on a fait une boucle pour verifier si la cassette demander existe dans le fichier de cassette s’il existe on affiche une message de l’existence : TROUVE et on passe toute suite de remplir l’autre information :
    b. La quantite de la cassette 
Quand on donne une quantite demander on fait 3 conditons :
    1. Si la quantite demander est superieure a la quantite disponible, si on tombe dans ce cas on affiche : La quantite disponible est moins de la quantite vous voulez.
    2. Si la quantite demander est inferieure a zero, on affiche : Mettrez une quantite superieure a zero.
    3. Si la quantite demander est inferieure ou egal a la quantite disponible on fait une soutraction de la quantite disponible de la quantite desirer, et alors maintenant le fichier va contenir la quantite qui reste apres la soustraction.
Apres la verification de la quantite on affiche que la cassette est NON TROUVE  si l’emprunteur mettre un nom d’une cassette qui n’existe pas dans le fichier.

   5.  void afficherEmprunteur() : cette fonction faire une affichage de tous des emprunteurs qui sont dans le fichier sur la console. C’est pour voir chaque emprunteur avec son nom, prenom, la cassette emprunter, adresse et numero de telephone. On a fait une boucle pour acceder DetailsdesEmprunteurs.txt et chercher si le fichier est different de NULL est si la condition est verifier on affiche tous, sinon rien n’affichera. Apres on utilise le pointeur pborne avec fclose() pour arreter l’access au fichier DetailsdesEmprunteurs.txt.
   
   6. void retourneCassette() : cette fonction permet l’emprunteur a retourner la ou les cassettes emprunter.
On accede le fichier ListedesCassette.txt avec fopen() dans le mode read et teste avec une condtion si le pointeur est different de NULL, si la condition est verifiee on demande :
    c. Le nom de la cassette
Apres on mettre le nom de la cassette, on lire le fichier ListedesCassette.txt et on a fait une boucle pour verifier si la cassette demander existe dans le fichier de cassette s’il existe on affiche une message de l’existence : TROUVE et on passe toute suite de remplir l’autre information :
    d. La quantite de la cassette pris
Quand on donne la quantite on fait une addition a la quantite disponible dans le fichier ListedesCassette.txt. C’est un mis a jours on fait a chaque fois un emprunteur retourne une cassette.
Apres l’addititon de la quantite emprunter a la quantite dans le fichier on affiche une message de confirmation : MERCI POUR RAMENER LA CASSETTE. Et si on mettre une cassette ou quantite qui est incorrect dans le fichier on affiche : Entrer les information correcte. A la fin on utilise le pointeur pborne avec fclose() pour arreter l’access au fichier ListedesCassette.txt.

   7. void supprimerEmprunteur() : la dernier fonction servir de supprimer un emprunteur apres retourner la cassette emprunter avec tous son details. On ouvris le fichier DetailsdesEmprunteurs.txt avec fopen() dans le mode read pour lecture et on cherche si le pointeur est different de NULL, quand on verifie on demande :
    a. Le nom d'emprunteur
On utilise ce information pour parcourir dans le fichier est supprimer tous les details en relation de cet emprunteur.
Dans le cas ou le nom demander est different de ce qui est dans le fichier on affiche une message d’erreur : Cet emprunteur n'existe pas.

 A la fin on utilise le pointeur pborne avec fclose() pour arreter l’access au fichier DetailsdesEmprunteurs.txt.
Pour parcourir les deux fichier DetailsdesEmprunteurs.txt et ListedesCassette.txt on a utiliser un fichier temporaire tmp.txt pour faire la lecture et ecriture pour ce qu’on veut.


