#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{

    int guntime[3];//will contain the first 3 inputs
    vector<int> input;
    fstream project;
    char name[100];//will contain the name of the file that contain the racers details
    int data;
    cout<<"enter the name of the result file: ";
    cin.getline(name,'\n');
    project.open(name);
    if (project.fail())//check that the file actually exists
		cout << "File open error!" << endl;
    else{
    //will take the numbers in the files and out them one by one into the vector(input)
    while(!project.eof() && !project.fail())
        {
            project>>data;
            input.push_back(data);
        }

    }
    //will save the first 3 int values in an array called: guntime cause we don't need them at all
    for(int i=0;i<<3;i++)
        guntime[i]=input[i];
    input.erase(input.begin(),input.begin()+3);//here we erase them so that they don't slow us down
    int counter=0;
    //this loop will calculate the number of racers by seeing how many times the first stage(0) happened
    //for everytime its called its a new racer
    for(int i=0;i<input.size();i+=5)
        {
            if(input[i]==0)
                counter++;
            else{break;}
        }
     //now we create an array that contain the racers numbers and their time records
     //counter stands for the number of the racers
     // 4 cols the first is for the racer number the second is for the time they started
     //third for the time taken for the racer to reach the midway sensor
     //fourth is for the time they reached the end sensor
    int arr[counter][4];
    int a=0,b=0,c=0,d=0;
    //we now that the first number of every line (in the data folder) is the sensor number
    //and after it 4 numbers of data so we will increment the i 5 times so that we are alway at the sensor number
    for(int i=0;i<input.size();i+=5)
        {
            //at the first sensor we will take the number after it (racer number) and save it in the first row
            if(input[i]==0){
                arr[0][a]=input[i+1];
                a++;
            //we will also take the time they started in hours mins and seconds and convert them all to seconds
            //then save them in the second row
                arr[1][b]=(input[i+2]-8)*3600+input[i+3]*60+input[i+4];
                b++;
            }
            else if(input[i]==1)
            {
                //1 stands for the second sensor so will also take the time for each racer and convert it then
                //store it in the 3rd row
                arr[2][c]=(input[i+2]-8)*3600+input[i+3]*60+input[i+4];
                c++;
            }
            else if(input[i]==2)
                {
                //2 stands for the finish sensor will take the time convert it then store it in the 4th row
                arr[3][d]=(input[i+2]-8)*3600+input[i+3]*60+input[i+4];
                d++;
                }
        }
     //now we have all the data we need just need to remember that the second sensor is at 7 miles from the start
     //and the finish sensor is at 13.1 miles from the start

     cout<<"enter the racer number: ";
     int choice,racer;
     cin>>choice;
     //will check if the racer number entered by the user actually exists or not if not end the program
     //then will compare the choice with the racer numbers and locate its number in the first row
     bool found=false;
     for(int i=0;i<counter;i++)
        {
            if(choice==arr[0][i])
                {
                racer=i;
                found=true;
                }
        }
     if(found==false)
     {
      cout<<"Racer not found now terminating.";
      return 0;
     }
     //we will assume that the racer won the first place by having the least time of all the racers
     //then compare his record with the others if his record time was bigger than another record will increase his place
     //from first to second and so but with numbers only
     int place=1;
     for(int i=0;i<counter;i++)
     {  int least=arr[3][racer];
        if(arr[3][i]<least)
            place++;
     }
     cout<<"the racer place is: "<<place<<endl;
     cout<<"racer overview:-"<<endl;
     cout<<"the racer time record for the first interval of the race= "<<(arr[2][racer]-arr[1][racer])/7<<" seconds per mile"<<endl;
     cout<<"the racer time record for the second interval of the race= "<<(arr[3][racer]-arr[2][racer])/(13.1-7)<<" seconds per mile"<<endl;
     cout<<"racer overall pace = "<<13.1<<" miles covered in "<<(arr[3][racer]-arr[1][racer])<<" seconds"<<endl;

}
//dah kol el mtloob bs msh mot2kd mn el overall pace hoa 3aiz el time feha mn el guntime wla mn el sania eli
//el racer 2btda feha.



