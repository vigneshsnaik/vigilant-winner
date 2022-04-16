#include <iostream>
#include <bits.h>
#include <bits/stdc++.h>
using namespace std;

//get_base_feq() fetches base freq values or freq for sa
int get_base_feq(){
    float tonic;
    cout << "Reference for Kattai" << endl ;
    cout << "C :1" << endl ;
    cout << "C#:1.5" << endl ;
    cout << "D :2" << endl ;
    cout << "D#:2.5" << endl ;
    cout << "E :3" << endl ;
    cout << "F :4";
    cout << "F#:4.5" << endl ;
    cout << "G :5" << endl ;
    cout << "G#:5.5" << endl ;
    cout << "A :6" << endl ;
    cout << "A#:6.5" << endl ;
    cout << "B :7" << endl ;
    cout << "Enter the Shruti(Tonic) in Kattai: ";
    cin >> tonic;
    cout << endl;
    int base=0;
    if (tonic==1){
        cout << "Shruti set to C" << endl;
        base=261;
    }
    else if (tonic==1.5){
        cout << "Shruti set to C#" << endl;
        base=277;
    }
    else if (tonic==2){
        cout << "Shruti set to D" << endl;
        base=293;
    }
    else if (tonic==2.5){
        cout << "Shruti set to D#" << endl;
        base=311;
    }
    else if (tonic==3){
        cout << "Shruti set to E" << endl;
        base=329;
    }
    else if (tonic==4){
        cout << "Shruti set to F" << endl;
        base=349;
    }
    else if (tonic==4.5){
        cout << "Shruti set to F#" << endl;
        base=369;
    }
    else if (tonic==5){
        cout << "Shruti set to G" << endl;
        base=392;
    }
    else if (tonic==5.5){
        cout << "Shruti set to G#" << endl;
        base=415;
    }
    else if (tonic==6){
        cout << "Shruti set to A" << endl;
        base=440;
    }
    else if (tonic==6.5){
        cout << "Shruti set to A#" << endl;
        base=466;
    }
    else if (tonic==7){
        cout << "Shruti set to B" << endl;
        base=493;
    }
    else{
        base=329;
        cout << "!!!ERROR!!!" << endl;
        cout << "Invalid Shruti"<<endl;
        cout << "Shruti set to default (E or 3 kattai)";
        cout << endl;
    }
    return base;
}

//bpm_time fetchs the tim of a particular note to be played
int bpm_time(){
    cout << "Enter Rate (Beats per Minute): ";
    float bpm , tme;
    cin >> bpm;
    cout << endl;
    tme=1000*60*(1/bpm);
    return tme; 
}

//this function reads the file
int read(int base, int time){

    //rtio is the ratio of freq of a note to freq of base note Sa
    int feq;

    // filestream variable file
    fstream file;
    string note, t, q, filename;
  
    // filename of the file
    cout << "Enter the Name of File";
    cin >> filename;
  
    // opening file
    file.open(filename.c_str());
  
    // extracting notes from the file
    while (file >> note){
        float note_feq;
        if (note=="Sa"){
            note_feq=base;
        }
        else if (note=="R1"){
            note_feq=base*16/15;
        }
        else if (note=="R2"||note=="G1"){
            note_feq=base*9/8;
        }
        else if (note=="R3"||note=="G2"){
            note_feq=base*6/5;
        }
        else if (note=="G3"){
            note_feq=base*5/4;
        }
        else if (note=="M1"){
            note_feq=base*4/3;
        }
        else if (note=="M2"){
            note_feq=base*17/12;
        }
        else if (note=="Pa"){
            note_feq=base*3/2;
        }
        else if (note=="D1"){
            note_feq=base*8/5;
        }
        else if (note=="D2"||note=="N1"){
            note_feq=base*5/3;
        }
        else if (note=="D3"||note=="N2"){
            note_feq=base*9/5;
        }
        else if (note=="N3"){
            note_feq=base*15/8;
        }
        else if (note=="S."){
            note_feq=base*2;
        }
        Beep(note_feq,time);
    }
    return 0;
}

int main(){
    int base_feq,dflt_time;
    base_feq=get_base_feq();
    dflt_time=bpm_time();
    read(base_feq,dflt_time);
    return 0;
}