# C-project
HOSPITAL MANAGEMENT SYSTEM


Done by:-
                1. Shreyas Arun
             2. Shreyank
             3. K V Nikhilesh
             4. M Nishal
             5.Vishal Shankar
          6.Aditya Nangarath
Execution:

Run Make command in terminal to compile all the files
Then run ./hospital to execute the program



Components:


New Patient Entry/ Existing patient details login system
Appointment system
Doctors / Nurses / Staff assigning
Room assignment for patients
Billing system


1.New Patient Entry/ Existing Patient details login system:

The patient_account_creation() takes in all the information about the patient such as name, age, sex, phone number, emergency contact number, sickness, patient id.

It checks whether an account of that name already exists or not and proceeds to show a message 

If the account does not exist it will create an account and it will print the above details in a defined order with a patient successfully being created in the system.
The patient_info_display() displays all the temporary information about the patient that has just been created.

After dynamically allocating the arrays to store all the patient’s information, the count_patient() counts the number of patients existing in the hospital.

Finally, when a patient is healed of sickness, he/she is removed from the system using the delete_patient_info() which frees all the dynamic memory related to that particular patient and deletes the patient info from the file, it also makes the doctor assigned to that patient available

If the patient is not found, it prints a message saying a non-existing patient cannot be deleted.


2. Creating an Appointment:



The Patient_appointment structure is a linked list type structure that stores the data of every patient.

 The read_new_patient() reads the information of the patient that has come to make an appointment.

The display_slots() displays all the available slots for the patient to select.

The book_appointment() successfully creates an appointment for the patient. If there are no slots left then it will print a message and redirect the user back to the main menu.

The remove_slot() removes the booked slot from future bookings.

The details_file() displays all the information about the appointment such as the patient details, time, phone  number and problem in a new file.





3.Room Assignment:

The room_assign() will take all the necessary information of the patient such as name, sex, age, etc. to allocate him/her a room.

In the above function there are four options for the user to choose based on the type of room required. ‘1’ for luxury rooms, ‘2’ for medium sized rooms, ‘3’ for economy rooms and ‘4’ if you don’t want any room.

After choosing the room type the user is requested to give the dates for which they are staying.

Based on the type of room selected and number of dates, the program will store  the cost per night of the room. Depending on the number of rooms available it dynamically changes the price of each room

Once the room is vacated, the deassign_room() deletes the information of the patient who was staying and makes it vacant for a new patient to stay.



4.Doctor:

The doctor_assign() takes in all the necessary information like name, age, sex, sickness, sickness level of the patient and assigns he/she to the respective doctor.

For example, if the patient has ‘flu’, he/she will be assigned to a General Medicine doctor. If it is ‘cardiac’, then the assigned doctor will be a cardiology doctor.

If all the details entered about the patient are correct and there are enough doctors available then the appointment will be fixed successfully.

Error will be raised if the doctor is not available.






5.Billing System:

The billing() calculates the total cost to the hospital based on the number of days the patient stayed in a room, doctors appointed, type of room allocated, etc.

It takes input from the user like date of joining and leaving the hospital, medicines consumed and prints out the total cost.

The user has to pay for these charges.



6.The int main().

Finally the above defined functions are called using int main().

Option ‘1’ is entered, to add a new patient.

Option ‘2’ to display all the information of a patient.

Option ‘3’ to assign a room to a patient.

Option ‘4’ to delete a patient from the system and checkout i.e., generate a bill.

Option ‘5’ to book an appointment with a doctor.

Option ‘0’ to exit the system.
